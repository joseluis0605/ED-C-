//
// Created by José Luis on 18/03/2022.
//

#include "DoblePointed.h"

void crearListaVacia(TLista  *l){
    l->final=NULL;
    l->principio= NULL;
}
int esListaVacia(TLista* l){
    //con que uno de los dos apunte a NULL ya estaria vacia
    return (l->principio==NULL);
}
int longitudLista(TLista* l){
    if (!esListaVacia(l)){
        nodo paux= l->principio;
        int contador= 0;

        while (paux!=NULL){
            contador++;
            paux=paux->sig;
        }
        return contador;
    }
    return 0;

}
void primeroLista(TLista * l, TElemento* e){
    if (!esListaVacia(l)){
        asignarElemento(&l->principio->info, e);
    }
}
void restoLista(TLista* l){
    if (!esListaVacia(l)){
        nodo paux= l->principio;
        if(paux->sig==NULL){
            //si solo hay un elemento
            l->principio=NULL;
            l->final= NULL;
        } else{
            l->principio= paux->sig;
        }
        free(paux);
    }
}
void ultimoLista(TLista* l, TElemento* e){
    if (!esListaVacia(l)){
        asignarElemento(&l->final->info, e);
    }
}
void destruirLista(TLista* l){
    if (!esListaVacia(l)){
        while (!esListaVacia(l)){
            restoLista(l);
        }
    }
}
void mostrarLista(TLista * l){
    if (!esListaVacia(l)){
        nodo paux= l->principio;
        printf("[ ");

        while (paux!=NULL){
            mostrarElemento(&paux->info);
            printf(" ");
            paux= paux->sig;
        }
        printf("]\n");

    }
}
void insertarLista(TElemento* e, TLista * l){
    if(esListaVacia(l)){
        nodo nuevo= malloc(sizeof (nodo));
        asignarElemento(e, &nuevo->info);
        nuevo->sig= NULL;
        l->principio= nuevo;
        l->final= nuevo;
    } else{
        nodo nuevo= malloc(sizeof (nodo));
        asignarElemento(e, &nuevo->info);
        nuevo->sig= l->principio;
        l->principio= nuevo;
    }
}
void asignarLista(TLista* orig, TLista* dest){
    if (!esListaVacia(orig)){
        nodo paux= orig->principio;
        while (paux!=NULL){
            insertarFinalLista(&paux->info, dest);
            paux= paux->sig;
        }
    }
}
void insertarFinalLista(TElemento* e, TLista * l){
    if (esListaVacia(l)){
        insertarLista(e, l);
    } else {
        nodo nuevo= malloc(sizeof (nodo));
        asignarElemento(e, &nuevo->info);
        l->final->sig= nuevo;
        nuevo->sig= NULL;
        l->final= nuevo;
    }
}
int contieneLista(TElemento* e, TLista* l){
    if (!esListaVacia(l)){
        int encontrado= 0;
        nodo paux= l->principio;

        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(e, &paux->info);
            if (encontrado==0){
                paux= paux->sig;
            }
        }
        return encontrado;
    }
    return 0;
}
int eliminarLista(TElemento* e, TLista * l){
    if (!esListaVacia(l)){
        int encontrado= 0;
        nodo paux= l->principio;
        nodo pant= NULL;

        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(&paux->info, e);
            if(encontrado==0){
                pant=paux;
                paux= paux->sig;
            }
        }

        if (encontrado){
            if(pant==NULL){
                //si es el primero
                if (paux->sig==NULL){
                    //si es el unico elemento
                    l->principio=NULL;
                    l->final=NULL;
                } else{
                    //si es el primero pero no es el unico que hay
                    l->principio= paux->sig;
                }
            } else{
                //si no es el primero
                if(paux->sig==NULL){
                    //si es el ultimo
                    l->final=pant;
                    l->final->sig=NULL;
                } else{
                    //si es uno del medio normal
                    pant->sig=paux->sig;
                }
            }
            free(paux);
        }
        return encontrado;
    }
    return 0;
}
void concatenarLista(TLista* l1, TLista* l2){
    if (esListaVacia(l1)){
        asignarLista(l2, l1);
    } else{
        nodo paux= l2->principio;
        while (paux!=NULL){
            insertarFinalLista(&paux->info, l1);
            paux= paux->sig;
        }
    }
}

