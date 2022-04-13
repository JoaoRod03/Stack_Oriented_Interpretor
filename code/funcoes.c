#include "tipos.h"
#include <stdio.h>

STACK* nova() {
    return ((STACK *) malloc(sizeof(STACK)));
}

// Insere elemento no topo da stack
void push(STACK *s,int x) {
    s->topo++ ;
    s->pilha[s->topo] = x;
}

// Retira elemento do topo da stack
int pop(STACK *s) {
    int v = s->pilha[s->topo];
    s->topo--;
    return v ;
}

// Associa um operador/token a uma operação
void handle (STACK *s,char *token){
    soma (s,token) || menos (s,token) || mul (s,token) ||
    incrementa (s,token) || decrementa (s,token) ||
    divide (s,token) || resto (s,token)|| expo (s,token) ||
    logica_and(s,token) || logica_or(s,token) || logica_xor(s,token) || 
    logica_not(s,token) ||
    num (s,token); // Deixar no fim
}

// Verifica se não há nenhum operador no input, coloca os numeros na stack
int num (STACK *s,char *token) {
    int val;
    sscanf(token, "%d", &val);
    push(s, val);
    return 1 ;
}

// Soma dois elementos da stack e coloca o resultado nesta
int soma (STACK *s,char *token) {
    if(strcmp(token, "+") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A + B);
        return 1;
    }
    return 0 ;
}

// Subtrai dois elementos da stack e coloca o resultado nesta
int menos (STACK *s,char *token) {
    if(strcmp(token, "-") == 0) {
        int B = pop(s);
        int A = pop(s);
        push(s, A - B);
        return 1;
    }
    return 0 ;
}

// Multiplica dois elementos da stack e coloca o resultado nesta
int mul (STACK *s,char *token) {
    if(strcmp(token, "*") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A * B);
        return 1;
    }
    return 0;
}

// Divide dois elementos da stack e coloca o resultado nesta
int divide (STACK *s,char *token) {
    if(strcmp(token, "/") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, A / B);
        return 1;
    }
    return 0;
}

// Calcula o resto da divisão de dois elementos da stack e coloca o resultado nesta
int resto (STACK *s,char *token) {
    if(strcmp(token, "%") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B % A);
        return 1;
    }
    return 0;
}

// Calcula o resultado de elevar um elemento da stack a outro, coloca o resultado na stack
int expo (STACK *s,char *token) {
    if(strcmp(token, "#") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, pow(A,B));
        return 1;
    }
    return 0;
}

// Incrementa um elemento da stack em 1 valor
int incrementa (STACK *s,char *token) {
    if(strcmp(token, ")") == 0) {
        int A = pop(s);
        push(s, A + 1);
        return 1;
    }
    return 0 ;
}

// Decrementa um elemento da stack em 1 valor
int decrementa (STACK *s,char *token) {
    if(strcmp(token, "(") == 0) {
        int A = pop(s);
        push(s, A - 1);
        return 1;
    }
    return 0 ;
}

// Transforma um numero decimal em um numero binario
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

// Realiza a operação (and / &) ao nivel binario
int logica_and (STACK *s,char *token) {
    if(strcmp(token, "&") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B & A);
        return 1;
    }
    return 0;
}

// Realiza a operação (or / |) ao nivel binario
int logica_or (STACK *s,char *token) {
    if(strcmp(token, "|") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B | A);
        return 1;
    }
    return 0;
}

// Realiza a operação (xor / ^) ao nivel binario
int logica_xor (STACK *s,char *token) {
    if(strcmp(token, "^") == 0) {
        int A = pop(s);
        int B = pop(s);
        push(s, B ^ A);
        return 1;
    }
    return 0;
}

// Realiza a operação (not / ~) ao nivel binario
int logica_not (STACK *s,char *token) {
    if(strcmp(token, "~") == 0) {
        int A = pop(s);
        push(s, ~A);
        return 1;
    }
    return 0;
}

//////////////////////////////////////////////////////////
// prototipos ////////////////////////////////////////////
// GUIAO 2    ////////////////////////////////////////////
//////////////////////////////////////////////////////////

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



//////////////////////////////////////////////////////////
// prototipos ////////////////////////////////////////////
// Outros Guioes    //////////////////////////////////////
//////////////////////////////////////////////////////////


int ler (STACK *s,char *token) {
    if(strcmp(token, "l") == 0) {
        STACK *s = nova2();
        input(nova2); // Temos de meter o codigo do input da main numa função chamada input e que recebe a stack onde realizar as operações
        return 1;
    }
    return 0;
}


*/