/*
4) Cargar una serie de números reales en un vector. No se conoce la cantidad
exacta de datos, pero se sabe que no superan los 100. No se conocen cotas
para los datos. Informar el valor máximo, la cantidad de veces que aparece y
la/s posición/es que ocupa.
*/
#include <stdio.h>
#define MF 100
typedef float TVector[MF];

void cargar_vector_reales(TVector vector, int* ML);
float maximo_valor(TVector vector, int ML);
void mostrar_cant_num_repetidos(TVector vector,int ML,float max_valor);
void mostrar_pos_max_valor(TVector vector, int ML, float max_valor);

int main(){

    TVector vector;
    int ML;
    cargar_vector_reales(vector,&ML);
    
    float max_valor=maximo_valor(vector,ML);
    printf("\nEl maximo valor que ha ingresado es : %f \n",max_valor);
    mostrar_cant_num_repetidos(vector,ML,max_valor);
    mostrar_pos_max_valor(vector,ML,max_valor);


    return 0;
}

void cargar_vector_reales(TVector vector, int* ML){
    int i=0;char resp;
    float num;
    do{
        printf("ingrese un numero : ");
        scanf("%f",&num);
        vector[i]=num;
        i++;
        printf("\n¿Quiere cargar otro numero? s(si) o n(no)\n");
        scanf(" %c",&resp);
    }while(i<MF && resp == 's');
    *ML=i;
}
float maximo_valor(TVector vector, int ML){
    int i=0;
    float max_valor=vector[0];
    for(i=1;i<ML;i++){
        if(vector[i]>max_valor){
            max_valor=vector[i];
        }
    }
    return(max_valor);
}
void mostrar_cant_num_repetidos(TVector vector,int ML,float max_valor){
    int i;int cont=0;
    for(i=0;i<ML;i++){
        if(vector[i]==max_valor){
            cont++;
        }
    }
    printf("\nEl numero %f se repitio %d veces en el vector\n",max_valor,cont);
}

void mostrar_pos_max_valor(TVector vector, int ML,float max_valor){
    int i;
    for(i=0;i<ML;i++){
        if(vector[i]==max_valor){
            printf("el %f se encuentra en la posicion %d del vector\n",max_valor,i);
        }
    }

}