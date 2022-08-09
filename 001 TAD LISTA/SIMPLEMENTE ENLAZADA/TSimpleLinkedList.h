//
// Created by José Luis on 12/02/2022.
//

struct nodo{
    int info;
    struct nodo* sig;
};
typedef struct nodo nodo;
typedef struct nodo* tlista;



void inicializar (tlista *lista);
void insertarElemento (tlista *lista, int elemento);
void mostrar (tlista *lista);
void eliminar (int elemento, tlista *lista);
void copiar (tlista original, tlista *copia);
void destruir (tlista *lista);
int contiene(int elemento, tlista lista);
int esVacia(tlista *lista);
void resto(tlista *lista);
void insertarFinal(int elemento, tlista *lista);
void primero(tlista *lista);
void ultimo(tlista *lista);


