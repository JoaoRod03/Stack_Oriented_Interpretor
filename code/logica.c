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

        if (c1!=0 || d1!=0) {
            push(s,t2);
        } else {
            push(s,t3);
        }

        return 1;
    }
    return 0;
}

int mai(STACK *s,char *token) {
    if(strcmp(token, ">") == 0) {
        tipos t1,t2,aux;
        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong || t1.tipo==tDouble || t2.tipo==tLong || t2.tipo==tDouble) {
            aux.tipo=tLong;
            double v1=0,v2=0;
            if (t1.tipo==tLong){v1=(double)t1.val.l;} else{v1=t1.val.d;}
            if (t2.tipo==tLong){v2=(double)t2.val.l;} else{v2=t2.val.d;}

            if (v1>v2) {aux.val.l=1;} else {aux.val.l=0;}
            push(s,aux);
        }

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

        return 1;
    }
    return 0 ;
}

/// Se um valor for maior que o outro ira devolver 1 senão irá devolver 0
int men(STACK *s, char *token) {
    if (strcmp(token, "<") == 0) {
        tipos t1,t2,aux;
        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong || t1.tipo==tDouble || t2.tipo==tLong || t2.tipo==tDouble) {
            aux.tipo=tLong;
            double v1=0,v2=0;
            if (t1.tipo==tLong) {v1=(double)t1.val.l;} else {v1=t1.val.d;}
            if (t2.tipo==tLong) {v2=(double)t2.val.l;} else {v2=t2.val.d;}

            if (v1<v2) {aux.val.l=1;} else {aux.val.l=0;}
            push(s,aux);
        }

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

        return 1;
    }
    return 0 ;
}

int igual(STACK *s,char *token) {
    if(strcmp(token, "=") == 0) {
        tipos t1,t2,aux;

        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong || t1.tipo==tDouble) {
            aux.tipo=tLong;
            double v1=0,v2=0;
            if(t1.tipo==tLong) {v1=(double)t1.val.l;} else {v1=t1.val.d;}
            if(t2.tipo==tLong) {v2=(double)t2.val.l;} else {v2=t2.val.d;}

            if(v1==v2) {aux.val.l=1;} else {aux.val.l=0;}
            push(s,aux);
        }

        if (t1.tipo == tStr && t2.tipo == tLong) {
            aux.tipo = tChar ; 
            aux.val.c = t1.val.s[t2.val.l] ;
            push(s,aux);
        }

        if (t1.tipo == tArr && t2.tipo == tLong) {
            push(s,t1.val.arr->pilha[t2.val.l+1]);
        }

        if (t1.tipo == tStr && t2.tipo == tStr) {
            aux.tipo=tLong;
            if (strcmp(t1.val.s,t2.val.s)==0) {aux.val.l=1;} else {aux.val.l=0;}
            push(s,aux);
        }

        return 1;
    }
    return 0 ;
}

int nao(STACK *s,char *token) {
    if(strcmp(token, "!") == 0) {
        tipos t1,aux;
        t1 = pop(s);
        aux.tipo=tLong;
        double v1=0;

        if(t1.tipo==tLong){v1=(double)t1.val.l;} else{v1=t1.val.d;}
        if(v1!=0){aux.val.l=0;}else aux.val.l=1;

        push(s,aux);

        return 1;
    }
    return 0 ;
}

int maior(STACK *s,char *token) {
    if(strcmp(token, "e>") == 0) {
        tipos t1,t2,aux;
        double v1=0,v2=0;

        t2 = pop(s);
        t1 = pop(s);

        // Numeros reais
        if (((t1.tipo==tLong || t1.tipo==tDouble ) && (t2.tipo==tDouble || t2.tipo==tLong))) {
            if(t1.tipo==tLong){v1=(double)t1.val.l;} else {v1=t1.val.d;}
            if(t2.tipo==tLong){v2=(double)t2.val.l;} else {v2=t2.val.d;}

            if (v1>v2) {if(t1.tipo==tLong) {aux.tipo=tLong; aux.val.l=v1;} else {aux.tipo=tDouble; aux.val.d=v1;}}
            else {if(t2.tipo==tLong){aux.tipo=tLong; aux.val.l=v2;} else {aux.tipo=tDouble; aux.val.d=v2;}}

            push(s,aux);
        }
        
        if (t1.tipo==tStr && t2.tipo==tStr) {
            tipos aux;
            if (strlen(t1.val.s) == strlen(t2.val.s)) {aux.val.s = t1.val.s;}
            push (s,aux);
        }

        return 1;
    }
    return 0 ;
}

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

            if (v1<v2) {if(t1.tipo==tLong) {aux.tipo=tLong; aux.val.l=v1;} else {aux.tipo=tDouble; aux.val.d=v1;}}
            else {if(t2.tipo==tLong) {aux.tipo=tLong; aux.val.l=v2;} else {aux.tipo=tDouble; aux.val.d=v2;}}
        
            push(s,aux);
        }

        if (t1.tipo==tStr && t2.tipo==tStr) {
            tipos aux;
            if (strlen(t1.val.s) == strlen(t2.val.s)) {aux.val.s = t2.val.s;}
            push (s,aux);
        }

        return 1;
    }
    return 0 ;
}

int conjuncao (STACK *s,char *token) {
    if(strcmp(token, "e&") == 0) {
        tipos t1,t2;
        double v1=0,v2=0;

        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong) {v1=(double)t1.val.l;} else {v1=t1.val.d;}
        if (t2.tipo==tLong) {v2=(double)t2.val.l;} else {v2=t2.val.d;}

        if (v1==0 || v2==0) {t1.tipo=tLong; t1.val.l=0; push(s,t1);} else {push(s,t2);}

        return 1;
    }
    return 0 ;
}

int disjuncao (STACK *s,char *token) {
    if(strcmp(token, "e|") == 0) {
        tipos t1,t2;
        double v1=0,v2=0;

        t2 = pop(s);
        t1 = pop(s);

        if (t1.tipo==tLong) {v1=(double)t1.val.l;} else {v1=t1.val.d;}
        if (t2.tipo==tLong) {v2=(double)t2.val.l;} else {v2=t2.val.d;}
        if (v1!=0 && v2!=0) { push(s,t1);}
        if (v1==0 && v2==0) {t1.tipo=tLong; t1.val.l=0; push(s,t1);}
        else {if (v1==0) {push(s,t2);}if (v2==0) {push(s,t1);}}

        return 1;
    }
    return 0 ;
}
