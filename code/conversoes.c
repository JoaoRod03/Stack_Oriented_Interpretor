// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"

//\/\/\/\/\/\/\/\/\/\/\/|---->  CONVERSÕES  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Converte o topo da stack para int.
int conv_int (STACK *s,char *token) {
    if (strcmp(token, "i") == 0) {
        tipos t1,aux;
        aux.tipo=tLong;

        t1 = pop(s);
        
        if (t1.tipo==tLong) {push(s,t1);}
        if (t1.tipo==tDouble) {aux.val.l = (int) t1.val.d; push(s,aux);}
        if (t1.tipo==tChar) {aux.val.l = (int) t1.val.c; push(s,aux);}

        return 1;
    }
    return 0;
}

/// Converte o topo da stack para double.
int conv_double (STACK *s,char *token) {
    if (strcmp(token, "f") == 0) {
        tipos t1,aux;
        aux.tipo=tDouble;

        t1 = pop(s);

        if (t1.tipo==tDouble) {push(s,t1);}
        if (t1.tipo==tLong) {aux.val.d = (double) t1.val.l; push(s,aux);}
        if (t1.tipo==tChar) {aux.val.d = (double) ((int) t1.val.l); push(s,aux);}

        return 1;
    }
    return 0;
}

/// Converte o topo da stack para char.
int conv_char (STACK *s,char *token) {
    if (strcmp(token, "c") == 0) {
        tipos t1,aux;
        aux.tipo=tChar;

        t1 = pop(s);

        if (t1.tipo==tChar) {push(s,t1);}
        if (t1.tipo==tLong) {aux.val.c = (char) t1.val.l; push(s,aux);}
        if (t1.tipo==tDouble) {aux.val.c = (char) ((int) t1.val.d); push(s,aux);}

        return 1;
    }
    return 0;
}

