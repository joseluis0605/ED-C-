#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "binarySearchTree.h"


void CrearArbolBusquedaVacio(TBinarySearchTree* a){
    *a=NULL;
}
void DevolverRaizBusqueda(TBinarySearchTree a, TElemento* r){
    if (!esArbolBusquedaVacio(a)){
        asignar(r, a->info);
    }
}
void DevolverHijoIzquierdoBusqueda(TBinarySearchTree a, TBinarySearchTree* r){
    if (!esArbolBusquedaVacio(a)){
        *r= a->left;
    }
}
void DevolverHijoDerechoBusqueda(TBinarySearchTree e, TBinarySearchTree* r){
    if (!esArbolBusquedaVacio(e)){
        *r =e->right;
    }
}
void destruirArbolBusqueda(TBinarySearchTree* a){
    if (!esArbolBusquedaVacio(*a)){
        destruirArbolBusqueda(&(*a)->left);
        destruirArbolBusqueda(&(*a)->right);
        free(*a);
        *a= NULL;
    }
}
void copiarArbolBusqueda(TBinarySearchTree original, TBinarySearchTree* copia){
    if (esArbolBusquedaVacio(original)){
        CrearArbolBusquedaVacio(copia);
    } else{
        //Vamos a construir el arbol de abajo a arriba
        //para ello, vamos a almacenar en dos punteros el arbol por izquierda y por derecha
        //esto es a donde va a apuntar el nuevo nodo
        TBinarySearchTree arbolDerecho, arbolIzquierda;
        //nos vamos para abajo
        copiarArbolBusqueda(original->left, &arbolIzquierda);
        copiarArbolBusqueda(original->right, &arbolDerecho);
        TBinarySearchTree nuevo= malloc(sizeof (TNodeSearchTree));
        nuevo->left= arbolIzquierda;
        nuevo->right= arbolDerecho;
        asignar(&nuevo->info, original->info);
        *copia= nuevo;
    }
}
int  esArbolBusquedaVacio(TBinarySearchTree a){
    return a==NULL;
}

//FUNCIONES ADICIONALES//
int numeroNodos(TBinarySearchTree a){
    //caso base
    if (esArbolBusquedaVacio(a)){
        return 0;
    } else{
        return 1 + numeroNodos(a->left) + numeroNodos(a->right);
    }
}
int numeroHojas(TBinarySearchTree a){
    if (esArbolBusquedaVacio(a)){
        return 0;
    } else{
        if (a->left==NULL && a->right==NULL){
            return 1;
        } else{
            return numeroHojas(a->left) + numeroHojas(a->right);
        }
    }
}
int altura(TBinarySearchTree a){
    if (esArbolBusquedaVacio(a)){
        return 0;
    } else{
        int alturaDerecha = altura(a->right);
        int alturaIzquierda= altura(a->left);
        if (alturaDerecha > alturaIzquierda){
            return 1 + alturaDerecha;
        } else{
            return 1 + alturaIzquierda;
        }
    }
}
void preorden(TBinarySearchTree a, TLinkedList* r){
    //RID
    if (!esArbolBusquedaVacio(a)){
        print(a->info);
        insertar(a->info,r);
        preorden(a->left,r);
        preorden(a->right,r);
    }
}
void inorden(TBinarySearchTree a, TLinkedList* r){
    if (!esArbolBusquedaVacio(a)){
        //IRD
        inorden(a->left,r);
        print(a->info);
        inorden(a->right, r);
    }
}
void postorden(TBinarySearchTree a, TLinkedList* r){
    if (!esArbolBusquedaVacio(a)){
        //IDR
        postorden(a->left,r);
        postorden(a->right,r);
        print(a->info);
    }
}
//FIN FUNCIONES ADICIONALES//


