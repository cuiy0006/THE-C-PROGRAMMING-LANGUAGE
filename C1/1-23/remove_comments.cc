#include <stdio.h>

int main(){
    char c = '\0';
    char last = '\0';
    bool single_comment = false;
    bool multi_comment = false;
    bool multi_comment_newline = false;
    bool double_quote = false;
    bool single_quote = false;
    while((c = getchar()) != EOF){
        if(single_comment){
            if(c == '\n'){
                putchar('\n');
                single_comment = false;
            }
            last = c;
            continue;
        }

        if(multi_comment){
            if(last == '*' && c == '/'){
                multi_comment = false;
            } else if(c == '\n' && multi_comment_newline){
                 putchar('\n');
                 multi_comment_newline = false;
            }
            
            last = c;
            continue;
        }

        if(c == '"'){
            if(!single_quote && !(double_quote && last == '\\')){
                double_quote = !double_quote;
            }
            putchar('"');
        } else if(c == '\''){
            if(!double_quote && !(single_quote && last == '\\')){
                single_quote = !single_quote;
            }
            putchar('\'');
        } else if(single_quote || double_quote){
            putchar(c);
        } else if(c == '/' && last == '/'){
            single_comment = true;
        } else if(c == '*' && last == '/'){
            multi_comment = true;
            multi_comment_newline = true;
        } else if(c != '/'){
            putchar(c);
        }
        last = c;
    }
}

/* 123 */