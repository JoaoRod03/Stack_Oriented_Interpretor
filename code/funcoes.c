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

/// Função que insere um elemento x no topo da stack. (PUSH de ints)
void push(STACK *s,long x) {
    s->topo++;
    s->pilha[s->topo].tipo = tLong;  // Indica que é long
    s->pilha[s->topo].val.l = x;  // Push para o campo int
}

/// Função que insere um elemento x no topo da stack. (PUSH de doubles)
void push_double(STACK *s,double x) {
    s->topo++;
    s->pilha[s->topo].tipo = tDouble;   // Indica que é double
    s->pilha[s->topo].val.d = x;  // Push para o campo double
}

/// Função que insere um elemento x no topo da stack. (PUSH de chars)
void push_char(STACK *s ,char x) {
    s->topo++;
    s->pilha[s->topo].tipo = tChar;  // Indica que é char
    s->pilha[s->topo].val.c = x;
}

/// Função que retira o elemento que se encontra no topo da stack. (Indentifica primeiro o tipo do elemento)
long pop(STACK *s) {
        long v = s->pilha[s->topo].val.l;
        s->topo--;
        return v ; 
}

double pop_double(STACK *s) {
        double v = s->pilha[s->topo].val.d;
        s->topo--;
        return v ;
}

char pop_char(STACK *s) {
        char v = s->pilha[s->topo].val.c;
        s->topo--;
        return v ;
}

/** Função responsavel por associar um token de um operador á sua função correspondente
*   @param [in] Stack
*   @param [in] Token
*/ 
void handle (STACK *s,char *token){
    if (
    soma (s,token) ||
    menos (s,token) ||
    mul (s,token) ||
    incrementa (s,token) || 
    decrementa (s,token) ||
    divide (s,token) || 
    resto (s,token)|| 
    expo (s,token) ||
    logica_and(s,token) || 
    logica_or(s,token) || 
    logica_xor(s,token) || 
    logica_not(s,token) ||
    duplicar (s,token) || 
    pop_elem (s,token) ||
    trocar (s,token) ||
    rodar (s,token) ||
    copia (s, token) ||
    conv_int (s, token) ||
    conv_double (s, token) ||
    conv_char (s, token) ||
    ler (s, token) ||
    maior (s,token) ||
    menor (s,token) ||
    num (s,token)) {return;} // Deixar no fim
}

/// Verifica se não há nenhum operador no input recebido/token desconhecido. Trata das constantes.
int num (STACK *s,char *token) {
    long val;
    double val2;
    char* ptr;
    
    sscanf(token, "%ld", &val);
    sscanf(token, "%lf", &val2);
    strtol(token,&ptr,10);

    if (*ptr=='\0') {
        push(s,val);
    } else {
        push_double (s,val2);
    }

    return 1 ;
}

/// Devolve o tipo do topo da stack
int topo_tipo (STACK *s) {
    int r;
    r = s->pilha[s->topo].tipo; 
    return r;
}

/// Função que soma dois elementos da stack e coloca o resultado no topo desta.
int soma (STACK *s,char *token) {
    if(strcmp(token, "+") == 0) {
        long i1=0, i2=0, t1=0;
        double d1=0.0, d2=0.0, t2=0;

        t2=topo_tipo(s);
        if (t2==tDouble) {d2=pop_double(s);} else {i2=pop(s);}
        
        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);} else {i1=pop(s);}
        
        if (t1==1 && t2==1) {push_double(s, d1 + d2);}
        if (t1==0 && t2==1) {push_double(s, i1 + d2);}
        if (t1==1 && t2==0) {push_double(s, d1 + i2);}
        if (t1==0 && t2==0) {push(s, i1 + i2);}

        return 1;
    }
    return 0 ;
}

/// Função que subtrai dois elementos da stack e coloca o resultado no topo desta.
int menos (STACK *s,char *token) {
    if(strcmp(token, "-") == 0) {
        long i1=0, i2=0, t1=0;
        double d1=0.0, d2=0.0, t2=0;

        t2=topo_tipo(s);
        if (t2==tDouble) {d2=pop_double(s);} else {i2=pop(s);}
        
        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);} else {i1=pop(s);}
        
        if (t1==1 && t2==1) {push_double(s, d1 - d2);}
        if (t1==0 && t2==1) {push_double(s, i1 - d2);}
        if (t1==1 && t2==0) {push_double(s, d1 - i2);}
        if (t1==0 && t2==0) {push(s, i1 - i2);}

        return 1;
    }
    return 0 ;
}

