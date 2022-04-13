// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Configs
#define MAXIMO 1000

// Tipos
typedef struct {
    int stack [MAXIMO];
    int pointer;
}STACK;


// Iniciar funções
STACK* nova ();
void push();
int pop();
void handle();
int soma();
int menos();
int mul();
int divide();
int resto();
int expo();
int incrementa();
int decrementa();
int num();


////////////////////////////////////////////////////////////////////////////////

int main() {
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

///////////////////////////////////////////////////////////////////////////////


STACK* nova() {
    return ((STACK *) malloc(sizeof(STACK)));
}

// Insere elemento no topo da stack
void push(STACK *s,int x) {
    s->pointer++ ;
    s->stack[s->pointer] = x;
}

// Retira elemento do topo da stack
int pop(STACK *s) {
    int v = s->stack[s->pointer];
    s->pointer--;
    return v ;
}

// ADICIONAR DESCRIÇÃO
void handle (STACK *s,char *token){
    soma (s,token) ||menos (s,token) ||mul (s,token) ||
    incrementa (s,token) ||decrementa (s,token) ||
    divide (s,token) ||resto (s,token)||expo (s,token)||num (s,token) ;
}

// Verifica se não há nenhum operador no input, coloca os numeros na stack
int num (STACK *s,char *token) {
    int val;
    sscanf(token, "%d", &val);
    push(s, val);
    return 1 ;
}

// Soma dois elementos da stack e coloca o resultado nesta
int soma (STACK *s,char *token) {
    if(strcmp(token, "+") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A + B);
        return 1;
    }
    return 0 ;
}

// Subtrai dois elementos da stack e coloca o resultado nesta
int menos (STACK *s,char *token) {
    if(strcmp(token, "-") == 0) {
        int B = pop(s);
        int A = pop(s);
        push(s, A - B);
        return 1;
    }
    return 0 ;
}

// Multiplica dois elementos da stack e coloca o resultado nesta
int mul (STACK *s,char *token) {
    if(strcmp(token, "*") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A * B);
        return 1;
    }
    return 0;
}

// Divide dois elementos da stack e coloca o resultado nesta
int divide (STACK *s,char *token) {
    if(strcmp(token, "/") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A / B);
        return 1;
    }
    return 0;
}

// Calcula o resto da divisão de dois elementos da stack e coloca o resultado nesta
int resto (STACK *s,char *token) {
    if(strcmp(token, "%") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B % A);
        return 1;
    }
    return 0;
}

// Calcula o resultado de elevar um elemento da stack a outro, coloca o resultado na stack
int expo (STACK *s,char *token) {
    if(strcmp(token, "#") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, pow(A,B));
        return 1;
    }
    return 0;
}

// Incrementa um elemento da stack em 1 valor
int incrementa (STACK *s,char *token) {
    if(strcmp(token, ")") == 0) {
        int A = pop(s);
        push(s, A + 1);
        return 1;
    }
    return 0 ;
}

// Decrementa um elemento da stack em 1 valor
int decrementa (STACK *s,char *token) {
    if(strcmp(token, "(") == 0) {
        int A = pop(s);
        push(s, A - 1);
        return 1;
    }
    return 0 ;
}

