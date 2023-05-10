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


int main(int argc, char* argv[]){
  List A = newList();
   List B = newList();
   List C = NULL;
   //List owen = newList();
   int i;
   //char * app = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20";
   ///char * pre = "20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1";
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


   for(i=1; i<=35; i+=2){
      //printf("loop %d.\n", i);
      append(A,i);
      //printf("append good.\n");
      //printList(stdout,A);
      //printf("print good.\n");
      prepend(B,i);
   }
   printf("------------------------------------------\n");
   printf("Check append() and prepend()\n");
   printf("------------------------------------------\n\n");
   assert(length(A) == 18);
   assert(length(B) == 18);
   printf("If no asserts, then the tests passed\n");



   //test the inserts
   printf("------------------------------------------\n");
   printf("Check insertBefore()\n");
   printf("------------------------------------------\n\n");   
   moveFront(A);
   assert(front(A) == 1);                             //front should be 1
   assert(back(A) == 35);                             //back should be 20
   for(i=0; i<5; i++) moveNext(A); // at index 5
   // printf("index: %d\n", index(A));
   // printf("cursor: %d\n", get(A));
   insertBefore(A, 3);            // at index 6      //insertBefore()
   for(i=0; i<9; i++){ moveNext(A); } // at index 15 
   insertAfter(A, -33);                                //insertAfter
   //printList(stdout, A);
   //printf("cursor: %d\n", get(A));
   for(i=0; i<7; i++) movePrev(A); // at index 12
    printf("If no asserts, then the tests passed\n");


   //Test the deletes                                                  
   delete(A);                                         //deletes 10
   deleteFront(A);                                    //deletes 1
   deleteBack(A);                                     //deletes 20
   printf("------------------------------------------\n");
   printf("Check delete(), deleteFront(), deleteBack()\n");
   printf("------------------------------------------\n");
   printf("\nIf no asserts, then the tests passed\n");

   //printf("%d\n", length(A));
   assert(length(A) == 17);                           //length should be 17
   clear(A);
   //printf("%d\n", length(A));
   assert(length(A) == 0);                            //length should be 0

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