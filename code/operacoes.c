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

/// Função que soma dois elementos da stack e coloca o resultado no topo desta.
int soma (STACK *s,char *token) {
    if(strcmp(token, "+") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s);
        t1 = pop(s);

        // Numero reais
        if (((t1.tipo==tLong || t1.tipo==tDouble ) && (t2.tipo==tDouble || t2.tipo==tLong))) {
            if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d + t2.val.d;}
            if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.l + t2.val.d;}
            if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d + t2.val.l;}
            if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l + t2.val.l;}
            push(s,aux);
        }

        // Strings
        if (t1.tipo==tStr && t2.tipo==tStr) {
            int total_size = strlen(t1.val.s) + strlen(t2.val.s);
            aux.tipo=tStr;
            aux.val.s = (char*) malloc ((total_size+1) * (sizeof(char)));
            strcpy (aux.val.s, t1.val.s);
            strcat (aux.val.s, t2.val.s);
            push(s,aux);
        }
        
        // Arrays (Concatenar)
        if (t1.tipo==tArr && t2.tipo==tArr) {
            int size2 = t2.val.arr->topo;

            for (int i=1; i<size2+1; i++) {
                push(t1.val.arr,t2.val.arr->pilha[i]);
            }
            push(s,t1);
        }

        // Arrays e inteiros (Adicionar)
        if (t1.tipo==tArr && t2.tipo==tLong) {
            push(t1.val.arr,t2);
            push(s,t1);
        }

        if (t1.tipo==tLong && t2.tipo==tArr) {
            int size = t2.val.arr->topo;
            t2.val.arr->topo++;

            for (int i=size+1; i>0; i--) {
                t2.val.arr->pilha[i+1] = t2.val.arr->pilha[i];
            }

            t2.val.arr->pilha[1]=t1;
            push(s,t2);
        }

        // Arrays e strings (Concatenar)
        /*
        if (t1.tipo==tStr && t2.tipo==tArr) {
            tipos aux;
            aux.tipo=tChar;
            int size1 = strlen(t1.val.s);
            int size = t2.val.arr->topo;
            
            for (int i=0; i<size1-2; i++) {t2.val.arr->topo++;} // obter espaço no arr

            for (int i=size+1; i>0; i--) {
                t2.val.arr->pilha[i+size1] = t2.val.arr->pilha[i];
            }

            for (int i=0; i<size1; i++) {
                aux.val.c = t1.val.s[i];
                t2.val.arr->pilha[i]=t1;
            }
            push(s,t2);
        }
        */

        if (t1.tipo==tArr && t2.tipo==tStr) {
            tipos aux;
            aux.tipo=tChar;
            int size2 = strlen(t2.val.s);

            for (int i=0; i<size2; i++) {
                aux.val.c = t2.val.s[i];
                push(t1.val.arr, aux);
            }
            push(s,t1);
        }

        if (t1.tipo==tStr && t2.tipo==tChar) {
            int size = strlen (t1.val.s);
            t1.val.s[size] = t2.val.c;
            push(s,t1);
        }

        return 1;
    }
    return 0 ;
}

/// Função que subtrai dois elementos da stack e coloca o resultado no topo desta.
int menos (STACK *s,char *token) {
    if(strcmp(token, "-") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s); t1 = pop(s);
        
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
        
        // Numero reais
        if (t1.tipo==tLong || t1.tipo==tDouble) {
            if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d * t2.val.d;}
            if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.l * t2.val.d;}
            if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d * t2.val.l;}
            if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l * t2.val.l;}
            push(s,aux);
        }

        // Operações com strings
        if (t1.tipo==tStr && t2.tipo==tLong) {
            int size = t2.val.l * strlen(t1.val.s);
            aux.tipo=tStr;
            aux.val.s = (char*) malloc ((size+1) * (sizeof(char)));
            strcpy (aux.val.s, t1.val.s);   
            for (int i=0; i<t2.val.l-1; i++) {
                strcat (aux.val.s, t1.val.s);
            }
            push(s,aux);
        }

        // Arrays (Concatenar)
        if (t1.tipo==tArr && t2.tipo==tLong) {
            int reps = t2.val.l;
            int size = t1.val.arr->topo;

            for (int i=1; i<reps; i++) {
                for (int w=1; w<size+1; w++) {
                    push(t1.val.arr, t1.val.arr->pilha[w]);
                }
            }

            push(s,t1);
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

        if (t1.tipo==tLong || t2.tipo==tLong || t1.tipo==tDouble || t2.tipo==tDouble) {
            if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d / t2.val.d;}
            if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = (double) t1.val.l / t2.val.d;}
            if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d / (double) t2.val.l;}
            if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l / t2.val.l;}
        }

        /*
        if (t1.tipo==tStr && t2.tipo==tStr) {
            int size1 = strlen(t1.val.s);
            int size2 = strlen(t2.val.s);
            for (int start=0; start<N; start++) {
        }
        */

        push(s,aux);
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


/// Incrementa o valor de um elemento da stack em 1 valor.
int incrementa (STACK *s,char *token) {
    if (strcmp(token, ")") == 0) {
        tipos t1,aux;
        t1 = pop(s);
        
        if (t1.tipo==tLong || t1.tipo==tDouble || t1.tipo==tChar) {
            if (t1.tipo==tLong) {aux.tipo=tLong; aux.val.l = t1.val.l+1;}
            if (t1.tipo==tDouble) {aux.tipo=tDouble; aux.val.d = t1.val.d+1;}
            if (t1.tipo==tChar) {aux.tipo=tChar; aux.val.c = (char) (((int) t1.val.c)+1);}
            push(s,aux);
        }

        // Remover ultimo elemento
        if (t1.tipo==tStr) {
            int size=strlen(t1.val.s);
            char alvo = t1.val.s[size];
            t1.val.s[size]='\0';
            tipos alvo_tipo;
            alvo_tipo.tipo=tChar;
            alvo_tipo.val.c=alvo;
            push(s,t1);
            push(s,alvo_tipo);
        }

        // Remover ultimo elemento
        if (t1.tipo==tArr) {
            int size = t1.val.arr->topo;
            tipos alvo = t1.val.arr->pilha[size];
            t1.val.arr->topo--;
            push(s,t1);
            push(s,alvo);
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
        
        if (t1.tipo==tLong || t1.tipo==tDouble || t1.tipo==tChar) {
            if (t1.tipo==tLong) {aux.tipo=tLong; aux.val.l = t1.val.l-1;}
            if (t1.tipo==tDouble) {aux.tipo=tDouble; aux.val.d = t1.val.d-1;}
            if (t1.tipo==tChar) {aux.tipo=tChar; aux.val.c = (char) (((int) t1.val.c)-1);}
            push(s,aux);
        }

        if (t1.tipo==tStr) {
            int size=strlen(t1.val.s);
            char alvo = t1.val.s[0];
            tipos alvo_tipo;

            alvo_tipo.tipo=tChar;
            alvo_tipo.val.c=alvo;

            int i;
            for (i=0; i<size-1; i++) {
                t1.val.s[i]=t1.val.s[i+1];
            }
            t1.val.s[i]='\0';

            push(s,t1);
            push(s,alvo_tipo);
        }


        if (t1.tipo==tArr) {
            int size = t1.val.arr->topo;
            tipos alvo = t1.val.arr->pilha[1];

            for (int i=0; i<size; i++) {
                t1.val.arr->pilha[i]=t1.val.arr->pilha[i+1];
            }

            t1.val.arr->topo--;
            push(s,t1);
            push(s,alvo);
        }

        return 1;
    }
    return 0 ;
}

