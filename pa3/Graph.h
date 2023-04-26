/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA3
* Graph.h 
* Header file for Graph ADT
*********************************************************************************/ 
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "List.h"
typedef int GraphElement;
typedef struct GraphObj* Graph;

#define UNDEF -1
#define NIL 0
#define WHITE -3
#define GREY -4
#define BLACK -5
/*** Constructors-Destructors ***/
Graph newGraph(int n); // returns a Graph pointing to a newly created GraphObj representing a graph having
// n vertices and no edges
void freeGraph(Graph* pG); // frees all heap memory associated with the Graph *pG,
// then sets the handle *pG to NULL

/*** Access functions ***/
int getOrder(Graph G); // returns the order of the graph
int getSize(Graph G);  // returns the size of the graph
int getParent(Graph G, int u); // will return the parent of vertex u in the DFS tree
// Pre: 1<=u<=n=getOrder(G)
List getList(Graph G, int u); // returns the list element at u vertex

int getDiscover(Graph G, int u); // returns the discover time of vertex u
// Pre: 1<=u<=n=getOrder(G)
int getFinish(Graph G, int u); // returns the finish time of vertex u
// Pre: 1<=u<=n=getOrder(G)

/*** Manipulation procedures ***/
void addEdge(Graph G, int u, int v); // inserts a new edge joining u to v,
// i.e. u is added to the adjacency List of v, and v to the adjacency List of u.
// Pre: 1<=u<=n, 1<=v<=n 
void addArc(Graph G, int u, int v); // inserts a new directed edge from u to v, 
// i.e. v is added to the adjacency List of u (but not u to the adjacency List of v)
// Pre: 1<=u<=n, 1<=v<=n 
void DFS(Graph G, List S); // perform the depth first search algorithm on G
// Pre: (i) length(𝑆) == 𝑛, and (ii) S contains some permutation of the integers {1, 2, … , 𝑛}
// where 𝑛 = getOrder(𝐺)
/*** Other operations ***/
Graph transpose(Graph G); // returns a reference to a new graph object 
// representing the transpose of G
Graph copyGraph(Graph G); // returns a reference to a new graph that 
// is a copy of G
void printGraph(FILE* out, Graph G); // prints the adjacency list representation of G 
// to the file pointed to by out
