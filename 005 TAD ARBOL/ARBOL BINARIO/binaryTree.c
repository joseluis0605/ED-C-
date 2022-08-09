#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

void CrearArbolVacio(TBinaryTree* a){
    *a=NULL;
}
void CrearArbol(TBinaryTree* a,TBinaryTree izq,TBinaryTree der,TElemento e){
    TBinaryTree nuevo= malloc(sizeof (TNodeTree));
    nuevo->left=izq;
    nuevo->right=der;
    asignar(&nuevo->info,e);
    *a= nuevo;
}

void DevolverRaiz(TBinaryTree a, TElemento* r){
    if (!esArbolVacio(a)){
        asignar(r, a->info);
    }
}
void DevolverHijoIzquierdo(TBinaryTree a, TBinaryTree* hIzq){
    if (!esArbolVacio(a)){
        *hIzq= a->left;
    }
}
void DevolverHijoDerecho(TBinaryTree a, TBinaryTree* hDer){
    if (!esArbolVacio(a)){
        *hDer= a->right;
    }
}

void destruirArbol(TBinaryTree* a){
    if (!esArbolVacio(*a)){
        destruirArbol(&(*a)->left);
        destruirArbol(&(*a)->right);
        TBinaryTree paux= *a;
        free(paux);
        *a=NULL;
    }
}
void copiarArbol(TBinaryTree original, TBinaryTree* copia){
    if (!esArbolVacio(original)){
        TBinaryTree derecho, izquierdo;
        copiarArbol(original->left, &izquierdo);
        copiarArbol(original->right, &derecho);
        TBinaryTree nuevo= malloc(sizeof (TNodeTree));
        asignar(&nuevo->info, original->info);
        nuevo->left=izquierdo;
        nuevo->right= derecho;
        *copia= nuevo;
    } else{
        CrearArbolVacio(copia);
    }
}
int  esArbolVacio(TBinaryTree a){
    return a==NULL;
}

//Las demás funciones son adicionales, no son las del TAD BinaryTree por defecto
int contieneArbolBinario(TBinaryTree a,TElemento e){
    if (esArbolVacio(a)){
        return 0;
    } else{
        if (igual(a->info, e)){
            return 1;
        } else{
            return contieneArbolBinario(a->left, e) || contieneArbolBinario(a->right, e);
        }
    }
}

int numeroNodos(TBinaryTree a){
    //caso base
    if (esArbolVacio(a)){
        return 0;
    } else{
        //retornamos la raiz mas lo que haya en ambas ramas
        return 1 + numeroNodos(a->left) + numeroNodos(a->right);
    }
}
int numeroHojas(TBinaryTree a){
    if (esArbolVacio(a)){
        return 0;
    } else{
        if (a->right==NULL && a->left==NULL){
            return 1;
        } else{
            return numeroHojas(a->left) + numeroHojas(a->right);
        }
    }
}
int altura(TBinaryTree a){
    if (esArbolVacio(a)){
        return 0;
    } else{
        int derecha= altura(a->right);
        int izquierda= altura(a->left);

        if (derecha > izquierda){
            return 1 + derecha;
        } else{
            return 1 + izquierda;
        }
    }
}
void imprimirPreorden (TBinaryTree a){
    if (!esArbolVacio(a)){
        print(a->info);
        imprimirPreorden(a->left);
        imprimirPreorden(a->right);
    }
}
void imprimirInorden (TBinaryTree a){
    if (!esArbolVacio(a)){
        imprimirInorden(a->left);
        print(a->info);
        imprimirInorden(a->right);
    }
}
void imprimirPostorden (TBinaryTree a){
    if (!esArbolVacio(a)){
        imprimirPostorden(a->left);
        imprimirPostorden(a->right);
        print(a->info);
    }
}
void preordenAux(TBinaryTree a, TLinkedList* r){
    if (!esArbolVacio(a)){
        insertar(a->info, r);
        preordenAux(a->left, r);
        preordenAux(a->right, r);
    }

}
void preorden(TBinaryTree a, TLinkedList* r){
    //R I D
    if (!esArbolVacio(a)){
        destruir(r);
        preordenAux(a,r);
    }
}
void inorden(TBinaryTree a, TLinkedList* r);
void postorden(TBinaryTree a, TLinkedList* r);

void imprimirNivel (TBinaryTree a, int nivel){
    if (!esArbolVacio(a)){
        if (nivel==1){
            print(a->info);
        }
        imprimirNivel(a->left, nivel-1);
        imprimirNivel(a->right, nivel-1);
    }
}
void dameListaNivelAux (TBinaryTree a, int nivel, TLinkedList* lista);
void dameListaNivel (TBinaryTree a, int nivel, TLinkedList* lista);
void imprimirNivelesImparesAux (TBinaryTree a, int nivel){
    if (!esArbolVacio(a)){
        if (nivel%2 != 0){
            print(a->info);
        }
        imprimirNivelesImparesAux(a->left, nivel+1);
        imprimirNivelesImparesAux(a->right, nivel+1);

    }
}
void imprimirNivelesParesAux (TBinaryTree a, int nivel){
    if (!esArbolVacio(a)){
        if (nivel%2 == 0){
            print(a->info);
        }
        imprimirNivelesParesAux(a->left, nivel+1);
        imprimirNivelesParesAux(a->right, nivel+1);

    }
}

