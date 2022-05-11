// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"

//\/\/\/\/\/\/\/\/\/\/\/|---->  STRINGS <-----|/\/\/\/\/\/\/\/\/\/\/\/

void handle_string (STACK* s, char* token, char* linha) {
    if (aspas(token)==2) {string_2a(s,token);}
    if (aspas(token)==1) {string_1a(s,token,linha);}
}

// Dá push 
void string_1a (STACK* s, char* token, char* linha) {
    limpa(token,1);
    char strFinal [BUFSIZ];         // String final
    strcpy(strFinal,token);         // Copiar o token para a string
    int sizeToken = strlen(token);  // Tamanho do token
    strFinal[sizeToken]=' ';        // Espaço no fim do token

    // Copiar desde token até -> " para strAux
    int i=0;
    while (linha[i]!='"' && linha[i]!='\0') {
        strFinal[i+sizeToken+1]=linha[i];
        i++;
    }
    limpa(linha,i+1); 

    // Pushar a string
    int tamanho = strlen(strFinal);
    tipos devolve; devolve.tipo = tStr;
    devolve.val.s=(char*) malloc((tamanho+1)*sizeof(char));
    strcpy(devolve.val.s, strFinal);
    push(s,devolve);
}

/// Dá push de uma string do tipo ("token")
void string_2a (STACK *s, char *token) {
    int size = strlen(token);
    char str[BUFSIZ];  
    tipos aux; aux.tipo=tStr;
    aux.val.s = (char*) malloc((size+1)*sizeof(char));

    for (int i=1; i<size-1; i++) {str[i-1] = token[i];}
    strcpy(aux.val.s, str);

    push(s,aux);
}

void limpa (char* linha ,int indice) {
    int i,s = strlen(linha);
    for (i = 0; i <s-indice; i++) {
        *(linha+i)=*(linha+i+indice);
    }
    if (*(linha-1+i)=='"') {*(linha-1+i)='\0';}
    if (*(linha-1+i)!='"') {*(linha+i)='\0';}
}


// Fornece o numero de aspas
int aspas (char* token) {
    int size=strlen(token);
    int aspas=0;
    for (int i=0; i<size; i++) {
        if (token[i]=='"') {aspas++;}
    }
    return aspas;
}

// Remove os x primeiros elementos
