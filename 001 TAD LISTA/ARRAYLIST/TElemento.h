//
// Created by José Luis on 22/02/2022.
//

#ifndef ARRAYLIST_TELEMENTO_H
#define ARRAYLIST_TELEMENTO_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef int TElemento;

void crearElemento(TElemento* e, int i);
void mostrarElemento(TElemento* e);
void asignarElemento(TElemento* orig, TElemento* dest);
int igualesElemento(TElemento* e1, TElemento* e2);

#endif //ARRAYLIST_TELEMENTO_H
