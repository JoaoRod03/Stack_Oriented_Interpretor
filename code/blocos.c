// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"

//\/\/\/\/\/\/\/\/\/\/\/|---->  BLOCOS  <-----|/\/\/\/\/\/\/\/\/\/\/\/

void executarBloco (STACK* stack, tipos t1) {
    char line[BUFSIZ];
    strcpy(line,t1.val.s);
    char token[10000];
    STACK* arr_alvo = stack;
    int arr_num=0;
    while (sscanf(line,"%s %[^\n]",token,line) == 2) {
            if (aspas(token)>0) {handle_string(arr_alvo,token,line);} else {
                if (strcmp(token,"{") == 0) {associaBloco(stack,line);} else {
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
    }
    if (line[0]) {
        if (aspas(token)>0) {handle_string(arr_alvo,token,line);} else {
            if (strcmp(token,"{") == 0) {associaBloco(stack,line);} else {
                if (strcmp(token,"[") != 0 && strcmp(token,"]") != 0) {
                    handle(arr_alvo,token,stack);
                }
            }
        }
    }
}   

// Aplica um bloco a um array ou string
void blocoAplicar (STACK* s, tipos t1, tipos t2) {
    if (t1.tipo==tArr) {
        tipos temp[BUFSIZ];
        int size = t1.val.arr->topo;

        for (int i=0; i<size; i++) {
            temp[i]=pop(t1.val.arr);
        }
        pop(t1.val.arr); // Pop do 0

        for (int i=size; i>=0; i--) {
            push(t1.val.arr, temp[i]);
            executarBloco(t1.val.arr, t2);
        }
        printStack(t1.val.arr);
    }
    push(s,t1.val.arr);
}   