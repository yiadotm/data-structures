/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA1
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
   printf("List A:                      ");
   printList(stdout,A); 
   printf("\nCompare with actual results: ");
   printf("1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 ");
   printf("\n\n");
   printf("List B:                      ");
   printList(stdout,B); 
   printf("\nCompare with actual results: ");
   printf("35 33 31 29 27 25 23 21 19 17 15 13 11 9 7 5 3 1 ");
   printf("\n\n");

   //check for moveFront, index, moveNext
   printf("------------------------------------------\n");
   printf("Check moveFront(), index(), and moveNext()\n");
   printf("------------------------------------------\n\n");
   printf("List A:                      ");
   for(moveFront(A); index(A)>=0; moveNext(A)){
      //int i;
      //printf("loop %d\n", i++);
      //printf("%d\n", index(A));
      printf("%d ", get(A));
   }
   printf("\nCompare with actual results: ");
   printf("1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 ");
   printf("\n\n");
   //check for moveBack, index, movePrev
   printf("------------------------------------------\n");
   printf("Check moveBack(), index(), and movePrev()\n");
   printf("------------------------------------------\n\n");
   printf("List A:                      ");
   for(moveBack(B); index(B)>=0; movePrev(B)){
      printf("%d ", get(B));
   }
   printf("\nCompare with actual results: ");
   printf("35 33 31 29 27 25 23 21 19 17 15 13 11 9 7 5 3 1 ");
   printf("\n\n");
   //printf("index: %d\n", index(A));

   C = copyList(A);                                   //test for copyList
   //printf("%s\n", equals(A,B)?"true":"false");      
   assert(!equals(A,B));                              //should be false
   //printf("%s\n", equals(B,C)?"true":"false");
   assert(!equals(B,C));                              //should be false
   //printf("%s\n", equals(C,A)?"true":"false");
   assert(equals(C, A));                              //should be true


   //test the inserts
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
   

   //Test the deletes                                                  
   delete(A);                                         //deletes 10
   deleteFront(A);                                    //deletes 1
   deleteBack(A);                                     //deletes 20
   printf("------------------------------------------\n");
   printf("Check delete(), deleteFront(), deleteBack()\n");
   printf("------------------------------------------\n");
   printf("\n");
   printf("List A:                      ");
   printList(stdout,A);
   printf("\nCompare with actual results: ");
   printf("3 5 7 9 3 11 13 17 19 21 23 25 27 29 -33 31 33 ");
   printf("\n\n");   

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

/*
Output of this program:
------------------------------------------
Check append() and prepend()
------------------------------------------

List A:                      1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35
Compare with actual results: 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35

List B:                      35 33 31 29 27 25 23 21 19 17 15 13 11 9 7 5 3 1 
Compare with actual results: 35 33 31 29 27 25 23 21 19 17 15 13 11 9 7 5 3 1 

------------------------------------------
Check moveFront(), index(), and moveNext()
------------------------------------------

List A:                      1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35
Compare with actual results: 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35

------------------------------------------
Check moveBack(), index(), and movePrev()
------------------------------------------

List A:                      1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35
Compare with actual results: 35 33 31 29 27 25 23 21 19 17 15 13 11 9 7 5 3 1 

------------------------------------------
Check delete(), deleteFront(), deleteBack()
------------------------------------------

List A:                       3 5 7 9 3 11 13 17 19 21 23 25 27 29 -33 31 33 
Compare with actual results:  3 5 7 9 3 11 13 17 19 21 23 25 27 29 -33 31 33

*/