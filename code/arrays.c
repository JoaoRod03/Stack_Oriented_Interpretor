// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"


//\/\/\/\/\/\/\/\/\/\/\/|---->  ARRAYS E STRINGS  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Cria uma string quando o token possui " no inicio e no fim.
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

        // Strings (devolve tamanho da string)
        if (t1.tipo == tStr) {
            aux.tipo=tLong;
            aux.val.l=strlen(t1.val.s);
            push(s,aux);
        }

        // Longs (Cria um array com elementos de 0 até X)
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

        // Arrays (Devolve tamanho do array)
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

/////////////////////////////////////////////////////////

void concatenar (STACK* s, tipos t1, tipos t2) {
    tipos aux;

    // Strings (Concatenar)  -------------------
    if (t1.tipo==tStr && t2.tipo==tStr) {
        int total_size = strlen(t1.val.s) + strlen(t2.val.s);
        aux.tipo=tStr;
        aux.val.s = (char*) malloc ((total_size+1) * (sizeof(char)));
        strcpy (aux.val.s, t1.val.s);
        strcat (aux.val.s, t2.val.s);
        push(s,aux);
    }
    
    // Arrays (Concatenar)  -------------------
    if (t1.tipo==tArr && t2.tipo==tArr) {
        int size2 = t2.val.arr->topo;
        for (int i=1; i<size2+1; i++) {
            push(t1.val.arr,t2.val.arr->pilha[i]);
        }
        push(s,t1);
    }

    // Arrays e inteiros (Inserir) -------------------
    // Inteiro no fim
    if (t1.tipo==tArr && t2.tipo==tLong) {
        push(t1.val.arr,t2);
        push(s,t1);
    }
    
    // Inteiro no inicio
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

    // Arrays e strings (Concatenar)
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

    // Strings e char (Inserir)
    if (t1.tipo==tStr && t2.tipo==tChar) {
        int size = strlen (t1.val.s);
        t1.val.s[size] = t2.val.c;
        push(s,t1);
    }
}

void concatenar_mul (STACK* s, tipos t1, tipos t2) { 
    tipos aux;

    // Strings (Concatenar varias vezes)
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

    // Arrays (Concatenar varias vezes)
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
}

void remover_last (STACK* s, tipos t1) { 
    // Strings (Remover ultimo elemento)
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

    // Arrays (Remover ultimo elemento)
    if (t1.tipo==tArr) {
        int size = t1.val.arr->topo;
        tipos alvo = t1.val.arr->pilha[size];
        t1.val.arr->topo--;
        push(s,t1);
        push(s,alvo);
    }
}

void remover_first (STACK* s, tipos t1) { 
        // Strings (Remove primeiro carater)
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

        // Arrays (Remove primeiro elemento)
        if (t1.tipo==tArr) {
            int size = t1.val.arr->topo;
            tipos alvo = t1.val.arr->pilha[1];

            for (int i=0; i<size; i++) {
                t1.val.arr->pilha[i] = t1.val.arr->pilha[i+1];
            }

            t1.val.arr->topo--;
            push(s,t1);
            push(s,alvo);
        }
}

void buscar_indice (STACK* s, tipos t1, tipos t2) { 
    tipos aux;

    // Buscar char á string por indice
    if (t1.tipo == tStr && t2.tipo == tLong) {
        aux.tipo = tChar ; 
        aux.val.c = t1.val.s[t2.val.l] ;
        push(s,aux);
    }

    // Buscar valor ao array por indice
    if (t1.tipo == tArr && t2.tipo == tLong) {
        push(s,t1.val.arr->pilha[t2.val.l+1]);
    }

    // Comprara strings
    if (t1.tipo == tStr && t2.tipo == tStr) {
        aux.tipo=tLong;
        if (strcmp(t1.val.s,t2.val.s)==0) {aux.val.l=1;} else {aux.val.l=0;}
        push(s,aux);
    }
}

void buscar_inicio (STACK* s, tipos t1, tipos t2) { 
    tipos aux;

    // Buscar x carateres ao inicio
    if (t1.tipo == tStr && t2.tipo == tStr) {
           aux.tipo=tLong;
           int size=strlen(t2.val.s);
           int teste=0;
           for (int i=0; i<size; i++) {
               if (t2.val.s[i]==t1.val.s[i]) {teste++;}
           }   
           if (size==teste) {aux.val.l=1;} else {aux.val.l=0;}
           push(s,aux);
    }
}

void buscar_fim (STACK* s, tipos t1, tipos t2) { 
    tipos aux;

    // Buscar x carateres ao fim
    if (t1.tipo == tStr && t2.tipo == tStr) {
        aux.tipo=tLong;
        int size=strlen(t2.val.s);
        int teste=0;

        for (int i=size; i>0; i--) {
            if (t2.val.s[size]==t1.val.s[i]) {teste++;}
        }   

        if (teste>0) {aux.val.l=1;} else {aux.val.l=0;}
        push(s,aux);
    }
}

void array_to_stack (STACK* s, tipos t1) { 
    tipos aux;

    // Arrays (Push de todos os elementos para a stack)
    if (t1.tipo==tArr) {
        int size = t1.val.arr->topo;
        for (int i=1; i<size+1; i++) {
            STACK* ajuda = t1.val.arr;
            aux.tipo = ajuda->pilha[i].tipo;
            if (aux.tipo==tLong) {aux.val.l = ajuda->pilha[i].val.l;}
            if (aux.tipo==tDouble) {aux.val.d = ajuda->pilha[i].val.d;}
            if (aux.tipo==tChar) {aux.val.c = ajuda->pilha[i].val.c;}
            if (aux.tipo==tStr) {aux.val.s = ajuda->pilha[i].val.s;}
            if (aux.tipo==tArr) {aux.val.arr = ajuda->pilha[i].val.arr;}
            push(s,aux);
        }
    }
}

void substring (STACK* s, tipos t1, tipos t2) {
    if (t1.tipo==tStr && t2.tipo==tStr) {
        tipos aux;
        aux.tipo=tArr;
        int arr_pos=1;
        int size1 = strlen(t1.val.s);
        int size2 = strlen(t2.val.s);


        for (int i=0; i<size1; i++) {

            for (int w=i; w<size2; w++) {
                int teste=-1;
                if (t1.val.s[w]==t2.val.s[w]) {teste++;}
            }

            if (teste==size2) {
                printf(".T.");
                t1.val.arr->pilha[arr_pos].tipo = tStr;  
                t1.val.arr->pilha[arr_pos].val.s = ;  
            }
        }
    } 
}