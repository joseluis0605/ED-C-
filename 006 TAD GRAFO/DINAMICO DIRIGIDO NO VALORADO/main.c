#include <stdio.h>
#include <stdlib.h>
#include "integerListGraph.h"
/*int gradoSalidaNodoPrincipal (TAdyacentGraph a, TElemento nodo){
    TLinkedList listaNodos;
    int cont=0;
    listaVertices (a, &listaNodos);
    while (!esVacia (listaNodos)) {
        TElemento n;
        primero (listaNodos, &n);
        eliminar (n, &listaNodos);
        if (esAdyacente (nodo, n, a)) {
            cont++;
        }
    }
    return cont;
}
*/
int main(){
    TAdyacentGraph g, copiado;
    crearGrafoVacio(&g);
    crearGrafoVacio(&copiado);

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

    printf("esta contenido el 5: %d\n", contieneVertice(5, g));
    printf("esta contenido el 1: %d\n", contieneVertice(1, g));
    printf("esta contenido el 0: %d\n", contieneVertice(0, g));
    printf("esta contenido el 4: %d\n", contieneVertice(4, g));
    printf("esta contenido el 8: %d\n", contieneVertice(8, g));
    printf("esta contenido el 57: %d\n", contieneVertice(57, g));
    printf("esta contenido el 50: %d\n", contieneVertice(50, g));
    printf("esta contenido el 40: %d\n", contieneVertice(40, g));

    printf("es adyacente: %d\n", esAdyacente(5,8, g));
    printf("es adyacente: %d\n", esAdyacente(8,5, g));
    printf("es adyacente: %d\n", esAdyacente(50,40, g));
    printf("es adyacente: %d\n", esAdyacente(40,50, g));




    crearVacia (&lista);
     listaVertices(g,&lista);
     mostrar(lista);


     crearVaciaA (&listaAux);
     listaAristas(g,&listaAux);
     mostrarA(listaAux);

    printf("copiamos el grafo\n");

    copiarG(g, &copiado);

    crearVacia (&lista);
    listaVertices(copiado,&lista);
    mostrar(lista);


    crearVaciaA (&listaAux);
    listaAristas(copiado,&listaAux);
    mostrarA(listaAux);
}