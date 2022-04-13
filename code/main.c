// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tipos.h"
#include "funcoes.c"

int main() {
    STACK *s = nova();
    char line[BUFSIZ];
    char token[BUFSIZ];

    // Input
    if (fgets(line,BUFSIZ,stdin)!= NULL) {
        while (sscanf(line,"%s %[^\n]",token,line) == 2) {
            handle(s ,token);
        }
        handle(s,token);

        for (int i =1; i <= (s->topo);i++){
            printf("%d",s->pilha[i]);
        }
        printf("\n");
    }
    return 0 ;
}