/// Função que multiplica dois elementos da stack e coloca o resultado no topo desta.
int mul (STACK *s,char *token) {
    if(strcmp(token, "*") == 0) {
        long i1=0, i2=0, t1=0;
        double d1=0.0, d2=0.0, t2=0;

        t2=topo_tipo(s);
        if (t2==tDouble) {d2=pop_double(s);} else {i2=pop(s);}
        
        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);} else {i1=pop(s);}
        
        if (t1==1 && t2==1) {push_double(s, d1 * d2);}
        if (t1==0 && t2==1) {push_double(s, i1 * d2);}
        if (t1==1 && t2==0) {push_double(s, d1 * i2);}
        if (t1==0 && t2==0) {push(s, i1 * i2);}

        return 1;
    }
    return 0;
}

/// Função que divide dois elementos da stack e coloca o resultado no topo desta.
int divide (STACK *s,char *token) {
    if(strcmp(token, "/") == 0) { 
        int i1=0, i2=0, t1=0;
        double d1=0.0, d2=0.0, t2=0;

        t2=topo_tipo(s);
        if (t2==tDouble) {d2=pop_double(s);} else {i2=pop(s);}
        
        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);} else {i1=pop(s);}
        
        if (t1==1 && t2==1) {push_double(s, d1 / d2);}
        if (t1==0 && t2==1) {push_double(s, (double) i1 / d2);}
        if (t1==1 && t2==0) {push_double(s, d1 / (double) i2);}
        if (t1==0 && t2==0) {push (s,i1 / i2);}
        
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
        int i1=0, i2=0, t1=0, t2=0;
        double d1=0.0, d2=0.0;

        t2=topo_tipo(s);
        if (t2==tDouble) {d2=pop_double(s);} else {i2=pop(s);}
        
        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);} else {i1=pop(s);}
        
        if (t1==1 && t2==1) {push_double(s, pow (d1,d2));}
        if (t1==0 && t2==1) {push_double(s, pow ((double) i1,d2));}
        if (t1==1 && t2==0) {push_double(s, pow (d1,(double) i2));}
        if (t1==0 && t2==0) {push (s, pow(i1,i2));}
        
        return 1;
    }
    return 0;
}

/// Incrementa o valor de um elemento da stack.
int incrementa (STACK *s,char *token) {
    if(strcmp(token, ")") == 0) {

        int i1=0,t1=0;
        double d1=0.0;
        char c1=' ';

        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);}
        else if (t1==tLong) {i1=pop(s);}
        else if (t1==tChar) {c1=pop_char(s);}

        if (t1==tLong) {push(s, i1+1);}
        if (t1==tDouble) {push_double(s, d1+1);}
        if (t1==tChar) {
            int aux = (int) c1;
            char aux2 = (char) (aux+1); 
            push_char(s, aux2);
        }

        return 1;
    }
    return 0 ;
}

/// Decrementa o valor de um elemento da stack.
int decrementa (STACK *s,char *token) {
    if(strcmp(token, "(") == 0) {
        int i1=0,t1=0;
        double d1=0.0;
        char c1=' ';

        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);}
        else if (t1==tLong) {i1=pop(s);}
        else if (t1==tChar) {c1=pop_char(s);}

        if (t1==tLong) {push(s, i1-1);}
        if (t1==tDouble) {push_double(s, d1-1);}
        if (t1==tChar) {
            int aux = (int) c1;
            char aux2 = (char) (aux-1); 
            push_char(s, aux2);
        }

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

