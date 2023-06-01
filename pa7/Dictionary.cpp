/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA7
* Dictionary.cpp
* File Implementation of Dictionary ADT
*********************************************************************************/

#include<iostream>
#include<string>
#include <cstdlib>
#include "Dictionary.h"

// Private Constructor --------------------------------------------------------

// Node constructor
Dictionary::Node::Node(keyType k, valType v) {
    key = k;
    val = v;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}


// Helper Functions (Optional) ---------------------------------------------

// inOrderString()
// Appends a string representation of the tree rooted at R to string s. The
// string appended consists of: "key : value \n" for each key-value pair in
// tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        std::cout << "huh13" << std::endl;
        std::cout  << "key: " << R->key << " val: " << R->val << std::endl;

        Dictionary::inOrderString(s, R->left);
        std::cout  << "key: " << R->key << "val: " << R->val << std::endl;
        s += R->key + " : " + std::to_string(R->val) + " \n";
        std::cout << s << std::endl;
        Dictionary::inOrderString(s, R->right);
    }
    
}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary::preOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        s += R->key + " : " +  " \n";
        Dictionary::inOrderString(s, R->left);
        Dictionary::inOrderString(s, R->right);

    }
}


// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N) {
    Node* C = this->root;
    if (R != N) {
        Node* M = new Node(R->key, R->val);
        M->parent = R->parent;
        M->left = R->left;
        M->right = R->right;
        C = M;
        C = C->left;
        preOrderCopy(R->left, N);
        preOrderCopy(R->right, N);

    }
}

// postOrderDelete()
// Deletes all Nodes in the subtree rooted at R.
void Dictionary::postOrderDelete(Node* R) {
    if (R != nil) {
        postOrderDelete(R->left);
        postOrderDelete(R->right);
        Node* N = R;
        N->parent = nil->parent;
        N->parent->right = nil->right;
        delete N;

    }
}

// search()
// Searches the subtree rooted at R for a Node with key==k. Returns
// the address of the Node if it exists, returns nil otherwise.
Dictionary::Node* Dictionary::search(Node* R, keyType k) const {
    Node* C = R;
    if (C == nil || k == C->key) {
        return R;
    }
    else if (k < C->key) {
        return search(C->left, k);
    }
    else {
        return search(C->right, k);
    }
}


// findMin()
// If the subtree rooted at R is not empty, returns a pointer to the 
// leftmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMin(Node* R) {
    if (R == nil) {
        return nil;
    }
    while (R->left != nil) {
        R = R->left;
    }
    return (R);
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the 
// rightmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMax(Node* R) {
    if (R == nil) {
        return nil;
    }
    while (R->right != nil) {
        R = R->right;
    }
    return (R);   
}



// findNext()
// If N does not point to the rightmost Node, returns a pointer to the
// Node after N in an in-order tree walk.  If N points to the rightmost 
// Node, or is nil, returns nil. 
Dictionary::Node* Dictionary::findNext(Node* N) {
    if (N == findMax(root) || N == nil) {
        return nil;
    }
    if (N->right != nil) {
        return findMin(N->right);
    }
    Node* y = N->parent;
    while (y != nil && N == y->right) {
        N = y;
        y = y->parent;
    }

    return y;


}

// findPrev()
// If N does not point to the leftmost Node, returns a pointer to the
// Node before N in an in-order tree walk.  If N points to the leftmost 
// Node, or is nil, returns nil.
Dictionary::Node* Dictionary::findPrev(Node* N) {
    if (N == findMax(root) || N == nil) {
        return nil;
    }
    if (N->left != nil) {
        return findMax(N->left);
    }
    Node* y = N->parent;
    while (y != nil && N == y->left) {
        N = y;
        y = y->parent;
    }
    return y;
}

// Class Constructors & Destructors ----------------------------------------
// Creates new Dictionary in the empty state.
Dictionary::Dictionary() {
    nil = new Node("a", 0);
    root = nil;
    current = nil;
    num_pairs = 0;
}



// Copy constructor.
Dictionary::Dictionary(const Dictionary& D) {
    nil = new Node("a", 0);
    this->root = D.root;
    preOrderCopy(D.root, D.nil);
    this->current = D.current;
    this->num_pairs = D.num_pairs;

}


// Destructor
Dictionary::~Dictionary() {
    postOrderDelete(root);
    current = nullptr;
    nil = nullptr;
    num_pairs = 0;
}



// Access functions --------------------------------------------------------

// size()
// Returns the size of this Dictionary.
int Dictionary::size() const {
    if (num_pairs < 0) {
        throw std::length_error("Dictionary: size: num out of bounds");
    }
    return (num_pairs);
}


// contains()
// Returns true if there exists a pair such that key==k, and returns false
// otherwise.
bool Dictionary::contains(keyType k) const {
    if (search(this->root, k) == nil) {
        return false;
    } 
    return true;
    
}

// getValue()
// Returns a reference to the value corresponding to key k.
// Pre: contains(k)
valType& Dictionary::getValue(keyType k) const {
    Node* N = search(this->root, k);
    if (N == nil) {
        throw std::logic_error("Dictionary: getValue: key does not exist");
    }
    return (N->val);
}

