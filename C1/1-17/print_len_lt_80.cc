#include <stdio.h>
#include "../../util/util.h"

#define MAXLINE 1000

int main(){
    char s[MAXLINE];
    int len;
    while((len = getline(s, MAXLINE)) != 0){
        if(len <= 80){
            continue;
        }
        printf("%d: ", len);
        printline(s, MAXLINE);
        putchar('\n');
    }
}