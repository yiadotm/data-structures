
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "Graph.h"
#include "List.h"

// INF = -1
// NIL = -2
// white = -3
// grey = -4
// black -5

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
// n vertices and no edges (size)
Graph newGraph(int n) {
    Graph G;
    G = malloc(sizeof(GraphObj));
    assert(G!=NULL);
    G->L = (List*)malloc(n+1*sizeof(List));
    for (int i = 1; i < n+1; i++) {
        G->L[i] = newList();
    }
    
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
    if (pG != NULL && *pG != NULL) {
        for (int i = 0; i < (*pG)->vertices; i++) {
            freeList(&(*pG)->L[i]);
        }
        free((*pG)->color);
        free((*pG)->parent);
        free((*pG)->distance);
        (*pG)->color = NULL;
        (*pG)->parent = NULL;
        (*pG)->distance = NULL;
        free(*pG);
        *pG = NULL;



    }
}

// Access functions -----------------------------------------------------------
// getOrder()
// returns the order of the graph (the vertices)
int getOrder(Graph G) {
    if (G==NULL) {
        printf("List Error: calling getOrder() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return (G->vertices);

}

// getSize()
// returns the size of the graph (edges)
int getSize(Graph G) {
    if (G==NULL) {
        printf("List Error: calling getSize() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return (G->size);
}

//getSource()
// returns the source vertex most recently used in function BFS(), or NIL if
// BFS() has not yet been called
int getSource(Graph G) {
    if (G==NULL) {
        printf("List Error: calling getSource() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    
    if (G->color[G->label] == WHITE) {
        return NIL;
    }

    return (G->label);
}

// getParent()
// will return the parent of vertex u in the BFS tree
// created by BFS(), or NIL if BFS() has not yet been called
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)
int getParent(Graph G, int u) {
    if (G==NULL) {
        printf("List Error: calling getParent() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }

    if (u < 1 || u > getOrder(G)) {
        // printf("List Error: calling getParent() on out of bounds input\n");
        exit(EXIT_FAILURE);
    }

    if (G->color[u] == WHITE) {
        return NIL;
    }
    return(G->parent[u]);
}

// getDist()
// returns the distance from
// the most recent BFS source to vertex u, 
// or INF if BFS() has not yet been called.
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)
int getDist(Graph G, int u) {
    if (G==NULL) {
        printf("List Error: calling getDist() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }

    if (u < 1 || u > getOrder(G)) {
        printf("List Error: calling getDist() on out of bounds input\n");
        exit(EXIT_FAILURE);
    }
    if (G->color[u] == WHITE) {
        return INF;
    }
    return(G->distance[u]);

}

// getPath()
// appends to the List L the vertices of a shortest path 
// in G from source to u, or appends to L the value NIL if
// no such path exists. 
// Pre: getSource(G)!=NIL
// Pre: 1 ≤ 𝑢 ≤ getOrder(𝐺)
void getPath(List L, Graph G, int u) {
    if (getSource(G) == NIL) {
        printf("List Error: calling getPath() when getSource(G) == NIL\n");
        exit(EXIT_FAILURE);       
    }
    if (u < 1 || u > getOrder(G)) {
        printf("List Error: calling getPath() on out of bounds input\n");
        exit(EXIT_FAILURE); 
    }
    if (G->distance[u] == 0) {
        append(L, NIL);
    }
    moveFront(G->L[u]);
    for (int i = 0; i < length(G->L[u]); i++) {
        append(L, get(G->L[u]));
        moveNext(G->L[u]);
    }


    
}

// Manipulation procedures ----------------------------------------------------

// makeNull()
// deletes all edges of G, restoring it to its
// original (no edge) state
void makeNull(Graph G) {
    for (int i = 0; i < G->vertices; i++) {
        clear(G->L[i]);
    }
    G->color = NULL;
    G->parent = NULL;
    G->distance = NULL;
    G->size = 0;
    G->label = 0;
}

//addEdge()
// inserts a new edge joining u to v,
// i.e. u is added to the adjacency List of v, and v to the adjacency List of u.
// Pre: two int arguments must lie in the range 1 to getOrder(G).
void addEdge(Graph G, int u, int v) {
    if (u < 1 || u > getOrder(G)) {
        printf("List Error: calling addEdge() on out of bounds input u\n");
        return;
    }
    if (v < 1 || v > getOrder(G)) {
        printf("List Error: calling addEdge() on out of bounds input v\n");
        return;
    } 
    append(G->L[u], v);
    printf("\n%d: ", u);
    printList(stdout, G->L[u]);
    append(G->L[v], u);
    printf("\n%d: ", v);
    printList(stdout, G->L[v]);
    printf("\n");

    G->size++;
       
}

// addArc()
// inserts a new directed edge from u to v, 
// i.e. v is added to the adjacency List of u (but not u to the adjacency List of v)
// Pre: two int arguments must lie in the range 1 to getOrder(G).
void addArc(Graph G, int u, int v) {
    if (u < 1 || u > getOrder(G)) {
        printf("List Error: calling addArc() on out of bounds input u\n");
        return;
    }
    if (v < 1 || v > getOrder(G)) {
        printf("List Error: calling getArc() on out of bounds input v\n");
        return;
    } 

    append(G->L[u], v);

}
// BFS()
// runs the BFS algorithm on the Graph G with source s,
// setting the color, distance, parent, and source fields of G accordingly
void BFS(Graph G, int s) {
    G->label = s;
    for (int i = 1; i <= G->vertices - s; i++) {
        G->color[i] = WHITE;
        G->distance[i] = INF;
        G->parent[i] = NIL;
    }
    G->color[s] = GREY;
    G->distance[s] = 0;
    List L = newList();
    append(L, s);
    while (L != NULL) {
        moveFront(L);
        int i = get(L);
        deleteFront(L);
        for (int y = 1; y <= length(G->L[i]); y++) {
            if (G->color[y] == WHITE) {
                G->color[y] = GREY;
                G->distance[y] = G->distance[i] + 1;
                G->parent[y] = i;
                append(L, y);
            }
        }
        G->color[i] = BLACK;
    }
}

// Other operations -----------------------------------------------------------

//printGraph()
// prints the adjacency list representation of G 
// to the file pointed to by out
void printGraph(FILE* out, Graph G) {
    for (int i = 1; i <= G->vertices; i++) {
        List L = newList();
        fprintf(out, "%d: ", i);
        getPath(L, G, i);
        printList(out, L);
        fprintf(out, "\n");

    }
}   