// GUIAO 2    ------------------------------------------- //
/// Duplica o elemento no topo da Stack 
int duplicar (STACK *s,char *token) {
    if(strcmp(token, "_") == 0) {
        long i1=0,t1=0;
        double d1=0.0;
        char c1=' ';
        
        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);}
        if (t1 == tLong) {i1=pop(s);}
        if (t1 == tChar) {c1=pop_char(s);}
        
        if (t1==tChar) {push_char(s, c1); push_char(s, c1);}
        if (t1==tDouble) {push_double(s, d1); push_double(s, d1);}
        if (t1==tLong) {push(s, i1); push(s, i1);}

        return 1;
    }
    return 0;
}

/// Roda os 3 elementos no topo da stack
int rodar (STACK *s,char *token) {
    if(strcmp(token, "@") == 0) {
        int i1=0, i2=0, i3=0, t1=0, t2=0, t3=0;
        double d1=0.0, d2=0.0, d3=0;
        char c1=' ',c2=' ',c3=' ';

        t3=topo_tipo(s);
        if (t3==tDouble) {d3=pop_double(s);}
        else if (t3==tLong) {i3=pop(s);}
        else if (t3==tChar) {c3=pop_char(s);}

        t2=topo_tipo(s);
        if (t2==tDouble) {d2=pop_double(s);}
        else if (t2==tLong) {i2=pop(s);}
        else if (t2==tChar) {c2=pop_char(s);}

        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);}
        else if (t1==tLong) {i1=pop(s);}
        else if (t1==tChar) {c1=pop_char(s);}

        /////////////////////////////////////////////

        // C
        if (t2==tLong) {push(s,i2);}
        if (t2==tDouble) {push_double(s, d2);}
        if (t2==tChar) {push_char(s, c2);}

        // B
        if (t3==tLong) {push(s,i3);}
        if (t3==tDouble) {push_double(s, d3);}
        if (t3==tChar) {push_char(s, c3);}


        // A
        if (t1==tLong) {push(s,i1);}
        if (t1==tDouble) {push_double(s, d1);}
        if (t1==tChar) {push_char(s, c1);}



        return 1;
    }
    return 0;
}

/// Dá Pop no topo da Stack
int pop_elem (STACK *s,char *token) {
    if(strcmp(token, ";") == 0) {
        int t1;
        t1=topo_tipo(s);
        if (t1 == tDouble) {pop_double(s);} else {pop(s);}
        return 1;
    }
    return 0;
}


/// Troca os dois elementos do topo da stack
int trocar (STACK *s,char *token) {
    if(strcmp(token, "\\") == 0) {
        long i1=0,i2=0,t1=0,t2=0;
        double d1=0.0,d2=0.0;
        char c1=' ',c2=' ';

        t1=topo_tipo(s);
        if (t1 == tDouble) {d1=pop_double(s);}
        else if (t1==tLong) {i1=pop(s);}
        else if (t1==tChar) {c1=pop_char(s);}

        t2=topo_tipo(s);
        if (t2==tDouble) {d2=pop_double(s);}
        else if (t2==tLong) {i2=pop(s);}
        else if (t2==tChar) {c2=pop_char(s);}


        /////////////////////////////////////////////

        // A
        if (t1==tLong) {push(s,i1);}
        if (t1==tDouble) {push_double(s, d1);}
        if (t1==tChar) {push_char(s, c1);}

        // B
        if (t2==tLong) {push(s,i2);}
        if (t2==tDouble) {push_double(s, d2);}
        if (t2==tChar) {push_char(s, c2);}

        return 1;
    }
    return 0;
}


///  Copia n-ésimo elemento para o topo da stack
int copia (STACK *s,char *token) {
    if(strcmp(token, "$") == 0) {
        int w,ultimo;
        int num = pop(s); // tira e guarda o indice
        int arr[BUFSIZ];
        
        if (num>=0) {
            for (w=0; w<=num-1; w++) { // copia tudo na stack até num para um array
                arr[w]= pop(s);
            }

            ultimo=pop(s);
            push (s, ultimo) ; 

            for (w = num - 1  ; w >= 0 ; w-- ) { // passa tudo do array para a stack
                push (s , arr[w]);
            }

            push(s,ultimo);
        }

        return 1;
    }
    return 0;
}

