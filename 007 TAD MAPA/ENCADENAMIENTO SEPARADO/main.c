#include <stdio.h>
#include <stdlib.h>
#include "TMapa.h"




int main(){
    TClave c1,c2,c3,c4;
    TValor v1,v2,v3,v4;
    set2 s;
    crearConjuntoVacio2(&s);
    Mapa m, copiado;
    crearMapaVacio(&m);
    crearMapaVacio(&copiado);

    printf("Es mapa vacio? %d\n",esMapaVacio(&m));
    crearValor("do",&v1);
    crearValor("fa",&v2);
    crearValor("sol",&v3);
    crearValor ("la",&v4);
    crearClave('c',&c1);
    crearClave('f',&c2);
    crearClave('g',&c3);
    crearClave('b',&c4);

    ponerMapa(&c1, &v1, &m);
    ponerMapa(&c2, &v2, &m);
    ponerMapa(&c3, &v3, &m);
    ponerMapa(&c4, &v4, &m);

    mostrarMapa(&m);

    TElemento aux;
    crearElemento(&c1, &v1, &aux);
    printf("devolvemos elemento: \n");
    devolver(&c4, &v2, &m);

    printf("\nEliminamos elemento: ");
    quitarMapa(&c1, &m);

    printf("\n chavalada que copiamos mapa: \n");
    asignarMapa(&m, &copiado);
    mostrarMapa(&copiado);

    printf("\nconjunto de todo: \n");
    set todo;
    crearConjuntoVacio(&todo);
    conjuntoEntradas(&todo, &m);
    mostrarConjunto(&todo);

    printf("\nconjunto de claves: \n");
    set1 clavesSolo;
    crearConjuntoVacio1(&clavesSolo);
    conjuntoClaves(&clavesSolo, &m);
    mostrarConjunto1(&clavesSolo);

    printf("\nconjunto de valores: \n");
    set2 valoresSolo;
    crearConjuntoVacio2(&valoresSolo);
    conjuntoValores(&valoresSolo, &m);
    mostrarConjunto2(&valoresSolo);

}
