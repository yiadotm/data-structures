/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA2
* FindPath.c
* The main executable for this program. 
* It reads multiple pairs of values to "0-0" from a specified 
* input file and sorts the file from least to greatest for each adj List.
* It then finds the shortest path from the following pair of values after the "0-0" 
* and finds the distance from the specified values.
*********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include "Graph.h"
#include "List.h"
int main(int argc, char *argv[]) {
    //int opt = 0;
   FILE *infile = stdin;
   FILE *outfile = stdout;
   int n = 0;
   int u = 0;
   int v = 0;
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

    
   fscanf(infile, "%d", &n);
   Graph G = newGraph(n);
   while (!feof(infile)) {
      fscanf(infile, "%d %d", &u, &v);
      if (u == 0 && v == 0) {
         break;
      }
      addEdge(G, u, v);
   }
   printGraph(outfile, G);
   fprintf(outfile, "\n");
   int dist = 0;
   while(!feof(infile)) {
   
      
      fscanf(infile, "%d %d", &u, &v);
      if (u == 0 && v == 0) {
         break;
      }   
      BFS(G, u);
      dist = getDist(G, v);
      if (dist == INF) {
         fprintf(outfile, "The distance from %d to %d is infinity\n", u, v);
         
      } else {
         fprintf(outfile, "The distance from %d to %d is %d\n", u, v, getDist(G, v));
      }
      List L = newList();
      getPath(L, G, v);
      moveFront(L);
      if (dist == INF) {
         fprintf(outfile, "No %d-%d path exists\n\n", u, v);
         
      }
      else {
         fprintf(outfile, "A shortest %d-%d path is: ", u, v);
         printList(outfile, L);
         fprintf(outfile, "\n\n");

      }
   }
   

   freeGraph(&G);
   return 0;
}
