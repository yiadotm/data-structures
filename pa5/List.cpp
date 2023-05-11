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
        return(num_elements);
    }

    // front()
    // Returns the front element in this List.
    // pre: length()>0
    ListElement List::front() const {
        if (length ==0) {
            throw std::length_error("List Error: front(): empty List");
        }
        return(frontDummy->data);
    }

    // back()
    // Returns the back element in this List.
    // pre: length()>0
    ListElement List::back() const {
        if (length ==0) {
            throw std::length_error("List Error: back(): empty List");
        }
        return(backDummy->data);
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
