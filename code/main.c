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
 

/// Função principal main responsavél por receber o input do utilizador e chamar o handler
int main() {
    STACK *s = nova();
    char line[BUFSIZ];
    char token[BUFSIZ];
    
    int arr_pos=0;

    // Input 
    if (fgets(line,BUFSIZ,stdin)!= NULL) {
        while (sscanf(line,"%s %[^\n]",token,line) == 2) {
            if (strcmp(token,"[") == 0) {arr_pos++;} 
            if (strcmp(token,"]") == 0) {arr_pos--;}

            if (token[0]!='[' && token[0]!=']') {
                if (arr_pos>0) {handle_arr(s,token);} 
                if (arr_pos==0) {handle(s, token);}
            }
        }
        if (token[0]!='[' && token[0]!=']') {handle(s,token);}

        printStack(s);
        printf("\n");
    }
    return 0 ;
} 

