/*! \mainpage Pagina Inicial
 *
 * \section intro_sec Projeto LI2 (stack)
 *
 * \subsection 1 Ficheiros:
 *
 * \include <main.c>
 * \include <funcoes.c>
 * \include <tipos.h>
 */

/**
* @file main.c
* Contém a função main e importa os restantes modulos.
*/


// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tipos.h"

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

        for (int i=1; i<=(s->topo); i++){
            if (s->pilha[i].tipo == tLong) {printf("%ld",s->pilha[i].val.l);} 
            if (s->pilha[i].tipo == tDouble) {printf("%g",s->pilha[i].val.d);} 
            if (s->pilha[i].tipo == tChar) {printf("%c",s->pilha[i].val.c);} 
            if (s->pilha[i].tipo == tStr) {printf("%s",s->pilha[i].val.s);} 
            }
        printf("\n");
    }
    return 0 ;
}


