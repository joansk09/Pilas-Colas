#include<stdio.h>
#include<stdlib.h>

#define MAX 3

int estaVacia(int);
int estaLlena(int);
void colar(int *, int *, int *, int);
int desencolar(int *, int *, int *);
int peek(int *, int, int);
void display(int *, int, int);

int main(){
    int ini = 0, n = 0, cola[MAX], op;
    int dato;

    do{
        printf("\n1) Colar\n2) Desencolar\n3) Tope\n4) Mostrar");
        fflush(stdin);
        scanf("%d", &op);
        if(op==5)break;

        switch(op){
            case 1:
                printf("\nIngrese el dato a colar");
                scanf("%d", &dato);
                colar(cola, &ini, &n, dato);
                break;
            case 2:
                printf("Dato: %d", desencolar(cola, &ini, &n));
                break;
            case 3:
                printf("Dato: %d", peek(cola, ini, n));
                break;
            case 4:
                display(cola, ini, n);
                break;
        }
        printf("\n\n\n");
        system("PAUSE");
        system("CLS");
    }while(op!=5);

    return 0;
}

int estaVacia(int n){
    return n == 0;
}

int estaLlena(int n){
    return n == MAX;
}

void colar(int *cola, int *ini, int *n, int dato){
    if( !estaLlena(*n) ){
        int pos = (*ini + *n) % MAX;
        cola[pos] = dato;
        *n = *n + 1;
    }
    else{
        printf("\nLa cola ya esta llena");
    }
}

int desencolar(int *cola, int *ini, int *n){
    if(!estaVacia(*n)){
        int v = cola[*ini];
        *ini = (*ini + 1) % MAX;
        *n = *n - 1;
        return v;
    }
    else{
        printf("\nLa cola ya esta vacia");
        return -1;
    }
}

int peek(int *cola, int ini, int n){
    if(!estaVacia(n)){
        return cola[ini];
    }
    else{
        printf("\nLa cola esta vacia");
        return -1;
    }
}

void display(int *cola, int ini, int n){
    if(!estaVacia(n)){
        int i;
        while(n!=0){
            printf("%d ", cola[ini]);
            ini++;
            if(ini == MAX){
                ini = 0;
            }
            n--;
        }
    }
    else{
        printf("\nLa cola eta vacia");
    }
}
