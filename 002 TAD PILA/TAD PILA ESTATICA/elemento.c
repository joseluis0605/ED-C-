#include "elemento.h"

void imprimir (TElemento t){ 
    printf("%f",t);
}

int sonIguales (TElemento e1, TElemento e2) {
    return (e1==e2);
}

void asignar (TElemento *e1, TElemento e2) {
    *e1=e2;
}
