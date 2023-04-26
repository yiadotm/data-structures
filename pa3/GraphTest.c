
/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA2
* GraphTest.c
* File that tests the Graph ADT
*********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include <stdint.h>
#include"Graph.h"
#include "List.h"

int main(int argc, char* argv[]){
   //FILE* outfile = fopen("i.txt", "w");
    Graph A = NULL;
    List L = newList();
    for (uint8_t i = 1; i <= 100; i++)
      if (getParent(A, i) != NIL)
        return 1;
    addArc(A, 64, 4);
    addArc(A, 64, 3);
    addArc(A, 42, 2);
    addArc(A, 2, 64);
    addArc(A, 4, 2);
    addArc(A, 3, 42);
    for (uint8_t i = 1; i <= 100; i++) {
      append(L, i);
    }
    DFS(A, L);
    if (getParent(A, 100) != NIL)
      return 2;
    if (getParent(A, 2) != NIL)
      return 3;
    if (getParent(A, 42) != 3)
      return 4;
    if (getParent(A, 3) != 64)
      return 5;
    if (getParent(A, 4) != 64)
      return 6;
    return 0;
 

   

   freeGraph(&A);
   return 0;
}
