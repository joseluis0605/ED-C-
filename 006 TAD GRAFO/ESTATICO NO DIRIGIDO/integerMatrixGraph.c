#include <stdio.h>
#include <stdlib.h>
#include "integerMatrixGraph.h"
// el arraylist lo vamos a usar para incluir las uniones
//el simplelinkedlist lo vamos a usar para incluir los vertices

void crearGrafoVacio (TMGraph* a){
    for (int i = 0; i < Dim; ++i) {
        a->nodes[i]=0;
    }
    for (int i = 0; i < Dim; ++i) {
        for (int j = 0; j < Dim; ++j) {
            a->matrix[i][j]=0;
        }
    }
}
void insertarVertice (int i, TMGraph* a){
    a->nodes[i]=1;
}
void insertarArista (int lhs,int rhs, TMGraph* a){
    a->nodes[lhs]=1;
    a->nodes[rhs]=1;
    a->matrix[lhs][rhs]=1;
    a->matrix[rhs][lhs]=1;
}
int eliminarVertice (int nodo, TMGraph* a){
    if (a->nodes[nodo]==1){
        for (int i = 0; i < Dim; ++i) {
            a->matrix[nodo][i]=0;
            a->matrix[i][nodo]=0;
        }
        a->nodes[nodo]=0;
        return 1;
    }
    return 0;
}
void eliminarArista (int lhs,int rhs, TMGraph* a){
    a->matrix[lhs][rhs]=0;
    a->matrix[rhs][lhs]=0;
}
int esAdyacente(int lhs,int rhs,TMGraph a){
    return a.matrix[lhs][rhs]==1;
}
int contieneVertice (int i, TMGraph a){
    return a.nodes[i]==1;
}
int esGrafoVacio (TMGraph a){
    int index= 0;
    int vacio= 1;
    while (index<Dim && vacio){
        if (a.nodes[index]==1){
            vacio=0;
        } else{
            index++;
        }
    }
    return vacio;
}



void listaVertices (TMGraph a, TLinkedList* l){
    //vamos a usar el Telemento destinado a los vertices, el cual va a contener un unico valor el Telemento
    crearVacia(l);
    for (int i = 0; i < Dim; ++i) {
        if (a.nodes[i]==1){
            TElemento nuevo;
            crear(i, &nuevo);
            insertarFinal(nuevo, l);
        }
    }
}
void listaAristas (TMGraph a,arrayList* l){
    crearVaciaA(l);
    for (int i = 0; i < Dim; ++i) {
        for (int j = i; j < Dim; ++j) {
            if (a.matrix[i][j]==1){
                TElemento1 nuevo;
                crear1(i, j, &nuevo);
                insertarFinalA(nuevo, l);
            }
        }
    }
}
void copiarG(TMGraph original, TMGraph* copia);
void destruirG(TMGraph* a);





