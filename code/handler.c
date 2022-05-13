/**
* @file handler.c
* Ficheiro .c que contém as funções principais utilizadas no projeto.
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"


/** Função responsavel por associar um token de um operador á sua função correspondente.
* É também responsável por inicializar as variaveis.
*/ 
STACK* nova() {
    STACK* s;
    s=((STACK*) malloc(sizeof(STACK)));

    // Variaveis
    s->var[0].tipo = s->var[1].tipo = s->var[2].tipo= s->var[3].tipo = s->var[4].tipo = s->var[5].tipo = tLong;
    s->var[23].tipo = s->var[24].tipo= s->var[25].tipo = tLong;
    s->var[13].tipo = s->var[18].tipo = tChar; 

    // Longs
    s->var[0].val.l=10;
    s->var[1].val.l=11;
    s->var[2].val.l=12;
    s->var[3].val.l=13;
    s->var[4].val.l=14;
    s->var[5].val.l=15;
    s->var[23].val.l=0;
    s->var[24].val.l=1;
    s->var[25].val.l=2;

    // Chars
    s->var[13].val.c='\n';
    s->var[18].val.c= ' ';
    return s;
}


/** Função responsavel por associar um token de um operador á sua função correspondente.
*   @param [in] Stack
*   @param [in] Token
*/ 
void handle (STACK* s, char* token, STACK* raiz) {
    if (
    soma (s,token)         || 
    menos (s,token)        || 
    mul (s,token)          ||
    divide (s,token)       || 
    resto (s,token)        || 
    expo (s,token)         ||
    incrementa (s,token)   || 
    decrementa (s,token)   ||
    bitwize_and(s,token)   || 
    bitwize_or(s,token)    || 
    bitwize_xor(s,token)   || 
    bitwize_not(s,token)   ||
    duplicar (s,token)     || 
    pop_elem (s,token)     ||
    trocar (s,token)       ||
    rodar (s,token)        ||
    copia (s, token)       ||
    conv_int (s, token)    ||
    conv_double (s, token) ||
    conv_char (s, token)   ||
    ler (s, token)         ||
    debugger (s, token)    ||
    mai (s, token)         ||
    men (s, token)         ||
    interroga (s, token)   ||
    igual (s, token)       ||
    nao (s, token)         ||
    maior (s, token)       ||
    menor (s, token)       ||
    conjuncao (s, token)   ||
    disjuncao (s, token)   ||
    input_all (s, token)   || // Acima das vars
    vars (raiz, token)        ||
    vars2p (s, token, raiz)||
    range (s, token) ||
    div_whitespace (s, token) ||
    num (s,token)) {return;} // Deixar no fim
}


STACK* criarArray (STACK *s) {
    s->topo++;
    s->pilha[s->topo].tipo = tArr;
    s->pilha[s->topo].val.arr = nova();
    return s->pilha[s->topo].val.arr;
}
STACK* criarBloco (STACK *s) {
    s->topo++;
    s->pilha[s->topo].tipo = tBlo;
    s->pilha[s->topo].val.blo = nova();
    return s->pilha[s->topo].val.blo;
}

void printStack (STACK *s) {
    for (int i=1; i<=(s->topo); i++) { 
        if (s->pilha[i].tipo == tLong) {printf("%ld",s->pilha[i].val.l);} 
        if (s->pilha[i].tipo == tDouble) {printf("%g",s->pilha[i].val.d);} 
        if (s->pilha[i].tipo == tChar) {printf("%c",s->pilha[i].val.c);} 
        if (s->pilha[i].tipo == tStr) {printf("%s",s->pilha[i].val.s);} 
        if (s->pilha[i].tipo == tArr) {printStack(s->pilha[i].val.arr);}
    }
}


/// Função que trata dos tokens não reconhecidos e constantes, verifica o tipo do token e atribui uma operação.
int num (STACK *s,char *token) {
    tipos aux;
    long l1;
    double d1;

    char* ptr;
    strtol(token,&ptr,10);

    if (*ptr=='\0') {   // Long
        sscanf(token, "%ld", &l1);
        aux.tipo = tLong;
        aux.val.l = l1;
        push(s,aux);      
    } else if (ptr[0]=='.') {  // Double
        sscanf(token, "%lf", &d1);
        aux.tipo = tDouble;
        aux.val.d = d1;
        push(s,aux);
    } else {
        printf("Erro token desconhecido!\nToken:%s\nOutput:",token);
    }

    return 1 ;
}


/// Devolve o tipo do topo da stack
int topo_tipo (STACK *s) {
    int r;
    r = s->pilha[s->topo].tipo; 
    return r;
}

