#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_BUFF_LEN 100

int buffer[STACK_BUFF_LEN];

void push(int number, unsigned int * i)
{
    buffer[*i] = number;
    *i += 1;
}

int pop(unsigned int * i)
{
    int result = buffer[*i];
    *i -= 1;
    return result;
}

int empty(unsigned int * i)
{
    return *i == 0;
}

int full(unsigned int * i)
{
    return *i == 100;
}

int main(int argc, char *argv[])
{
    unsigned int i, index, iterations, pushes, pops, result;

    if(argc < 2){
        iterations = 100;
    } else {
        iterations = atoi(argv[1]);
    }

    index = 0;
    pushes = 0;
    pops = 0;
    result = 0;

    for(i = 0; i < iterations; i++){
        if(i % 2 == 0){
            push(1, &index);
            pushes++;
        }
        else{
            result += (pop(&index) * i % 7);
            pops++;
        }
    }

    printf("pushes: %u, pops: %u, result: %d\n", pushes, pops, result);
    return 0;
}
