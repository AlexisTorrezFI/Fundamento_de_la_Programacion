#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MF 5

typedef int tvector[MF];

void mostrar(tvector vector, int n)
{
  int k;    
  for(k=0; k<n; k++)
    printf("%d ",vector[k]);
}

void ordenar(tvector vector, int n)
{
  int i, j, aux;    
  // método burbujeo
  bool cambios=true;
  i=1;
  while(i<n && cambios){
    for(j=0; j<n-i; j++){ // "burbujeo" del mayor valor
        cambios=false;
        if(vector[j] > vector[j+1]){  //si corresponde intercambio
            aux=vector[j];
            vector[j]=vector[j+1];
            vector[j+1]=aux;
            cambios=true;
        }
    }
    i++;
  }
  
}


void ordenar_con_seguimiento(tvector vector, int n)
{
  int i, j, aux;    
  i=1;
  bool cambios=true;
  while(i<n && cambios){ //ciclo de n-1 iteraciones
    cambios=false;
    for(j=0; j<n-i; j++){ // "burbujeo" del mayor valor
      if(vector[j] > vector[j+1]){  //si corresponde intercambio
         aux=vector[j];
         vector[j]=vector[j+1];
         vector[j+1]=aux;
         cambios=true;
      }
      mostrar(vector, n);
      printf("   i= %d   j= %d   j+1= %d \n",i,j,j+1);
    }
    printf("\n");
    i++;

  }
}


void main(){
  tvector vec={8,1,9,2,10};

  printf("VECTOR ORIGINAL\n");
  mostrar(vec, MF);

  printf("\n\nMETODO DE BURBUJEO\n\n");
  ordenar_con_seguimiento(vec, MF);
       
  printf("\nVECTOR FINAL\n");
  mostrar(vec, MF);
  printf("\n");
       
}