#include <stdio.h>
#include "string.h"

void invertirFrase (char palabra[], int inicio, int fin){
    if (inicio < fin){
        char aux;
        aux= palabra[inicio];
        palabra[inicio]= palabra[fin];
        palabra[fin]=aux;
        invertirFrase(palabra, inicio+1, fin-1);
    }
}

int main() {

    char palabra[250];
    scanf("%s", palabra);
    int tam= strlen(palabra);
    tam--;

    invertirFrase( palabra,0,tam);

    printf("%s", palabra);

    return 0;
}
