// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"

//\/\/\/\/\/\/\/\/\/\/\/|---->  OPERAÇÕES BITWISE  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Realiza a operação (and / &) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int bitwize_and (STACK *s,char *token) {
    if(strcmp(token, "&") == 0) {
        tipos A = pop(s);
        tipos B = pop(s);
        A.val.l = A.val.l & B.val.l;
        push(s,A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (or / |) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int bitwize_or (STACK *s,char *token) {
    if(strcmp(token, "|") == 0) {
        tipos A = pop(s);
        tipos B = pop(s);
        A.val.l = A.val.l | B.val.l;
        push(s,A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (xor / ^) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int bitwize_xor (STACK *s,char *token) {
    if(strcmp(token, "^") == 0) {
        tipos A = pop(s);
        tipos B = pop(s);
        A.val.l = B.val.l ^ A.val.l;
        push(s,A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (not / ~) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int bitwize_not (STACK *s,char *token) {
    if(strcmp(token, "~") == 0) {
        tipos t1 = pop(s);

        if (t1.tipo==tLong) {
            t1.val.l = (~(t1.val.l));
            push(s,t1);
        }

        // Coloca na stack os elementos do array
        if (t1.tipo==tArr) {
            tipos aux;
            int size = t1.val.arr->topo;
            for (int i=1; i<size+1; i++) {
                STACK* ajuda = t1.val.arr;
                aux.tipo = ajuda->pilha[i].tipo;
                if (aux.tipo==tLong) {aux.val.l = ajuda->pilha[i].val.l;}
                if (aux.tipo==tDouble) {aux.val.d = ajuda->pilha[i].val.d;}
                if (aux.tipo==tChar) {aux.val.c = ajuda->pilha[i].val.c;}
                if (aux.tipo==tStr) {aux.val.s = ajuda->pilha[i].val.s;}
                if (aux.tipo==tArr) {aux.val.arr = ajuda->pilha[i].val.arr;}
                push(s,aux);
            }
        }

        return 1;
    }
    return 0;
}
