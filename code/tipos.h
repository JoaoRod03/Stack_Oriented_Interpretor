/**
* @file tipos.h
* Contém o struct stack e inicializa as funções
*/

#ifndef TIPOS_H
#define TIPOS_H

// Configs
#define STACK_SIZE 1000 ///< Constante que define o tamanho da stack

/////////////////// TIPOS ///////////////////

/// Enum que facilita a leitura de codigo.
typedef enum {
    tLong,    // Valor 0
    tDouble,  // Valor 1
    tChar,    // Valor 2
    tStr      // Valor 3
} Enum_tipo;

/// União responsavel por oferecer á stack varios tipos.
typedef union un {
    long l;         // Long
    double d;       // Double
    char c;         // Char
    char s[BUFSIZ]; // String
} Uniao_tipos;

/// Struct que define o tipo dos elementos da stack (Possuem uma união de tipos e um enum que indica o tipo do elemento)
typedef struct ru {
    Enum_tipo tipo;
    Uniao_tipos val;
} reuniao;

/// Struct da stack, constituido por um array que armazena os valores da stack e um apontador para o topo desta.
typedef struct stack {
    reuniao pilha [STACK_SIZE]; 
    int topo; 
} STACK;

/////////////////// INICIALIZAÇÃO DE FUNÇÕES ///////////////////

// Iniciar stack
STACK* nova();

// PUSH'S
void push (STACK *s,long x);
void push_double (STACK *s,double x);
void push_char (STACK *s,char x);
void push_string (STACK *s,char* x);

// POP'S
long pop (STACK *s);
double pop_double (STACK *s);
char pop_char (STACK *s);
char* pop_string (STACK *s);

// OUTROS
void handle (STACK *s,char *token);
int num (STACK *s,char *token);
int top_tipo (STACK *s);

// OPERAÇÕES
int soma (STACK *s,char *token);
int menos (STACK *s,char *token);
int mul (STACK *s,char *token);
int divide (STACK *s,char *token);
int resto (STACK *s,char *token);
int expo (STACK *s,char *token);
int incrementa (STACK *s,char *token);
int decrementa (STACK *s,char *token);

// BITWISE
int logica_and (STACK *s,char *token);
int logica_or (STACK *s,char *token);
int logica_xor (STACK *s,char *token);
int logica_not (STACK *s,char *token);

// OPERAÇÕES 2
int duplicar (STACK *s,char *token);
int rodar (STACK *s,char *token);
int pop_elem (STACK *s,char *token);
int trocar (STACK *s,char *token);
int copia (STACK *s,char *token);

// CONVERSÕES
int conv_int (STACK *s,char *token);
int conv_double (STACK *s,char *token);
int conv_char (STACK *s,char *token);
int ler (STACK *s, char *token);
int debugger (STACK *s, char *token);
// long binario(); Não implementado


#endif // TIPOS_H