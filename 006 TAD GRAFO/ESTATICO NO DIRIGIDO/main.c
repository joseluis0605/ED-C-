#include <stdio.h>
#include <stdlib.h>
#include "integerMatrixGraph.h"


int main(){
    TMGraph g;
    crearGrafoVacio(&g);
    TLinkedList lista;
    arrayList listaAux;

    insertarVertice(1,&g);
    insertarVertice(6,&g);
    insertarVertice(0,&g);
    insertarVertice(4,&g);
    insertarVertice(8,&g);
    insertarVertice(5,&g);
    insertarArista(1,6,&g);
    insertarArista(1,8,&g);
    insertarArista(1,4,&g);
    insertarArista(8,6,&g);
    insertarArista(4,6,&g);
    insertarArista(5,6,&g);
    insertarArista(5,8,&g);
    insertarArista(4,0,&g);
    insertarArista(40,50,&g);

    crearVacia (&lista);
    listaVertices(g,&lista); 
    mostrar(lista);


    crearVaciaA (&listaAux);
    listaAristas(g,&listaAux);
    mostrarA(listaAux);
}