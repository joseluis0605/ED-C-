#include <stdio.h>

int sumacifras(int numero, int acumulador){
    //caso base
    if(numero/10 == 0){
        acumulador= acumulador+ (numero%10);
        printf("%d", acumulador);
        return acumulador;
    } else{
        //caso recursivo
        int resto;
        resto= numero%10;
        acumulador= acumulador+ resto;
        sumacifras(numero/10, acumulador);
    }
}

int main() {

    int numero;
    scanf("%d", &numero);

    sumacifras(numero, 0);

    return 0;
}
