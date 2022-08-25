#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define maxSize 100 //Puse las restricciones del tamaño como constantes, son mas facil de cambiar valor
#define minSize 2

/* PROTOTIPOS DE FUNCIONES */
int leerYValidar (int, int);
int anteriorEs1 (int [], int, int, int);
void cargaVector (int[], int, int, int);
void mostrarVector(int[],int);
int jumpOnMarsh(int[], int);


int main()
{
    setlocale(LC_ALL, "spanish"); //En teoria esta linea no tiene que generar problemas en ningun S.O

    int vecStonesPits[maxSize], n, saltosMin; //n = tamaño del vector.

    printf("Technical Exam for EY - TTT Campus\n");
    printf("----------------------------------------\n\n");

    //Cantidad Elementos del vector
    printf("Ingrese la cantidad de Stones/Pits en el agua (el tamaño del vector):\n");
    n = leerYValidar(minSize, maxSize);

    //la carga del vector
    system("cls");
    printf("El vector tendra un tamaño de %d, iniciemos su carga: \n", n);
    cargaVector(vecStonesPits, n, 0, 1); //0 y 1 son los valores validos.
    mostrarVector(vecStonesPits, n);

    printf("Saltos Realizados: \n");
    saltosMin = jumpOnMarsh(vecStonesPits, n);
    printf("\n\nSaltos minimos necesarios para escapar: %d",saltosMin);


    printf("\n\n");
    printf("FIN DEL PROGRAMA.\n");
    system("pause");
    return 0;
}

/* DESARROLLO DE FUNCIONES */

int leerYValidar(int lInf, int lSup) //recibe Limite inferior y superior
{
    int cant;
     do
    {
        printf("Minimo %d, maximo %d: ",lInf, lSup);
        scanf("%d",&cant);

        if(cant<2 || cant>100)
            printf("\nERROR: ");

    }while(cant<2 || cant>100);

    return cant;
}


void cargaVector(int vec[], int n, int val, int val2) //val1 y val2 son los valores admitidos. 0 y 1.
{
    int i, anterior;

    printf("\nCargar el vector teniendo en cuenta que: \n0 = Stone (puede saltar)\n1 = Pit (NO puede saltar)\nY es IMPOSIBLE que haya un 1 consecutivo a otro...\n\n");
    printf("La primer posicion debe ser Stone (o sea, 0), si no... se caera!\n");

    for(i=0;i<n;i++)
    {

        do
        {
            anterior=1;
            printf("Posicion %d: Ingrese un 0 o un 1: \n",i);
            scanf("%d",&vec[i]);
            if(vec[i]==1)
                anterior = anteriorEs1(vec, i, vec[i], n); //Para evitar ingreso de "1" consecutivos.

        }while(!(vec[i]==0 || anterior == 0));

    }
}

int anteriorEs1 (int vec[], int i, int valor, int n)
{
    int flag = 2;
    if(i!=0) //asi no me salgo del vector para revisar
    {
        if(vec[i-1]==0) //o sea que me sirve el 1, porque antes no hay un 1.
        {
            printf("\n1 Valido\n");
            flag = 0;
        }
    }
    else
        printf("La primer posicion tiene que ser si o si un 0\n");

    if (i==n-1)//ultima posicion
    {
        printf("El ultimo valor NO puede ser 1. Ingrese un 0\n");
        flag=1;
    }

    return flag;

}

void mostrarVector(int vec [],int n)
{
    int i;

    printf("Indice\tStone/Pit\n");
    for(i=0;i<n;i++)
        printf("%3d%10d\n",i,vec[i]);
}

int jumpOnMarsh(int vec[], int n) //"n" es la cantidad de elementos del vector. Uso un while para ir modificando el iterador, para ir saltando
{
    int i=0, saltos=0;

    while(i+1<n)
    {
        //si me paso del vector, salgo del bucle.

        if(vec[i+2]==0)
        {
            i=i+2;
            saltos++;
            printf("jumped (2 positions) to position %d\n",i);
        }
        else
            if(vec[i+1]==0)
            {
                i=i+1;
                saltos++;
                printf("jumped (1 position) to position %d\n",i);
            }
            else
                printf("\n Error: No hay STONE Disponible para saltar\n"); //si todo esta correcto, es IMPOSIBLE que llegue a este error.

    }
    return saltos;
}


