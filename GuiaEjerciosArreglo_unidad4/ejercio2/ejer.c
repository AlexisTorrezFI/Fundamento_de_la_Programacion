/*2) Dado un listado de números reales del cual no se conoce la cantidad,
almacenar los números en un vector en el orden de entrada. Informar la
cantidad de números y el contenido del vector indicando la posición ocupada
por cada número a partir de la primera posición. */

#include <stdio.h>
#define MF 10000
typedef float TamVector[MF];

void llenarVector(TamVector vector, int* ML){
    char resp;
    int i=0;int num;
    do{
        printf("ingrese un numero real \n");
        scanf("%d",&num);
        vector[i]=num;
        i++;
        printf("quiere ingresar otro numero, s(si) / n(no)\n");
        scanf(" %c",&resp);
    }while(resp=='s');
    *ML=i;
}

void mostrarPosNumsVector(TamVector vector, int ML){
    int i;
    for(i=1;i<ML;i++){
        printf(" posicion %d = %f \n",i,vector[i]);
    }
}


int main(){
    int ML;
    TamVector vector;
    llenarVector(vector,&ML);
    printf("La cantidad de numeros del vector es %d\n",ML);
    mostrarPosNumsVector(vector,ML);

    return 0;
}