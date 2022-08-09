#define Dim 100

#include "arraylist.h"

void crearVaciaA (arrayList* a){
    a->indice=-1;
}

int esVaciaA (arrayList a){
    return (a.indice==-1);
}

int longitudA(arrayList a){
    return (a.indice + 1);
}

void mostrarA (arrayList a){
    if (!esVaciaA(a)){
        for (int i=a.indice;i>-1;i--){
            print1 (a.almacen[i]);
            printf(" ");
        }
        printf("\n");
    }    
}

void insertarA (TElemento1 e, arrayList* a){
    if(a->indice<Dim-1){
        (a->indice)++;
        asignar1(&(a->almacen[a->indice]),e);
    }
    else{
        printf("La lista esta llena");
    // redimensionar redimensionar (a);insertar (e,a);
    }
}

void insertarFinalA (TElemento1 e, arrayList* a){
    if(a->indice<Dim-1){
        for(int i=a->indice;i>-1;i--){
            asignar1(&(a->almacen[i+1]),a->almacen[i]);
        }
        (a->indice)++;
        asignar1(&(a->almacen[0]),e);
    }
    else{
        printf("La lista esta llena");
    }
}

int eliminarA (TElemento1 e, arrayList* a){
    int i = a->indice;// i=0
    int encontrado=0;
    while ((i>-1)&&(!encontrado)){ //(i<dim&&(!encontrado))
     //   encontrado=(a->almacen[i]==e);
        encontrado=igual1(&a->almacen[i],&e);
        if (encontrado){
            for(int j=i;j<a->indice;j++){ 
                asignar1(&(a->almacen[j]),a->almacen[j+1]);
            }
            (a->indice)--;
        }
        else{
            i--;  
        }    
    }
    return encontrado;
}

void primeroA (arrayList a, TElemento1* e){
    if (!esVaciaA(a)){
        asignar1(e,(a.almacen[a.indice]));
    }
}

void restoA (arrayList* a){
    if (!esVaciaA(*a)){
        (a->indice)--;
    }
}

void ultimoA (arrayList a, TElemento1* e){
    if (!esVaciaA(a)){
        asignar1(e,(a.almacen[0]));
    }
}

void concatenarA(arrayList* a1, arrayList a2){
    
    for(int elemento = (a2.indice); elemento>-1;elemento--){
        insertarFinalA(a2.almacen[elemento],a1);
    }

}

int contieneA (TElemento1 e, arrayList a){
    int esta=0;
    int i=-1;
    while ((i<(a.indice))&&(!esta)){
        i++;
        esta=igual1(&a.almacen[i],&e);
    }
    return esta;
}

void destruirA(arrayList* a){
    a->indice=-1;
}

void copiarA(arrayList original, arrayList* copia){
    copia->indice=original.indice;
    for(int i=0;i<original.indice;i++){
        asignar1(&copia->almacen[i],original.almacen[i]);
    }
}





