#ifndef TIPOS_H
#define TIPOS_H

// Configs
#define STACK_SIZE 1000

// Tipos
typedef struct stack {
    int pilha [STACK_SIZE];
    int topo;
} STACK;

// Iniciar funções
STACK* nova();
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
long binario();
int logica_and();
int logica_or();
int logica_xor();
int logica_not();

#endif