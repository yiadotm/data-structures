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
   frontDummy = new Node(0);
   backDummy = new Node(1);
   beforeCursor = frontDummy;
   afterCursor = backDummy;
   pos_cursor = 0;
   num_elements = 0;
}

// Copy constructor.
List::List(const List& L) {
    //empty list
    frontDummy = new Node(0);
    backDummy = new Node(1);
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;

    //load elements
    Node* N = L.frontDummy->next;
    while(N != backDummy) {
        this->insertBefore(N->data);
        N = N->next;
    }
}

// Destructor
List::~List() {
    moveBack();
    while (num_elements>0) {
        eraseBefore();
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
    if (length() ==0) {
        throw std::length_error("List Error: front(): empty List");
    }
    return(frontDummy->next->data);
}

// back()
// Returns the back element in this List.
// pre: length()>0
ListElement List::back() const {
    if (length() ==0) {
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
    if (pos_cursor <=0 || pos_cursor >= length()) {
        throw std::length_error("List Error: peekNext(): out of bounds");
    }        
    return(afterCursor->data);
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
ListElement List::peekPrev() const {
    if (pos_cursor <=0 || pos_cursor >= length()) {
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
    while(frontDummy->next != backDummy) {
        eraseBefore();
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
    beforeCursor = frontDummy->next;
    beforeCursor->prev= frontDummy;
    afterCursor->prev = beforeCursor;
    afterCursor->next = frontDummy->next;
    frontDummy->next->prev = afterCursor;
}

// moveBack()
// Moves cursor to position length() in this List.
void List::moveBack() {
    if (length() == 0) {
        return;
    }
    if (pos_cursor == length() -1) {
        return;
    }
    pos_cursor = length() - 1;
    backDummy->prev = afterCursor;
    afterCursor->next = backDummy;
    afterCursor->prev = beforeCursor;
    beforeCursor->next = afterCursor;
    beforeCursor->prev = backDummy->prev;
    backDummy->prev->next = beforeCursor;

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

    N->next = beforeCursor->next;
    beforeCursor->next = N;
    N->prev = beforeCursor;
    beforeCursor->next->prev = N;



    // pos_cursor++;
    num_elements++;


  

    // num_elements++;
}


// insertBefore()
// Inserts x before cursor.
void List::insertBefore(ListElement x) {
    Node* N = new Node(x);
    N->next = afterCursor;
    afterCursor->prev = N;
    beforeCursor->next = N;
    N->prev = beforeCursor;


    beforeCursor = N;
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
    afterCursor->prev = beforeCursor;
    beforeCursor->next = afterCursor;
    delete N;
    num_elements--;
}

// eraseBefore()
// Deletes element before cursor.
// pre: position()>0
void List::eraseBefore() {
    if (pos_cursor <= 0) {
        throw std::length_error("List Error: eraseBefore(): out of bounds");
    }
    Node* N = beforeCursor;
    beforeCursor = N->prev;
    beforeCursor->next = afterCursor;
    afterCursor->prev = beforeCursor;
    delete N;
    num_elements--;
    pos_cursor--;

} 


   // Other Functions ---------------------------------------------------------

// findNext()
// Starting from the current cursor position, performs a linear search (in 
// the direction front-to-back) for the first occurrence of element x. If x
// is found, places the cursor immediately after the found element, then 
// returns the final cursor position. If x is not found, places the cursor 
// at position length(), and returns -1. 
int List::findNext(ListElement x) {
    moveFront();
    for (int i = 0; i < length(); i++) {
        ListElement y = moveNext();
        if (x == y) {
            return pos_cursor;
        }
    }
    moveBack();
    return -1;
}


// findPrev()
// Starting from the current cursor position, performs a linear search (in 
// the direction back-to-front) for the first occurrence of element x. If x
// is found, places the cursor immediately before the found element, then
// returns the final cursor position. If x is not found, places the cursor 
// at position 0, and returns -1. 
int List::findPrev(ListElement x) {
    moveBack();
    for (int i = 0; i < length(); i++) {
        ListElement y = movePrev();
        if (x == y) {
            return pos_cursor;
        }
    }
    moveFront();
    return -1;

}

// cleanup()
// Removes any repeated elements in this List, leaving only unique elements.
// The order of the remaining elements is obtained by retaining the frontmost 
// occurrance of each element, and removing all other occurances. The cursor 
// is not moved with respect to the retained elements, i.e. it lies between 
// the same two retained elements that it did before cleanup() was called.
void List::cleanup() {
    moveFront();
    List S = *this;
    S.moveFront();
    for (int i = 0; i < length(); i++) {
        ListElement x = moveNext();
        for (int y = i; y < S.length(); y++) {
            ListElement j = moveNext();
            if (j == x) {
                eraseBefore();
            }
        }
    }
}

// concat()
// Returns a new List consisting of the elements of this List, followed by
// the elements of L. The cursor in the returned List will be at postion 0.
List List::concat(const List& L) const {
    List R = *this;
    List LL = L;
    R.num_elements = this->num_elements + LL.num_elements;
    LL.moveFront();
    R.moveBack();
    for (int i = 0; i < LL.num_elements; i++) {
        ListElement x = LL.moveNext();
        R.insertAfter(x);
    }

    R.moveFront();
    return R;
}

// to_string()
// Returns a string representation of this List consisting of a comma 
// separated sequence of elements, surrounded by parentheses.
std::string List::to_string() const {

    // std::string s = "(";

    // for (R.moveFront(); R.position() < R.length(); R.moveNext()) {
    //     s += std::to_string(R.peekPrev());
    //     if (R.position() == (R.length() - 1)) {
    //         s += ")";
    //     }
    //     else {
    //         s += ", ";
    //     }
    // }
    // Node* N = frontDummy->next;
    // for (int i = 0; i < length(); i++) {
    //     s += std::to_string(N->data);
    //     if (i == (length() - 1)) {
    //         s += ")";
    //     }
    //     else {
    //         s += ", ";
    //     }
    // }
    // return s;

    Node* N = nullptr;
    std::string s = "(";
    for (N =frontDummy->next; N != nullptr; N = N->next) {
        s += std::to_string(N->data);
        if (N == backDummy->prev) {
            s += ")";
            break;
        }
        else {
            s += ", ";
        }

    }
    return s;

}

// equals()
// Returns true if and only if this List is the same integer sequence as R.
// The cursors in this List and in R are unchanged.
bool List::equals(const List& R) const {
    bool eq = false;
    Node* N = nullptr;
    Node* M = nullptr;
    eq = (this->length() == R.length());
    N = this->frontDummy->next;
    M = R.frontDummy->next;
    while(eq && N != nullptr) {
        eq = (N->data == M->data);
        N = N->next;
        M = M->next;
    }
    return eq;
}



// Overriden Operators -----------------------------------------------------



// operator<<()
// Inserts string representation of L into stream.
std::ostream& operator<<( std::ostream& stream, const List& L ) {
    return stream << L.List::to_string();
}

// operator==()
// Returns true if and only if A is the same integer sequence as B. The 
// cursors in both Lists are unchanged.
bool operator==( const List& A, const List& B ) {
    return A.List::equals(B);
}

// operator=()
// Overwrites the state of this List with state of L.
List& List::operator=( const List& L ) {
    if (this != &L) {
        List temp = L;

        std::swap(frontDummy, temp.frontDummy);
        std::swap(backDummy, temp.backDummy);
        std::swap(beforeCursor, temp.beforeCursor);
        std::swap(afterCursor, temp.afterCursor);
        std::swap(num_elements, temp.num_elements);
        std::swap(pos_cursor, temp.pos_cursor);
    }
    return *this;
}
