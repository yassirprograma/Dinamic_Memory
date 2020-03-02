#include <stdio.h>
#include <stdlib.h>
int n,m,o;
int arr[10][10][10];
void arregloengrafico(int [],int,int,int);

int main()
{
    puts("dame el numero de filas");
    scanf("%d",&m);
    puts("dame el numero de elementos por cada fila");
    scanf("%d",&o);
    puts("dame el numero de capas (eje z) ");
    scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    for(int k=0;k<o;k++){
                        scanf("%d",& *(*(*(arr+i)+j)+k));
                    }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    for(int k=0;k<o;k++){
                        printf("%d ", *(*(*(arr+i)+j)+k));
                    }
                    puts("\n");
            }
        }

    initwindow(700, 700);	// init window graphics

         for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                 arregloengrafico(*(*(arr+i)+j),o,j,i);
                 delay(1000);
            }
        }

    getch();
    closegraph();

    return 0;
}
void arregloengrafico( int arraux[],int largo, int numfila, int numcapa){
    numcapa--;
    int tamcuadrito=70;
    int xi=100-(numcapa*10),xf=tamcuadrito+xi; //coordenadas donde va a graficar el rectangulo
    int yi=tamcuadrito+(numfila*tamcuadrito)+(numcapa*10), yf=tamcuadrito*numfila;

    char toscreen[10]; //guarda el numero en forma de caracter

    for(int i=0;i<largo;i++){
        sprintf(toscreen,"%d",*(arraux+i)); //GUARDA LO QUE VA A MOSTRAR EN GRAFICO

        setcolor(numcapa+4);
        rectangle(xi,yi,xf,yf);
        setfillstyle(1,numcapa+4);
        settextstyle(1,0,1);
        outtextxy(  (xi+xf)/2 -10, (yi+yf)/2 -10, toscreen);

        xi+=71;
        xf+=71;

    }
}


