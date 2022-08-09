#include <stdio.h>
#include <string.h>


typedef char TElemento;

void print (TElemento t);

void asignar(TElemento* copia, TElemento original);

int igual(TElemento* uno, TElemento* dos);

void crear(char i, TElemento* e);

//Traductor de Char a Posicion en el array del BooleanArraySet
int damePosicion (TElemento e);
//Traductor de Posicion al Char
void dameElemento (int posicion, TElemento *e);