
/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA3
* GraphTest.c
* File that tests the Graph ADT
*********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include"Graph.h"
#include "List.h"

int main(int argc, char* argv[]){
   //FILE* outfile = fopen("i.txt", "w");
    Graph A = newGraph(15);
    
    List S = newList();
     A = newGraph(15);
      for(int i=1; i<=15; i++){
      //printf("i: %d \n", i);
      if( i%5!=0 ) addArc(A, i, i+1);
      //printf("here 4\n");
      if( i<=10  ) addArc(A, i, i+5);
      //printf("here 10\n");
   }
   Graph T = transpose(A);
   for(int i=1; i<=15; i++) append(S, i);
   printf("------------------------------------------\n");
   printf("Check addArc() transpose() and printGraph()\n");
   printf("------------------------------------------\n\n");
   printf("List A:                      \n");
   printGraph(stdout, A);
   printf("\nCompare with actual results: \n");
   printf("1: 2 6\n2: 3 7\n3: 4 8 \n4: 5 9 \n5: 10 \n6: 7 11 \n7: 8 12 \n8: 9 13 \n9: 10 14 \n10: 15 \n11: 12 \n12: 13 \n13: 14 \n14: 15 \n15:  \n");
   printf("\nList T (Transpose):                      \n");
   printGraph(stdout, T);
   printf("\nCompare with actual results: \n");
   printf("1: \n2: 1 \n3: 2 \n4: 3 \n5: 4 \n6: 1 \n7: 2 6 \n8: 3 7 \n9: 4 8 \n10: 5 9 \n11: 6 \n12: 7 11 \n13: 8 12 \n14: 9 13 \n15: 10 14 \n");
   printf("\n------------------------------------------\n");
   printf("Check DFS() transpose() getDiscover() getParent() and getFinish()\n");
   printf("------------------------------------------\n");  
   printf("\nIf there are no asserts, then they passed\n\n");
   DFS(A, S);
   DFS(T, S);
   

   // assert(getDiscover(A, 3) == 3);
   // assert(getDiscover(A, 14) == 12);
   // assert(getParent(A, 4) == 3);
   // assert(getParent(A, 3) == 2);
   // assert(getParent(A, 10) == 5);
   // assert(getFinish(A, 13) == 20);
   // assert(getFinish(A, 9) == 14);

   // printf("%d\n",getDiscover(A, 3));
   // printf("%d\n",getDiscover(A, 14));
   // printf("%d\n",getParent(A, 4));
   // printf("%d\n",getParent(A, 3));
   // printf("%d\n",getParent(A, 10));
   // printf("%d\n",getFinish(A, 13));
   // printf("%d\n",getFinish(A, 9));




   

   freeGraph(&A);
   return 0;
}
