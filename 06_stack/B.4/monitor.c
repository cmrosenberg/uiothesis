#include <stdio.h>
#include <string.h>

#define PUSH 0
#define POP 1
#define EMPTY 2

#define COMMAND_BUF_LEN 16

int main(void)
{
    int tf[3][3];
    char command[COMMAND_BUF_LEN];

    tf[0][PUSH] = 0;
    tf[0][POP] = 0;
    tf[0][EMPTY] = 0;

    tf[1][PUSH] = 1;
    tf[1][POP] = 2;
    tf[1][EMPTY] = 0;

    tf[2][PUSH] = 1;
    tf[2][POP] = 2;
    tf[2][EMPTY] = 2;


    int arg, retval, state = 2;

    retval = scanf("%s %d\n", command, &arg);

    while(retval != EOF){

        if(strncmp(command, "POP", COMMAND_BUF_LEN) == 0){
            state = tf[state][POP];
        }

        if(strncmp(command, "PUSH", COMMAND_BUF_LEN) == 0){
            state = tf[state][PUSH];
        }

        if((strncmp(command, "EMPTY", COMMAND_BUF_LEN) == 0) && arg == 1){
            state = tf[state][EMPTY];
        }

        retval = scanf("%s %d\n", command, &arg);
    }

    switch(state){
        case 0:
            printf("REJECTED\n");
            break;
        default:
            printf("INCONCLUSIVE\n");
            break;
    }

    return 0;
}
