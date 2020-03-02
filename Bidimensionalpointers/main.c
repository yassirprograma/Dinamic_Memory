#include <stdio.h>
#include <stdlib.h>
int arr[12][12];
int n,m; //n filas, m columnas

void arregloengrafico(int[],int, int);


int main()
{
    puts("Ingresa numero de filas");
    scanf("%d",&n);
    puts("Ingresa numero de elementos de cada fila");
    scanf("%d",&m);


    for(int i=0;i<n;i++){
        printf("ESCRIBE LOS DATOS DE LA FILA  NUMERO  %d \n",i+1);  //lee en consola
        for(int j=0;j<m;j++){
            scanf("%d",& *(*(arr+i)+j) );
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", *(*(arr+i)+j) );  //imprime en consola
        }
        puts("\n");
    }


    initwindow(700, 700);	// init window graphics

             for(int i=0;i<n;i++){ //va fila por fila imprimendo cada posicion
                arregloengrafico(*(arr+i),m,i); //manda a grafico la fila
            }

    getch();
    closegraph();

    return 0;
}

void arregloengrafico( int arraux[],int largo, int numfila){
    int tamcuadrito=70;
    int xi=100,xf=tamcuadrito+xi; //coordenadas donde va a graficar el rectangulo
    int yi=tamcuadrito+(numfila*tamcuadrito), yf=tamcuadrito*numfila;

    char toscreen[10]; //guarda el numero en forma de caracter

    for(int i=0;i<largo;i++){
        sprintf(toscreen,"%d",*(arraux+i)); //GUARDA LO QUE VA A MOSTRAR EN GRAFICO

        rectangle(xi,yi,xf,yf);
        settextstyle(1,0,1);

        outtextxy(  (xi+xf)/2 -10, (yi+yf)/2 -10, toscreen);

        xi+=71;
        xf+=71;

    }
}
