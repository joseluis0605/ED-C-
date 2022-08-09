#include <stdio.h>

int fibonacci (int veces, int sumador, int acumulador){
    //caso base
    if(veces==0){
        acumulador= acumulador+ sumador;
        printf("%d", acumulador);
        return acumulador;
    } else{

        return fibonacci(veces-1, acumulador, acumulador+ sumador);
    }
}

int main() {

    int numero;
    scanf("%d", &numero);

    fibonacci(numero, 1,0);



    return 0;
}
