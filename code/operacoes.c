/**
* @file operacoes.c
* Ficheiro .c que contém as funções que tratam das operações utilizadas no projeto.
*/


// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"


//\/\/\/\/\/\/\/\/\/\/\/|---->  OPERAÇÕES  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Função que soma dois elementos da stack e coloca o resultado no topo desta. (Com overloading)
int soma (STACK *s,char *token) {
    if(strcmp(token, "+") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s); 
        t1 = pop(s);

        // Numero reais (Soma)
        if (((t1.tipo==tLong || t1.tipo==tDouble ) && (t2.tipo==tDouble || t2.tipo==tLong))) {
            if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d + t2.val.d;}
            if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.l + t2.val.d;}
            if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d + t2.val.l;}
            if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l + t2.val.l;}
            push(s,aux);
        }

        // Strins e arrays (Concatenar e inserir)
        if (t1.tipo==tStr || t2.tipo==tStr || t1.tipo==tArr || t2.tipo==tArr) {
            concatenar(s,t1,t2);
        }

        return 1;
    }
    return 0 ;
}

/// Função que subtrai dois elementos da stack e coloca o resultado no topo desta.
int menos (STACK *s,char *token) {
    if(strcmp(token, "-") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s); 
        t1 = pop(s);
        
        if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d - t2.val.d;}
        if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.l - t2.val.d;}
        if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d - t2.val.l;}
        if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l - t2.val.l;}

        push(s,aux);

        return 1;
    }
    return 0 ;
}

/// Função que multiplica dois elementos da stack e coloca o resultado no topo desta.
int mul (STACK *s,char *token) {
    if(strcmp(token, "*") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s);
        t1 = pop(s);
        
        // Numeros reais (Multiplicar)
        if (((t1.tipo==tLong || t1.tipo==tDouble ) && (t2.tipo==tDouble || t2.tipo==tLong))) {
            if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d * t2.val.d;}
            if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.l * t2.val.d;}
            if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d * t2.val.l;}
            if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l * t2.val.l;}
            push(s,aux);
        }

        // Arrays,Strings (Concatenar varias vezes)
        if (t1.tipo==tStr || t2.tipo==tStr || t1.tipo==tArr || t2.tipo==tArr) {
            concatenar_mul(s,t1,t2);
        }

        return 1;
    }
    return 0;
}

/// Função que divide dois elementos da stack e coloca o resultado no topo desta.
int divide (STACK *s,char *token) {
    if(strcmp(token, "/") == 0) { 
        tipos t1,t2,aux;

        t2 = pop(s);
        t1 = pop(s);

        // Numeros reais (dividir)
        if (((t1.tipo==tLong || t1.tipo==tDouble ) && (t2.tipo==tDouble || t2.tipo==tLong))) {
            if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d / t2.val.d;}
            if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = (double) t1.val.l / t2.val.d;}
            if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d / (double) t2.val.l;}
            if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l / t2.val.l;}
            push(s,aux);
        }

        // Strings (Procurar substring)
        if (t1.tipo==tStr && t2.tipo==tStr) {
            substring(s,t1,t2);
        }

        return 1;
    }
    return 0;
}

/// Função que calcula o resto da divisao de dois elementos da stack e coloca o resultado no topo desta.
int resto (STACK *s,char *token) {
    if(strcmp(token, "%") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s);
        t1 = pop(s);
        
        if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = (long) t1.val.d % (long) t2.val.d;}
        if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.l % (long) t2.val.d;}
        if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = (long) t1.val.d % t2.val.l;}
        if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l % t2.val.l;}

        push(s,aux);

        return 1;
    }
    return 0;
}


/// Calcula o resultado de elevar um elemento da stack a outro, coloca o resultado no topo da stack.
int expo (STACK *s,char *token) {
    if(strcmp(token, "#") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s);
        t1 = pop(s);
        
        if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = pow(t1.val.d, t2.val.d);}
        if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = pow(t1.val.l, t2.val.d);}
        if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = pow(t1.val.d, t2.val.l);}
        if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = pow (t1.val.l, t2.val.l);}

        push(s,aux);

        return 1;
    }
    return 0;
}


/// Incrementa o valor de um elemento da stack em 1 valor. (Com overloading)
int incrementa (STACK *s,char *token) {
    if (strcmp(token, ")") == 0) {
        tipos t1,aux;
        t1 = pop(s);
        
        // Long,double,char (Incrementar valor)
        if (t1.tipo==tLong || t1.tipo==tDouble || t1.tipo==tChar) {
            if (t1.tipo==tLong) {aux.tipo=tLong; aux.val.l = t1.val.l+1;}
            if (t1.tipo==tDouble) {aux.tipo=tDouble; aux.val.d = t1.val.d+1;}
            if (t1.tipo==tChar) {aux.tipo=tChar; aux.val.c = (char) (((int) t1.val.c)+1);}
            push(s,aux);
        }

        // Arrays,Strings (Remover ultimo elemento)
        if (t1.tipo==tArr || t1.tipo==tStr) {
            remover_last(s,t1);
        }

        return 1;
    }
    return 0 ;
}

/// Decrementa o valor de um elemento da stack em 1 valor.
int decrementa (STACK *s,char *token) {
    if(strcmp(token, "(") == 0) {
        tipos t1,aux;
        t1 = pop(s);
        
        // Long,double,char (Decrementa valor)
        if (t1.tipo==tLong || t1.tipo==tDouble || t1.tipo==tChar) {
            if (t1.tipo==tLong) {aux.tipo=tLong; aux.val.l = t1.val.l-1;}
            if (t1.tipo==tDouble) {aux.tipo=tDouble; aux.val.d = t1.val.d-1;}
            if (t1.tipo==tChar) {aux.tipo=tChar; aux.val.c = (char) (((int) t1.val.c)-1);}
            push(s,aux);
        }

        // Arrays,Strings (Remover primeiro elemento)
        if (t1.tipo==tArr || t1.tipo==tStr) {
            remover_first(s,t1);
        }

        return 1;
    }
    return 0 ;
}

