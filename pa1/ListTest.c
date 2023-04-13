/****************************************************************************************
*  ListClient.c
*  Test client for List ADT
*****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"List.h"

int main(int argc, char* argv[]){
   
   List A = newList();
   List B = newList();
   List C = NULL;
   // List Piyush = newList();
   int i;
   // printf("Created Lists.\n");
   // List O = newList();
   // append(O, 1);
   // append(O, 2);
   // prepend(O, 3);
   // prepend(O, 4);
   // printList(stdout, O);
   // moveBack(O);
   // printf("index: %d\n", index(O));
   // printf("c: %d\n", get(O));
   // movePrev(O);
   // printf("index: %d\n", index(O));
   // printf("c: %d\n", get(O));

   //insertAfter(O, 5);
   // movePrev(O);
   // printf("index: %d\n", index(O));
   // printf("c: %d\n", get(O));
   // insertAfter(O, 6);
   // printList(stdout, O);
   // printf("\n");

   // insertBefore(O, 7);

   // printList(stdout, O);
   // printf("\nseparator\n");


   for(i=1; i<=20; i++){
      //printf("loop %d.\n", i);
      append(A,i);
      //printf("append good.\n");
      //printList(stdout,A);
      //printf("print good.\n");
      prepend(B,i);
   }
   //printf("appended and prepended.\n");
   printList(stdout,A); 
   printf("\n");
   printList(stdout,B); 
   printf("\n");

   for(moveFront(A); index(A)>=0; moveNext(A)){
      //int i;
      //printf("loop %d\n", i++);
      //printf("%d\n", index(A));
      printf("%d ", get(A));
   }
   printf("\n");
   for(moveBack(B); index(B)>=0; movePrev(B)){
      printf("%d ", get(B));
   }
   printf("\n");
   //printf("index: %d\n", index(A));
   C = copyList(A);
   printf("%s\n", equals(A,B)?"true":"false");
   printf("%s\n", equals(B,C)?"true":"false");
   printf("%s\n", equals(C,A)?"true":"false");


   moveFront(A);
   for(i=0; i<5; i++) moveNext(A); // at index 5
   // printf("index: %d\n", index(A));
   // printf("cursor: %d\n", get(A));
   insertBefore(A, -1);            // at index 6
   for(i=0; i<9; i++){ moveNext(A); } // at index 15 
   insertAfter(A, -2);
   //printList(stdout, A);
   //printf("cursor: %d\n", get(A));
   for(i=0; i<5; i++) movePrev(A); // at index 10
   delete(A);
   printList(stdout,A);
   //printf("\n");
   printf("%d\n", length(A));
   clear(A);
   printf("%d\n", length(A));

   // append(Piyush, 2);
   // append(Piyush, 3);
   // moveFront(Piyush);
   // printList(stdout, Piyush);
   // printf("\n");
   // insertAfter(Piyush, 5);
   // printList(stdout, Piyush);
   // printf("\n");
   // printf("Cursor at %d\n", index(Piyush));
   // moveNext(Piyush);
   // printf("Cursor at %d\n", index(Piyush));
   // insertBefore(Piyush, 6);
   // printf("Cursor at %d\n", index(Piyush));
   // printList(stdout, Piyush);
   // printf("Cursor at %d\n", index(Piyush));
   


   //freeList(&Piyush);

   freeList(&A);
   freeList(&B);
   freeList(&C);

   return(0);
}

/*
Output of this program:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
false
false
true
1 2 3 4 5 -1 6 7 8 9 11 12 13 14 15 -2 16 17 18 19 20
21
0
*/