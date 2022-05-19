/**
 * @file operacoes.c
 * Ficheiro .c que contém as funções que tratam das operações lógicas utilizadas no projeto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "Tipos.h"

//\/\/\/\/\/\/\/\/\/\/\/|---->  Logica  <-----|/\/\/\/\/\/\/\/\/\/\/\/

/// Função que lê input e insere o resultado desse input na stack.
int interroga (STACK *s, char *token) {
    if (strcmp(token, "?") == 0) {
        tipos t1,t2,t3;
        int c1=0;
        double d1=0;

        t3 = pop(s);
        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong) {c1=t1.val.l;} 
        if (t1.tipo==tDouble) {d1=t1.val.d;} 
        if (t1.tipo==tArr) {
            if(t1.val.arr->topo > 0) {c1=1;}
        }

        if (c1!=0 || d1!=0) {
            push(s,t2);
        } else {
            push(s,t3);
        }

        return 1;
    }
    return 0;
}

/// Função que compara dois valores no topo da stack, sendo que se o primeiro é maior que o segundo devolve 1 senão devolve 0.
int mai(STACK *s,char *token) {
    if (strcmp(token, ">") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo == tStr && t2.tipo == tLong) {
            buscar_fim(s,t1,t2);
            return 1;
        }

        // Numeros reais (Comparação maior)
        if (t1.tipo==tLong || t1.tipo==tDouble || t2.tipo==tLong || t2.tipo==tDouble) {
            aux.tipo=tLong;
            double v1=0,v2=0;
            if (t1.tipo==tLong) {v1=(double)t1.val.l;} else {v1=t1.val.d;}
            if (t2.tipo==tLong) {v2=(double)t2.val.l;} else {v2=t2.val.d;}

            if (v1>v2) {aux.val.l=1;} else {aux.val.l=0;}
            push(s,aux);
        }

        // Strings e arrays (Vai buscar x elementos ao fim)
        if (t1.tipo == tStr || t1.tipo == tArr || t2.tipo == tStr || t2.tipo == tArr ) {
            buscar_fim(s,t1,t2);
        }

        return 1;
    }
    return 0 ;
}

/// Função que compara dois valores no topo da stack, sendo que se o primeiro é menor que o segundo devolve 1 senão devolve 0.
int men(STACK *s, char *token) {
    if (strcmp(token, "<") == 0) {
        tipos t1,t2,aux;
        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo == tStr && t2.tipo == tLong) {
            buscar_inicio(s,t1,t2);
            return 1;
        }
        // Numeros reais (Comparação menor)
        if (t1.tipo==tLong || t1.tipo==tDouble || t2.tipo==tLong || t2.tipo==tDouble) {
            aux.tipo=tLong;
            double v1=0,v2=0;
            if (t1.tipo==tLong) {v1=(double)t1.val.l;} else {v1=t1.val.d;}
            if (t2.tipo==tLong) {v2=(double)t2.val.l;} else {v2=t2.val.d;}

            if (v1<v2) {aux.val.l=1;} else {aux.val.l=0;}
            push(s,aux);
        }

        // Strings e arrays (Vai buscar x elementos ao inicio)
        if (t1.tipo == tStr || t1.tipo == tArr || t2.tipo == tStr || t2.tipo == tArr ) {
            buscar_inicio(s,t1,t2);
        }

        return 1;
    }
    return 0 ;
}

/// Função que compara dois valores no topo da stack, sendo que se o primeiro é igual que o segundo devolve 1 senão devolve 0.
int igual(STACK *s,char *token) {
    if(strcmp(token, "=") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s);
        t1 = pop(s);
        
        // Numeros reais (Verifica se os elementos são iguais)
        if (t1.tipo==tLong || t1.tipo==tDouble) {
            aux.tipo=tLong;
            double v1=0,v2=0;
            if(t1.tipo==tLong) {v1=(double)t1.val.l;} else {v1=t1.val.d;}
            if(t2.tipo==tLong) {v2=(double)t2.val.l;} else {v2=t2.val.d;}

            if (v1==v2) {aux.val.l=1;} else {aux.val.l=0;}
            push(s,aux);
        }

        // Strings e arrays (Vai buscar um valor por indice)
        if (t1.tipo==tArr || t1.tipo==tStr) {
            buscar_indice(s,t1,t2);
        }

        return 1;
    }
    return 0 ;
}

/// Função que dado um valor no topo da stack se este for diferente de 0 devolve 0 senão devolve 1.
int nao (STACK *s,char *token) {
    if (strcmp(token, "!") == 0) {
        tipos t1,aux;
        aux.tipo=tLong;

        t1 = pop(s);
        double v1=0;

        if (t1.tipo==tLong) {v1=(double) t1.val.l;} else {v1=t1.val.d;}
        if (v1!=0) {aux.val.l=0;} else {aux.val.l=1;}

        push(s,aux);

        return 1;
    }
    return 0 ;
}


/// Função responsável por colocar o maior dos dois valores na stack.
int maior(STACK *s,char *token) {
    if(strcmp(token, "e>") == 0) {
        tipos t1,t2,aux;
        double v1=0,v2=0;

        t2 = pop(s);
        t1 = pop(s);

        // Numeros reais
        if (((t1.tipo==tLong || t1.tipo==tDouble ) && (t2.tipo==tDouble || t2.tipo==tLong))) {
            if (t1.tipo==tLong) {v1=(double) t1.val.l;} else {v1=t1.val.d;}
            if (t2.tipo==tLong) {v2=(double) t2.val.l;} else {v2=t2.val.d;}

            if (v1>v2) {if (t1.tipo==tLong) {aux.tipo=tLong; aux.val.l=v1;} else {aux.tipo=tDouble; aux.val.d=v1;}}
            else {if (t2.tipo==tLong) {aux.tipo=tLong; aux.val.l=v2;} else {aux.tipo=tDouble; aux.val.d=v2;}}

            push(s,aux);
        }
        
        // Strings (Ordem lexicografica)
        if (t1.tipo==tStr && t2.tipo==tStr) {
            tipos aux; aux.tipo=tStr;
            if(strcmp(t1.val.s,t2.val.s)>0) {aux.val.s=t1.val.s;}
            if(strcmp(t1.val.s,t2.val.s)<0) {aux.val.s=t2.val.s;}
            if(strcmp(t1.val.s,t2.val.s)==0) {aux.val.s=t2.val.s;}
            push (s,aux);
        }

        return 1;
    }
    return 0 ;
}


/// Função responsável por colocar o menor dos dois valores na stack.
int menor(STACK *s,char *token) {
    if(strcmp(token, "e<") == 0) {
        tipos t1,t2,aux;
        double v1=0,v2=0;

        t2 = pop(s);
        t1 = pop(s);

        // Numeros reais
        if (((t1.tipo==tLong || t1.tipo==tDouble ) && (t2.tipo==tDouble || t2.tipo==tLong))) {
            if(t1.tipo==tLong) {v1=(double)t1.val.l;} else {v1=t1.val.d;}
            if(t2.tipo==tLong) {v2=(double)t2.val.l;} else {v2=t2.val.d;}

            if (v1<v2) {if (t1.tipo==tLong) {aux.tipo=tLong; aux.val.l=v1;} else {aux.tipo=tDouble; aux.val.d=v1;}}
            else {if (t2.tipo==tLong) {aux.tipo=tLong; aux.val.l=v2;} else {aux.tipo=tDouble; aux.val.d=v2;}}
        
            push(s,aux);
        }

        // Strings (Ordem lexicografica)
        if (t1.tipo==tStr && t2.tipo==tStr) {
            tipos aux; aux.tipo=tStr;
            if(strcmp(t1.val.s,t2.val.s)<0) {aux.val.s=t1.val.s;}
            if(strcmp(t1.val.s,t2.val.s)>0) {aux.val.s=t2.val.s;}
            if(strcmp(t1.val.s,t2.val.s)==0) {aux.val.s=t2.val.s;}
            push (s,aux);
        }

        return 1;
    }
    return 0 ;
}

/// Função que da pop a dois valores no topo da stack, se um destes for zero coloca na stack o valor 0, senão coloca o segundo elemento.
int conjuncao (STACK *s, char *token) {
    if(strcmp(token, "e&") == 0) {
        tipos t1,t2;
        double v1=0,v2=0;

        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong) {v1=(double) t1.val.l;} else {v1=t1.val.d;}
        if (t2.tipo==tLong) {v2=(double) t2.val.l;} else {v2=t2.val.d;}

        if (v1==0 || v2==0) {t1.tipo=tLong; t1.val.l=0; push(s,t1);} else {push(s,t2);}

        return 1;
    }
    return 0 ;
}

/// Função que da pop a dois valores no topo da stack, se ambos forem 0 devolve 0. Se apenas 1 dos elementos for 0 devolve o que não é nulo.
int disjuncao (STACK *s,char *token) {
    if(strcmp(token, "e|") == 0) {
        tipos t1,t2;
        double v1=0,v2=0;

        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong) {v1=(double) t1.val.l;} else {v1=t1.val.d;}
        if (t2.tipo==tLong) {v2=(double) t2.val.l;} else {v2=t2.val.d;}
        if (v1!=0 && v2!=0) {push(s,t1);}
        if (v1==0 && v2==0) {t1.tipo=tLong; t1.val.l=0; push(s,t1);}
        else {if (v1==0) {push(s,t2);} if (v2==0) {push(s,t1);}}

        return 1;
    }
    return 0 ;
}
