
const http = require('http');
const pg = require('pg');
const config =require('config.json');

const conString = config.conString;

const client = new pg.Client(conString);

client.connect(function(error){
    if(error){
        console.log("could not connect to postgresql");
    }
});

client.query('SELECT pg_backend_pid() as PID',
        function (error, result){

            if(error){
                console.log(error);
                return;
            }
             console.log("Node.js PID is " + process.pid);
             console.log("PostgreSQL client PID is " +
                     result.rows[0]["pid"]);
            }
        );

const hostname = '127.0.0.1';
const port = 1337;

http.createServer((req, res) => {

    res.writeHead(200, { 'Content-Type': 'text/plain' });

    client.query('INSERT INTO entries(entry) VALUES($1)',
            [req.headers['user-agent']],
            function (error, result){
                if(error){
                    res.end('Query failed\n');
                }
            });

    res.end('Accepted entry\n');

}).listen(port, hostname, () => {
    console.log('Server running at ' + hostname + ', port ' + port);
});
