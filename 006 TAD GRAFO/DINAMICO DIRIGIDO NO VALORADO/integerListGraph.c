#include <stdio.h>
#include <stdlib.h>
#include "integerListGraph.h"

void crearGrafoVacio (TAdyacentGraph* a){
    *a=NULL;
}
void insertarVertice (TElemento e, TAdyacentGraph* a){
    if (!contieneVertice(e,*a)){
        TAdyacentGraph nuevo= malloc(sizeof (TnodoG));
        asignar(&nuevo->info, e);
        crearVacia(&nuevo->adyacentes);
        nuevo->sig= *a;
        (*a)=nuevo;
    }
}
void insertarArista (TElemento e1,TElemento e2, TAdyacentGraph* a){
    if (!esGrafoVacio(*a)){
        //buscamos el nodo
        insertarVertice(e1, a);
        insertarVertice(e2,a);
        int encontrado= 0;
        TAdyacentGraph paux= *a;
        while (paux!=NULL && !encontrado){
            encontrado= igual(&paux->info, &e1);
            if (encontrado==0){
                paux=paux->sig;
            }
        }
        //si lo hemos encontrado, vemos si no esta contenido, si no esta, insertamos
        if (encontrado){
            if (!contiene(e2, paux->adyacentes)){
                insertar(e2, &paux->adyacentes);
            }
        }
    }
}
int eliminarVertice (TElemento e, TAdyacentGraph* a){
    if (!esGrafoVacio(*a)){
        if (contieneVertice(e,*a)){
            TAdyacentGraph paux= *a;
            //eliminamos todos los elementos de las listas de adyacencia
            while (paux!=NULL){
                eliminar(e, &paux->adyacentes);
                paux= paux->sig;
            }

            //una vez eliminados todas las aristas, borramos el vertice
            TAdyacentGraph pant= NULL;
            paux= *a;
            int encontrado=0;
            while (paux!=NULL && !encontrado){
                encontrado= igual(&paux->info,&e);
                if (encontrado==0){
                    pant= paux;
                    paux=paux->sig;
                }
            }

            //si hemos encontrado el vertice
            if (encontrado){
                //si es el primero
                if (pant==NULL){
                    *a= paux->sig;
                    free(paux);
                } else{
                    pant->sig=paux->sig;
                    free(paux);
                }
            }
        }
    }
}
void eliminarArista (TElemento e1,TElemento e2, TAdyacentGraph* a){
    if (!esGrafoVacio(*a)){
        //buscamos el nodo primero
        int encontrado= 0;
        TAdyacentGraph paux= *a;
        while (paux!=NULL && !encontrado){
            encontrado= igual(&paux->info, &e1);
            if (!encontrado){
                paux=paux->sig;
            }
        }
        //si lo hemos encontrado
        if (encontrado){
            eliminar(e2, &paux->adyacentes);
        }
    }
}
int esAdyacente(TElemento e1,TElemento e2,TAdyacentGraph a){
    if (!esGrafoVacio(a)){
        //buscamos el primer elemento
        TAdyacentGraph paux= a;
        int encontrado= 0, adyacente= 0;
        while (paux!=NULL && !encontrado){
            encontrado= igual(&paux->info, &e1);
            if (encontrado==0){
                paux=paux->sig;
            } else{
                adyacente= contiene(e2, paux->adyacentes);
            }
        }
        return adyacente;
    }
    return 0;
}
int contieneVertice (TElemento e, TAdyacentGraph a){
    if (!esGrafoVacio(a)){
        int encontrado= 0;
        TAdyacentGraph paux= a;
        while (paux!=NULL && !encontrado){
            encontrado= igual(&paux->info, &e);
            if (encontrado==0){
                paux=paux->sig;
            }
        }
        return encontrado;
    }
    return 0;
}
int esGrafoVacio (TAdyacentGraph a){
    return a==NULL;
}
void listaVertices (TAdyacentGraph a, TLinkedList* l){
    if (!esGrafoVacio(a)){
        crearVacia(l);
        TAdyacentGraph paux= a;
        while (paux!=NULL){
            insertar(paux->info, l);
            paux= paux->sig;
        }
    }
}
void listaAristas (TAdyacentGraph a, arrayList* l){
    if (!esGrafoVacio(a)){
        crearVaciaA(l);
        TAdyacentGraph paux= a;
        while (paux!=NULL){
            TLinkedList nuevo;
            copiar(paux->adyacentes, &nuevo);
            while (!esVacia(nuevo)){
                TElemento aux;
                primero(nuevo, &aux);
                resto(&nuevo);
                TElemento1 nuevaArista;
                crear1(paux->info, aux, &nuevaArista);
                insertarFinalA(nuevaArista, l);
            }
            paux= paux->sig;
        }
    }
}
void copiarG(TAdyacentGraph original, TAdyacentGraph* copia){
    if (!esGrafoVacio(original)){
        TAdyacentGraph paux= original;

        while (paux!=NULL){
            TLinkedList nuevaLista;
            crearVacia(&nuevaLista);
            copiar(paux->adyacentes, &nuevaLista);
            insertarVertice(paux->info, copia);
            (*copia)->adyacentes= nuevaLista;
            paux= paux->sig;
        }
    }
}
void destruirG(TAdyacentGraph* a){
    if (!esGrafoVacio(*a)){
        TAdyacentGraph paux= *a;
        while (paux!=NULL){
            destruir(&paux->adyacentes);
            paux= paux->sig;
        }

        paux=*a;
        while (!esGrafoVacio(*a)){
            *a= paux->sig;
            free(paux);
            paux=*a;
        }
    }
}

int gradoEntradaNodo (TAdyacentGraph a, TElemento nodo);
int gradoSalidaNodo (TAdyacentGraph a, TElemento nodo);