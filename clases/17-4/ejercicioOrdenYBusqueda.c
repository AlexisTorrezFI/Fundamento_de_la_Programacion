/*Ingresar los padrones y las notas de los alumnos
del curso de Algoritmos y programación 1.

Como máximo se cargarán 50 alumnos.
---------------------------------------------------
Se pide:
  1) Realizar el modulo de carga de datos.
  2) Mostrar aprobados (padrón y nota) en orden de notas crecientes.
  3) Agregar un modulo que permita la busqueda, dado un padrón ingresado por el usuario
    indicar que nota obtuvo el alumno.

*/
#include <stdio.h>
#include <stdbool.h>
#define MAX_ALUM 50
typedef int TMvector_padron[MAX_ALUM];
typedef int TMvector_notas[MAX_ALUM];

void cargar_datos_alumnos(TMvector_padron padron_alumnos,TMvector_notas notas_alumnos,int* ML){
    int i=0;
    char resp;
    int num;
    do{
        printf("\nIngrese el padron del alumno %d : ",i+1);scanf(" %d",&num);
        padron_alumnos[i]=num;
        printf("\nIngrese su nota(0 al 10) :");scanf("%d",&num);
        notas_alumnos[i]=num;
        i++;
        if(i<MAX_ALUM){
            printf("\n¿Quiere ingresar el dato de otro alumno? s(si) / n(no) ");scanf(" %c",&resp);
        }else{
            printf("\nSuperaste el limite de alumnos! \n");
        }
    }while(i<MAX_ALUM && resp=='s' );
    *ML=i;
}
void ordenar_crecientemente_por_nota_alumno(TMvector_padron padron_alumnos,TMvector_notas notas_alumnos,int ML){
    int i,j,aux;
    i=1;
    bool cambios=true;
    while(i<ML && cambios){
        cambios=false;
        for(j=0;j<ML-i;j++){
            if(notas_alumnos[j]>notas_alumnos[j+1]){
                aux=notas_alumnos[j];
                notas_alumnos[j]=notas_alumnos[j+1];
                notas_alumnos[j+1]=aux;
                aux=padron_alumnos[j];
                padron_alumnos[j]=padron_alumnos[j+1];
                padron_alumnos[j+1]=aux;
                cambios=true;
            }
        }
        i++;
    }
}
void mostrar_aprobados(TMvector_padron padron_alumnos, TMvector_notas notas_alumnos,int ML){
    int i;
    printf("\nAprobados:\n");
    for(i=0;i<ML;i++){
        if(notas_alumnos[i]>=4){
            printf("Padron -- %d ,la nota es: %d \n",padron_alumnos[i],notas_alumnos[i]);
        }
    }

}

void buscar_nota_alumno(TMvector_padron padron_alumnos,TMvector_notas notas_alumnos,int ML,int padron_bucar){
    int i=0;
    bool encontrado=false;
    while(i<ML && !encontrado){    
        if(padron_bucar==padron_alumnos[i]){
            encontrado=true;
            printf("\nEl alumno saco un %d \n",notas_alumnos[i]);
        }
        i++;
    }
    if(!encontrado){
        printf("\nNo hay algun alumno con ese padron\n");
    }

}
int main(){
    TMvector_padron padron_alumnos;
    TMvector_notas notas_alumnos;
    int ML,padron_bucar;
    cargar_datos_alumnos(padron_alumnos,notas_alumnos,&ML);
    ordenar_crecientemente_por_nota_alumno(padron_alumnos,notas_alumnos,ML);
    mostrar_aprobados(padron_alumnos,notas_alumnos,ML);
    printf("\nla nota de cual padron queres buscar,ingrese el padron\n");
    scanf("%d",&padron_bucar);
    buscar_nota_alumno(padron_alumnos,notas_alumnos,ML,padron_bucar);
    return 0;
}