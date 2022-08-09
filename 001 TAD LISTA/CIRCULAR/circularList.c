//
// Created by José Luis on 18/03/2022.
//

#include "circularList.h"




void crearListaVacia(TLista  *l){
    *l=NULL;
}
int esListaVacia(TLista* l){
    return *l==NULL;
}
int longitudLista(TLista* l){
    if (!esListaVacia(l)){
        int contador= 0;
        TLista paux= (*l)->sig;
        while (paux!=*l){
            contador++;
            paux= paux->sig;
        }
        contador++;
        return contador;
    }
    return 0;
}
void primeroLista(TLista * l, TElemento* e){
    if (!esListaVacia(l)){
        asignarElemento(&(*l)->sig->info, e);
    }
}
void restoLista(TLista* l){
    if (!esListaVacia(l)){
        nodo *paux= (*l)->sig;
        if (paux == *l){
            //si es unico elemento
            *l= NULL;
        } else{
            (*l)->sig=paux->sig;
        }
        free(paux);
    }
}
void ultimoLista(TLista* l, TElemento* e){
    if (!esListaVacia(l)){
        TLista paux= *l;
        asignarElemento(&(*l)->info, e);
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
    printf("[ ");
    if (!esListaVacia(l)){
        TLista paux= (*l)->sig;
        while (paux!=*l){
            mostrarElemento(&paux->info);
            printf(" ");
            paux= paux->sig;
        }
        mostrarElemento(&(*l)->info);

    }
    printf("]\n");

}
void insertarLista(TElemento* e, TLista * l){
    struct nodo* nuevo= malloc(sizeof (nodo));
    asignarElemento(e, &nuevo->info);
    if (esListaVacia(l)){
        *l=nuevo;
        nuevo->sig= *l;
    }else{
        nuevo->sig=(*l)->sig;
        (*l)->sig=nuevo;
    }

}
void asignarLista(TLista* orig, TLista* dest){
    if (!esListaVacia(orig)){
        TLista paux= (*orig)->sig;
        while (paux!=*orig){
            insertarFinalLista(&paux->info, dest);
            paux= paux->sig;
        }
        insertarFinalLista(&(*orig)->info, dest);
    }
}
void insertarFinalLista(TElemento* e, TLista * l){
    if (!esListaVacia(l)){
        nodo *nuevo= malloc(sizeof (nodo));
        asignarElemento(e, &nuevo->info);
        nuevo->sig= (*l)->sig;
        (*l)->sig= nuevo;
        (*l)=nuevo;
    } else{
        insertarLista(e,l);
    }
}
int contieneLista(TElemento* e, TLista* l){
    if (!esListaVacia(l)){
        TLista paux= (*l)->sig;
        int encontrado= 0;
        while (paux!=*l && !encontrado){
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
        TLista paux= (*l)->sig;
        TLista pant= NULL;

        while (paux!=*l && !encontrado){
            encontrado= igualesElemento(e, &paux->info);
            if (encontrado==0){
                pant= paux;
                paux= paux->sig;
            }
        }
        if (encontrado== 0){
            //comprobamos que no sea el ultimo de los elementos el que buscamos
            encontrado= igualesElemento(&(*l)->info, e);
        }
        if (encontrado){
            if (paux==*l && pant==NULL){
                //si es el unico que hay
                *l=NULL;
            }else{
                if (pant==NULL){
                    //si es el primero de los elementos
                    (*l)->sig=paux->sig;
                } else{
                    if(pant->sig==*l){
                        //si el que eliminamos es el ultimo
                        pant->sig=(*l)->sig;
                        (*l)=pant;
                    } else{
                        //si es uno de los del medio
                        pant->sig= paux->sig;
                    }
                }
            }
        }
        free(paux);
        return encontrado;
    }
    return 0;
}
void concatenarLista(TLista* l1, TLista* l2){
    if (esListaVacia(l1)){
        asignarLista(l2, l1);
    } else{
        TLista paux= (*l2)->sig;
        while (paux!=*l2){
            insertarFinalLista(&paux->info, l1);
            paux=paux->sig;
        }

        insertarFinalLista(&(*l2)->info, l1);

    }
}

void mostrarListaInvertida(TLista * l);
int igualLista(TLista* l1, TLista* l2){
    if (longitudLista(l1) == longitudLista(l2)){
        TLista paux1= (*l1)->sig;
        TLista paux2= (*l2)->sig;
        int elMismo= 1;
        while (paux1!=*l1 && elMismo){
            elMismo= igualesElemento(&paux1->info, &paux2->info);
            if (elMismo){
                paux1= paux1->sig;
                paux2= paux2->sig;
            }
        }

        if (elMismo){
            elMismo= igualesElemento(&paux1->info, &paux2->info);
        }
        printf("%d", elMismo);
    }
    return 0;
}
void unique (TLista *lista){
    if (!esListaVacia(lista)){
        TLista pant= (*lista)->sig;
        TLista paux= pant->sig;
        int mismo;
        while (paux!=*lista){

            mismo= igualesElemento(&pant->info, &paux->info);
            if (mismo==1){
                pant->sig=paux->sig;
                free(paux);
                paux= pant->sig;
            } else{
                pant= paux;
                paux=paux->sig;
            }
        }

        if (paux==*lista){
            if (igualesElemento(&pant->info, &paux->info)){
                *lista=pant;
                pant->sig=paux->sig;
                free(paux);

            }

        }

        mostrarLista(lista);
    }
}
void borrarUltimo (TLista *lista){
    if (!esListaVacia(lista)){
        TLista paux= (*lista)->sig;
        TLista pant=NULL;
        if (paux==*lista){
            *lista=NULL;
            free(paux);
        } else{
            while (paux!=*lista){
                pant=paux;
                paux=paux->sig;
            }
            *lista= pant;
            pant->sig= paux->sig;
            free(paux);
        }
        mostrarLista(lista);
    }
}
void borrarNprimeros (TLista *lista, int n){
    if (!esListaVacia(lista)){
        if (n == longitudLista(lista)){
            destruirLista(lista);
        } else{
            for (int i = 0; i < n; ++i) {
                restoLista(lista);
            }
        }
        mostrarLista(lista);
    }
}
void borrarCadaX (TLista *lista, int n){
    if (!esListaVacia(lista)){
        int tam= longitudLista(lista);
        TLista paux= (*lista)->sig;
        TLista pant= NULL;
        if (n==1){
            destruirLista(lista);
        } else{
            for (int i = 1; i <= tam; ++i) {
                if (i%n == 0){
                    pant->sig=paux->sig;
                    if (paux==(*lista)){
                        (*lista)=pant;
                    }
                    free(paux);
                    paux=pant->sig;
                } else{
                    pant=paux;
                    paux=paux->sig;

                }
            }
        }
        mostrarLista(lista);
    }
}
void insertarDespuesDe (TLista *lista, TElemento insertardespues, TElemento elemento){
    if (!esListaVacia(lista)){
        int encontrado= 0;
        TLista paux= (*lista)->sig;
        while (paux!=*lista && !encontrado){
            encontrado = igualesElemento(&paux->info, &insertardespues);
            if (!encontrado){
                paux= paux->sig;
            }
        }
        if (encontrado==0){
            encontrado= igualesElemento(&(*lista)->info, &insertardespues);
        }
        if (encontrado){
            TLista nuevo= malloc(sizeof (nodo));
            asignarElemento(&elemento, &nuevo->info);
            if (paux==*lista){
                nuevo->sig=(*lista)->sig;
                (*lista)->sig=nuevo;
                *lista=nuevo;
            } else{
                nuevo->sig= paux->sig;
                paux->sig=nuevo;
            }
        }
        mostrarLista(lista);
    }
}
void insertarOrdenado (TLista *lista, TElemento elemento);
void vecesXelemento (TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        TLista paux= (*lista)->sig;
        int contador= 0;
        while (paux!=*lista){
            if (igualesElemento(&paux->info, &elemento)){
                contador++;
            }
            paux=paux->sig;
        }
        printf("%d", contador);
    }
}
void sumarLista (TLista *lista){
    if (!esListaVacia(lista)){
        TElemento contador;
        crearElemento(&contador, 0);
        TLista paux=(*lista)->sig;
        while (paux!=*lista){
            suma(contador, paux->info, &contador);
            paux=paux->sig;
        }
        suma(contador, (*lista)->info, &contador);
        mostrarElemento(&contador);
    }
}
void posfija (TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        TLista paux= (*lista)->sig;
        TLista aux;
        crearListaVacia(&aux);
        int encontrado=0;

        while (paux!=*lista && !encontrado){
            encontrado= igualesElemento(&paux->info, &elemento);
            if (!encontrado){
                paux=paux->sig;
            }
        }
        if (encontrado==1){
            while (paux!=*lista){
                insertarFinalLista(&paux->info, &aux);
                paux=paux->sig;
            }
            insertarFinalLista(&(*lista)->info, &aux);
            restoLista(&aux);
        }
        mostrarLista((&aux));
    }
}
void listaOrdenada (TLista *lista1, TLista *lista2);
void sumaAnteriores(TLista *lista, TElemento elemento){
    if (!esListaVacia(lista)){
        TElemento contador;
        crearElemento(&contador, 0);
        TLista paux = (*lista)->sig;
        int encontrado=0;

        while (paux!=(*lista) && !encontrado){
            encontrado= igualesElemento(&paux->info, &elemento);
            if (!encontrado){
                suma(contador, paux->info, &contador);
            }
            paux=paux->sig;
        }
        if (!encontrado){
            suma(contador, paux->info, &contador);
        }
        mostrarElemento(&contador);
    }
}
void criba (TLista *lista, int salto){
    if (!esListaVacia(lista)){
        int tam= longitudLista(lista);
        TLista paux= (*lista)->sig;

        for (int i = 1; i <= tam ; ++i) {
            if (i%salto != 0){
                mostrarElemento(&paux->info);
            }
            paux=paux->sig;
        }
    }
}