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
    while (R != nil) {
        Dictionary::inOrderString(s, R->left);

        s += R->key + ": " + std::to_string(R->val) + " \n";

        Dictionary::inOrderString(s, R->right);
    }
    
}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary::preOrderString(std::string& s, Node* R) const {
    while (R != nil) {
        s += R->key + ": " +  " \n";
        Dictionary::inOrderString(s, R->left);
        Dictionary::inOrderString(s, R->right);

    }
}


// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N) {
    Node* C = this->root;
    while (R != nil) {
        Node* M = new Node(R->key, R->val);
        M->parent = R->parent;
        M->left = R->left;
        M->right = R->right;
        C->left = M;
        C = C->left;
        if (R == N) {
            break;
        }
        preOrderCopy(R->left, N);
        preOrderCopy(R->right, N);

    }
}

// postOrderDelete()
// Deletes all Nodes in the subtree rooted at R.
void Dictionary::postOrderDelete(Node* R) {
    while (R != nil) {
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
    if (R == nil || k == R->key) {
        return R;
    }
    else if (k < R->key) {
        return search(R->left, k);
    }
    else {
        return search(R->right, k);
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
        N == y;
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
    nil = new Node(0, 0);
    root = nil;
    current = nil;
    num_pairs = 0;
}



// Copy constructor.
Dictionary::Dictionary(const Dictionary& D) {
    Dictionary N = D;
    N.nil = nil;
    preOrderCopy(N.root, findMax(root));
    N.current = this->current;
    N.num_pairs = num_pairs;

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
    Node* N = search(root, k);
    if (N != nil) {
        N->val = v;
        return;
    }

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
        
    }
}

