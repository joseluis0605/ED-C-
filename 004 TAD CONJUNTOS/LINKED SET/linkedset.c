#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "linkedset.h"

void crearConjuntoVacio (set* a){
    *a=NULL;
}
void mostrarConjunto (set* a){
    if (!esConjuntoVacio(a)){
        set paux;
        paux=*a;
        while (paux!=NULL){
            mostrarElemento(&paux->info);
            paux=paux->sig;
        }
    }
}
void poner (TElemento* e, set* a){
    if (!pertenece(e,a)){
        set nuevo= malloc(sizeof (TnodoSet));
        asignarElemento(e, &nuevo->info);
        nuevo->sig=*a;
        *a=nuevo;
    }
}
int quitar (TElemento* e, set* a){
    if(!esConjuntoVacio(a)){
        int encontrado=0;
        set paux= *a;
        set pant= NULL;
        while (paux!=NULL && !encontrado){
            encontrado= igualElemento(e, &paux->info);
            if (encontrado==0){
                pant=paux;
                paux=paux->sig;
            }
        }

        if (encontrado){
            //si es el primero
            if (pant==NULL){
                //si es el unico
                *a=paux->sig;
                free(paux);
            } else{
                pant->sig=paux->sig;
                free(paux);
            }
        }
        mostrarConjunto(a);
    }
    return 0;

}
int elegir (TElemento* e, set* a){
    srand(time(NULL));
    int numeroPosiciones= rand() % cardinal(a);
    set paux= *a;
    while (numeroPosiciones){
        numeroPosiciones--;
        paux=paux->sig;
    }
    asignarElemento(&paux->info, e);
    mostrarElemento(e);
}
void interseccion (set* a1, set* a2, set* u){
    if (!esConjuntoVacio(a1) && !esConjuntoVacio(a2)){
        set paux1= *a1;
        crearConjuntoVacio(u);
        while (paux1!=NULL){
            if (pertenece(&paux1->info, a2)){
                poner(&paux1->info, u);
            }
            paux1=paux1->sig;
        }
        mostrarConjunto(u);
    }
}
void diferencia (set* a1, set* a2, set* u){
    set paux1=*a1;
    crearConjuntoVacio(u);

    while (paux1!=NULL){
        if (!pertenece(&paux1->info, a2)){
            poner(&paux1->info, u);
        }
        paux1=paux1->sig;
    }
    mostrarConjunto(u);
}
void unir(set* a1, set* a2, set* u){
    set paux1= *a1;
    set paux2= *a2;
    while (paux1!=NULL){
        poner(&paux1->info, u);
        paux1=paux1->sig;
    }
    while (paux2!=NULL){
        poner(&paux2->info, u);
        paux2= paux2->sig;
    }
    mostrarConjunto(u);
}
int esSubconjunto (set* a1, set* a2){
    if(!esConjuntoVacio(a1) && !esConjuntoVacio(a2)){
        set paux= *a1;
        int encontrado= 1;
        while (paux!=NULL && encontrado){
            encontrado= pertenece(&paux->info, a2);
            if (encontrado){
                paux=paux->sig;
            }
        }
        printf("%d", encontrado);
        return encontrado;

    }
}
int pertenece (TElemento* e, set* a){
    if( !esConjuntoVacio(a)){
        int encontrado= 0;
        set paux= *a;
        while (paux!=NULL && !encontrado){
            encontrado= igualElemento(&paux->info, e);
            if (!encontrado){
                paux= paux->sig;
            }
        }
        return encontrado;
    }
    return 0;
}
int esConjuntoVacio (set* a){
    return *a==NULL;
}
int cardinal (set* a){
    if (!esConjuntoVacio(a)){
        set paux= *a;
        int contador= 0;
        while (paux!=NULL){
            contador++;
            paux=paux->sig;
        }
        return contador;
    }
    return 0;
}
int igualConjunto (set* l1, set* l2){
    if (cardinal(l1)== cardinal(l2)){
        set paux1= *l1;
        set paux2= *l2;
        int encontrado= 1;
        while (paux1!=NULL && encontrado){
            int estaSegundoConjunto=0;
            paux2= *l2;
            while (paux2 && !estaSegundoConjunto){
                estaSegundoConjunto= igualElemento(&paux2->info, &paux1->info);
                if (!estaSegundoConjunto){
                    paux2= paux2->sig;
                }
            }
            encontrado= estaSegundoConjunto;
            if (encontrado){
                paux1= paux1->sig;
            }
        }
        printf("%d", encontrado);
    }
    printf("0");
    return 0;
}
void asignarConjunto(set* original, set* copia){
    if(!esConjuntoVacio(original)){
        crearConjuntoVacio(copia);
        set paux= *original;
        while (paux!=NULL){
            poner(&paux->info, copia);
            paux= paux->sig;
        }
        mostrarConjunto(copia);
    }
}
void destruirConjunto(set* a){
    set paux= *a;
    while (!esConjuntoVacio(a)){
        *a= paux->sig;
        free(paux);
        paux= *a;
    }
    mostrarConjunto(a);
}