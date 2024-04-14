/*1) Dado n entero positivo y un listado de n números reales, almacenar los
números en un vector en el orden de entrada. Informar el contenido del vector
indicando la posición ocupada por cada número a partir de la primera posición. 
*/

#include <stdio.h>
#define MF 3
typedef float TamVector[MF];

void llenarVector(TamVector vector,int* ML){
    char resp;
    float num;
    int i=0;
    do{
        printf("ingrese un valor real\n");
        scanf("%f",&num);
        vector[i]=num;
        i++;
        if(i<MF){
        printf("Quiere ingresar otro numero mas? s(si) / n(no) \n");
        scanf(" %c",&resp);
        }else{
            printf("Superaste la cantidad maxima del vector\n");
        }

    }while(i<MF && resp=='s');
    *ML=i;
}
void mostrarPosNumsVector(TamVector vector, int ML){
    int i;
    for(i=0;i<ML;i++){
        printf("pos %d = %f \n",i,vector[i]);
    }
}

int main(){

    TamVector vecReales;
    int ML;
    llenarVector(vecReales,&ML);
    mostrarPosNumsVector(vecReales,ML);



    return 0;
}