//EJERCICIOS ADICIONALES

void imprimirHojas (TBinaryTree a){
    if (!esArbolVacio(a)){
        if (a->left==NULL && a->right==NULL){
            print(a->info);
        } else{
            imprimirHojas(a->left);
            imprimirHojas(a->right);
        }
    }
}
int esArbolPar (TBinaryTree a){
    //todos los nodos tengan dos hijos
    if (esArbolVacio(a)){
        return 1;
    } else if (a->left != NULL && a->right != NULL){
        return 1;
    } else if (a->left == NULL && a->right==NULL){
        return 1;
    }else if (a->left ==NULL || a->right==NULL){
            return 0;
    } else{
        return esArbolPar(a->left) && esArbolPar(a->right);
    }
}
int numeroNodosSoloDerechoVacio (TBinaryTree a){
    if (esArbolVacio(a)){
        return 0;
    } else{
        if (a->left!=NULL && a->right==NULL){
            return 1;
        } else{
            return numeroNodosSoloDerechoVacio(a->left) + numeroNodosSoloDerechoVacio(a->right);
        }
    }
}
int numeroNodosSoloIzquierdoVacio (TBinaryTree a){
    if (esArbolVacio(a)){
        return 0;
    } else{
        if (a->left==NULL && a->right!=NULL){
            return 1;
        } else{
            return numeroNodosSoloIzquierdoVacio(a->left) + numeroNodosSoloIzquierdoVacio(a->right);
        }
    }
}
void borrarHojas (TBinaryTree *a){
    if (!esArbolVacio(*a)){
        if ((*a)->right==NULL && (*a)->left==NULL){
            TBinaryTree paux= *a;
            free(paux);
            *a=NULL;
        } else{
            borrarHojas(&(*a)->left);
            borrarHojas(&(*a)->right);
        }
    }
}
void espejo (TBinaryTree a, TBinaryTree *esp){
    if (!esArbolVacio(a)){
        TBinaryTree derecho, izquierdo;
        espejo(a->left, &derecho);
        espejo(a->right, &izquierdo);
        TBinaryTree nuevo= malloc(sizeof (TNodeTree));
        asignar(&nuevo->info, a->info);
        nuevo->left=izquierdo;
        nuevo->right= derecho;
        *esp= nuevo;
    } else{
        CrearArbolVacio(esp);
    }
}
//REVISAR ESTA FUNCION Y DIBUJARLA EN UN FOLIO
int sonEspejo (TBinaryTree a, TBinaryTree b){
    if (esArbolVacio(a) && esArbolVacio(b)){
        return 1;
    } else if (esArbolVacio(a) || esArbolVacio(b)){
        return 0;
    } else{
        return igual(a->info, b->info) && sonEspejo(a->left, b->right) && sonEspejo(a->right, b->left);
    }
}
int sonIguales (TBinaryTree a, TBinaryTree b){
    if (esArbolVacio(a) && esArbolVacio(b)){
        return 1;
    } else if (esArbolVacio(a) || esArbolVacio(b)){
        return 0;
    } else{
        return igual(a->info, b->info) && sonIguales(a->left, b->left) && sonIguales(a->right, b->right);
    }
}
int esDegenerado (TBinaryTree a);
void minimoAux (TBinaryTree a, TElemento *min){
    if (!esArbolVacio(a)){
        minimoAux(a->left, min);
        minimoAux(a->right,min);
        TElemento posibleMax;
        asignar(&posibleMax, a->info);
        if (posibleMax< *min){
            asignar(min, posibleMax);
        }
    }
}
void minimo (TBinaryTree a, TElemento *min){
    if (!esArbolVacio(a)){
        *min= 99999;
        minimoAux(a, min);
    }
}
void mayorAux (TBinaryTree a, TElemento *max){
    if (!esArbolVacio(a)){
        mayorAux(a->left, max);
        mayorAux(a->right, max);
        TElemento posibleMax;
        asignar(&posibleMax, a->info);
        if (posibleMax > *max){
            asignar(max, posibleMax);
        }
    }
}
void mayor (TBinaryTree a, TElemento *max){
    if (!esArbolVacio(a)){
        *max= -9999;
        mayorAux(a, max);
    }
}
int esABB (TBinaryTree a){
    if (esArbolVacio(a)){
        return 1;
    } else{
        if (a->left!=NULL){
            TElemento nuevo;
            mayor(a->left, &nuevo);
            if (esMayor(nuevo, a->info)){
                return 1;
            } else{
                return 0;
            }
        } else if (a->right !=NULL){
            TElemento nuevo;
            mayor(a->right, &nuevo);
            if (esMayor(nuevo, a->info)){
                return 1;
            } else{
                return 0;
            }
        } else{
            return 1 && esABB(a->left) && esABB(a->right);
        }
    }
}