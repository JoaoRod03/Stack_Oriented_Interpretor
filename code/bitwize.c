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

        // Longs (Operação bitwize)
        if (t1.tipo==tLong) {
            t1.val.l = (~(t1.val.l));
            push(s,t1);
        }

        // Arrays (Coloca na stack os elementos do array)
        if (t1.tipo==tArr) {array_to_stack(s,t1);}

        // Blocos (Executar bloco)
        if (t1.tipo==tBlc) {executarBloco(s,t1);}

        return 1;
    }
    return 0;
}

