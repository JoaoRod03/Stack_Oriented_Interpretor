TEIKIRIZE
#0348

TEIKIRIZE — 03/11/2021
Jota — 03/11/2021
paneleiro
TEIKIRIZE — 03/11/2021
ja aceitei vou so vestir e buscar a camisola ao carro e ligo
5 min tou ai
tou com vontade de cagar mas tou com pouco tempo sera que consigo fazer a ficha e tar vchamada no pc enquanto cago
Jota — 03/11/2021
n
tamos fudidos
n sabemos nada
TEIKIRIZE — 03/11/2021
e 12
pensa  que em 3 so conta os dois melhores
Jota — 03/11/2021
fudeu a mesma
anda mase chamada
TEIKIRIZE — 03/11/2021
ok deixa por fones qq barulho e so um cagalhao
vou entrar tipo 15 h 53
deixa ver se acabo de cagar fast
e melhor numa secretaria
atende
TEIKIRIZE
 iniciou uma chamada que durou 21 minutos.
 — 03/11/2021
Jota — 08/11/2021
rapido
caralho
fsd
asfdbjklsdfmnhnsdklfjg
TEIKIRIZE — 08/11/2021
cona
https://github.com/RisingFisan/Programacao-Funcional/blob/master/50questoes.hs
GitHub
Programacao-Funcional/50questoes.hs at master · RisingFisan/Program...
Contém todas as fichas relativas à cadeira de Programação Funcional, do ano letivo 2018/19, e resoluções de testes e exames de anos anteriores. - Programacao-Funcional/50questoes.hs at master · Ris...
Programacao-Funcional/50questoes.hs at master · RisingFisan/Program...
Jota — 08/11/2021
no uc
TEIKIRIZE
 iniciou uma chamada que durou poucos segundos.
 — 08/11/2021
Jota — 25/11/2021
https://discord.gg/98gcDntB
Jota — 14/01/2022
https://discord.gg/AKV9ZDHf
TEIKIRIZE — 20/01/2022
tas a fazer o quê bio
boi
Jota — 20/01/2022
LI
PQ?
TEIKIRIZE
 iniciou uma chamada que durou 3 minutos.
 — 18/02/2022
Jota — 18/02/2022
https://discord.gg/zVRFbjuD
TEIKIRIZE
 iniciou uma chamada que durou 29 minutos.
 — 19/04/2022
Jota
 iniciou uma chamada que durou uma hora.
 — 20/04/2022
Jota — 20/04/2022
https://discord.gg/9zDeNyBa
TEIKIRIZE — Hoje às 10:57
/**
* @file tipos.h
* Contém o struct stack e inicializa as funções
*/

#ifndef TIPOS_H
Expandir
message.txt
5 KB
﻿
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
void push (STACK *s,long x); /// Função que insere um elemento do tipo long no topo da stack. 
void push_double (STACK *s,double x);/// Função que insere um elemento do tipo double no topo da stack.
void push_char (STACK *s,char x);/// Função que insere um elemento do tipo char no topo da stack. 
void push_string (STACK *s,char* x);/// Função que insere um elemento do tipo string no topo da stack. 

// POP'S
long pop (STACK *s);/// Função que retira o elemento do tipo long que se encontra no topo da stack.
double pop_double (STACK *s);/// Função que retira o elemento do tipo double que se encontra no topo da stack.
char pop_char (STACK *s);/// Função que retira o elemento do tipo char que se encontra no topo da stack.
char* pop_string (STACK *s);/// Função que retira o elemento do tipo string que se encontra no topo da stack.

// OUTROS
void handle (STACK *s,char *token);/// decide que função irá ser usada
int num (STACK *s,char *token);/// Função que trata dos tokens não reconhecidos e constantes, verifica o tipo do token e atribui uma operação.
int top_tipo (STACK *s);/// Devolve o tipo do topo da stack

// OPERAÇÕES
int soma (STACK *s,char *token);/// Função que soma dois elementos da stack e coloca o resultado no topo desta.
int menos (STACK *s,char *token);/// Função que subtrai dois elementos da stack e coloca o resultado no topo desta.
int mul (STACK *s,char *token);/// Função que multiplica dois elementos da stack e coloca o resultado no topo desta.
int divide (STACK *s,char *token);/// Função que divide dois elementos da stack e coloca o resultado no topo desta.
int resto (STACK *s,char *token);/// Função que calcula o resto da divisao de dois elementos da stack e coloca o resultado no topo desta.
int expo (STACK *s,char *token);/// Calcula o resultado de elevar um elemento da stack a outro, coloca o resultado no topo da stack.
int incrementa (STACK *s,char *token);/// Incrementa o valor de um elemento da stack em 1 valor.
int decrementa (STACK *s,char *token);/// Decrementa o valor de um elemento da stack em 1 valor.

// BITWISE
int logica_and (STACK *s,char *token);/// Realiza a operação (and / &) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_or (STACK *s,char *token);/// Realiza a operação (or / |) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_xor (STACK *s,char *token);/// Realiza a operação (xor / ^) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.
int logica_not (STACK *s,char *token);/// Realiza a operação (not / ~) ao nivel binario entre dois elementos da stack, coloca o resultado final nesta.

// OPERAÇÕES 2
int duplicar (STACK *s,char *token);/// Duplica o elemento que se encontra no topo da stack. 
int rodar (STACK *s,char *token);/// Roda os 3 elementos no topo da stack (123 -> 231).
int pop_elem (STACK *s,char *token);/// Retira o elemento que se encontra no topo da stack.
int trocar (STACK *s,char *token);/// Troca os dois elementos do topo da stack
int copia (STACK *s,char *token);///  Copia n-ésimo elemento para o topo da stack. (n $)

// CONVERSÕES
int conv_int (STACK *s,char *token);/// Converte o topo da stack para int.
int conv_double (STACK *s,char *token);/// Converte o topo da stack para double.
int conv_char (STACK *s,char *token);/// Converte o topo da stack para char.
int ler (STACK *s, char *token);/// Função que lê input e insere o resultado desse input na stack.
int debugger (STACK *s, char *token);/// Função responsavel pelo debug do programa.
// long binario(); Não implementado


#endif // TIPOS_H