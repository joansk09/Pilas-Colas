#include<stdlib.h>
#include<stdio.h>
#include<time.h>
typedef struct nodo{
    int dato;
    struct nodo *sig;
}*NODO;

void insertar(NODO *, int);
int eliminar(NODO *);
void mostrar(NODO);
int tope(NODO);

int main(){
    int i, v;
    NODO pila = NULL;
    srand(time(NULL));

    for(i=0; i<=100; i+=10)
        insertar(&pila, rand()%100);

    printf("\nPila desordenada: \n");
    mostrar(pila);
    printf("\nEliminado: ");
    eliminar(&pila);
    mostrar(pila);


    printf("\nPila ordenada: \n");
    NODO nueva = NULL;

    while(pila != NULL){
        if(nueva == NULL){
            insertar(&nueva, eliminar(&pila));
        }
        else{
            v = eliminar(&pila);
            while(v > tope(nueva) && nueva!=NULL){
                insertar(&pila, eliminar(&nueva));
            }
            insertar(&nueva, v);
        }
    }

    mostrar(nueva);

    return 0;
}


void insertar(NODO *pila, int dato){
    NODO nuevo = calloc(1, sizeof(struct nodo));
    nuevo->dato = dato;

    if(*pila == NULL){
        *pila = nuevo;
    }
    else{
        nuevo->sig = *pila;
        *pila = nuevo;
    }
}

int eliminar(NODO *pila){
    int v = -1;
    NODO aux;
    if(*pila != NULL){
        v = (*pila)->dato;
        aux = *pila;
        (*pila) = (*pila)->sig;
        free(aux);
    }
    else{
        printf("\nPila vacia");
    }
    return v;
}

void mostrar(NODO nodo){
    NODO aux = nodo;
    while(aux != NULL){
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
}

int tope(NODO pila){
    return (pila == NULL) ? -1 : pila->dato;
}
