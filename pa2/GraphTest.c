#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include"Graph.h"
#include "List.h"

int main(int argc, char* argv[]){
   //FILE* outfile = fopen("i.txt", "w");
    Graph A = NULL;
     A = newGraph(15);
      for(int i=1; i<=15; i++){
      //printf("i: %d \n", i);
      if( i%5!=0 ) addEdge(A, i, i+1);
      //printf("here 4\n");
      if( i<=10  ) addEdge(A, i, i+5);
      //printf("here 10\n");
   }
   printf("------------------------------------------\n");
   printf("Check addEdge() and printGraph()\n");
   printf("------------------------------------------\n\n");
   printf("List A:                      \n");
   printGraph(stdout, A);
   printf("\nCompare with actual results: \n");
   printf("1: 2 6 \n2: 1 3 7 \n3: 2 4 8 \n4: 3 5 9 \n5: 4 10 \n6: 1 7 11 \n7: 2 6 8 12 \n8: 3 7 9 13 \n9: 4 8 10 14 \n10: 5 9 15 \n11: 6 12 \n12: 7 11 13 \n13: 8 12 14 \n14: 9 13 15 \n15: 10 14 \n");
   printf("\n------------------------------------------\n");
   printf("Check BFS() getDist() getParent() and getSource()\n");
   printf("------------------------------------------\n");  
   printf("\nIf there are no asserts, then they passed\n\n");
   assert(getSource(A));
   BFS(A, 3);
   assert(getSource(A));
   assert(getDist(A, 3) == 0);
   assert(getDist(A, 14) == 3);
   assert(getParent(A, 4) == 3);
   assert(getParent(A, 3) == NIL);
   assert(getParent(A, 10) == 5);
 

   

   freeGraph(&A);
   return 0;
}
