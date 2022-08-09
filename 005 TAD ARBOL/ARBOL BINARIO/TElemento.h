#ifndef TELEMENTO_H
#define TELEMENTO_H
#include <stdio.h>
#include <string.h>

typedef int TElemento;

void print (TElemento t);

void asignar(TElemento* copia, TElemento original);

int igual(TElemento uno, TElemento dos);

void crear(int n, TElemento* e);

int esMayor (TElemento a, TElemento b);
#endif


/*

typedef float TElemento;

void print (TElemento t);

void asignar(TElemento* copia, TElemento original);

void igual(TElemento* uno, TElemento* dos);

void crear(float f, TElemento* e); */