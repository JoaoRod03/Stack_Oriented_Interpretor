/**
* @file funcoes.c
* Ficheiro .c que contém as funções utilizadas no projeto.
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"

// |\/\/\/\/\/\/\/\/\/\/\/|---->  PUSH e POP  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Função que insere um elemento no topo da stack. 
void push (STACK *s, tipos x) {
    s->topo++;                 // Aumenta o apontador para o topo da stack
    s->pilha[s->topo] = x;     // Push para o campo long
}


/// Função que retira o elemento que se encontra no topo da stack.
tipos pop (STACK *s) {
        tipos v = s->pilha[s->topo];  // Obtem o elemento no topo da stack
        //if (s->pilha[s->topo].tipo == tStr) {free(s->pilha[s->topo].val.s);} // Limpa o espaço ocupado pela string
        s->topo--;  
        return v ; 
}

//\/\/\/\/\/\/\/\/\/\/\/|---->  OPERAÇÕES  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Duplica o elemento que se encontra no topo da stack. 
int duplicar (STACK *s,char *token) {
    if(strcmp(token, "_") == 0) {  
        tipos t1 = pop(s);
        push(s,t1);
        push(s,t1);

        return 1;
    }
    return 0;
}

/// Roda os 3 elementos no topo da stack (123 -> 231).
int rodar (STACK *s,char *token) {
    if(strcmp(token, "@") == 0) {
        tipos t3 = pop(s);
        tipos t2 = pop(s);
        tipos t1 = pop(s);

        push (s,t2);
        push (s,t3);
        push (s,t1);

        return 1;
    }
    return 0;
}

/// Retira o elemento que se encontra no topo da stack.
int pop_elem (STACK *s,char *token) {
    if(strcmp(token, ";") == 0) {
        pop(s);
        return 1;
    }
    return 0;
}

/// Troca os dois elementos do topo da stack
int trocar (STACK *s,char *token) {
    if(strcmp(token, "\\") == 0) {
        tipos t2 = pop(s);
        tipos t1 = pop(s);
        
        push(s,t2);
        push(s,t1);

        return 1;
    }
    return 0;
}

///  Copia n-ésimo elemento para o topo da stack. (n $)
int copia (STACK *s,char *token) {
    if(strcmp(token, "$") == 0) {
        int w;
        tipos ultimo;
        tipos* arr = malloc(BUFSIZ*sizeof(tipos));
        tipos num=pop(s);

        if (num.val.l>=0) {
            for (w=0; w<=(num.val.l-1); w++) { // copia tudo na stack até num para um array
                arr[w]=pop(s);
            }

            ultimo=pop(s);
            push (s,ultimo); 

            for (w = (num.val.l)-1; w>= 0; w--) { // passa tudo do array para a stack
                push (s, arr[w]);
            }

            push(s,ultimo);
        }
        
        free (arr);
        return 1;
    }
    return 0;
}

//\/\/\/\/\/\/\/\/\/\/\/|---->  OUTROS  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Função que lê input e insere o resultado desse input na stack.
int ler (STACK *s, char *token) {
    char line [BUFSIZ] ; 
    if (strcmp(token, "l") == 0) {
        if (fgets(line , BUFSIZ , stdin)) {
        while (sscanf(line,"%s %[^\n]",token,line) == 2) {
                handle(s ,token);
                }
        handle(s,token);
        }

        return 1;
    }
    return 0;
}


/// Função responsavel pelo debug do programa. Escrever DEBUG e depois inserir o input para realizar o debug.
int debugger (STACK *s, char *token) {
    char line [BUFSIZ] ; 
    char avancar[4]="next",ver[4]="next";
    int exec=0;
    if (strcmp(token, "DEBUG") == 0) {
        if (fgets(line , BUFSIZ , stdin)) {
        printf("\n");
        while (sscanf(line,"%s %[^\n]",token,line) == 2) {
                if (strcmp(avancar,ver)!=0 ){
                    printf("Passo: %d\n",exec);
                    printf("Token: %s\n",token);
                    handle(s ,token);
                    printf ("Stack:");
                    for (int i=1; i<=(s->topo); i++){
                        if (s->pilha[i].tipo == tLong) {printf("%ld",s->pilha[i].val.l);} 
                        if (s->pilha[i].tipo == tDouble) {printf("%g",s->pilha[i].val.d);} 
                        if (s->pilha[i].tipo == tChar) {printf("%c",s->pilha[i].val.c);} 
                        if (s->pilha[i].tipo == tStr) {printf("%s",s->pilha[i].val.s);} 
                    }
                    printf("\n");
                    exec++;
                    if (scanf("%s",avancar)){}; 
                    printf("\n");
                }
            }
        handle(s,token);
        }
        return 1;
    }
    return 0;
}

int vars (STACK *s, char *token) {
    if (strlen(token) == 1 && token[0]>='A' && token[0]<='Z') {
        tipos aux ;
        int vall = ((int) token[0])-65 ;
        aux.tipo = s->var[vall].tipo;
        if (aux.tipo==tLong) {aux.val.l = s->var[vall].val.l;}
        if (aux.tipo==tDouble) {aux.val.d = s->var[vall].val.d;}
        if (aux.tipo==tChar) {aux.val.c = s->var[vall].val.c;}
        if (aux.tipo==tStr) {aux.val.s = s->var[vall].val.s;}
        push(s,aux);
        return 1;
    }
    return 0 ;
}

int vars2p (STACK *s, char *token, STACK* raiz) {
    if (strlen(token) == 2 && ':'==token[0] && isalpha (token[1]) != 0 )  {
        int vall = ((int) token[1]) - 65;
        raiz->var[vall] = s->pilha[s->topo];
        return 1;
    }
    return 0;
}

