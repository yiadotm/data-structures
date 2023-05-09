/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA4
* ListTest.c
* File that tests the List ADT
*********************************************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <assert.h>
#include"List.h"
#include "Matrix.h"

int main(int argc, char* argv[]){
    Matrix A = newMatrix(10);
    Matrix B = newMatrix(10);
    changeEntry(A, 1, 1, 4);
    changeEntry(A, 1, 2, 2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 1, 2);
    changeEntry(A, 3, 1, 0);
    changeEntry(A, 2, 2, 2);
    changeEntry(A, 3, 3, 0);
    Matrix C = sum(A, A);
    if (NNZ(C) != 4 || NNZ(A) != 4)
      return 1;
    changeEntry(B, 1, 1, -4);
    changeEntry(B, 1, 2, 0);
    changeEntry(B, 2, 1, 0);
    changeEntry(B, 2, 2, -2);
    changeEntry(B, 2, 4, 2);
    changeEntry(B, 3, 1, 0);
    changeEntry(B, 3, 2, 2);
    changeEntry(B, 7, 8, 5);
    Matrix D = sum(A, B);
    printf("NNZ: %d", NNZ(D));
    if (NNZ(D) != 5)
      return 2;
    return 0;

}