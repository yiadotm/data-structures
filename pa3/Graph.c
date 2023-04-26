/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA2
* Graph.c
* File Implementation of Graph ADT.
*********************************************************************************/
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
int time = 0;
// structs --------------------------------------------------------------------
//private GraphObj type
typedef struct GraphObj {
    List* L;
    GraphElement* color;
    GraphElement* parent;
    GraphElement* discover;
    GraphElement* finish;
    int vertices;
    int size;


} GraphObj;

// Constructors-Destructors ---------------------------------------------------
// newGraph()
// returns a Graph pointing to a newly created GraphObj representing a graph having
// n vertices and no edges (size)
Graph newGraph(int n) {
    Graph G = (Graph)malloc(sizeof(GraphObj));
    assert(G!=NULL);
    G->L = (List*)calloc(n+1, sizeof(List));
    G->color = (GraphElement*)calloc(n+1, sizeof(GraphElement));
    G->parent = (GraphElement*)calloc(n+1, sizeof(GraphElement));
    G->discover = (GraphElement*)calloc(n+1, sizeof(GraphElement));
    G->finish = (GraphElement*)calloc(n+1, sizeof(GraphElement));

    for (int i = 1; i < n+1; i++) {
        G->L[i] = newList();
        // printf("initial list length: %d\n", length(G->L[i]));
        G->color[i] = WHITE;
        G->parent[i] = NIL;
        G->discover[i] = UNDEF;
        G->finish[i] = UNDEF;
    }
    
    // printf("[1]: %d\n", length(G->L[1]));
    // append(G->L[1], 2);
    // printf("[1]: %d\n", length(G->L[1]));
    //printf("size index 1: %d\n", length(G->L[1]));

    G->vertices = n;
    G->size = 0;
    return (G);
}

// freeGraph()
// frees all heap memory associated with the Graph *pG,
// then sets the handle *pG to NULL
void freeGraph(Graph* pG) {
    if (pG != NULL && *pG != NULL) {
        // for (int i = 1; i <= (*pG)->vertices; i++) {
        //     freeList(&((*pG)->L[i]));
        // }
        // free((*pG)->L);
        // free((*pG)->color);
        // free((*pG)->parent);
        // free((*pG)->distance);
        makeNull(*pG);
        free(*pG);
        *pG = NULL;

    }
}

