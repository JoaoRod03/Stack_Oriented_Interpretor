/**
* @file tipos.h
* Contém o struct stack e inicializa as funções
*/

#ifndef TIPOS_H
#define TIPOS_H

// Configs
#define STACK_SIZE 1000 ///< Constante que define o tamanho da stack


/////////////////////////// TIPOS -> STRUCTS -> STACK ///////////////////////////
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
    struct stack *arr; // Array
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
} STACK;


/////////////////// INICIALIZAÇÃO DE FUNÇÕES ///////////////////
// ------------------- HANDLER.C -------------------
STACK* nova();      /// Função responsável por iniciar a stack
void handle ();     /// Função responsavel por associar um token de um operador á sua função correspondente.
int num ();         /// Função que trata dos tokens não reconhecidos e constantes, verifica o tipo do token e atribui uma operação.
int top_tipo ();    /// Devolve o tipo do topo da stack
int vars ();
int vars2p ();
void printStack();
STACK* criarArray();


// ------------------- FUNCOES.C -------------------
void push ();       /// Função que insere um elemento no topo da stack. 
tipos pop ();       /// Função que retira o elemento que se encontra no topo da stack.
int duplicar ();    /// Duplica o elemento que se encontra no topo da stack. 
int rodar ();       /// Roda os 3 elementos no topo da stack (123 -> 231).
int pop_elem ();    /// Retira o elemento que se encontra no topo da stack.
int trocar ();      /// Troca os dois elementos do topo da stack
int copia ();       ///  Copia n-ésimo elemento para o topo da stack. (n $)


// ------------------- OPERACOES.C -------------------
int soma ();        /// Função que soma dois elementos da stack e coloca o resultado no topo desta.
int menos ();       /// Função que subtrai dois elementos da stack e coloca o resultado no topo desta.
int mul ();         /// Função que multiplica dois elementos da stack e coloca o resultado no topo desta.
int divide ();      /// Função que divide dois elementos da stack e coloca o resultado no topo desta.
int resto ();       /// Função que calcula o resto da divisao de dois elementos da stack e coloca o resultado no topo desta.
int expo ();        /// Calcula o resultado de elevar um elemento da stack a outro, coloca o resultado no topo da stack.
int incrementa ();  /// Incrementa o valor de um elemento da stack em 1 valor.
int decrementa ();  /// Decrementa o valor de um elemento da stack em 1 valor.


// ------------------- BITWIZE.C -------------------
int bitwize_and ();  /// Realiza a operação (and / &) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int bitwize_or ();   /// Realiza a operação (or / |) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int bitwize_xor ();  /// Realiza a operação (xor / ^) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int bitwize_not ();  /// Realiza a operação (not / ~) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.


// ------------------- CONVERSOES.C -------------------
int conv_int ();    /// Converte o topo da stack para int.
int conv_double (); /// Converte o topo da stack para double.
int conv_char ();   /// Converte o topo da stack para char.


int ler ();         /// Função que lê input e insere o resultado desse input na stack.
int debugger ();    /// Função responsavel pelo debug do programa.

// ------------------- LOGICA.C -------------------
int mai (); 
int men ();
int interroga();
int igual ();
int nao ();
int maior ();
int menor ();
int conjuncao ();
int disjuncao ();

// ------------------- ARRAYS.C -------------------
int strings ();
int range ();
int input_all();

#endif // TIPOS_H
