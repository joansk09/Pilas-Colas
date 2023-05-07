#include<stdio.h>
#include<stdlib.h>

#define MAXTAM 5

int estaVacia(int, int);
int estaLlena(int);
void colar(int *, int *, int);
int desencolar(int *, int *, int);
int peek(int *, int, int);
void display(int *, int, int);

int main(){
    int i, ini = 0, fin = -1;
    int cola[MAXTAM];
    int op;
    int dato;

    do{
        printf("\n1) Colar \n2) Desencolar \n3) Ver tope\n4) Mostrar cola\n5) Salir\n--> ");
        scanf("%d", &op);
        if(op==5)break;

        switch(op){
            case 1:
                fflush(stdin);
                printf("\n\nIngrese el dato a colar\n--> ");
                scanf("%d", &dato);
                colar(cola, &fin, dato);
                break;
            case 2:
                printf("\nDato: %d", desencolar(cola, &ini, fin));
                break;
            case 3:
                printf("\nTope: %d", peek(cola, ini, fin));
                break;
            case 4:
                display(cola, ini, fin);
                break;
        }
        printf("\n\n\n\n");
        system("PAUSE");
        system("CLS");
    }while(op!=5);


    return 0;
}

int estaVacia(int ini, int fin){
    return ini > fin;
}

int estaLlena(int fin){
    return fin == MAXTAM - 1;
}

void colar(int *cola, int *fin, int dato){
    if(!estaLlena(*fin) ){
        *fin = *fin + 1;
        cola[*fin] = dato;
    }
    else{
        printf("\nLa cola ya esta llena");
    }
}

int desencolar(int *cola, int *ini, int fin){
    if(!estaVacia(*ini, fin)){
        *ini = *ini + 1;
        return cola[*ini - 1];
    }
    else{
        printf("\nLa cola ya esta vacia");
        return -1;
    }
}

int peek(int *cola, int ini, int fin){
    if(!estaVacia(ini, fin)){
        return cola[ini];
    }
    else{
        printf("\nLa cola ya esta vacia");
        return -1;
    }
}
void display(int *cola, int ini, int fin){
    int i;
    if(!estaVacia(ini, fin)){
        for(i=ini; i<=fin; i++){
            printf("%d ", cola[i]);
        }
    }
    else{
        printf("\n\nLa cola ya esta vacia");
    }
}
