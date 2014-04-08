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

void obtenerPosiciones(int i,int col[],boolean fila[],boolean diagonalB[],boolean diagonalS[],int *num);

int main(int argc, char** argv) {

    
    int col[8]={0,0,0,0,0,0,0,0};
    int i;
    boolean diagonalB[15],diagonalS[15],fila[8];
    for(i=0;i<15;++i){
        if(i<8)
            fila[i]=TRUE;
        diagonalB[i]=diagonalS[i]=TRUE;
    }
    int num=1;
    obtenerPosiciones(0,col,fila,diagonalB,diagonalS,&num);
}

void obtenerPosiciones(int i,int col[],boolean fila[],boolean diagonalB[],boolean diagonalS[],int *num){
    int j;
    if(i==8){//si encuentra solucion la imprime
        int k;
        printf("%d-",*num);
        (*num)=(*num)+1;
        for(k=0;k<8;++k)
            if(k<7)
                printf("%d,",col[k]+1);
            else
              printf("%d\n",col[k]+1);  
    }
      
    for(j=0;j<8;++j){
        if(fila[j] && diagonalB[7+i-j] && diagonalS[i+j]){//si hay oportunidad hacemos otra llamada para colocar la siguiente reyna
            col[i]=j;
            diagonalB[7+i-j]=diagonalS[i+j]=fila[j]=FALSE;
            obtenerPosiciones(i+1,col,fila,diagonalB,diagonalS,num);//llamada a colocar a la siguienete reyna
            diagonalB[7+i-j]=diagonalS[i+j]=fila[j]=TRUE;
            }
        
        }
    }





