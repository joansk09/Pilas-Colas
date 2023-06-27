#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const char operadores[] = "^*/+-()";

typedef struct nodo{
    char dato;
    struct nodo *sig;
}*NODO;

int esOperador(char);
int prioridad(char);
int estaVacia(NODO);
void mostrar(NODO);
void insertar(NODO *, char);
char eliminar(NODO *);
char tope(NODO);

int main(){
    int i=0, j=0;
    NODO pila = NULL;
    NODO nuevaPila = NULL;
    char *text = (char *) calloc(32, sizeof(char));
    char *nuevo = (char *) calloc(32, sizeof(char));
    gets(text);
    char aux;

    for(i=strlen(text)-1; i>=0; i--){
        aux = text[i];
        printf("\nConsultando %c", aux);
        if(!esOperador(aux)){
            printf("\tAgregue directo %c", aux);
            nuevo[j] = aux;
            j++;
        }
        else{
            if(estaVacia(pila)){
                printf("\tAgregue directo %c", aux);
                insertar(&pila, aux);
            }
            else{
                if(aux == ')'){
                    printf("\tAgregue directo %c", aux);
                    insertar(&pila, aux);
        printf("\nPILA: ");
        mostrar(pila);
        printf("\n");
        printf("RESULTADO: %s\n", nuevo);
                    continue;
                }
                if(aux == '('){
                    printf("\t Es uno que abre, vaciar pila hasta encontrar que cierra");
                    while(tope(pila) != ')'){
                        printf("\nEl tope es %c\n", tope(pila));
                        nuevo[j] = eliminar(&pila);
                        j++;
                    }
                    eliminar(&pila);
                    printf("\nPILA: ");
                    mostrar(pila);
                    printf("\n");
                    printf("RESULTADO: %s\n", nuevo);
                    continue;
                }
                while(prioridad(aux) <= prioridad(tope(pila))){
                    nuevo[j] = eliminar(&pila);
                    j++;
                    if(estaVacia(pila))break;
                }
                insertar(&pila, aux);
            }
        printf("\nPILA: ");
        mostrar(pila);
        printf("\n");
        printf("RESULTADO: %s\n", nuevo);
        }
    }
    while(pila != NULL){
        nuevo[j] = eliminar(&pila);
        j++;
    }

    for(i=0; i<strlen(nuevo); i++){
        insertar(&nuevaPila, nuevo[i] );
    }

    printf("\nLa conversion de %s a postfija es: \n", text);
    while(nuevaPila != NULL){
        aux = eliminar(&nuevaPila);
        printf("%c", aux);
    }

    return 0;
}

int estaVacia(NODO pila){
    return pila==NULL;
}

void insertar(NODO *pila, char dato){
    NODO nuevo = calloc(1, sizeof(char));
    nuevo->dato = dato;
    if(*pila != NULL){
        nuevo->sig = *pila;
        *pila = nuevo;
    }
    else{
        *pila = nuevo;
    }
}

char eliminar(NODO *pila){
    NODO aux = *pila;
    char v = '\0';
    if(*pila != NULL){
        v = aux->dato;
        *pila = (*pila)->sig;
        free(aux);
    }
    else{
        printf("\nPila vacia");
    }
    return v;
}

char tope(NODO pila){
    if(pila != NULL){
        return pila->dato;
    }
    return ' ';
}

void mostrar(NODO pila){
    NODO aux = pila;
    while(aux != NULL){
        printf("%c ", aux->dato);
        aux = aux->sig;
    }
}

int esOperador(char sig){
    int i;
    for(i=0; i<strlen(operadores); i++){
        if(operadores[i] == sig)
            return 1;
    }
    return 0;
}

int prioridad(char sig){
    return (sig=='^')? 3 : (sig=='/' || sig=='*')? 2 : (sig=='+'||sig=='-')? 1 : 0;
}
