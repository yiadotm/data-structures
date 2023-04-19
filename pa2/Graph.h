/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA2
* Graph.h 
* Header file for Graph ADT
*********************************************************************************/ 
#include <stdio.h>
#include <stdbool.h>
#include "List.h"
typedef int GraphElement;
typedef struct GraphObj* Graph;

#define INF -1
#define NIL -2
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
int getSource(Graph G); // returns the source vertex most recently used in function BFS(), or NIL if
// BFS() has not yet been called
int getParent(Graph G, int u); // will return the parent of vertex u in the BFS tree
// created by BFS(), or NIL if BFS() has not yet been called
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)
int getDist(Graph G, int u); // returns the distance from
// the most recent BFS source to vertex u, 
// or INF if BFS() has not yet been called.
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)
void getPath(List L, Graph G, int u); // appends to the List L the vertices of a shortest path 
// in G from source to u, or appends to L the value NIL if
// no such path exists. 
// Pre: getSource(G)!=NIL
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)

/*** Manipulation procedures ***/
void makeNull(Graph G); // deletes all edges of G, restoring it to its
// original (no edge) state
void addEdge(Graph G, int u, int v); // inserts a new edge joining u to v,
// i.e. u is added to the adjacency List of v, and v to the adjacency List of u.
// Pre: two int arguments must lie in the range 1 to getOrder(G).
void addArc(Graph G, int u, int v); // inserts a new directed edge from u to v, 
// i.e. v is added to the adjacency List of u (but not u to the adjacency List of v)
// Pre: two int arguments must lie in the range 1 to getOrder(G).
void BFS(Graph G, int s); // runs the BFS algorithm on the Graph G with source s,
// setting the color, distance, parent, and source fields of G accordingly

/*** Other operations ***/
void printGraph(FILE* out, Graph G); // prints the adjacency list representation of G 
// to the file pointed to by out
