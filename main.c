/* 
 * File:   main.c
 * Author: miguel
 *
 * Created on 25 de marzo de 2014, 10:33 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

enum bool {FALSE, TRUE};
typedef enum bool boolean;

void obtenerPosiciones(int i,int col[],boolean fila[],boolean diagonalB[],boolean diagonalS[],int *num,int n);

int main(int argc, char** argv) {
    int n;
    do{
    printf("ingresa el tamaño del tablero (mayor a 3):");
    scanf("%d",&n);
    }while(n<4);
    int col[n];
    int i;
    boolean diagonalB[(n*2)-1],diagonalS[(n*2)-1],fila[n];
    for(i=0;i<(n*2)-1;++i){
        if(i<n)
            fila[i]=TRUE;
        diagonalB[i]=diagonalS[i]=TRUE;
    }
    int num=1;
    obtenerPosiciones(0,col,fila,diagonalB,diagonalS,&num,n);
}

void obtenerPosiciones(int i,int col[],boolean fila[],boolean diagonalB[],boolean diagonalS[],int *num,int n){
    int j;
    if(i==n){//si encuentra solucion la imprime
        int k;
        printf("%d-",*num);
        (*num)=(*num)+1;
        for(k=0;k<n;++k)
            if(k<n-1)
                printf("%d,",col[k]+1);
            else
              printf("%d\n",col[k]+1);  
    }
      
    for(j=0;j<n;++j){
        if(fila[j] && diagonalB[(n-1)+i-j] && diagonalS[i+j]){//si hay oportunidad hacemos otra llamada para colocar la siguiente reyna
            col[i]=j;
            diagonalB[(n-1)+i-j]=diagonalS[i+j]=fila[j]=FALSE;
            obtenerPosiciones(i+1,col,fila,diagonalB,diagonalS,num,n);//llamada a colocar a la siguienete reyna
            diagonalB[(n-1)+i-j]=diagonalS[i+j]=fila[j]=TRUE;
            }
        
        }
    }





