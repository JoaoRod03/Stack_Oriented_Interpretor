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
    return ((STACK*) malloc(sizeof(STACK)));
}


//\/\/\/\/\/\/\/\/\/\/\/|---->  PUSH e POP  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Função que insere um elemento no topo da stack. 
void push(STACK *s, tipos x) {
    s->topo++;                 // Aumenta o apontador para o topo da stack
    s->pilha[s->topo] = x;     // Push para o campo long
}


/// Função que retira o elemento que se encontra no topo da stack.
tipos pop(STACK *s) {
        tipos v = s->pilha[s->topo];  // Obtem o elemento no topo da stack
        s->topo--;  
        return v ; 
}


//\/\/\/\/\/\/\/\/\/\/\/|---->  OUTROS  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/** Função responsavel por associar um token de um operador á sua função correspondente.
*   @param [in] Stack
*   @param [in] Token
*/ 
void handle (STACK *s,char *token){
    if (
    soma (s,token) || 
    menos (s,token) || 
    mul (s,token) ||
    divide (s,token) || 
    resto (s,token)|| 
    expo (s,token) ||
    incrementa (s,token) || 
    decrementa (s,token) ||
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
    debugger (s, token) ||
    num (s,token)) {return;} // Deixar no fim
}

/// Função que trata dos tokens não reconhecidos e constantes, verifica o tipo do token e atribui uma operação.
int num (STACK *s,char *token) {
    tipos aux;
    long l1;
    double d1;
    
    char* ptr;
    strtol(token,&ptr,10);

    if (*ptr=='\0') {
        sscanf(token, "%ld", &l1);
        aux.tipo = tLong;
        aux.val.l = l1;
        push(s,aux);      
    } else {
        sscanf(token, "%lf", &d1);
        aux.tipo = tDouble;
        aux.val.d = d1;
        push(s,aux);
    }

    return 1 ;
}

/// Devolve o tipo do topo da stack
int topo_tipo (STACK *s) {
    int r;
    r = s->pilha[s->topo].tipo; 
    return r;
}


//\/\/\/\/\/\/\/\/\/\/\/|---->  OPERAÇÕES  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Função que soma dois elementos da stack e coloca o resultado no topo desta.
int soma (STACK *s,char *token) {
    if(strcmp(token, "+") == 0) {
        tipos t1,t2,aux;

        t1 = pop(s);
        t2 = pop(s);
        
        if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d + t2.val.d;}
        if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.l + t2.val.d;}
        if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d + t2.val.l;}
        if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l + t2.val.l;}

        push(s,aux);

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
        
        if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d * t2.val.d;}
        if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.l * t2.val.d;}
        if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d * t2.val.l;}
        if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l * t2.val.l;}

        push(s,aux);

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
        
        if (t1.tipo==1 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = t1.val.d / t2.val.d;}
        if (t1.tipo==0 && t2.tipo==1) {aux.tipo=tDouble; aux.val.d = (double) t1.val.l / t2.val.d;}
        if (t1.tipo==1 && t2.tipo==0) {aux.tipo=tDouble; aux.val.d = t1.val.d / (double) t2.val.l;}
        if (t1.tipo==0 && t2.tipo==0) {aux.tipo=tLong; aux.val.l = t1.val.l / t2.val.l;}

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
    if(strcmp(token, ")") == 0) {
        tipos t1,aux;

        t1 = pop(s);
        
        if (t1.tipo==tLong) {aux.tipo=tLong; aux.val.l = t1.val.l+1;}
        if (t1.tipo==tDouble) {aux.tipo=tDouble; aux.val.d = t1.val.d+1;}
        if (t1.tipo==tChar) {aux.tipo=tChar; aux.val.c = (char) (((int) t1.val.c)+1);}

        push(s,aux);

        return 1;
    }
    return 0 ;
}