// hasCurrent()
// Returns true if the current iterator is defined, and returns false 
// otherwise.
bool Dictionary::hasCurrent() const {
    if (current == nil) {
        return false;
    }
    return true;
}

// currentKey()
// Returns the current key.
// Pre: hasCurrent() 
keyType Dictionary::currentKey() const {
    if (hasCurrent() == false) {
        throw std::logic_error("Dictionary: currentKey: current is not defined");
    }
    return (current->key);
}

// currentVal()
// Returns a reference to the current value.
// Pre: hasCurrent()
valType& Dictionary::currentVal() const {
    if (hasCurrent() == false) {
        throw std::logic_error("Dictionary: currentVal: current is not defined");
    }
    return (current->val);
}

// Manipulation procedures -------------------------------------------------

// clear()
// Resets this Dictionary to the empty state, containing no pairs.
void Dictionary::clear() {
    postOrderDelete(this->root);
    num_pairs = 0;
    current = nil;
    root = nil;
}



// setValue()
// If a pair with key==k exists, overwrites the corresponding value with v, 
// otherwise inserts the new pair (k, v).
void Dictionary::setValue(keyType k, valType v) {
    std::cout << "huh" << std::endl;
    Node* N = search(root, k);
    if (N != nil) {
        N->val = v;
        return;
    }
    std::cout << "huh2" << std::endl;
    Node* y = nil;
    Node* x = root;
    Node* z = new Node(k, v);
    while (x != nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    std::cout << "huh3" << std::endl;
    z->parent = y;
    if (y == nil) {
        root = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    std::cout << "huh4" << std::endl;
    num_pairs++;

}

// Transplant()
// Replaces node u with node v and relinks all the nodes.
void Dictionary::Transplant(Node* u, Node* v) {
    if (u->parent == nil) {
        root = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    if (v != nil) {
        v->parent = u->parent;
    }
}

// remove()
// Deletes the pair for which key==k. If that pair is current, then current
// becomes undefined.
// Pre: contains(k).
void Dictionary::remove(keyType k) {
    Node* z = search(root, k);
    if (z == current) {
        current = nil;
    }

    if (z->left == nil) {
        Transplant(z, z->right);
    }
    else if (z->right == nil) {
        Transplant(z, z->left);
    }
    else {
        Node* y = findMin(z->right);
        if (y->parent != z) {
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    num_pairs--;
}


// begin()
// If non-empty, places current iterator at the first (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing. 
void Dictionary::begin() {
    if (num_pairs != 0) {
        current = findMin(root);
    }
}

// end()
// If non-empty, places current iterator at the last (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing. 
void Dictionary::end() {
    if (num_pairs != 0) {
        current = findMax(root);
    }
}

// next()
// If the current iterator is not at the last pair, advances current 
// to the next pair (as defined by the order operator < on keys). If 
// the current iterator is at the last pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::next() {
    if (hasCurrent()) {
        if (current != findMax(root)) {
            current = findNext(current);
        }
        if (current == findMax(root)) {
            current = nil;
        }
    }

}

// prev()
// If the current iterator is not at the first pair, moves current to  
// the previous pair (as defined by the order operator < on keys). If 
// the current iterator is at the first pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::prev() {
    if (hasCurrent()) {
        if (current != findMin(root)) {
            current = findPrev(current);
        }
        if (current == findMin(root)) {
            current = nil;
        }
    }
}

// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this Dictionary. Consecutive (key, value)
// pairs are separated by a newline "\n" character, and the items key and value 
// are separated by the sequence space-colon-space " : ". The pairs are arranged 
// in order, as defined by the order operator <.
std::string Dictionary::to_string() const {
    std::string s = "";
    inOrderString(s, root);
    return s;

}

// pre_string()
// Returns a string consisting of all keys in this Dictionary. Consecutive
// keys are separated by newline "\n" characters. The key order is given
// by a pre-order tree walk.
std::string Dictionary::pre_string() const {
    std::string s = "";
    preOrderString(s, root);
    return s;
}

// equals()
// Returns true if and only if this Dictionary contains the same (key, value)
// pairs as Dictionary D.
bool Dictionary::equals(const Dictionary& D) const {
    if (size() != D.size()) {
        return false;
    }
    std::string thisStr = "";
    std::string DStr = "";

    inOrderString(thisStr, this->root);
    inOrderString(DStr, D.root);
    if (thisStr != DStr) {
        return false;
    }
    return true;
}

// Overloaded Operators ----------------------------------------------------

// operator<<()
// Inserts string representation of Dictionary D into stream, as defined by
// member function to_string().
std::ostream& operator<<( std::ostream& stream, Dictionary& D ) {
    return stream << D.to_string();
}

// operator==()
// Returns true if and only if Dictionary A equals Dictionary B, as defined
// by member function equals(). 
bool operator==( const Dictionary& A, const Dictionary& B ) {
    return A.equals(B);
}


// operator=()
// Overwrites the state of this Dictionary with state of D, and returns a
// reference to this Dictionary.
Dictionary& Dictionary::operator=( const Dictionary& D ) {
    Dictionary C(D);
    preOrderCopy(D.root, findMax(C.root));
    return *this;
}
