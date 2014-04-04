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
void cambio(char a[][3]);

int main(int argc, char** argv) {

    char array[3][3] ={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    int i=0,j=0;
    
    for(i=0;i<3;++i){
        for(j=0;j<3;++j)
            printf("%c ",array[i][j]);
        printf("\n");
}
    cambio(array);

    for(i=0;i<3;++i){
        for(j=0;j<3;++j)
            printf("%c ",array[i][j]);
        printf("\n");
}
}

void cambio(char a[][3]){
    a[1][1]='5';
}

