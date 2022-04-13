#include <stdio.h>
#include <math.h>
// Função que transforma um numero decimal em binario

long binario (int x){
    long v = 0;
    long i=1 ;
    while (x >=1){
        v+= (x%2* i);
        x = x/2 ;
        i=i*10;
    }
    return v ;
}
//binario para decimal
int decimal (int x){


}
int main () {
    long f =999;
    //scanf("%d",&f);
    printf("%ld\n",binario (f));
}
//o que falta fazer :

//criar uma função qeu compara dois valores em binario .
// 1- meter ambos os valores numa array e com um for comparar se os valores (0 e 1 ) sao iguais .
