#include "booleanarrayset.h"
#include "time.h"

void crearConjuntoVacio (booleanbarraySet* a){
    for (int i = 0; i < Dim; ++i) {
        a->almacen[i]=0;
    }
    a->numeroElementos= 0;
}
void mostrarConjunto (booleanbarraySet* a){
    for (int i = 0; i < Dim; ++i) {
        if (a->almacen[i]==1){
            TElemento nuevo;
            dameElemento(i, &nuevo);
            print(nuevo);
            printf(" ");
        }
    }
    printf("\n");
}
void insertarConjunto (TElemento e, booleanbarraySet* a){
    int posicion= damePosicion(e);
    if (a->almacen[posicion]==0){
        a->numeroElementos++;
    }
    a->almacen[posicion]= 1;

}
int eliminarConjunto (TElemento e, booleanbarraySet* a){
    int posicion= damePosicion(e);
    if (a->almacen[posicion]==1){
        a->numeroElementos--;
    }
    a->almacen[posicion]=0;
    mostrarConjunto(a);
}
void elegir (TElemento* e, booleanbarraySet* a){
    srand(time(NULL));
    int posiciones= rand() % cardinal(a);
    int index = 0;
    while (index < Dim && posiciones >= 0){
        if (a->almacen[index]==1){
            if (posiciones==0){
                dameElemento(index, e);
                print(*e);
            }
            posiciones--;
        }
        index++;
    }
    printf("\n");
}
void interseccion (booleanbarraySet* a1, booleanbarraySet* a2, booleanbarraySet* i){
    crearConjuntoVacio(i);
    for (int j = 0; j < Dim; ++j) {
        if (a1->almacen[j] && a2->almacen[j]){
            i->almacen[j]=1;
            i->numeroElementos++;
        }
    }
    mostrarConjunto(i);
}
void diferencia (booleanbarraySet* a1, booleanbarraySet* a2, booleanbarraySet* d){
    for (int i = 0; i < Dim; ++i) {
        if (a1->almacen[i] && !a2->almacen[i]){
            d->almacen[i]=1;
            d->numeroElementos++;
        }
    }
    mostrarConjunto(d);
}
void unir(booleanbarraySet* a1, booleanbarraySet* a2, booleanbarraySet* u){
    for (int i = 0; i < Dim; ++i) {
        if(a1->almacen[i] || a2->almacen[i]){
            u->almacen[i]=1;
            u->numeroElementos++;
        }
    }
    mostrarConjunto(u);
}
int esSubconjunto (booleanbarraySet* a1, booleanbarraySet* a2){
    int index= 0;
    int esta= 1;
    while (index<Dim && esta){
        if (a1->almacen [index]==1){
            TElemento  nuevo;
            dameElemento(index, &nuevo);
            esta= contiene(nuevo, a2);
        }
        index++;
    }
    printf("%d", esta);
    return esta;
}
int contiene (TElemento e, booleanbarraySet* a){
    int esta= damePosicion(e);
    return a->almacen[esta];
}
int esConjuntoVacio (booleanbarraySet* a){
    return a->numeroElementos==0;
}
int cardinal (booleanbarraySet* a){
    return a->numeroElementos;
}
void copiarConjunto(booleanbarraySet* original, booleanbarraySet* copia){
    crearConjuntoVacio(copia);
    for (int i = 0; i < Dim; ++i) {
        copia->almacen[i]= original->almacen[i];
        if(copia->almacen[i]==1){
            copia->numeroElementos++;
        }
    }
    mostrarConjunto(copia);
}
void destruirConjunto(booleanbarraySet* a){
    for (int i = 0; i < Dim; ++i) {
        a->almacen[i]=0;
    }
    a->numeroElementos=0;
}