// Access functions -----------------------------------------------------------
// getOrder()
// returns the order of the graph (the vertices)
int getOrder(Graph G) {
    if (G==NULL) {
        printf("Graph Error: calling getOrder() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return (G->vertices);

}

// getSize()
// returns the size of the graph (edges)
int getSize(Graph G) {
    if (G==NULL) {
        printf("Graph Error: calling getSize() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return (G->size);
}



// getParent()
// will return the parent of vertex u in the DFS tree
// Pre: 1<=u<=n=getOrder(G)
int getParent(Graph G, int u) {
    if (G==NULL) {
        printf("Graph Error: calling getParent() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }

    if (u < 1 || u > getOrder(G)) {
        // printf("List Error: calling getParent() on out of bounds input\n");
        exit(EXIT_FAILURE);
    }
    if (G->parent[u] == NIL) {
        return NIL;
    }
    return(G->parent[u]);
}

// get Discover()
// returns the discover time of vertex u
// Pre: 1<=u<=n=getOrder(G)
int getDiscover(Graph G, int u) {
    if (u < 1 || u > getOrder(G)) {
        // printf("List Error: calling getDiscover() on out of bounds input\n");
        exit(EXIT_FAILURE);
    }

    return(G->discover[u]);
}

// getFinish()
// returns the finish time of vertex u
// Pre: 1<=u<=n=getOrder(G)
int getFinish(Graph G, int u) {
    if (u < 1 || u > getOrder(G)) {
        // printf("List Error: calling getFinish() on out of bounds input\n");
        exit(EXIT_FAILURE);
    }
    return(G->finish[u]);
}

// Manipulation procedures ----------------------------------------------------


// makeNull()
// deletes all edges of G, restoring it to its
// original (no edge) state
void makeNull(Graph G) {
    for (int i = 1; i <= G->vertices; i++) {
        freeList(&(G->L[i]));
        G->L[i] = NULL;
    }
    free(G->L);
    free(G->color);
    free(G->parent);
    free(G->discover);
    free(G->finish);
    G->L = NULL;
    G->color = NULL;
    G->parent = NULL;
    G->discover = NULL;
    G->finish = NULL;
    G->size = 0;


}

// addArc()
// inserts a new directed edge from u to v, 
// i.e. v is added to the adjacency List of u (but not u to the adjacency List of v)
// Pre: 1<=u<=n, 1<=v<=n 
void addArc(Graph G, int u, int v) {
    if (u < 1 || u > getOrder(G)) {
        printf("Graph Error: calling addArc() on out of bounds input u\n");
        return;
    }
    if (v < 1 || v > getOrder(G)) {
        printf("Graph Error: calling getArc() on out of bounds input v\n");
        return;
    } 

    //printf("size 1: %d\n", length(G->L[u]));
    // if there is nothing to the list
    if (isEmpty(G->L[u])) {
        // printf("size 1: %d\n", length(G->L[u]));
        //printf("size 3: %d\n", length(G->L[u]));

        append(G->L[u], v);
        G->size++;

        // printf("size 2: %d\n", length(G->L[u]));
        // printf("%d: ", u);
        // printList(stdout, G->L[u]);
        // printf("\n");
        return;
    }
    moveFront(G->L[u]);
    //printf("cursor: %d \n", index(G->L[u]));

    for (int i = 0; i < length(G->L[u]); i++) {
        //printf("cursor: %d \n", get(G->L[u]));
        if (v < get(G->L[u])) {
            //printf("insert\n");
            insertBefore(G->L[u], v);
            break;
        }
        if (i == length(G->L[u]) - 1) {
            append(G->L[u], v);
            //printf("append\n");
            // printList(stdout, L);
            break;
        }        
        moveNext(G->L[u]);
    }
    // printf("%d: ", u);
    // printList(stdout, G->L[u]);
    // printf("\n");

    G->size++;
}

//addEdge()
// inserts a new edge joining u to v,
// i.e. u is added to the adjacency List of v, and v to the adjacency List of u.
// Pre: 1<=u<=n, 1<=v<=n 
void addEdge(Graph G, int u, int v) {
    if (u < 1 || u > getOrder(G)) {
        printf("Graph Error: calling addEdge() on out of bounds input u\n");
        return;
    }
    if (v < 1 || v > getOrder(G)) {
        printf("Graph Error: calling addEdge() on out of bounds input v\n");
        return;
    } 
    addArc(G, u, v);
    addArc(G, v, u);


    G->size--;
       
}
// Visit()
// visits the vertex and sets the discover/finished time
void Visit(Graph G, int u, List A) {
    G->discover[u] = ++time;
    G->color[u] = GREY;
    moveFront(G->L[u]);
    for (int i = 0; i < length(G->L[u]); i++) {
        int y = get(G->L[u]);
        if (G->color[y] == WHITE) {
            G->parent[y] = u;
            Visit(G, y, A);
        }
        // if (i == length(G->L[u]) - 1) {
            
        //     //printf("append\n");
        //     // printList(stdout, L);
        //     break;
        // } 
        moveNext(G->L[u]);
    }
    G->color[u] = BLACK;
    // printf("\ntime: %d\n", time);
    G->finish[u] = ++time;
    prepend(A, u);

    
}
// DFS()
// perform the depth first search algorithm on G
// Pre: (i) length(𝑆) == 𝑛, and (ii) S contains some permutation of the integers {1, 2, … , 𝑛}
// where 𝑛 = getOrder(𝐺)
void DFS(Graph G, List S) {
    List copy = newList();
    copy = copyList(S);
    clear(S);
    if (length(copy) != getOrder(G)) {
        printf("Graph Error: calling DPS() when List S is not equal to vertices of Graph G \n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i <= getOrder(G); i++) {
        G->color[i] = WHITE;
        G->parent[i] = 0;

    }
    time = 0;
    moveFront(copy);
    for (int i = 1; i <= getOrder(G); i++) {
        int x = get(copy);
        if (G->color[x] == WHITE) {
            Visit(G, x, S);
        }
        // if (i == length(G->L[x]) - 1) {
            
        //     //printf("append\n");
        //     // printList(stdout, L);
        //     break;
        // } 
        moveNext(copy);
    }

    // printf("\n");
    // printList(stdout, copy);
    // printf("\n");
    // clear(S);
    // S = copyList(copy);
    
    // printf("length: %d\n", length(S));
    // printf("Copy: ");
    // printList(stdout, copy);
    // printf("\n");
    // printList(stdout, S);
    // printf("\n");
    // freeList(&copy);

    // clear(S);
    // moveFront(S);
    // for (int i = 1; i <= getOrder(G); i++) {
    //     int x = get(S);
    //     if (G->finish[i] > G->finish[x]) {
    //         insertBefore(S, i);
    //         moveNext(S);
    //         continue;
    //     }
    //     if (i == length(S) - 1) {
    //         append(S, i);
    //         //printf("append\n");
    //         // printList(stdout, L);
    //         break;
    //     } 
    //     moveNext(S); 
    // }
    // printList(stdout, S);
}
// Other operations -----------------------------------------------------------

//transpose()
// returns a reference to a new graph object 
// representing the transpose of G
Graph transpose(Graph G) {
    Graph new = newGraph(getOrder(G));
    for (int i = 1; i <= getOrder(G); i++) {
        moveFront(G->L[i]);
        for (int j = 0; j < length(G->L[i]); j++) {
            int x = get(G->L[i]);
            addArc(new, x, i);
            moveNext(G->L[i]);
        }
    }
    new->vertices = getOrder(G);
    new->size = getSize(G);
    return(new);
}

//copyGraph()
// returns a reference to a new graph that 
// is a copy of G
Graph copyGraph(Graph G) {
    Graph new = newGraph(getOrder(G));
    assert(G!=NULL);
    for (int i = 1; i <= getOrder(G); i++) {
        // printList(stdout, G->L[i]);
        // printf("\n");
        if (!isEmpty(G->L[i])) {
            new->L[i] = copyList(G->L[i]);
        }

        // printList(stdout, G->L[i]);
        // printf("\n");
        // printList(stdout, new->L[i]);
        // printf("\n");
        // new->color[i] = G->color[i];

    }
    new->vertices = getOrder(G);
    new->size = getSize(G);
    return(new);
}

//printGraph()
// prints the adjacency list representation of G 
// to the file pointed to by out
void printGraph(FILE* out, Graph G) {
    for (int i = 1; i <= G->vertices; i++) {
        //List L = newList();
        fprintf(out, "%d: ", i);
        //getPath(L, G, i);
        printList(out, G->L[i]);
        fprintf(out, "\n");

    }

}   
