/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA4
* Sparse.c
* The main executable for this program. 
* It reads in an input file that contains the data for 2 matrices and 
* runs several arithmetic operations and outputs in a txt file.
*********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "Matrix.h"
#include "List.h"
int main(int argc, char *argv[]) {
    //int opt = 0;
   FILE *infile = stdin;
   FILE *outfile = stdout;
   int n = 0;
   int a = 0;
   int b = 0;
   // check command line for correct number of arguments
   if( argc != 3 ){
      fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }
   // open files for reading and writing 
   infile = fopen(argv[1], "r");
      if( infile==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

   outfile = fopen(argv[2], "w");
   if( outfile==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }      

    
   fscanf(infile, "%d %d %d", &n, &a, &b);
   Matrix A = newMatrix(n);
   Matrix B = newMatrix(n);
   Matrix sA, ApB, ApA, BsA, AsA, T, AmB, BmB;

   for (int i = 0; i < a; i++) {
    int r, c;
    double v;
      fscanf(infile, "%d %d %lf", &r, &c, &v);
      //printf("r: %d, c: %d, v: %0.1f \n", r, c, v);
      changeEntry(A, r, c, v);
   }
   for (int i = 0; i < b; i++) {
    int r, c;
    double v;
      fscanf(infile, "%d %d %lf", &r, &c, &v);
      changeEntry(B, r, c, v);
   }
    
   fprintf(outfile, "A has %d non-zero entries: \n", NNZ(A));
   printMatrix(outfile, A);
   fprintf(outfile, "\n");

   fprintf(outfile, "B has %d non-zero entries: \n", NNZ(B));
   printMatrix(outfile, B);
   fprintf(outfile, "\n");

   fprintf(outfile, "(1.5)*A = \n");
   sA = scalarMult(1.5, A); 
   printMatrix(outfile, sA);
   fprintf(outfile, "\n");

   fprintf(outfile, "A+B = \n");

   ApB = sum(A, B); 
   // printf("NNZ: %d, size: %d\n", NNZ(ApB), size(A));
   printMatrix(outfile, ApB);   
   fprintf(outfile, "\n");


   fprintf(outfile, "A+A = \n");
   ApA = sum(A, A); 
   printMatrix(outfile, ApA);
   fprintf(outfile, "\n");

   fprintf(outfile, "B-A = \n");
   BsA = diff(B, A); 
   printMatrix(outfile, BsA);
   fprintf(outfile, "\n");

   // printf("here\n");

   fprintf(outfile, "A-A = \n");
   AsA = diff(A, A); 
   printMatrix(outfile, AsA);
   fprintf(outfile, "\n");

   fprintf(outfile, "Transpose(A) = \n");
   T = transpose(A); 
   printMatrix(outfile, T);
   fprintf(outfile, "\n");

   fprintf(outfile, "A*B = \n");
   AmB = product(A, B); 
   printMatrix(outfile, AmB);
   fprintf(outfile, "\n");

   fprintf(outfile, "B*B = \n");
   BmB = product(B, B); 
   printMatrix(outfile, BmB);
   fprintf(outfile, "\n");  


//    Matrix ApB, ApA, BsA, AsA, T, AmB, BmB;

   freeMatrix(&A);
   freeMatrix(&B);
   freeMatrix(&sA);
   freeMatrix(&ApB);
   freeMatrix(&ApA);
   freeMatrix(&BsA);
   freeMatrix(&AsA);
   freeMatrix(&T);
   freeMatrix(&AmB);
   freeMatrix(&BmB);

   fclose(infile);
   fclose(outfile);

   return 0;
}