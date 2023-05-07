#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int dato;
    struct nodo *sig;
};
typedef struct nodo* NODO;


int estaVacia(NODO *);
void colar(NODO *, NODO *, int);
int desencolar(NODO *, NODO *);

int main(){
    int i;
    NODO ini = NULL, fin = NULL;
    for(i=1; i<=10; i++)
        colar(&ini, &fin, i);

    while(!estaVacia(&fin)){
        printf("%d ", desencolar(&ini, &fin));
    }

    return 0;
}

int estaVacia(NODO *ini){
    return *ini == NULL;
}

void colar(NODO *ini, NODO *fin, int dato){
    NODO aux = (NODO) malloc(sizeof(struct nodo));
    aux->dato = dato;
    if(estaVacia(ini)){
        *ini = aux;
        *fin = aux;
    }
    else{
        (*fin)->sig = aux;
        *fin = aux;
    }
}

int desencolar(NODO *ini, NODO *fin){
    if(!estaVacia(ini)){
        NODO aux = *ini;
        int v = aux->dato;
        *ini = aux->sig;
        free(aux);
        if(*ini == NULL)
            *fin = NULL;
        return v;
    }
    else{
        printf("\nLa cola esta vacia, no puedo desencolar");
        return -1;
    }
}
