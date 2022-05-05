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
    tStr,     // Valor 3
    tArr      // Valor 4     
} Enum_tipo;

/// União responsavel por oferecer á stack varios tipos.
typedef union un {
    long l;          // Long
    double d;        // Double
    char c;          // Char
    char* s;         // String
} Uniao_tipos;

/// Struct que define o tipo dos elementos da stack (Possuem uma união de tipos e um enum que indica o tipo do elemento)
typedef struct ru {
    Enum_tipo tipo;
    Uniao_tipos val;
} tipos;

/// Struct da stack, constituido por um array que armazena os valores da stack e um apontador para o topo desta.
typedef struct stack {
    tipos pilha [STACK_SIZE]; 
    tipos var [30];
    int topo;
    struct stack* next_stack;
    struct stack* prev_stack;
} STACK;

/////////////////// INICIALIZAÇÃO DE FUNÇÕES ///////////////////

// Iniciar stack
STACK* nova();

// PUSH e POP
void push (STACK *s,tipos x); /// Função que insere um elemento no topo da stack. 
tipos pop (STACK *s); /// Função que retira o elemento que se encontra no topo da stack.

// OUTROS
void handle (STACK *s,char *token); // Função responsavel por associar um token de um operador á sua função correspondente.
int num (STACK *s,char *token); /// Função que trata dos tokens não reconhecidos e constantes, verifica o tipo do token e atribui uma operação.
int top_tipo (STACK *s); /// Devolve o tipo do topo da stack
int vars (STACK *s ,char *token);
int vars2p (STACK *s ,char *token);

// OPERAÇÕES
int soma (STACK *s,char *token); /// Função que soma dois elementos da stack e coloca o resultado no topo desta.
int menos (STACK *s,char *token); /// Função que subtrai dois elementos da stack e coloca o resultado no topo desta.
int mul (STACK *s,char *token); /// Função que multiplica dois elementos da stack e coloca o resultado no topo desta.
int divide (STACK *s,char *token); /// Função que divide dois elementos da stack e coloca o resultado no topo desta.
int resto (STACK *s,char *token); /// Função que calcula o resto da divisao de dois elementos da stack e coloca o resultado no topo desta.
int expo (STACK *s,char *token); /// Calcula o resultado de elevar um elemento da stack a outro, coloca o resultado no topo da stack.
int incrementa (STACK *s,char *token); /// Incrementa o valor de um elemento da stack em 1 valor.
int decrementa (STACK *s,char *token); /// Decrementa o valor de um elemento da stack em 1 valor.

// BITWISE
int logica_and (STACK *s,char *token); /// Realiza a operação (and / &) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_or (STACK *s,char *token); /// Realiza a operação (or / |) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_xor (STACK *s,char *token); /// Realiza a operação (xor / ^) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_not (STACK *s,char *token); /// Realiza a operação (not / ~) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.

// OPERAÇÕES 2
int duplicar (STACK *s,char *token); /// Duplica o elemento que se encontra no topo da stack. 
int rodar (STACK *s,char *token); /// Roda os 3 elementos no topo da stack (123 -> 231).
int pop_elem (STACK *s,char *token); /// Retira o elemento que se encontra no topo da stack.
int trocar (STACK *s,char *token); /// Troca os dois elementos do topo da stack
int copia (STACK *s,char *token); ///  Copia n-ésimo elemento para o topo da stack. (n $)

// CONVERSÕES
int conv_int (STACK *s,char *token); /// Converte o topo da stack para int.
int conv_double (STACK *s,char *token); /// Converte o topo da stack para double.
int conv_char (STACK *s,char *token); /// Converte o topo da stack para char.
int ler (STACK *s, char *token); /// Função que lê input e insere o resultado desse input na stack.
int debugger (STACK *s, char *token); /// Função responsavel pelo debug do programa.
int mai (STACK *s, char *token); 
int men (STACK *s, char *token);
int interroga(STACK *s, char *token);
int igual (STACK *s, char *token);
int nao (STACK *s, char *token);
int maior (STACK *s, char *token);
int menor (STACK *s, char *token);
int conjuncao (STACK *s, char *token);
int disjuncao (STACK *s, char *token);
int strings (STACK *s, char *token);
int range (STACK *s, char *token);
int array_start (STACK *s, char *token);
int array_end (STACK *s, char *token);
#endif // TIPOS_H

