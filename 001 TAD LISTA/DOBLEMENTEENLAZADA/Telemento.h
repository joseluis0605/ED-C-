//
// Created by José Luis on 18/03/2022.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int TElemento;

void crearElemento(TElemento* e, int i);
void mostrarElemento(TElemento* e);
void asignarElemento(TElemento* orig, TElemento* dest);
int igualesElemento(TElemento* e1, TElemento* e2);
void suma(TElemento e1, TElemento e2, TElemento *resultado);
int esMenor (TElemento e1, TElemento e2);