/// Converte o topo da stack para int
int conv_int (STACK *s,char *token) {
    if (strcmp(token, "i") == 0) {
        if (topo_tipo(s) == tLong) { 
            long aux = pop(s);
            int r = (int) aux;
            push (s,r);
        }
        
        if (topo_tipo(s) == tDouble) { 
            double aux = pop_double(s);
            int r = (int) aux;
            push (s,r);
        }

        if (topo_tipo(s) == tChar) { 
            char aux = pop_char(s);
            int r = (int) aux;
            push (s,r);
        }

        return 1;
    }
    return 0;
}

/// Converte o topo da stack para double
int conv_double (STACK *s,char *token) {
    if (strcmp(token, "f") == 0) {
        if (topo_tipo(s) == tLong) { 
            long aux = pop(s);
            double r = (double) aux;
            push_double (s,r);
        }

        if (topo_tipo(s) == tDouble) { 
            double aux = pop_double(s);
            push_double (s,aux);
        }

        return 1;
    }
    return 0;
}

/// Converte o topo da stack para char
int conv_char (STACK *s,char *token) {
    if (strcmp(token, "c") == 0) {
        if (topo_tipo(s) == tLong) { 
            long aux = pop(s);
            int x = (int) aux;
            char r = (char) x;
            push_char (s,r);
        }

        if (topo_tipo(s)  == tDouble) { 
            double aux = pop_double(s);
            int x = (int) aux;
            char r = (char) x;
            push_char (s,r);
        }

        return 1;
    }
    return 0;
}

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

//-------------------------------------------
//-------------------------------------------

/// Converte o topo da stack para string
/*
int conv_string (STACK *s,char *token) {
    if(strcmp(token, "s") == 0) {
        if (s->pilha[s->topo].tipo == 0) { 
            long aux = pop(s);
            double r = (double) aux;
            push (s,r);
        }

        if (s->pilha[s->topo].tipo == 1) { 
            double aux = pop(s);
            double r = aux;
            push (s,r);
        }
        return 1;
    }
    return 0;
}
*/
//---------------------------------------


// Prototipos ------------------------------------------- //
int maior (STACK *s,char *token) {
    if(strcmp(token, "e>") == 0) {
        long i1=0, i2=0, t1=0;
        double d1=0.0, d2=0.0, t2=0;

        t2=topo_tipo(s);
        if (t2==tDouble) {
            d2=pop_double(s);} else {i2=pop(s);
        }
        t1=topo_tipo(s);
        if (t1 == tDouble) {
            d1=pop_double(s);} else {i1=pop(s);
        }

        if (t1==1 && t2==1) {
            if (d1>d2){
                push_double(s, d1);
            }
            else push_double(s, d2);
        }
        if (t1==0 && t2==1) {
            if (i1>d2){
                push(s, i1);
            }
            else push_double(s, d2);
        }
        if (t1==1 && t2==0) {
            if (d1>i2){
                push_double(s, d1);
            }
            else push(s, i2);
        }
        if (t1==0 && t2==0) {
            if (i1-i2>0){
                push(s, i1);
            }
            else push(s, i2);
        }
        return 1;
    }
    return 0 ;
}

int menor (STACK *s,char *token) {
    if(strcmp(token, "e<") == 0) {
        long i1=0, i2=0, t1=0;
        double d1=0.0, d2=0.0, t2=0;

        t2=topo_tipo(s);
        if (t2==tDouble) {
            d2=pop_double(s);} else {i2=pop(s);
        }
        t1=topo_tipo(s);
        if (t1 == tDouble) {
            d1=pop_double(s);} else {i1=pop(s);
        }
        if (t1==1 && t2==1) {
            if (d1>d2){
                push_double(s, d2);
            }
            else push_double(s, d1);
        }
        if (t1==0 && t2==1) {
            if (i1>d2){
                push(s, d2);
            }
            else push_double(s, i1);
        }
        if (t1==1 && t2==0) {
            if (d1>i2){
                push_double(s, i2);
            }
            else push(s, d1);
        }
        if (t1==0 && t2==0) {
            if (i1>i2){
                push(s, i2);
            }
            else push(s, i1);
        }
        return 1;
    }
    return 0 ;
}
// Outros guiões ---------------------------------------- //

