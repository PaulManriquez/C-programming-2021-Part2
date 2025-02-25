#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct{
    int dato;//Dato que ingresa a la cola
    struct nodo* siguiente; //anida la estructura
}nodo;
nodo* primero=NULL;

void insertarNodo();
void desplegarPila();
void buscarNodoDato();
void modificarNodo();
void eliminarNodo();
int main()
{
    int opcion=0,seguir=0;

    do{
    printf("\n\tCreacion de pilas, etructura de datos");
    printf("\n1.-Insertar nodo\t2.-Desplegar pila\n");
    printf("\t3.-Buscar Dato en nodo\n");
    printf("4.-Modificar nodo\t5.-Eliminar nodo\n");
    printf("Opcion:");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
        insertarNodo();
        break;
        case 2:
        desplegarPila();
        break;
        case 3:
        buscarNodoDato();
        break;
        case 4:
        modificarNodo();
        break;
        case 5:
        eliminarNodo();
        break;
        default :
        printf("Opcion no existente\n");
     }
     printf("Desea continuar?(1)si-(0)no:");
     scanf("%d",&seguir);
     system("cls");
    }while(seguir==1);


    return 0;
}
void insertarNodo(){
    nodo* nuevo=(nodo*)malloc(sizeof(nodo));
    printf("\nIngresa el nuevo dato del nodo:");
    scanf("%d",&nuevo->dato);
    nuevo->siguiente=primero;
    primero=nuevo;
}
void desplegarPila(){
    nodo* actual=(nodo*)malloc(sizeof(nodo));
    actual=primero;
    printf("\nPila desplegada: ");
    if(primero!=NULL){
        while(actual!=NULL){
        printf("%d ",actual->dato);
        actual=actual->siguiente;
        }
    }else{
        printf("La pila est� vacia\n");
    }
    putchar('\n');
    free(actual);
}

void buscarNodoDato(){
    nodo* actual=(nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado=0,encontrado=0;
    printf("\nIngrese el dato del nodo a buscar:");
    scanf("%d",&nodoBuscado);
    if(primero!=NULL){
        while(actual!=NULL && encontrado!=1){
            if(actual->dato==nodoBuscado){
                printf("El nodo con el dato %d encontrado\n",nodoBuscado);
                encontrado=1;
            }
            actual=actual->siguiente;
        }
        if(encontrado==0){
            printf("Nodo no encontrado\n");
        }
    }else{
        printf("La pila se encuentra vacia.\n");
    }
    free(actual);
}
void modificarNodo(){

    nodo* actual=(nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado=0,encontrado=0;
    printf("\nIngrese el dato del nodo a buscar para modificar:");
    scanf("%d",&nodoBuscado);
    if(primero!=NULL){
        while(actual!=NULL && encontrado!=1){
            if(actual->dato==nodoBuscado){
                printf("\nEl nodo con el dato %d encontrado\n",nodoBuscado);

                printf("Ingrese el nuevo dato para este nodo:");
                scanf("%d",&actual->dato);
                printf("Nodo modificado con exito\n");

                encontrado=1;
            }
            actual=actual->siguiente;
        }
        if(encontrado==0){
            printf("Nodo no encontrado\n");
        }
    }else{
        printf("La pila se encuentra vacia.\n");
    }
}

void eliminarNodo(){

    nodo* actual=(nodo*) malloc(sizeof(nodo));
    actual = primero;
    nodo* anterior=(nodo*) malloc(sizeof(nodo));
    anterior=NULL;
    int nodoBuscado=0,encontrado=0;
    printf("\nIngrese el dato del nodo a buscar para eliminar:");
    scanf("%d",&nodoBuscado);
    if(primero!=NULL){
        while(actual!=NULL && encontrado!=1){
            if(actual->dato==nodoBuscado){
                if(actual==primero){
                    primero=primero->siguiente;
                }else{
                    anterior->siguiente=actual->siguiente;
                }
                printf("\nEl nodo con el dato %d ha sido eliminado con exito\n",nodoBuscado);
                encontrado=1;
            }
            anterior=actual;
            actual=actual->siguiente;
        }
        if(encontrado==0){
            printf("Nodo no encontrado\n");
        }else{
                free(anterior);
            }
    }else{
    printf("La pila se encuentra vacia\n");
    }
}
