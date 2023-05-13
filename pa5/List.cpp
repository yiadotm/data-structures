/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA5
* List.cpp
* File Implementation of List ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include "List.h"

// Private Constructor --------------------------------------------------------
// Node constructor
List::Node::Node(ListElement x){
   data = x;
   next = nullptr;
   prev = nullptr;
}

// Class Constructors & Destructors -------------------------------------------
// Creates new List in the empty state.


List::List() {
   frontDummy = nullptr;
   backDummy = nullptr;
   beforeCursor = frontDummy;
   afterCursor = backDummy;
   pos_cursor = 0;
   num_elements = 0;
}

// Copy constructor.
List::List(const List& L) {
    //empty list
    frontDummy = nullptr;
    backDummy = nullptr;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;

    //load elements
    Node* N = L.frontDummy;
    while(N != nullptr) {
        this->insertAfter(N->data);
        N = N->next;
    }
}

// Destructor
List::~List() {
    moveBack();
    while (num_elements>0) {
        eraseAfter();
    }
}

// Access functions -----------------------------------------------------------

// length()
// Returns the length of this List.
int List::length() const {
    return(num_elements-1);
}

// front()
// Returns the front element in this List.
// pre: length()>0
ListElement List::front() const {
    if (length ==0) {
        throw std::length_error("List Error: front(): empty List");
    }
    return(frontDummy->next->data);
}

// back()
// Returns the back element in this List.
// pre: length()>0
ListElement List::back() const {
    if (length ==0) {
        throw std::length_error("List Error: back(): empty List");
    }
    return(backDummy->prev->data);
}

// position()
// Returns the position of cursor in this List: 0 <= position() <= length().
int List::position() const {
    if (pos_cursor <0 || pos_cursor > length()) {
        throw std::length_error("List Error: position(): out of bounds");
    }
    return(pos_cursor);
}

// peekNext()
// Returns the element after the cursor.
// pre: position()<length()
ListElement List::peekNext() const {
    if (pos_cursor <0 || pos_cursor > length()) {
        throw std::length_error("List Error: peekNext(): out of bounds");
    }        
    return(afterCursor->data);
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
ListElement List::peekPrev() const {
    if (pos_cursor <0 || pos_cursor > length()) {
        throw std::length_error("List Error: peekPrev(): out of bounds");
    }        
    return(beforeCursor->data);
}

// Manipulation procedures -------------------------------------------------

// clear()
// Deletes all elements in this List, setting it to the empty state.
void List::clear() {
    if (length() == 0) {
        return;
    }
    moveFront();
    while(frontDummy->next != nullptr) {
        eraseAfter();
    }
    num_elements = 0;
    pos_cursor = 0;
}

// moveFront()
// Moves cursor to position 0 in this List.
void List::moveFront() {
    if (length() == 0) {
        return;
    }
    pos_cursor = 0;
    beforeCursor = frontDummy;
    afterCursor = frontDummy->next;
}

// moveBack()
// Moves cursor to position length() in this List.
void List::moveBack() {
    if (length() == 0) {
        return;
    }
    pos_cursor = length();
    afterCursor = backDummy;
    beforeCursor = backDummy->prev;
}

// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<length() 
ListElement List::moveNext() {
    if (pos_cursor >= length()) {
        throw std::length_error("List Error: moveNext(): out of bounds");
    }

    //move afterCursor next
    Node* N = afterCursor;
    afterCursor = afterCursor->next;
    beforeCursor = N;
    pos_cursor++;
    return(peekPrev());
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
ListElement List::movePrev() {
    if (pos_cursor <= 0) {
        throw std::length_error("List Error: movePrev(): out of bounds");
    }

    //move beforeCursor before
    Node* N = beforeCursor;
    beforeCursor = beforeCursor->prev;
    afterCursor= N;
    pos_cursor--;
    return(peekNext());
}

// insertAfter()
// Inserts x after cursor.
void List::insertAfter(ListElement x) {
    Node* N = new Node(x);
    N->prev = afterCursor;
    N->next = afterCursor->next;
    afterCursor->next = N;
    N->next->prev = N;
    num_elements++;
}


// insertBefore()
// Inserts x before cursor.
void List::insertBefore(ListElement x) {
    Node* N = new Node(x);
    beforeCursor->prev->next = N;
    N->prev = beforeCursor->prev;
    N->next = beforeCursor;
    beforeCursor->prev = N;
    

    pos_cursor++;
    num_elements++;

}

// setAfter()
// Overwrites the List element after the cursor with x.
// pre: position()<length()
void List::setAfter(ListElement x) {
    if (pos_cursor >= length()) {
        throw std::length_error("List Error: setAfter(): out of bounds");
        
    }
    afterCursor->data = x;
}

// setBefore()
// Overwrites the List element before the cursor with x.
// pre: position()>0
void List::setBefore(ListElement x) {
    if (pos_cursor >= length()) {
        throw std::length_error("List Error: setBefore(): out of bounds");
    }    

    beforeCursor->data = x;
}

// eraseAfter()
// Deletes element after cursor.
// pre: position()<length()
void List::eraseAfter() {
    if (pos_cursor >= length()) {
        throw std::length_error("List Error: eraseAfter(): out of bounds");
    }
    Node* N = afterCursor;
    afterCursor = afterCursor->next;
    
}

