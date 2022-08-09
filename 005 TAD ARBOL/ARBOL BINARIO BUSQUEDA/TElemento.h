#ifndef TELEMENTO_H
#define TELEMENTO_H
#include <stdio.h>
#include <string.h>

typedef struct TAlumno{
     char nombre [20];
     char dni[10];
     float notaMedia;
}TElemento;

void print (TElemento t);

void asignar(TElemento* copia, TElemento original);

int igual(TElemento* uno, TElemento* dos);

void crear(char* n, char* d, float nt, TElemento* e);

int esMayor(TElemento lhs, TElemento rhs);

#endif
/*

typedef float TElemento;

void print (TElemento t);

void asignar(TElemento* copia, TElemento original);

void igual(TElemento* uno, TElemento* dos);

void crear(float f, TElemento* e); */