//ejericicos de examen
void unique (TLista *lista){
    if (!esListaVacia(lista)){
        nodo pant, pe;
        pant= lista->principio;
        pe= pant->sig;
        int iguales;
        while (pe !=NULL){
            pe= pant->sig;
            iguales= igualesElemento(&pant->info, &pe->info);
            if (iguales){
                //si son el ultimo
                if (pe->sig==NULL){
                    pant->sig= NULL;
                    lista->final=pant;
                } else{
                    pant->sig=pe->sig;
                }
                free(pe);
            } else{
                pant=pe;
                pe= pe->sig;
            }
            pe= pant->sig;
        }
    }
}
void borrarUltimo (TLista *lista){
    if (!esListaVacia(lista)){
        nodo paux= lista->principio;
        nodo pborrado= lista->final;

        while (paux->sig != pborrado){
            paux= paux->sig;
        }
        lista->final= paux;
        paux->sig=NULL;
        free(pborrado);
    }
}
void borrarNprimeros (TLista *lista, int n){
    if (!esListaVacia(lista)){
        if (n< longitudLista(lista)){
            for (int i = 0; i < n; ++i) {
                restoLista(lista);
            }
        } else if (n == longitudLista(lista)){
            destruirLista(lista);
        }
    }
}
void borrarCadaX (TLista *lista, int n){
    if (!esListaVacia(lista)){
        int tam= longitudLista(lista);
        TLista aux;
        crearListaVacia(&aux);
        nodo paux;
        paux= lista->principio;
        for (int i = 1; i <= tam; ++i) {
            if (i%n != 0){
                insertarFinalLista(&paux->info, &aux);
            }
            paux= paux->sig;
        }
        destruirLista(lista);
        *lista= aux;
    }
}
void insertarDespuesDe (TLista *lista, TElemento insertardespues, TElemento elemento){
    if (!esListaVacia(lista)){
        nodo paux= lista->principio;
        int encontrado= 0;
        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(&insertardespues, &paux->info);
            if (encontrado==0){
                paux= paux->sig;
            }
        }

        if (encontrado){
            nodo nuevo= malloc(sizeof (nodo));
            asignarElemento(&elemento, &nuevo->info);
            if (paux->sig==NULL){
                //si es el ultimo
                paux->sig= nuevo;
                nuevo->sig= NULL;
                lista->final= nuevo;
            } else{
                nuevo->sig=paux->sig;
                paux->sig= nuevo;
            }
        }
    }
}
void insertarOrdenado (TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        //esta ordenada de menor a mayor
        nodo paux = lista->principio;
        nodo pant= NULL;
        int encontrado= 0;
        while (paux!=NULL && !encontrado){
            encontrado= esMenor(elemento, paux->info);
            if (encontrado==0){
                pant= paux;
                paux=paux->sig;
            }
        }
        nodo nuevo= malloc(sizeof (nodo));
        asignarElemento(&elemento, &nuevo->info);
        if (encontrado){

            if (pant==NULL){
                //si es el primero
                nuevo->sig=paux;
                lista->principio=nuevo;
            } else{
                pant->sig=nuevo;
                nuevo->sig=paux;
            }
        } else{
            // lo insertamos al final
            nuevo->sig=NULL;
            if (pant!=NULL){
                pant->sig=nuevo;
            }
            lista->final=nuevo;
        }
    }
}
void vecesXelemento (TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        int esElMismo= 0;
        nodo paux= lista->principio;
        int contador=0;
        while (paux!=NULL){
            esElMismo= igualesElemento(&paux->info, &elemento);
            if (esElMismo){
                contador++;
            }
            paux=paux->sig;
        }
        printf("%d", contador);
    }
}
void sumarLista (TLista *lista){
    if (!esListaVacia(lista)){
        int contador= 0;
        nodo paux= lista->principio;
        while (paux!=NULL){
            contador= contador + paux->info;
            paux= paux->sig;
        }
        printf("%d", contador);
    }
}
void posfija (TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        nodo paux= lista->principio;
        int encontrado= 0;
        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(&paux->info, &elemento);
            if (encontrado==0){
                paux= paux->sig;
            }
        }
        if (paux!=NULL){
            paux= paux->sig;
        }
        if (encontrado){
            while (paux!=NULL){
                mostrarElemento(&paux->info);
                paux= paux->sig;
            }
        }
    }
}
void listaOrdenada (TLista *lista1, TLista *lista2){
    if (esListaVacia(lista1) && !esListaVacia(lista2)){
        TLista nueva;
        crearListaVacia(&nueva);
        asignarLista(lista2, &nueva);
        mostrarLista(&nueva);
    } else if (!esListaVacia(lista1) && esListaVacia(lista2)){
        TLista nueva;
        crearListaVacia(&nueva);
        asignarLista(lista1, &nueva);
        mostrarLista(&nueva);
    } else{
        nodo paux1, paux2;
        TLista nuevaLista, listaAux1, listaAux2;
        crearListaVacia(&nuevaLista);
        crearListaVacia(&listaAux1);
        crearListaVacia(&listaAux2);

        //copiamos
        asignarLista(lista1, &listaAux1);
        asignarLista(lista2, &listaAux2);

        while (!esListaVacia(&listaAux1) && !esListaVacia(&listaAux2)){
            TElemento elementoL1, elementoL2;
            primeroLista(&listaAux1, &elementoL1);
            primeroLista(&listaAux2, &elementoL2);

            if (esMenor(elementoL1, elementoL2)){
                restoLista(&listaAux1);
                insertarFinalLista(&elementoL1, &nuevaLista);
            } else{
                restoLista(&listaAux2);
                insertarFinalLista(&elementoL2, &nuevaLista);
            }
        }

        if(esListaVacia(lista1)){
            asignarLista(&listaAux2, &nuevaLista);
        } else{
            asignarLista(&listaAux1, &nuevaLista);

        }
        mostrarLista(&nuevaLista);
    }
}
void sumaAnteriores(TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        TElemento acumulador;
        crearElemento(&acumulador, 0);

        nodo paux= lista->principio;
        int encontrado= 0;
        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(&paux->info, &elemento);
            if (!encontrado){
                suma(paux->info, acumulador, &acumulador);
            }
            paux= paux->sig;
        }
        mostrarElemento(&acumulador);
    }
}
void criba (TLista *lista, int salto){
    //mostras elementos menos salto y multiplos de salto
    if (!esListaVacia(lista)){
        nodo paux= lista->principio;
        int tam= longitudLista(lista);
        for (int i = 1; i <= tam; ++i) {
            if (i%salto != 0){
                mostrarElemento(&paux->info);
            }
            paux= paux->sig;
        }
    }
}
