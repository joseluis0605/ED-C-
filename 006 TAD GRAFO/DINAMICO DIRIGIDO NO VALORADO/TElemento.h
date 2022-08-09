#include <stdio.h>
#include <string.h>


typedef int TElemento;

void print (TElemento t);

void asignar(TElemento* copia, TElemento original);

int igual(TElemento* uno, TElemento* dos);

void crear(int i, TElemento* e); 

int esMayor(TElemento* lhs, TElemento* rhs);