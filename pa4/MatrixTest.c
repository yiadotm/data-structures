/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA4
* MatrixTest.c
* File that tests the Matrix ADT
*********************************************************************************/ 
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include <assert.h>
#include"Matrix.h"
     
int main(){

   int n=100;
   Matrix A = newMatrix(n);
   Matrix B = newMatrix(n);
   Matrix C;
   Matrix D;
   Matrix E;
   Matrix F;
   Matrix G;
   Matrix H;

    //printf("hi3\n");
   changeEntry(A, 1,1,2); changeEntry(B, 1,1,2);
   //printf("hi1\n");
   changeEntry(A, 1,2,3); changeEntry(B, 1,2,1);
   changeEntry(A, 1,3,5); changeEntry(B, 1,3,3);
   changeEntry(A, 2,1,7); changeEntry(B, 2,1,1);
   changeEntry(A, 2,2,5); changeEntry(B, 2,2,4);
   changeEntry(A, 2,3,2); changeEntry(B, 2,3,2);
   changeEntry(A, 3,1,9); changeEntry(B, 3,1,3);
   changeEntry(A, 3,2,8); changeEntry(B, 3,2,7);
   changeEntry(A, 3,3,5); changeEntry(B, 3,3,8);
    //printf("hi3\n");
   printf("A has %d elements:\n", NNZ(A));
   printMatrix(stdout, A);
   printf("\n");

   printf("B has %d elements:\n", NNZ(B));
   printMatrix(stdout, B);
   printf("\n");

   C = scalarMult(1.5, A);
   printf("1.5 * A has %d elements:\n", NNZ(C));
   printMatrix(stdout, C);
   printf("\n");

   D = sum(A, B);
   printf("A+B has %d elements:\n", NNZ(D));
   printMatrix(stdout, D);
   printf("\n");


   E = diff(A, B);
   printf("A-B has %d elements:\n", NNZ(E));
   printMatrix(stdout, E);
   printf("\n");

   F = transpose(A);
   printf("Transpose of A has %d elements:\n", NNZ(F));
   printMatrix(stdout, F);
   printf("\n");

   G = product(A, B);
   printf("A*B has %d elements:\n", NNZ(G));
   printMatrix(stdout, G);
   printf("\n");

   H = copy(A);
   printf("copy of A has %d elements:\n", NNZ(H));
   printMatrix(stdout, H);
   printf("\n");

   // printf("%s\n", equals(A, H)?"true":"false" );
   assert(equals(A, H) == true);
   // printf("%s\n", equals(A, B)?"true":"false" );
   assert(equals(A,B) == false);
   // printf("%s\n", equals(A, A)?"true":"false" );
   assert(equals(A,A) == true);

   makeZero(A);
   printf("After setting A to zero state, A has %d elements\n", NNZ(A));
   printMatrix(stdout, A);

   freeMatrix(&A);
   freeMatrix(&B);
   freeMatrix(&C);
   freeMatrix(&D);
   freeMatrix(&E);
   freeMatrix(&F);
   freeMatrix(&G);
   freeMatrix(&H);


   return 0;
}
