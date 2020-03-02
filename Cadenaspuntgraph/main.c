#include <stdio.h>
#include <stdlib.h>
//#include <winbgim.h>

#include <string.h>

char arr[100]; //arreglo estatico a llenar
int tam; //numero de elementos a meter
char *point; //apuntador a las direcciones de memoria del arreglo

void leearreglo(void);
void arregloengrafico(char [],int );

int main()
{

   //puts("DAME EL NUMERO DE ELEMENTOS A METER EN DEL ARREGLO");
 //  scanf("%d",&tam); //lee el numero de valores que se guardaran en el arreglo
   puts("INGRESE la cadena\n");
 //  leearreglo(); //lee un arreglo unidimensional estatico

    gets(arr);
   point=arr; //le asigna al apuntador la direccion del arreglo en su posicion 0 (apuntamos al arreglo)
   printf("EL ARREGLO ES: \n");

   while(point<(arr+strlen(arr))){ //imprime el arreglo usando artimetica de apuntadores
        printf("%c  ",*point); //imprime el valor que se encuentra en la direccion a la que apunta point
        point++;    //aumenta un entero en el apuntador, osea, pasa al siguiente entero en la memoria

    }


    initwindow(700, 700);	// init window graphics


            setbkcolor(12); // Color de fondo de la ventana
            cleardevice();


            arregloengrafico(arr,strlen(arr));
    getch();
    closegraph();





    return 0;
}


void arregloengrafico( char arraux[20],int largo){
    int xi=10,xf=90; //coordenadas donde va a graficar el rectangulo
    int yi=10, yf=90;

    char tograph[4];

    outtextxy(  70, 150, "ESTE ES EL ARREGLO");

    for(int i=0;i<largo;i++){
        //GUARDA LO QUE VA A MOSTRAR EN GRAFICO

      rectangle(xi,yi,xf,yf);
      settextstyle(1,0,1);

      tograph[0]=*(arraux+i);

      outtextxy(  (xi+xf)/2 -10, (yi+yf)/2 -10, tograph);


        xi+=91;
        xf+=91;


    }
}
