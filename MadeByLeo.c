#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//---------------------------------declaration type stack ;
#define MAXIMO 1000
typedef struct {
    int stack [MAXIMO];
    int pointer;
}STACK;
STACK * nova ();
//---------------------------------end of declaration :

STACK * nova (){
    return ((STACK *) malloc(sizeof(STACK)));
}

void push(STACK *s,int x){
    s->pointer++ ;
    s->stack[s->pointer] = x;
}

int pop(STACK *s){
    int v = s->stack[s->pointer];
    s->pointer--;
    return v ;
}
int soma (STACK *s,char *token) {
    if(strcmp(token, "+") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A + B);
        return 1;
    }
    return 0 ;
}
int menos (STACK *s,char *token) {
    if(strcmp(token, "-") == 0) {
        int B = pop(s);
        int A = pop(s);
        push(s, A - B);
        return 1;
    }
    return 0 ;
}
int mul (STACK *s,char *token) {
    if(strcmp(token, "*") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A * B);
        return 1;
    }
    return 0;
}
int divide (STACK *s,char *token) {
    if(strcmp(token, "/") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A / B);
        return 1;
    }
    return 0;
}
int resto (STACK *s,char *token) {
    if(strcmp(token, "%") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B % A);
        return 1;
    }
    return 0;
}
int expo (STACK *s,char *token) {
    if(strcmp(token, "#") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, pow(A,B));
        return 1;
    }
    return 0;
}
int incrementa (STACK *s,char *token) {
    if(strcmp(token, ")") == 0) {
        int A = pop(s);
        push(s, A + 1);
        return 1;
    }
    return 0 ;
}
int decrementa (STACK *s,char *token) {
    if(strcmp(token, "(") == 0) {
        int A = pop(s);
        push(s, A - 1);
        return 1;
    }
    return 0 ;
}

int num (STACK *s,char *token) {
    int val;
    sscanf(token, "%d", &val);
    push(s, val);
    return 1 ;

}
void handle (STACK *s,char *token){
    soma (s,token) ||menos (s,token) ||mul (s,token) ||
    incrementa (s,token) ||decrementa (s,token) ||
    divide (s,token) ||resto (s,token)||expo (s,token)||num (s,token) ;
}
//--------------------------------Main function that starts the stack
int main (){
    STACK *s = nova();
    char line[BUFSIZ];
    char token[BUFSIZ];

    if (fgets(line,BUFSIZ,stdin)!= NULL) {
        while (sscanf(line,"%s %[^\n]",token,line) == 2) {
            handle(s ,token);
        }
        handle(s,token);

        for (int i =1; i <= (s->pointer );i++){
            printf("%d",s->stack[i]);
        }
        printf("\n");
    }
    return 0 ;
}
