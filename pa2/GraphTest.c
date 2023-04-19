#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]){

    Graph G = NULL;
    G = newGraph(35);
   for(int i=1; i<35; i++){
      printf("i: %d \n", i);
      if( i%7!=0 ) addEdge(G, i, i+1);
      printf("here 4\n");
      if( i<=28  ) addEdge(G, i, i+7);
      printf("here 10\n");
   }
    
}