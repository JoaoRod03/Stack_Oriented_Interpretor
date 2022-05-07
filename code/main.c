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
    STACK *stack = nova();
    char line[BUFSIZ];
    char token[BUFSIZ];
    
    STACK* arr_alvo = stack;
    int arr_num=0;
    
    // Input 
    if (fgets(line,BUFSIZ,stdin)!= NULL) {
        while (sscanf(line,"%s %[^\n]",token,line) == 2) {

            // Verificar token de array
            if (strcmp(token,"[") == 0) {arr_alvo = criarArray(arr_alvo); arr_num++;} 
            if (strcmp(token,"]") == 0) {arr_num--;} 

            // Aceder ao array
            arr_alvo = stack;
            for (int i=0; i<arr_num; i++) {
                arr_alvo = arr_alvo->pilha[arr_alvo->topo].val.arr;
            }

            // Handle
            if (strcmp(token,"[") != 0 && strcmp(token,"]") != 0) {
                handle(arr_alvo,token);
            }
        }
        
        if (strcmp(token,"[") != 0 && strcmp(token,"]") != 0) {handle(arr_alvo,token);}

        printStack(stack);
        printf("\n");
    }
    return 0 ;
} 




