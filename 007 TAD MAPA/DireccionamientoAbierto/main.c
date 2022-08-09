#include <stdio.h>
#include <stdlib.h>
#include "TMapa.h"




int main(){
    TClave c1,c2,c3,c4;
    TValor v1,v2,v3,v4;
    TClave cc1,cc2,cc3,cc4;
    TValor vv1,vv2,vv3,vv4;
    set2 s;
    crearConjuntoVacio2(&s);
    Mapa m;
    crearMapaVacio(&m);
    printf("Es mapa vacio? %d\n",esMapaVacio(&m));
    crearValor("do",&v1);
    crearValor("fa",&v2);
    crearValor("sol",&v3);
    crearValor ("la",&v4);
    crearClave('c',&c1);
    crearClave('f',&c2);
    crearClave('g',&c3);
    crearClave('b',&c4);
    ponerMapa(&c1,&v1,&m);
    ponerMapa(&c2,&v2,&m);
    ponerMapa(&c3,&v3,&m);
    ponerMapa(&c4,&v4,&m);
    printf("MUESTRO EL PRIMER MAPA\n");
    mostrarMapa(&m);
    TValor resul;
    devolver(&c4,&resul,&m);
    printf("EL VALOR ASOCIADO ES \n");
    mostrarValor(&resul);

    Mapa m2;
    crearMapaVacio(&m2);
    printf("Es mapa vacio? %d\n",esMapaVacio(&m));
    crearValor("po",&vv1);
    crearValor("fa",&vv2);
    crearValor("sol",&vv3);
    crearValor ("la",&vv4);
    crearClave('c',&cc1);
    crearClave('f',&cc2);
    crearClave('g',&cc3);
    crearClave('b',&cc4);
    ponerMapa(&cc1,&vv1,&m2);
    ponerMapa(&cc2,&vv2,&m2);
    ponerMapa(&cc3,&vv3,&m2);
    ponerMapa(&cc4,&vv4,&m2);
    printf("MUESTRO EL SEGUNDO MAPA\n");
    mostrarMapa(&m2);
    printf("------------------------------------------------------\n");
    printf("SON IGUALES ? %i\n", SonIgualesMapa(&m,&m2));

    Mapa copia;
    crearMapaVacio(&copia);
    asignarMapa(&m2,&copia);
    printf("MUESTRO LA COPIA\n");
    mostrarMapa(&copia);
    set1 conjunto;
    crearConjuntoVacio1(&conjunto);
    conjuntoClaves(&conjunto,&copia);
    printf("MUESTRO EL CONJUNTO DE CLAVES\n");
    mostrarConjunto1(&conjunto);
    printf("\nMUESTRO EL CONJUNTO DE VALORES\n");
    set2 conjunto2;
    crearConjuntoVacio2(&conjunto2);
    conjuntoValores(&conjunto2,&copia);
    mostrarConjunto2(&conjunto2);
    printf("\nMUESTRO EL CONJUNTO DE ENTRADAS\n");
    set conjunto1;
    crearConjuntoVacio(&conjunto1);
    conjuntoEntradas(&conjunto1,&copia);
    mostrarConjunto(&conjunto1);
    printf("MUESTRO EL MAPA 1\n");
    mostrarMapa(&m);
    printf("MUESTRO EL MAPA 2\n");
    mostrarMapa(&m2);
    printf("SON IGUALES EL MAPA 1 CON EL MAPA 2? %i\n", SonIgualesMapaV2(&m,&m2));
    printf("UN PAR DE PRUEBAS\n");
    ponerMapa(&c1,&vv1,&m);
    mostrarMapa(&m);
    return 0;
}
