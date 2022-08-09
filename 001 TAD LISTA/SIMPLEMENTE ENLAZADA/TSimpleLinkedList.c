//
// Created by José Luis on 12/02/2022.
//
#include "stdio.h"
#include "stdlib.h"
#include "TSimpleLinkedList.h"


void inicializar (tlista *lista){
    *lista= NULL;
}
void insertarElemento (tlista *lista, int elemento){
    tlista nuevo= malloc(sizeof (struct nodo));
    nuevo->info= elemento;
    nuevo->sig= *lista;
    *lista= nuevo;
}
void mostrar (tlista *lista){
    if (!esVacia(lista)){
        tlista paux= *lista;
        printf("[");
        while (paux!=NULL){
            printf(" %d ", paux->info);
            paux= paux->sig;
        }
        printf("]");
    } else{
        printf("NO HAY ELEMENTOS");
    }
    printf("\n");
}
void eliminar (int elemento, tlista *lista){
    if(!esVacia(lista)){
        int encontrado= 0;
        tlista paux= *lista;
        tlista pant= NULL;
        while (paux!=NULL && !encontrado){
            encontrado= (paux->info==elemento);
            if(!encontrado){
                pant=paux;
                paux=paux->sig;
            }
        }
        if(encontrado){
            if(paux->sig==NULL){//si es el ultimo elemento
                pant->sig=NULL;
            } else if(pant==NULL){//si es el primero
                *lista= paux->sig;
            } else{
                pant->sig= paux->sig;
            }
            free(paux);
        }
    }

}
void copiar (tlista original, tlista *copia){
    if(!esVacia(&original)){
        *copia= NULL;
        tlista paux= original;
        while (paux!=NULL){
            insertarElemento(copia, paux->info);
            paux= paux->sig;
        }
    }
}
void destruir (tlista *lista){
    if(!esVacia(lista)){
        tlista paux= *lista;
        while (*lista!=NULL){
            *lista= paux->sig;
            free(paux);
            paux=*lista;
        }
    }
}
int contiene(int elemento, tlista lista){
    if (!esVacia(&lista)){
        int encontrado= 0;
        tlista paux= lista;
        while (paux!=NULL && !encontrado){
            if(paux->info==elemento){
                encontrado= 1;
                printf("ENCONTRADO\n");
            }
            paux=paux->sig;
        }
        if(!encontrado){
            printf("NO ENCONTRADO\n");
        }
        return encontrado;
    }
}
int esVacia(tlista *lista){
    return *lista==NULL;
}
void resto(tlista *lista){
    if (!esVacia(lista)){
        nodo * paux= *lista;
        *lista= paux->sig;
        free(paux);
    }
}
void insertarFinal(int elemento, tlista *lista){
    if(esVacia(lista)){
        insertarElemento(lista, elemento);
    } else{
        tlista paux;
        paux= *lista;
        while (paux->sig!=NULL){
            paux = paux->sig;
        }
        nodo *nuevo= malloc(sizeof (nodo));
        nuevo->info= elemento;
        nuevo->sig= NULL;
        paux->sig= nuevo;
    }
}
void primero(tlista *lista){
    if(!esVacia(lista)){
        printf("%d", (*lista)->info);
    }
}
void ultimo(tlista *lista){
    if(!esVacia(lista)){
        tlista paux;
        paux= *lista;
        while (paux->sig!=NULL){
            paux=paux->sig;
        }
        printf("%d", paux->info);
    }
}