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
      addArc(G, u, v);
   }
   fprintf(outfile, "Adjacency list representation of G:\n");
   printGraph(outfile, G);
   fprintf(outfile, "\n");
   
   Graph T = transpose(G);
   List S = newList();
   for(int i=1; i<=n; i++) append(S, i);
   DFS(G, S);
   DFS(T, S);
   int count = 1;
   //Graph SCC = newGraph(length(S));
   List* SCC = (List*)calloc(length(S)+1, sizeof(List));
   for (int i = 1; i < length(S)+1; i++) {
      SCC[i] = newList();
   }
   moveBack(S);
   while (index(S) != -1) {
      prepend(SCC[count], get(S));
      // addArc(SCC, count, get(S));
      // printf("parent of %d: %d\n", get(S), getParent(T, get(S)));
      if (getParent(T, get(S)) == 0) {
         count++;
      }
      movePrev(S);

   }

   // }
   // printGraph(outfile, SCC);
   // printList(outfile, S);
   // fprintf(outfile, "\n");
   if (count-1 == 1) {
      fprintf(outfile, "G contains 1 strongly connected component:\n");
   }
   else if (count-1 == 0) {
      fprintf(outfile, "G contains 0 strongly connected components.\n");
      freeGraph(&G);
      freeGraph(&T);
      freeGraph(&SCC);
      freeList(&S);
      fclose(infile);
      fclose(outfile);
      return 0;
   }
   else {
      fprintf(outfile, "G contains %d strongly connected components:\n", count-1);
   }
   // fprintf(outfile, "G contains %d strongly connected components:\n", count-1);
   for (int i = 1; i < count; i++) {
      fprintf(outfile, "Component %d: ", i);
      printList(outfile, SCC[i]);
      fprintf(outfile, "\n");
   }
   freeGraph(&G);
   freeGraph(&T);
   //freeGraph(&SCC);
   for (int i = 1; i < length(S)+1; i++) {
      freeList(&SCC[i]);
   }
   free(SCC);
   freeList(&S);
   fclose(infile);
   fclose(outfile);
   return 0;
}
