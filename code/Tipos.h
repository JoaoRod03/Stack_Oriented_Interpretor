/**
* @file tipos.h
* Contém o struct stack e inicializa as funções
*/

#ifndef TIPOS_H
#define TIPOS_H

// Configs
#define STACK_SIZE 20000 ///< Constante que define o tamanho da stack


/////////////////////////// TIPOS -> STRUCTS -> STACK ///////////////////////////
/// Enum que facilita a leitura de codigo.
typedef enum {
    tLong,    // Valor 0
    tDouble,  // Valor 1
    tChar,    // Valor 2
    tStr,     // Valor 3    
    tArr,     // Valor 4
    tBlc      // Valor 5 
} Enum_tipo;

/// União responsavel por oferecer á stack varios tipos.
typedef union un {
    long l;            // Long
    double d;          // Double
    char c;            // Char
    char* s;           // String e blocos
    struct stack *arr; // Array
} Uniao_tipos;

/// Struct que define o tipo dos elementos da stack (Possuem uma união de tipos e um enum que indica o tipo do elemento)
typedef struct ru {
    Enum_tipo tipo;
    Uniao_tipos val;
} tipos;

/// Struct da stack, constituido por um array que armazena os valores da stack e um apontador para o topo desta.
typedef struct stack {
    tipos pilha [STACK_SIZE];   // O array de tipos que guarda os valores da stack.
    tipos var [30];             // Array que guarda os valores das variáveis.
    int topo;                   // Indica onde se encontra o topo da stack.
} STACK;


/////////////////// INICIALIZAÇÃO DE FUNÇÕES ///////////////////
// ------------------- HANDLER.C -------------------
STACK* nova();      /// Função responsável por iniciar a stack.
void handle ();     /// Função responsavel por associar um token de um operador à sua função correspondente.
int num ();         /// Função que trata dos tokens não reconhecidos e constantes, verifica o tipo do token e atribui uma operação.
int top_tipo ();    /// Devolve o tipo do topo da stack.
int vars ();        /// Função que lida com as variáveis.
int vars2p ();      /// Função que lida com as atribuições das variáveis.
void printStack();  /// Função responsável para dar print à stack.
STACK* criarArray();/// Função responsável por criar a stack.
char* criarBloco(); /// Função responsável por criar um bloco.
void associaBloco();/// Função que associa um bloco.

// ------------------- FUNCOES.C -------------------
void push ();       /// Função que insere um elemento no topo da stack. 
tipos pop ();       /// Função que retira o elemento que se encontra no topo da stack.
int duplicar ();    /// Duplica o elemento que se encontra no topo da stack. 
int rodar ();       /// Roda os 3 elementos no topo da stack (123 -> 231).
int pop_elem ();    /// Retira o elemento que se encontra no topo da stack.
int trocar ();      /// Troca os dois elementos do topo da stack
int copia ();       /// Copia n-ésimo elemento para o topo da stack. (n $)
int ler ();         /// Função que lê input e insere o resultado desse input na stack.
int debugger ();    /// Função responsavel pelo debug do programa.

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

// ------------------- LOGICA.C -------------------
int mai (); 
int men ();         /// Função que se um valor for maior que o outro irá devolver 1 senão irá devolver 0.
int interroga();    /// Função que lê input e insere o resultado desse input na stack.
int igual ();
int nao ();
int maior ();       ///Função responsável por colocar o maior dos dois valores na stack.
int menor ();       ///Função responsável por colocar o menor dos dois valores na stack.
int conjuncao ();
int disjuncao ();

// ------------------- ARRAYS.C -------------------
void removeAspas();     ///Função responsável por remover as aspas.
int range ();           ///Função que devolve o tamanho do array ou string.
int input_all();
void concatenar();      ///Função responsável por concatenar strings e arrays.
void concatenar_mul();  ///Função responsável por concatenar strings e arrays várias vezes.
void remover_first();   ///Função utilizada para remover o primeiro caracter de uma string e para remover o primeiro elemento de um array.
void remover_last();    ///Função utilizada para remover o último caracter de uma string e para remover o último elemento de um array.
void buscar_indice();   ///Função que nas strings, vai buscar um caracter por índice e que nos arrays vai buscar um elemento por índice.
void buscar_inicio();   ///Função que nas strings, vai buscar x caracteres ao início e que nos arrays vai buscar x elementos ao início.
void buscar_fim();      ///Função que nas strings, vai buscar x caracteres ao fim e que nos arrays vai buscar x elementos ao fim.
void array_to_stack();  ///Função responsável para ir a um array e dar push de todos elmentos para a stack.
void sub_igual();
void substring();

// ------------------- STRINGS.C -------------------
void handle_string();   /// Função responsável pelo handle das strings inseridas pelo utilizador.
void string_1a();       /// Função reponsável tratar das strings com espaços. 
void string_2a();       /// Função que recebe uma string sem espaços e dá push desta para a stack/array correspondente.
void limpa();           /// Função que elemina os primeiros x elementos de uma string.
int aspas();            /// Função que dado um token devolve o numero de aspas que este possui.
int div_whitespace ();  /// Função que divide uma string por cada whitespace existente, colocando as strings entre estes num array.

// ------------------- BLOCOS.C -------------------
void executarBloco();  ///Funçao responsável para executar um bloco.
void blocoAplicar();   ///Função que aplica um bloco a um array ou string.
void fold();           ///Função que aplica um bloco a um array. 
void filter();         ///Função responsável por filtar um array.
#endif // TIPOS_H
