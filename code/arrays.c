// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"


//\/\/\/\/\/\/\/\/\/\/\/|---->  ARRAYS E STRINGS  <-----|/\/\/\/\/\/\/\/\/\/\/\/


int strings (STACK *s, char *token) {
    int size = strlen(token);
    if (token[0]=='"' && token[size-1]=='"') {
        tipos aux;
        char str[BUFSIZ];

        for (int i=1; i<size-1; i++) {str[i-1] = token[i];}
        aux.tipo=tStr;
        aux.val.s = (char*) malloc((size+1)*sizeof(char));
        strcpy(aux.val.s, str);

        push(s,aux);
        return 1;
    }
    return 0 ;
}

int range (STACK *s, char *token) {
    if (strcmp(token, ",") == 0) {
        tipos t1,aux;
        t1 = pop(s);

        // Devolve tamanho da string
        if (t1.tipo == tStr) {
            aux.tipo=tLong;
            aux.val.l=strlen(t1.val.s);
            push(s,aux);
        }

        if (t1.tipo == tLong) {
            tipos valor;
            aux.tipo = tArr;
            aux.val.arr=nova();
            int x = t1.val.l ;

            for (int i = 0 ; i < x; i++ ) {
                valor.tipo=tLong
                ;
                valor.val.l = i;
                push(aux.val.arr, valor);
            }

            push (s,aux);
        }

        if (t1.tipo == tArr) {
            tipos aux;
            aux.tipo=tLong;
            aux.val.l = t1.val.arr->topo;
            push(s,aux);
        }

        return 1;
    }
    return 0 ;
}

int input_all (STACK *s, char *token) {
    if (strcmp(token, "t") == 0) {
        char line [BUFSIZ] ; 
        tipos aux;
        aux.tipo=tStr;
        char auxx[BUFSIZ];

        int ola=0;
        while (fgets(line , BUFSIZ , stdin) != NULL && ola!=4) {
            while (sscanf(line,"%s %[^\n]",token,line) == 2) {
                    strcat(auxx,token);
            }
            strcat(auxx,token);
            ola++;
        }
        sscanf(line,"%s %[^\n]",token,line);
        strcat(auxx,token);

        aux.val.s=auxx;
        push(s,aux);

        return 1;
    }
    return 0 ;
}