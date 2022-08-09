//
// Created by José Luis on 18/03/2022.
//

#include "Telemento.h"
#include "DoblePointedSimpleLinkedList.h"
#include "stdlib.h"
#include "stdio.h"


void crearListaVacia(TLista * l){
    *l=NULL;
}
int esListaVacia(TLista* l){
    return *l==NULL;
}
int longitudLista(TLista* l){
    if (!esListaVacia(l)){
        TLista paux= *l;
        int contador= 0;
        while (paux!=NULL){
            contador++;
            paux= paux->sig;
        }
        return contador;
    }
    return 0;
}
void primeroLista(TLista * l, TElemento* e){
    if (!esListaVacia(l)){
        TLista paux= *l;
        asignarElemento(&paux->info, e);
    }
}
void restoLista(TLista* l){

    if(!esListaVacia(l)){
        TLista paux= *l;
        *l= paux->sig;
        if (paux->sig!=NULL){ //Si NO es el unico de los elementos de la lista
            (*l)->ant=NULL;
        }
        free(paux);
    }

}
void ultimoLista(TLista* l, TElemento* e){
    if (!esListaVacia(l)){
        TLista paux= *l;
        while (paux->sig!=NULL){
            paux= paux->sig;
        }
        asignarElemento(&paux->info, e);


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
        TLista paux= *l;
        printf("[ ");
        while (paux!=NULL){
            mostrarElemento(&paux->info);
            paux= paux->sig;
            printf(" ");
        }
        printf("]");
    }
}
void insertarLista(TElemento* e, TLista * l){
    TLista nuevo= malloc(sizeof (nodo));
    nuevo->ant= NULL;
    nuevo->sig=*l;
    asignarElemento(e, &nuevo->info);

    if (esListaVacia(l)){
        *l=nuevo;
    }else{
        (*l)->ant=nuevo;
    }
    *l=nuevo;
}
void asignarLista(TLista* orig, TLista* dest){//copiamos una lista en otra

    if (!esListaVacia(orig)){
        TLista paux= *orig;
        crearListaVacia(dest);
        while (paux!=NULL){
            TElemento nuevo;
            asignarElemento(&paux->info, &nuevo);
            insertarFinalLista(&nuevo, dest);
            paux= paux->sig;
        }
    }

}
void insertarFinalLista(TElemento* e, TLista * l){
    if (esListaVacia(l)){
        insertarLista(e, l);
    }else{
        TLista paux=*l;
        while (paux->sig!=NULL){
            paux= paux->sig;
        }

        TLista nuevo= malloc(sizeof (nodo));
        asignarElemento(e, &nuevo->info);
        nuevo->sig=NULL;
        nuevo->ant=paux;
        paux->sig=nuevo;
    }
}
int contieneLista(TElemento* e, TLista* l){
    if (!esListaVacia(l)){
        int encontrado= 0;
        TLista paux= *l;

        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(&paux->info, e);
            if (encontrado== 0){
                paux=paux->sig;
            }
        }
        return encontrado;
    }
    return 0;
}

