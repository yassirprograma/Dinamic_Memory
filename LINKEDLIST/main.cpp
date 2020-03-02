#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <winbgim.h>

struct nodo {
    char *nombre;
    struct nodo *siguiente;
};

void mostrarlista(nodo *);
void insertafinal(nodo *&,char *);
void insertainicio(nodo *&,char *);
void insenmedio(nodo *&,char *,int);
void dibuja(nodo *);


char namedi[20][20]; //guarda el nombre a asginar a cada nod
int n,menu;

int main()
{
    int nav=0; //es el navegador

    nodo *lista;
    lista=(nodo*)malloc(sizeof(nodo));  //asigna espacio de memoria equivalente al tamnyo de la estructura
    lista->nombre="inicio";
    lista->siguiente=NULL;
    nav++;

    label:
    puts("ESCRIBA 1 SI DESEA INSERTAR UN NODO AL INICIO");
    puts("ESCRIBA 2 SI DESEA INSERTAR UN NODO EN MEDIO");
    puts("ESCRIBA 3 SI DESEA INSERTAR UN NODO AL FINAL");
    puts("ESCRIBA 9 SI DESEA SALIR");


    scanf("%d",&menu);
    fflush(stdin);

    //strcpy(namedi,"");
    switch(menu){
        case 1:
//            limpia();
            puts("Escriba el nombre del nodo a insertar al inicio");
            scanf("%s",& *(namedi+nav));
            fflush(stdin); //borra el buffer de entrada
            insertainicio(lista,*(namedi+nav));
            nav++;
        break;

        case 2:
             puts("Escriba el nombre del nodo a insertar enmedio");
            scanf("%s",& *(namedi+nav));
            fflush(stdin); //borra el buffer de entrada
            insenmedio(lista,*(namedi+nav),nav);
            nav++;

        break;

        case 3:
            puts("Escriba el nombre del nodo a insertar al final");
            scanf("%s",& *(namedi+nav));
            fflush(stdin); //borra el buffer de entrada
            insertafinal(lista,*(namedi+nav));
            nav++;
        break;

        case 9:
            break;
        break;


    }
    mostrarlista(lista);

     initwindow(700, 700);	// init window graphics
            setbkcolor(12); // Color de fondo de la ventana
            cleardevice();
            dibuja(lista);
    getch();
    closegraph();


    puts("Presione 8 si desea meter otro valor, 9 si desea salir\n");
    fflush(stdin);
    scanf("%d",&menu);
    if(menu==8){
        system("cls");
        goto label;
    }


    return 0;
}


void mostrarlista(nodo *lista){ //le pasa una copia de la lista para que no pase nada raro
    nodo *actual=(nodo*)malloc(sizeof(nodo)); //declaramos y le asignamos memoria
    actual=lista; //actual apunta a la lista
    while(actual!=NULL){ //mientras el actual no llegue al final de la lista
        printf("%s \n",actual->nombre);  //imprime el miembro nombre de actual
        actual=actual->siguiente; //actual apunta al siguiente
    }
}

void insertainicio(nodo *&lista, char *id){
    nodo *nuevonodo,*aux1,*aux2;
    nuevonodo=(nodo*)malloc(sizeof(nodo));  //asigna espacio de memoria equivalente al tamnyo de la estructura
    nuevonodo->nombre=id; //asigna el nombre en cadena de caracteres

    aux2=lista->siguiente;
    nuevonodo->siguiente=aux2;
    lista->siguiente=nuevonodo;
}
void insenmedio(nodo *&lista, char *id,int tam){
    nodo *nuevonodo;
    nuevonodo=(nodo*)malloc(sizeof(nodo));  //asigna espacio de memoria equivalente al tamnyo de la estructura
    nuevonodo->nombre=id; //asigna el nombre en cadena de caracteres
    nodo *aux1=lista;
    nodo *aux2;

    for(int i=1;i<=(tam/2)+1;i++){
        aux2=aux1;
        aux1=aux1->siguiente;
    }
    aux2->siguiente=nuevonodo;
    nuevonodo->siguiente=aux1;
}

void insertafinal(nodo *&lista, char *id){ //le pasa la lista por referencia

     nodo *nuevonodo;
     nuevonodo=(nodo*)malloc(sizeof(nodo));  //asigna espacio de memoria equivalente al tamnyo de la estructura

     nuevonodo->nombre=id; //asigna el nombre en cadena de caracteres

     nodo *aux1=lista; //crea un nodo auxiliar para guardar a lista
     nodo *aux2;
     while(aux1!=NULL ){ //se va hasta el final de la lista
            aux2=aux1;  //se pasa al otro nodo
            aux1=aux1->siguiente; //aux1 es igual a aux1.sig, simula aumentar un indice
     }

     if(lista==aux1){ //no ha entrado al while
        lista=nuevonodo;  //primer nodo
     } else {
         aux2->siguiente=nuevonodo; // aux.siguiente apunta al nuevo nodo
     }
     nuevonodo->siguiente=aux1; //nuevo.siguiente apunta a aux
     puts("HECHO \n");

}

void dibuja(nodo *listaadibujar){

    int xi=10,xf=100; //coordenadas donde va a graficar el rectangulo
    int yi=10, yf=100;

    nodo *actual; //declaramos y le asignamos memoria
    actual=listaadibujar; //actual apunta a la lista

    bool bandera=false;
    while(actual!=NULL){ //mientras el actual no llegue al final de la lista

        rectangle(xi,yi,xf,yf);
        line(xi+20,yi,xi+20,yf);
        if(bandera){
            line(xi,(yi+yf)/2,xf-120,(yi+yf)/2);
            line(xi-10,((yi+yf)/2)-10,xi,(yi+yf)/2);
            line(xi-10,((yi+yf)/2)+10,xi,(yi+yf)/2);

        }

        settextstyle(0,0,1);
        outtextxy(  (xi+xf)/2 -10, (yi+yf)/2 -10, actual->nombre);


        xi+=120;
        xf+=120;
         if(actual->siguiente==NULL){
            line(xi,(yi+yf)/2,xf-120,(yi+yf)/2);
            line(xi,(yi+yf)/2,xi,yf+10);
            outtextxy( xi-10,yf+10 ,"NULL");
        }

        actual=actual->siguiente; //actual apunta al siguiente

        bandera=true;// para que no le ponga flecha al primero
    }
        //GUARDA LO QUE VA A MOSTRAR EN GRAFICO
}
