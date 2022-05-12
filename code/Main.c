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
#include "Tipos.h"
 
/// Função principal main responsavél por receber o input do utilizador e chamar o handler
int main() {
    STACK *stack = nova();
    char line[BUFSIZ];
    char token[BUFSIZ];
    
    // Variaveis auxiliares das funções (Indicam o estado do input)
    STACK* arr_alvo = stack;
    int arr_num=0;

    // Input 
    if (fgets(line,BUFSIZ,stdin)!= NULL) {
        while (sscanf(line,"%s %[^\n]",token,line) == 2) {
                if (aspas(token)>0) {handle_string(arr_alvo,token,line);} else {
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
                        handle(arr_alvo,token,stack);
                    }
                }
        }

        if (line[0]) {
            if (aspas(token)>0) {handle_string(arr_alvo,token,line);} else {
                if (strcmp(token,"[") != 0 && strcmp(token,"]") != 0) {
                    handle(arr_alvo,token,stack);
                }
            }
        }
        
        printStack(stack);
        printf("\n");
    }
    return 0 ;
} 




