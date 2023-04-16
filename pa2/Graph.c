
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "Graph.h"
#include "List.h"

// structs --------------------------------------------------------------------
//private GraphObj type
typedef struct GraphObj {
    List* L;
    GraphElement* color;
    GraphElement* parent;
    GraphElement* distance;
    int vertices;
    int size;
    int label;

} GraphObj;

// Constructors-Destructors ---------------------------------------------------
// newGraph()
// returns a Graph pointing to a newly created GraphObj representing a graph having
// n vertices and no edges
Graph newGraph(int n) {
    Graph G;
    G = malloc(sizeof(GraphObj));
    assert(G!=NULL);
    G->color = (GraphElement*)malloc(n+1*sizeof(GraphElement));
    G->parent = (GraphElement*)malloc(n+1*sizeof(GraphElement));
    G->distance = (GraphElement*)malloc(n+1*sizeof(GraphElement));
    G->vertices = n;
    G->size = 0;
    G->label = 0;
    return (G);
}

// freeGraph()
// frees all heap memory associated with the Graph *pG,
// then sets the handle *pG to NULL
void freeGraph(Graph* pG) {

}

// Access functions -----------------------------------------------------------
// getOrder()
// returns the order of the graph
int getOrder(Graph G) {

}

// getSize()
// returns the size of the graph
int getSize(Graph G) {

}

//getSource()
// returns the source vertex most recently used in function BFS(), or NIL if
// BFS() has not yet been called
int getSource(Graph G) {

}

// getParent()
// will return the parent of vertex u in the BFS tree
// created by BFS(), or NIL if BFS() has not yet been called
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)
int getParent(Graph G, int u) {

}

// getDist()
// returns the distance from
// the most recent BFS source to vertex u, 
// or INF if BFS() has not yet been called.
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)
int getDist(Graph G, int u) {

}

// getPath()
// appends to the List L the vertices of a shortest path 
// in G from source to u, or appends to L the value NIL if
// no such path exists. 
// Pre: getSource(G)!=NIL
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)
void getPath(List L, Graph G, int u) {
    
}

// Manipulation procedures ----------------------------------------------------

// makeNull()
// deletes all edges of G, restoring it to its
// original (no edge) state
void makeNull(Graph G) {

}

//addEdge()
// inserts a new edge joining u to v,
// i.e. u is added to the adjacency List of v, and v to the adjacency List of u.
// Pre: two int arguments must lie in the range 1 to getOrder(G).
void addEdge(Graph G, int u, int v) {

}

// addArc()
// inserts a new directed edge from u to v, 
// i.e. v is added to the adjacency List of u (but not u to the adjacency List of v)
// Pre: two int arguments must lie in the range 1 to getOrder(G).
void addArc(Graph G, int u, int v) {

}
// BFS()
// runs the BFS algorithm on the Graph G with source s,
// setting the color, distance, parent, and source fields of G accordingly
void BFS(Graph G, int s) {

}

// Other operations -----------------------------------------------------------

//printGraph()
// prints the adjacency list representation of G 
// to the file pointed to by out
void printGraph(FILE* out, Graph G) {

}