int eliminarLista(TElemento* e, TLista * l){

    if (!esListaVacia(l)){

        //fase 1: buscamos el elemento
        int encontrado=0;
        TLista paux= *l;

        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(&paux->info, e);
            if (encontrado== 0){
                paux=paux->sig;
            }
        }

        //fase 2: eliminamos elemento
        if (encontrado==1){
            //si es el primero
            if(paux->ant==NULL){
                *l=paux->sig;
            }else{
                paux->ant->sig= paux->sig;
                if (paux->sig==NULL){
                    paux->sig->ant= paux->ant;
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
        TLista paux= *l2;
        while (paux!=NULL){
            insertarFinalLista(&paux->info, l1);
            paux=paux->sig;
        }
    }
}

//EJERCICIOS EXTRAS

void mostrarListaInvertida(TLista * l){
    if (!esListaVacia(l)){
        TLista paux= *l;
        while (paux->sig !=NULL){
            paux=paux->sig;
        }
        while (paux!=NULL){
            mostrarElemento(&paux->info);
            paux= paux->ant;
        }
    }
}
int igualLista(TLista* l1, TLista* l2){
    if (!esListaVacia(l1) && !esListaVacia(l2)){
        if (longitudLista(l1) && longitudLista(l2)){
            int elMismo= 1;
            TLista paux1= *l1;
            TLista paux2 =*l2;

            while (paux1!=NULL && elMismo){
                elMismo= igualesElemento(&paux1->info, &paux2->info);
                if (elMismo){
                    paux1= paux1->sig;
                    paux2= paux2->sig;
                }
            }
            return elMismo;
        }
    }
    return 0;
}
void unique (TLista *lista){
    if (!esListaVacia(lista)){
        TLista paux,pant;
        pant= (*lista);
        paux= pant->sig;
        int encontrado= 0;
        while (paux!=NULL){
            encontrado= igualesElemento(&paux->info, &pant->info);
            if (encontrado){
                if (paux->sig==NULL){
                    //si es el ultimo
                    pant->sig=NULL;
                    free(paux);
                } else{
                    pant->sig=paux->sig;
                    paux->sig->ant=pant;
                    free(paux);
                }
                paux= pant->sig;
            } else{
                pant= paux;
                paux= paux->sig;
            }
        }
        mostrarLista(lista);
    }
}
void borrarUltimo (TLista *lista){
    if (!esListaVacia(lista)){
        TLista paux= *lista;
        while (paux->sig!=NULL){
            paux= paux->sig;
        }
        if (paux->ant==NULL){
            //solo hay un elemento
            *lista= NULL;
            free(paux);
        } else{
            paux->ant->sig=NULL;
            free(paux);
        }
    }
    mostrarLista(lista);

}
void borrarNprimeros (TLista *lista, int n){
    if (!esListaVacia(lista)){
        if (n>= longitudLista(lista)){
            destruirLista(lista);
        } else{
            for (int i = 0; i < n; ++i) {
                TLista paux = *lista;
                (*lista)=paux->sig;
                paux->sig->ant=NULL;
                free(paux);
            }
        }
        mostrarLista(lista);
    }
}
void borrarCadaX (TLista *lista, int n){
    if (!esListaVacia(lista)){
        TLista paux= *lista;
        TLista pant= NULL;
        int tam= longitudLista(lista);
        if (n==1){
            destruirLista(lista);
        } else{
            for (int i = 1; i <= tam; ++i) {
                if (i%n != 0){
                    pant=paux;
                    paux = paux->sig;
                } else{
                    if (paux->sig==NULL){
                        pant->sig=NULL;
                        free(paux);
                        paux= pant->sig;
                    } else{
                        pant->sig=paux->sig;
                        paux->sig->ant=pant;
                        free(paux);
                        paux= pant->sig;
                    }
                }
            }
        }
        mostrarLista(lista);

    }
}
void insertarDespuesDe (TLista *lista, TElemento insertardespues, TElemento elemento){

}
void insertarOrdenado (TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        TLista paux= *lista;
        int encontrado= 0;
        while (paux!=NULL && !encontrado){
            encontrado= esMenor(elemento, paux->info);
            if (encontrado){
                TLista nuevo= malloc(sizeof (nodo));
                asignarElemento(&elemento, &nuevo->info);
                if (paux->ant==NULL){
                    nuevo->ant=NULL;
                    nuevo->sig= paux;
                    paux->ant= nuevo;
                    *lista= nuevo;
                }else{nuevo->sig=paux;
                    paux->ant->sig=nuevo;
                    nuevo->ant= paux->ant;
                    paux->ant= nuevo;

                }

            } else{
                paux= paux->sig;
            }
        }
        if (encontrado==0){
            insertarFinalLista(&elemento, lista);
        }
    }
    mostrarLista(lista);
}
void vecesXelemento (TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        TLista paux= *lista;
        int contador= 0;
        while (paux!=NULL){
            if (igualesElemento(&paux->info, &elemento)){
                contador++;
            }
            paux= paux->sig;
        }
        printf("%d", contador);
    }
}
void sumarLista (TLista *lista){
    if (!esListaVacia(lista)){
        TLista paux= *lista;
        TElemento acumulador;
        crearElemento(&acumulador, 0);
        while (paux!=NULL){
            suma(acumulador, paux->info, &acumulador);
            paux=paux->sig;
        }
        mostrarElemento(&acumulador);
    }
}
void posfija (TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        TLista paux= *lista;
        int encontrado= 0;
        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(&paux->info, &elemento);
            if (encontrado==0){
                paux=paux->sig;
            }
        }
        if (paux!=NULL){
            paux= paux->sig;
            while (paux!=NULL){
                mostrarElemento(&paux->info);
                paux= paux->sig;
            }
        }

    }
}
void listaOrdenada (TLista *lista1, TLista *lista2);
void sumaAnteriores(TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        TElemento acumulador;
        crearElemento(&acumulador, 0);
        TLista paux= *lista;
        int encontrado= 0;
        while (paux!=NULL && !encontrado){
            encontrado= igualesElemento(&elemento, &paux->info);
            if (!encontrado){
                suma(paux->info, acumulador, &acumulador);
                paux=paux->sig;
            }
        }
        mostrarElemento(&acumulador);

    }
}
void criba (TLista *lista, int salto){
    if (!esListaVacia(lista)){
        TLista nueva;
        crearListaVacia(&nueva);
        int tam= longitudLista(lista);
        TLista paux= *lista;
        for (int i = 1; i <= tam; ++i) {
            if (i%salto != 0){
                insertarFinalLista(&paux->info, &nueva);
            }
            paux= paux->sig;
        }
        mostrarLista(&nueva);
    }

}

void duplicarValores(TLista* a){
    if (*a!=NULL){//si no es vacia
        TLista pant=*a;

        while (pant!=NULL){
            //creamos el elemento repetido
            nodo *repetido= malloc(sizeof (nodo));
            asignarElemento(&pant->info, &repetido->info);
            //lo enlazamos con el de delante
            if(pant->sig!=NULL){
                //si no es el ultimo elemento
                repetido->sig= pant->sig;
                pant->sig->ant= repetido;
            } else{
                //si es el ultimo elemento
                repetido->sig=NULL;
            }
            //lo enlazamos hacia atras
            pant->sig=repetido;
            repetido->ant= pant;
            //pasamos al siguiente, que seria el repetido y otra vez al siguiente
            pant=pant->sig->sig;
        }
    }
    mostrarLista(a);
}