/// Decrementa o valor de um elemento da stack em 1 valor.
int decrementa (STACK *s,char *token) {
    if(strcmp(token, "(") == 0) {
        tipos t1,aux;

        t1 = pop(s);
        
        if (t1.tipo==tLong) {aux.tipo=tLong; aux.val.l = t1.val.l-1;}
        if (t1.tipo==tDouble) {aux.tipo=tDouble; aux.val.d = t1.val.d-1;}
        if (t1.tipo==tChar) {aux.tipo=tChar; aux.val.c = (char) (((int) t1.val.c)-1);}

        push(s,aux);

        return 1;
        }
    return 0 ;
}


//\/\/\/\/\/\/\/\/\/\/\/|---->  OPERAÇÕES BITWISE  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Realiza a operação (and / &) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_and (STACK *s,char *token) {
    if(strcmp(token, "&") == 0) {
        tipos A = pop(s);
        tipos B = pop(s);
        A.val.l = A.val.l & B.val.l;
        push(s,A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (or / |) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_or (STACK *s,char *token) {
    if(strcmp(token, "|") == 0) {
        tipos A = pop(s);
        tipos B = pop(s);
        A.val.l = A.val.l | B.val.l;
        push(s,A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (xor / ^) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_xor (STACK *s,char *token) {
    if(strcmp(token, "^") == 0) {
        tipos A = pop(s);
        tipos B = pop(s);
        A.val.l = B.val.l ^ A.val.l;
        push(s,A);
        return 1;
    }
    return 0;
}

/// Realiza a operação (not / ~) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_not (STACK *s,char *token) {
    if(strcmp(token, "~") == 0) {
        tipos A = pop(s);
        A.val.l = (~(A.val.l));
        push(s,A);
        return 1;
    }
    return 0;
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


//\/\/\/\/\/\/\/\/\/\/\/|---->  CONVERSÕES  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Converte o topo da stack para int.
int conv_int (STACK *s,char *token) {
    if (strcmp(token, "i") == 0) {
        tipos t1,aux;
        aux.tipo=tLong;

        t1 = pop(s);
        
        if (t1.tipo==tLong) {push(s,t1);}
        if (t1.tipo==tDouble) {aux.val.l = (int) t1.val.d; push(s,aux);}
        if (t1.tipo==tChar) {aux.val.l = (int) t1.val.c; push(s,aux);}

        return 1;
    }
    return 0;
}

/// Converte o topo da stack para double.
int conv_double (STACK *s,char *token) {
    if (strcmp(token, "f") == 0) {
        tipos t1,aux;
        aux.tipo=tDouble;

        t1 = pop(s);

        if (t1.tipo==tDouble) {push(s,t1);}
        if (t1.tipo==tLong) {aux.val.d = (double) t1.val.l; push(s,aux);}
        if (t1.tipo==tChar) {aux.val.d = (double) ((int) t1.val.l); push(s,aux);}

        return 1;
    }
    return 0;
}

/// Converte o topo da stack para char.
int conv_char (STACK *s,char *token) {
    if (strcmp(token, "c") == 0) {
        tipos t1,aux;
        aux.tipo=tChar;

        t1 = pop(s);

        if (t1.tipo==tChar) {push(s,t1);}
        if (t1.tipo==tLong) {aux.val.c = (char) t1.val.l; push(s,aux);}
        if (t1.tipo==tDouble) {aux.val.c = (char) ((int) t1.val.d); push(s,aux);}

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

//\/\/\/\/\/\/\/\/\/\/\/|---->  Logica  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Função que lê input e insere o resultado desse input na stack.
int ifThenElse (STACK *s, char *token) {
    if (strcmp(token, "?") == 0) {
        tipos t1,t2,t3;
        int c1=0;
        double d1=0;

        t3 = pop(s);
        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong) {c1=t1.val.l;} 
        if (t1.tipo==tDouble) {d1=t1.val.d;} 

        if (c1!=0 || d1!=0) {
            push(s,t2);
        } else {
            push(s,t3);
        }

        return 1;
    }
    return 0;
}

/*
/// Converte o topo da stack para string
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

// NAO UTILIZADO: Transforma um numero decimal em um numero binario
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