#include <stdio.h>

int invertirNumero (int numero, int acumulador){
    //caso base
    if (numero/10 == 0){
        acumulador= acumulador*10 + (numero%10);
        return acumulador;
    } else{
        int resto;
        resto= numero%10;
        acumulador= acumulador*10+ resto;
        invertirNumero(numero/10, acumulador);
    }
}


int main() {

    int numero;
    scanf("%d", &numero);

    printf("%d", invertirNumero(numero, 0));


    return 0;
}
