/**
* @file funcoes.c
* Ficheiro .c que contém as funções utilizadas no projeto.
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tipos.h"

/// Função responsavel por alocar o espaço necessario na memoria para criar uma stack.
STACK* nova() {
    return ((STACK *) malloc(sizeof(STACK)));
}

/// Função que insere um elemento x no topo da stack.
void push(STACK *s,int x) {
    s->topo++ ;
    s->pilha[s->topo] = x;
}

/// Função que retira o elemento que se encontra no topo da stack.
int pop(STACK *s) {
    int v = s->pilha[s->topo];
    s->topo--;
    return v ;
}

/** Função responsavel por associar um token de um operador á sua função correspondente
*   @param [in] Stack
*   @param [in] Token
*/ 
void handle (STACK *s,char *token){
    if (soma (s,token) || menos (s,token) || mul (s,token) ||
    incrementa (s,token) || decrementa (s,token) ||
    divide (s,token) || resto (s,token)|| expo (s,token) ||
    logica_and(s,token) || logica_or(s,token) || logica_xor(s,token) || logica_not(s,token) ||
    num (s,token)) {return;} // Deixar no fim
}

/// Verifica se não há nenhum operador no input recebido/token desconhecido. 
int num (STACK *s,char *token) {
    int val;
    sscanf(token, "%d", &val);
    push(s, val);
    return 1 ;
}

/// Função que soma dois elementos da stack e coloca o resultado no topo desta.
int soma (STACK *s,char *token) {
    if(strcmp(token, "+") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A + B);
        return 1;
    }
    return 0 ;
}

/// Função que subtrai dois elementos da stack e coloca o resultado no topo desta.
int menos (STACK *s,char *token) {
    if(strcmp(token, "-") == 0) {
        int B = pop(s);
        int A = pop(s);
        push(s, A - B);
        return 1;
    }
    return 0 ;
}

/// Função que multiplica dois elementos da stack e coloca o resultado no topo desta.
int mul (STACK *s,char *token) {
    if(strcmp(token, "*") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A * B);
        return 1;
    }
    return 0;
}

/// Função que divide dois elementos da stack e coloca o resultado no topo desta.
int divide (STACK *s,char *token) {
    if(strcmp(token, "/") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B / A);
        return 1;
    }
    return 0;
}

/// Função que calcula o resto da divisao de dois elementos da stack e coloca o resultado no topo desta.
int resto (STACK *s,char *token) {
    if(strcmp(token, "%") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B % A);
        return 1;
    }
    return 0;
}

/// Calcula o resultado de elevar um elemento da stack a outro, coloca o resultado no topo da stack.
int expo (STACK *s,char *token) {
    if(strcmp(token, "#") == 0) {
        int B = pop(s);
        int A = pop(s);
        push(s, pow(A,B));
        return 1;
    }
    return 0;
}

/// Incrementa o valor de um elemento da stack.
int incrementa (STACK *s,char *token) {
    if(strcmp(token, ")") == 0) {
        int A = pop(s);
        push(s, A + 1);
        return 1;
    }
    return 0 ;
}

/// Decrementa o valor de um elemento da stack.
int decrementa (STACK *s,char *token) {
    if(strcmp(token, "(") == 0) {
        int A = pop(s);
        push(s, A - 1);
        return 1;
    }
    return 0 ;
}

// NAO UTILIZADO: Transforma um numero decimal em um numero binario
/*
long binario (int x) {
	long r=0;
    int i=0,resto=0;
	while (x>=1) {
		resto=x%2;
		r=r+(resto*pow(10,i));
		x=(x-resto)/2;
		i++;
	}
	return r;
} 
*/

/// Realiza a operação (and / &) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_and (STACK *s,char *token) {
    if(strcmp(token, "&") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B & A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (or / |) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_or (STACK *s,char *token) {
    if(strcmp(token, "|") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B | A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (xor / ^) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_xor (STACK *s,char *token) {
    if(strcmp(token, "^") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B ^ A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (not / ~) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_not (STACK *s,char *token) {
    if(strcmp(token, "~") == 0) {
        int A = pop(s);
        push(s, ~A);
        return 1;
    }
    return 0;
}


// Prototipos ------------------------------------------- //
// GUIAO 2    ------------------------------------------- //

/*
int duplicar (STACK *s,char *token) {
    if(strcmp(token, "_") == 0) {
        pop(s);
        int B = pop(s);
        push(s, A);
        push(s, A);
        return 1;
    }
    return 0;
}

int rodar (STACK *s,char *token) {
    if(strcmp(token, "@") == 0) {
        int A = pop(s);
        int B = pop(s);
        int C = pop(s);
        
        push(s, B);
        push(s, C);
        push(s, A);
        return 1;
    }
    return 0;
}

int pop_elem (STACK *s,char *token) {
    if(strcmp(token, ";") == 0) {
        pop(s);
        return 1;
    }
    return 0;
}

int copia (STACK *s,char *token) {
    if(strcmp(token, "$") == 0) {
        int w,ultimo;
        int num = pop(s);
        int arr[BUFSIZ];
        
        if (num>0) {
            for (w=0; w<num-1; w++) { // copia tudo na stack até num para um array
                arr[w]= pop(s);
            }

            ultimo=pop(s); 

            for (w=0; w<num-1; w++) { // passa tudo do array para a stack
                push (s,arr[w]);
            }

            push(s,ultimo);
        }

        return 1;
    }
    return 0;
}


// Prototipos ------------------------------------------- //
// Outros guiões ---------------------------------------- //

int ler (STACK *s,char *token) {
    if(strcmp(token, "l") == 0) {
        STACK *s = nova2();
        input(nova2); // Temos de meter o codigo do input da main numa função chamada input e que recebe a stack onde realizar as operações
        return 1;
    }
    return 0;
}


*/
