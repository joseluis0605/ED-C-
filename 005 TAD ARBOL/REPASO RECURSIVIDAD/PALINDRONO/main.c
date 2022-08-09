#include <stdio.h>
#include "string.h"

int palindrono (char palabra[], int igual, int inicio, int fin){
    if(igual==1 && inicio<fin){
        igual= palabra[inicio]==palabra[fin];
        return palindrono(palabra, igual, inicio + 1, fin - 1) && igual;
    }
}

int main() {

    char palabra[250];
    scanf("%s", palabra);

    int igual= 1;

    printf("%d", palindrono(palabra, igual, 0, strlen(palabra)-1));



    return 0;
}
