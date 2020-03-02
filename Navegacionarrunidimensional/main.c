#include <stdio.h>
#include <stdlib.h>
//#include <winbgim.h>

#include <string.h>

int arr[100]; //arreglo estatico a llenar
int tam; //numero de elementos a meter
int *point; //apuntador a las direcciones de memoria del arreglo

void leearreglo(void);
void arregloengrafico(int [],int );

int main()
{

   puts("DAME EL NUMERO DE ELEMENTOS A METER EN DEL ARREGLO");
   scanf("%d",&tam); //lee el numero de valores que se guardaran en el arreglo
   puts("INGRESE LOS VALORES\n");
   leearreglo(); //lee un arreglo unidimensional estatico

   point=arr; //le asigna al apuntador la direccion del arreglo en su posicion 0 (apuntamos al arreglo)
   printf("EL ARREGLO ES: \n");

   while(point<(arr+tam)){ //imprime el arreglo usando artimetica de apuntadores
        //(arr+tam) obtiene la direccion de memoria del ultimo entero en el arreglo

        printf("%d  ",*point); //imprime el valor que se encuentra en la direccion a la que apunta point
        point++;    //aumenta un entero en el apuntador, osea, pasa al siguiente entero en la memoria

    }


    initwindow(700, 700);	// init window graphics


            setbkcolor(12); // Color de fondo de la ventana
            cleardevice();


            arregloengrafico(arr,tam);
    getch();
    closegraph();





    return 0;
}

void leearreglo(){
    int aux=0;
    for(int i=0;i<tam;i++){  //lee el arreglo
        scanf("%d",&aux); //lee un entero
        *(arr+i)=aux;     //asigna el valor de aux en la posicion de memoria (0+ i enteros)
   }
}
void arregloengrafico( int arraux[],int largo){
    int xi=10,xf=90; //coordenadas donde va a graficar el rectangulo
    int yi=10, yf=90;

    char toscreen[10]; //guarda el numero en forma de caracter

    outtextxy(  70, 150, "ESTE ES EL ARREGLO");

    for(int i=0;i<largo;i++){
        sprintf(toscreen,"%d",*(arraux+i)); //GUARDA LO QUE VA A MOSTRAR EN GRAFICO

        rectangle(xi,yi,xf,yf);
        settextstyle(1,0,1);


        outtextxy(  (xi+xf)/2 -10, (yi+yf)/2 -10, toscreen);

        xi+=91;
        xf+=91;


    }
}
