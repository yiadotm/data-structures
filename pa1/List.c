/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA1
* List.c
* File Implementation of List ADT
*********************************************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "List.h"

// structs --------------------------------------------------------------------
// private Node type
typedef struct NodeObj* Node;

// private NodeObj type
typedef struct NodeObj{
   ListElement data;
   Node prev;
   Node next;
} NodeObj;

// private ListObj type
typedef struct ListObj{
   Node front;
   Node back;
   Node cursor;
   int index;
   int length;
} ListObj;

// Constructors-Destructors ---------------------------------------------------
// newNode()
// Returns reference to new Node object. Initializes next and data fields.
Node newNode(ListElement data){
   Node N = malloc(sizeof(NodeObj));
   assert( N!=NULL );
   N->data = data;
   N->next = N->prev = NULL;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newList()
// Returns reference to new empty List object.
List newList(){
   List L;
   L = malloc(sizeof(ListObj));
   assert( L!=NULL );
   L->front = L->back = L->cursor= NULL;
   L->length = L->index = 0;
   return(L);
}

// freeList()
// Frees all heap memory associated with List *pL, and sets *pL to NULL.
void freeList(List* pL){
   if(pL!=NULL && *pL!=NULL) { 
      while( !isEmpty(*pL) ) { 
         deleteFront(*pL); 
      }
      free(*pL);
      *pL = NULL;
   }
}

// Access functions -----------------------------------------------------------

// length()
// Returns the length of the List.
int length(List L) {
    if (L==NULL) {
        printf("List Error: calling length() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    return(L->length);
}
// index()
// Returns the index of the cursor element. If not defined, return -1.
int index(List L) {
    if (L==NULL) {
        printf("List Error: calling index() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (L->index < 0 ||L->index > length(L)) {
        return -1;
    }
    return(L->index);
}

// front()
// Returns the value at the front of L.
// Pre: !isEmpty(L)
int front(List L) {
   if( L==NULL ){
      printf("List Error: calling front() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(L) ){
      printf("List Error: calling front() on an empty List\n");
      exit(EXIT_FAILURE);
   }
   return(L->front->data);    
}

// back()
// Return the value at the back of L.
// Pre: !isEmpty(L)
int back(List L) {
   if( L==NULL ){
      printf("List Error: calling back() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(L) ){
      printf("List Error: calling back() on an empty List\n");
      exit(EXIT_FAILURE);
   }

   return(L->back->data); 
}
// get()
// Return the value at the index of the cursor element.
// Pre: length()>0, index()>=0
int get(List L) {
   if( L==NULL ){
      printf("List Error: calling get() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(L) ){
      printf("List Error: calling get() on an empty List\n");
      exit(EXIT_FAILURE);
   }
      if(index(L) < 0){
      printf("List Error: calling get() on an index out of bounds\n");
      exit(EXIT_FAILURE);
   }
   return(L->cursor->data);
}
// equals()
// Returns true iff Lists A and B are in same state, and returns false otherwise.
bool equals(List A, List B) {
   if( A==NULL || B==NULL ){
      printf("List Error: calling equals() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }

   bool eq;
   Node N, M;

   eq = ( A->length == B->length );
   N = A->front;
   M = B->front;
   while( eq && N!=NULL){
      eq = ( N->data==M->data );
      N = N->next;
      M = M->next;
   }
   return eq;
}

// isEmpty()
// Returns true if Q is empty, otherwise returns false.
bool isEmpty(List L){
   if( L==NULL ){
      printf("List Error: calling isEmpty() on NULL List reference\n");
      exit(EXIT_FAILURE);
   }
   return(L->length==0);
}

// Manipulation procedures ----------------------------------------------------

// clear()
// Resets L to its original empty state.
void clear(List L) {
   if( isEmpty(L) ){
      return;
   }  
   L->front = L->back = L->cursor= NULL;
   L->length = L->index = 0;

}
// set()
// Overwrites the cursor element’s data with x
// Pre: length()>0, index()>=0
void set(List L, int x) {
   if (L->length < 0 || L->index < 0) {
      printf("List Error: calling set() with out of bounds parameter.\n");
      exit(EXIT_FAILURE);
   }
   L->cursor->data = x;

}

// moveFront()
// If L is non-empty, sets cursor under the front element, otherwise does nothing.
void moveFront(List L) {
   if( isEmpty(L) ){
      return;
   }
   L->front->next = L->cursor;

}

// moveBack()
// If L is non-empty, sets cursor under the back element, otherwise does nothing.
void moveBack(List L) {
   if( isEmpty(L) ){
      return;
   }
   L->back->next = L->cursor;

}
// movePrev()
// If cursor is defined and not at front, move cursor one
// step toward the front of L; if cursor is defined and at
// front, cursor becomes undefined; if cursor is undefined
// do nothing
void movePrev(List L) {
   if (L->index != -1 && L->cursor != L->front) {
      L->index--;
      L->cursor = L->cursor->prev;
   }

   if (L->index != -1 && L->cursor == L->front) {
      L->index = -1;
   }
}

// moveNext()
// If cursor is defined and not at back, move cursor one
// step toward the back of L; if cursor is defined and at
// back, cursor becomes undefined; if cursor is undefined
// do nothing
void moveNext(List L) {
   if (L->index != -1 && L->cursor != L->back) {
      L->index++;
      L->cursor = L->cursor->next;
   }

   if (L->index != -1 && L->cursor == L->front) {
      L->index = -1;
   }

}

// prepend()
// Insert new element into L. If L is non-empty,
// insertion takes place before front element.
void prepend(List L, int x) {
   Node N = newNode(x);

   if( L==NULL ){
      printf("Queue Error: calling Enqueue() on NULL Queue reference\n");
      exit(EXIT_FAILURE);
   }
   
   if( isEmpty(L) ) { 
      L->front = L->back = N; 
   }else{ 
      L->front->next = N; 
      L->front = N; 
   }
   L->length++;
}