//PROPIAS DEL TAD ABB
int contieneArbolBinarioBusqueda(TBinarySearchTree a,TElemento e){
    if (esArbolBusquedaVacio(a)){
        return 0;
    } else{
        if (igual(&a->info,&e)){
            printf("ENCONTRADO");
            return 1;
        } else if (esMayor(a->info, e)){
            contieneArbolBinarioBusqueda(a->left,e);
        } else{
            contieneArbolBinarioBusqueda(a->right,e);
        }
    }
}
void insertarArbolBusqueda(TBinarySearchTree* a,TElemento e){
    if (esArbolBusquedaVacio(*a)){
        TBinarySearchTree nuevo= (TNodeSearchTree*) malloc(sizeof (TNodeSearchTree));
        asignar(&(nuevo->info),e);
        nuevo->right=NULL;
        nuevo->left=NULL;
        *a= nuevo;
    } else{
        if (esMayor((*a)->info,e)){
            insertarArbolBusqueda(&(*a)->left,e);
        } else{
            insertarArbolBusqueda(&(*a)->right,e);
        }
    }
}
void eliminarArbolBusqueda(TBinarySearchTree* a,TElemento e){
    if (!esArbolBusquedaVacio(*a)){
        //si lo hemos encontrado
        if (igual(&(*a)->info, &e)){
            //si es un nodo hoja
            if ((*a)->right==NULL && (*a)->left==NULL){
                free(a);
                *a=NULL;
            } else if ((*a)->left!=NULL && (*a)->right==NULL){
                //si tiene un hijo por la izquierda
                TBinarySearchTree paux= *a;
                (*a)= paux->left;
                free(paux);
            } else if ((*a)->left==NULL && (*a)->right!=NULL){
                    //si tiene un hijo solo por la derecha
                    TBinarySearchTree paux= *a;
                    (*a)=paux->right;
                    free(paux);
            } else{
                //si tiene dos hijos, vamos a coger el menor de los mayores o el mayor de los menores
                //lo sustituimos
                //eliminamos el otro

                //COGEMOS EL MAYOR DE LOS MENORES
                TElemento mayores;
                mayorNodo(&mayores, (*a)->left);
                asignar(&(*a)->info, mayores);
                eliminarArbolBusqueda(&(*a)->left, mayores);
            }
        } else{
            //buscamos
            if (esMayor((*a)->info, e)){
                eliminarArbolBusqueda(&(*a)->left,e);
            }else{
                eliminarArbolBusqueda(&(*a)->right,e);
            }
        }
    }
}
void mayorNodo(TElemento * e, TBinarySearchTree a){
    if (!esArbolBusquedaVacio(a)){
        while (a->right!=NULL){
            a= a->right;
        }
        printf("EL MAYOR ES:\n");
        print(a->info);
        asignar(e, a->info);
    }
}
void menorNodo(TElemento * e, TBinarySearchTree a){
    if (!esArbolBusquedaVacio(a)){
        while (a->left!=NULL){
            a= a->left;
        }
        printf("EL MENOR ES:\n");
        print(a->info);
        asignar(e, a->info);
    }
}

//consideramos que la lista esta inicializada

void ascendientes (TBinarySearchTree* a, TElemento* e, TLinkedList * r){
    if (*a != NULL){
        //caso base
        if (igual(&(*a)->info, e)){
            //si es igual, quiere decir que lo hemos encontrado
            insertarFinal((*a)->info, r);
        } else if ((*a)->right==NULL && (*a)->left==NULL){
            //significa que no lo hemos encontrado y hemos llegado a un nodo hoja, destruimos lista
            destruir(r);
        }else{
            //casos recursivos
            if (esMayor((*a)->info, *e)){
                //esta por la izquierda, insertamos el nodo y seguimos buscando el elemento por la izquierda
                insertarFinal((*a)->info, r);
                ascendientes(&(*a)->left, e,r);
            } else{
                //esta por la derecha, insertamos el nod y seguimos buscando el elemento por la derecha
                insertarFinal((*a)->info, r);
                ascendientes(&(*a)->right, e,r);
            }
        }
    }
}