#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "config.h"

#define MAXOP 100

int getop(char []);
void push(double);
double pop(void);
void print_top(void);
void duplicate_top(void);
void swap_top_two(void);

main(){
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF){
        switch (type)
        {
        case '\n':
            printf("\t%.8g\n", pop());
            break;

        case NUMBER:
            push(atof(s));
            break;

        case COMMAND:
            if(strcmp(s, "+") == 0)
                push(pop() + pop());
            else if(strcmp(s, "*") == 0)
                push(pop() * pop());
            else if(strcmp(s, "-") == 0){
                op2 = pop();
                push(pop() - op2);
            } else if(strcmp(s, "/") == 0){
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
            } else if((strcmp(s, "sin") == 0)){
                push(sin(pop()));
            } else if((strcmp(s, "exp") == 0)){
                push(exp(pop()));
            } else if((strcmp(s, "pow") == 0)){
                op2 = pop();
                push(pow(pop(), op2));
            }
            else
                printf("error: unknown command %s\n", s);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}