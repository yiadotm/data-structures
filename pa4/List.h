/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA4
* List.h 
* Header file for List ADT
*********************************************************************************/ 
#pragma once
#include <stdio.h>
#include <stdbool.h>

#define UNUSED(x) (void)x 
typedef void* ListElement;
typedef struct ListObj* List;


// Constructors-Destructors ---------------------------------------------------
List newList(void); // Creates and returns a new empty List.

void freeList(List* pL); // Frees all heap memory associated with *pL, and sets
 // *pL to NULL.

// Access functions -----------------------------------------------------------
int length(List L); // Returns the number of elements in L.

int index(List L); // Returns index of cursor element if defined, -1 otherwise.

ListElement front(List L); // Returns front element of L. Pre: length()>0

ListElement back(List L); // Returns back element of L. Pre: length()>0

ListElement get(List L); // Returns cursor element of L. Pre: length()>0, index()>=0



bool isEmpty(List L); // Returns true if Q is empty, otherwise returns false.

// Manipulation procedures ----------------------------------------------------
void clear(List L); // Resets L to its original empty state.

void set(List L, ListElement x); // Overwrites the cursor element’s data with x.
 // Pre: length()>0, index()>=0

void moveFront(List L); // If L is non-empty, sets cursor under the front element,
 // otherwise does nothing.

void moveBack(List L); // If L is non-empty, sets cursor under the back element,
 // otherwise does nothing.

void movePrev(List L); // If cursor is defined and not at front, move cursor one
 // step toward the front of L; if cursor is defined and at
 // front, cursor becomes undefined; if cursor is undefined
 // do nothing

void moveNext(List L); // If cursor is defined and not at back, move cursor one
 // step toward the back of L; if cursor is defined and at
 // back, cursor becomes undefined; if cursor is undefined
 // do nothing

void prepend(List L, ListElement x); // Insert new element into L. If L is non-empty,
 // insertion takes place before front element.

void append(List L, ListElement x); // Insert new element into L. If L is non-empty,
 // insertion takes place after back element.

void insertBefore(List L, ListElement x); // Insert new element before cursor.
 // Pre: length()>0, index()>=0

void insertAfter(List L, ListElement x); // Insert new element after cursor.
 // Pre: length()>0, index()>=0

void deleteFront(List L); // Delete the front element. Pre: length()>0

void deleteBack(List L); // Delete the back element. Pre: length()>0

void delete(List L); // Delete cursor element, making cursor undefined.
 // Pre: length()>0, index()>=0

// Other operations -----------------------------------------------------------
void printList(FILE* out, List L); // Prints to the file pointed to by out, a
 // string representation of L consisting
 // of a space separated sequence of integers,
// with front on left.

