#include <stdio.h>
#include <string.h>


typedef struct Elemento1{
    int origen,destino;
}TElemento1;

void print1 (TElemento1 t);

void asignar1(TElemento1* copia, TElemento1 original);

int igual1(TElemento1* uno, TElemento1* dos);

void crear1(int o, int d, TElemento1* e); 

