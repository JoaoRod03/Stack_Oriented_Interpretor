/**
* @file tipos.h
* Contém o struct stack e inicializa as funções
*/

#ifndef TIPOS_H
#define TIPOS_H

// Configs
#define STACK_SIZE 1000 ///< Constante que define o tamanho da stack

/// Função para aceitar qualquer tipo de Data 

union uniao {
    long l ;
    double d ;
    char c ;
    char s[20] ; 
    int pos ;
    }  ;




// Tipos

/// Struct que define a stack
typedef struct stack {
    union uniao pilha [STACK_SIZE]; 
    int topo; 
} STACK;

// Iniciar funções
STACK* nova();
void push(STACK *s,int x);
int pop(STACK *s);
void handle(STACK *s,char *token);
int soma(STACK *s,char *token);
int menos(STACK *s,char *token);
int mul(STACK *s,char *token);
int divide(STACK *s,char *token);
int resto(STACK *s,char *token);
int expo(STACK *s,char *token);
int incrementa(STACK *s,char *token);
int decrementa(STACK *s,char *token);
int num(STACK *s,char *token);
// long binario(); Não implementado
int logica_and(STACK *s,char *token);
int logica_or(STACK *s,char *token);
int logica_xor(STACK *s,char *token);
int logica_not(STACK *s,char *token);
int duplicar(STACK *s,char *token);
int rodar (STACK *s,char *token);
int pop_elem (STACK *s,char *token);
int trocar (STACK *s,char *token);
int copia (STACK *s,char *token);

#endif // TIPOS_H