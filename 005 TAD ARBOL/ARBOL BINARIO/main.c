#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
/*
int numeroHojas(TBinaryTree a) {
    if (esArbolVacio(a)){
        return 0;
    }else {
        TBinaryTree hi;
        TBinaryTree hd;
        DevolverHijoIzquierdo (a, &hi);
        DevolverHijoDerecho (a, &hd);
        if (esArbolVacio(hi) && (esArbolVacio(hd))) {
            return 1;
        } else {
            return numeroHojas(hi) + numeroHojas(hd);
        }
    }
}*/


int main(){
    TElemento e1,e2,e3,e4,e5,e6,e7, nuevo;
    TBinaryTree a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11, arbolAux;
    TLinkedList preO;
    TLinkedList lista;


    crear(1,&e1);
    crear(2,&e2);
    crear(3,&e3);
    crear(4,&e4);
    crear(5,&e5);
    crear(6,&e6);
    crear(7,&e7);
    CrearArbolVacio(&a1);
    CrearArbolVacio(&a2);
    CrearArbolVacio(&a3);
    CrearArbolVacio(&a4);
    CrearArbolVacio(&a5);
    CrearArbolVacio(&a6);
    CrearArbolVacio(&arbolAux);
    CrearArbol(&a7,a1,a2,e1);
    CrearArbol(&a8,a3,a4,e2);
    CrearArbol(&a9,a8,a7,e3);
    CrearArbol(&a10,a9,a5,e4);
    CrearArbol(&a11,a6,a10,e5);



    printf("esta contenido el elemento: %d\n", contieneArbolBinario(a11, e1));
    printf("esta contenido el elemento: %d\n", contieneArbolBinario(a11, e2));
    printf("esta contenido el elemento: %d\n", contieneArbolBinario(a11, e3));
    printf("esta contenido el elemento: %d\n", contieneArbolBinario(a11, e4));
    printf("esta contenido el elemento: %d\n", contieneArbolBinario(a11, e5));
    printf("esta contenido el elemento: %d\n", contieneArbolBinario(a11, e6));
    printf("esta contenido el elemento: %d\n", contieneArbolBinario(a11, e7));


    printf("Numero de hojas %d\n",numeroHojas(a11));
    printf("Numero de nodos %d\n",numeroNodos(a11));
    printf("Altura %d\n",altura(a11));

    printf("preorden: ");
    imprimirPreorden(a11);
    printf("\ninorden: ");
    imprimirInorden(a11);
    printf("\npostorden: ");
    imprimirPostorden(a11);

    printf("\nimpimir nivel: ");
    imprimirNivel(a11, 1);
    printf("\n");
    imprimirNivel(a11, 2);
    printf("\n");
    imprimirNivel(a11, 3);
    printf("\n");
    imprimirNivel(a11, 4);
    printf("\n");

    printf("impimir nivel impar: ");
    imprimirNivelesImparesAux(a11, 1);
    printf("\n");

    printf("impimir nivel par: ");
    imprimirNivelesParesAux(a11, 1);
    printf("\n");

    printf("impimir hojas: ");
    imprimirHojas(a11);

    printf("\nes arbol par: %d\n", esArbolPar(a11));

    printf("numero nodos derecha vacio: %d\n", numeroNodosSoloDerechoVacio(a11));

    printf("numero nodos izquierda vacio: %d\n", numeroNodosSoloIzquierdoVacio(a11));

    /*printf("borrar hojas: ");
    borrarHojas(&a11);
    imprimirPreorden(a11);*/

    printf("\ncreamos arbol espejo: ");
    espejo(a11, &arbolAux);
    imprimirPreorden(arbolAux);

    printf("\nson espejos: %d", sonEspejo(a11, arbolAux));

   printf("\nson iguales: %d", sonIguales(a11, a11));

   printf("\nel minimo es: ");
   minimo(a11, &nuevo);
   print(nuevo);

    printf("\nel mayor es: ");
    mayor(a11, &nuevo);
    print(nuevo);

    printf("\nes ABB: %d: ", esABB(a11));

    /*printf("\nel mayor es: ");
    mayor(a11, &nuevo);
    print(nuevo);*/
return 0;
}