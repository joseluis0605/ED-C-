#include <stdio.h>

//VAMOS A SUMAR LAS POSICIONES IMPARES DE UN ARRAY CON RECURSIVIDAD

int sumaImpares (int array[],int index, int acumulador){
    //caso base
    if (index==19){
        acumulador= acumulador + array[index];
        return acumulador;
    } else{
        //caso recursivo
        if(index%2 != 0){
            sumaImpares(array, index+1, acumulador+ array[index]);
        } else{
            sumaImpares(array, index+1, acumulador);
        }

    }
}


int main() {

    int array[20], acumulador= 0, indice= 0;
    for (int i = 0; i < 20; ++i) {
        scanf("%d", &array[i]);
    }

    printf("%d", sumaImpares(array,indice, acumulador));

    return 0;
}
