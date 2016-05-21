#!/usr/sbin/dtrace -qs

#pragma D option defaultargs

/*
q0 mapped to 1
q1 mapped to 0
*/

/*
node$target:node::http-server-response/ (nresponses > nqueries)/ mapped to 0
tick-10hz/((nrequests - nresponses) > 100) || ((nrequests - nqueries) > 100)/ mapped to 1
*/

int HAS_VERDICT;
int state;
int tf[2][2];

/* Counter initialization manually added */
int nrequests, nresponses, nqueries;

node$target:node::http-server-request
{
    nrequests++;
}

node$target:node::http-server-response
{
    nresponses++;
}

postgresql$$1:postgres:PortalRun:query-execute-done
{
    nqueries++;
}

dtrace:::BEGIN
{
	tf[0][0] = 1;
	tf[0][1] = 1;
	tf[1][0] = 1;
	tf[1][1] = 1;
	HAS_VERDICT = 0;
    /* state expression manually corrected to $2 */
	state = ($2 ? $2: 0);
}

node$target:node::http-server-response
/ ( (nresponses > nqueries)) && (state == 0)/
{
	trace("REJECTED DUE TO MISMATCH");
	HAS_VERDICT = 1;
	exit(0);
}

tick-10hz
/ (((nrequests - nresponses) > 100) || ((nrequests - nqueries) > 100)) && (state == 0)/
{
	trace("REJECTED DUE TO UNRESPONSIVENESS");
	HAS_VERDICT = 1;
	exit(0);
}

dtrace:::END
/ !HAS_VERDICT /
{
	trace("INCONCLUSIVE");
}

