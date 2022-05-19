/**
* @file Tipos.h
* Contém o struct stack e inicializa as funções.
*/

#ifndef TIPOS_H
#define TIPOS_H

// Configs
#define STACK_SIZE 20000 ///< Constante que define o tamanho da stack


//.///////////////////////// TIPOS -> STRUCTS -> STACK ///////////////////////////
/// Enum que facilita a leitura de codigo.
typedef enum {
    tLong,    ///< Equivalente ao valor 0
    tDouble,  ///< Equivalente ao valor 1 
    tChar,    ///< Equivalente ao valor 2   
    tStr,     ///< Equivalente ao valor 3    
    tArr,     ///< Equivalente ao valor 4   
    tBlc      ///< Equivalente ao valor 5   
} Enum_tipo;

/// União responsavel por oferecer á stack varios tipos.
typedef union un {
    long l;            ///< Tipo long da union 
    double d;          ///< Tipo double da union 
    char c;            ///< Tipo char da union 
    char* s;           ///< Tipo string/bloco da union 
    struct stack *arr; ///< Tipo array da union 
} Uniao_tipos;

/// Struct que define o tipo dos elementos da stack (Possuem uma união de tipos e um enum que indica o tipo do elemento)
typedef struct ru {
    Enum_tipo tipo;   ///< Enum que indica o tipo do elemento 
    Uniao_tipos val;  ///< Armazena o elemento da stack no campo da union 
} tipos;

/// Struct da stack, constituido por um array que armazena os valores da stack e um apontador para o topo desta.
typedef struct stack {
    tipos pilha [STACK_SIZE];   ///< O array de tipos que guarda os valores da stack. 
    tipos var [30];             ///< Array que guarda os valores das variáveis. 
    int topo;                   ///< Indica onde se encontra o topo da stack. 
} STACK;


/////////////////// INICIALIZAÇÃO DE FUNÇÕES ///////////////////
// ------------------- HANDLER.C -------------------
STACK* nova();       /// Função responsável por iniciar a stack.
void handle ();      /// Função responsavel por associar um token de um operador à sua função correspondente.
int num ();          /// Função que trata dos tokens não reconhecidos e constantes, verifica o tipo do token e atribui uma operação.
int top_tipo ();     /// Devolve o tipo do topo da stack.
STACK* criarArray(); /// Função responsável por criar a stack.
char* criarBloco();  /// Função responsável por criar um bloco.
void associaBloco(); /// Função que associa um bloco.
void printStack();   /// Função responsável para dar print à stack.
int vars ();         /// Função que lida com as variáveis.
int vars2p ();       /// Função que lida com as atribuições das variáveis.

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
int mai ();         /// Função que compara dois valores no topo da stack, sendo que se o primeiro é maior que o segundo devolve 1 senão devolve 0.
int men ();         /// Função que compara dois valores no topo da stack, sendo que se o primeiro é menor que o segundo devolve 1 senão devolve 0.
int interroga();    /// Função que lê input e insere o resultado desse input na stack.
int igual ();       /// Função que compara dois valores no topo da stack, sendo que se o primeiro é igual que o segundo devolve 1 senão devolve 0.
int nao ();         /// Função que dado um valor no topo da stack se este for diferente de 0 devolve 0 senão devolve 1.
int maior ();       /// Função responsável por colocar o maior dos dois valores na stack.
int menor ();       /// Função responsável por colocar o menor dos dois valores na stack.
int conjuncao ();   /// Função que da pop a dois valores no topo da stack, se um destes for zero coloca na stack o valor 0, senão coloca o segundo elemento.
int disjuncao ();   /// Função que da pop a dois valores no topo da stack, se ambos forem 0 devolve 0. Se apenas 1 dos elementos for 0 devolve o que não é nulo.

// ------------------- ARRAYS.C -------------------
void removeAspas();     /// Função responsável por remover as aspas.
int range ();           /// Função que dado um array ou string devolve o seu tamanho. Dado um long devolve um array ordenado sendo 0 o primeiro elemento e X o ultimo.
int input_all();        /// Função que se responsabiliza por receber várias linhas de input.
void concatenar();      /// Função responsável por concatenar strings e arrays.
void concatenar_mul();  /// Função responsável por concatenar strings e arrays várias vezes.
void remover_first();   /// Função utilizada para remover o primeiro caracter de uma string e para remover o primeiro elemento de um array.
void remover_last();    /// Função utilizada para remover o último caracter de uma string e para remover o último elemento de um array.
void buscar_indice();   /// Função que nas strings, vai buscar um caracter por índice e que nos arrays vai buscar um elemento por índice.
void buscar_inicio();   /// Função que nas strings, vai buscar x caracteres ao início e que nos arrays vai buscar x elementos ao início.
void buscar_fim();      /// Função que nas strings, vai buscar x caracteres ao fim e que nos arrays vai buscar x elementos ao fim.
void array_to_stack();  /// Função responsável para ir a um array e dar push de todos elmentos para a stack.
void sub_igual();       /// Função que dá pop a duas strings no topo da stack e devolve -1 se não encontrar a segunda na primeira. Caso contrario devolve o indice.
void substring();       /// Função que recebe duas strings divide a primeira string apartir de cada ocorrencia da segunda na primeira. O resultado de cada divisão é colocado em um array.

// ------------------- STRINGS.C -------------------
void handle_string();   /// Função responsável pelo handle das strings inseridas pelo utilizador.
void string_1a();       /// Função reponsável tratar das strings com espaços. 
void string_2a();       /// Função que recebe uma string sem espaços e dá push desta para a stack/array correspondente.
void limpa();           /// Função que elemina os primeiros x elementos de uma string.
int aspas();            /// Função que dado um token devolve o numero de aspas que este possui.
int div_whitespace ();  /// Função que divide uma string por cada whitespace existente, colocando as strings entre estes num array.
void concatenar_strings();  /// Continuação da função concatenar para strings.

// ------------------- BLOCOS.C -------------------
void executarBloco();  /// Funçao responsável para executar um bloco.
void blocoAplicar();   /// Função que aplica um bloco a um array ou string.
void fold();           /// Função que aplica um bloco a um array. 
void filter();         /// Função responsável por filtar um array.
#endif // TIPOS_H
