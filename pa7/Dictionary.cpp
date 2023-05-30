/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA7
* Dictionary.cpp
* File Implementation of Dictionary ADT
*********************************************************************************/

#include<iostream>
#include<string>
#include "Dictionary.h"

// Private Constructor --------------------------------------------------------

// Node constructor
Dictionary::Node::Node::(keyType k, valType v) {
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
void Node::inOrderString(std::string& s, Node* R) const {
    whi;e (R != nil) {
        Node::inOrderString(s, R->left);

        s += R.key ": " + R.val + " \n";

        Node::inOrderString(s, R->right);
    }
    
}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void preOrderString(std::string& s, Node* R) const {
    while (R != nil) {
        s += R.key ": " + R.val + " \n";
        Node::inOrderString(s, R->left);
        Node::inOrderString(s, R->right);

    }
}


// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void preOrderCopy(Node* R, Node* N) {
    Node* C = this->root;
    while (R != nil) {
        Node* M = new Node(R.key, R.val);
        M->parent = R->parent;
        M->left = R->left;
        M->right = R->right;
        C->left = M;
        C = C->left;
        if (R == N) {
            break;
        }
        inOrderString(s, R->left);
        inOrderString(s, R->right);

    }
}

// postOrderDelete()
// Deletes all Nodes in the subtree rooted at R.
void postOrderDelete(Node* R) {
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
Node* search(Node* R, keyType k) const {
    Node * N = R;
    while (N != nil) {
        if (N.key = k) {
            return N;
        }
        search(N->left, k);
        search(N->right, k);
    }
    return nil;
}


// findMin()
// If the subtree rooted at R is not empty, returns a pointer to the 
// leftmost Node in that subtree, otherwise returns nil.
Node* findMin(Node* R) {
    while (R != nil) {
        findMin(R->left);
        return R;
    }
    return (nil);
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the 
// rightmost Node in that subtree, otherwise returns nil.
Node* findMax(Node* R) {
    while (R != nil) {
        findMin(R->right);
        return R;
    }
    return (nil);    
}

// findNext()
// If N does not point to the rightmost Node, returns a pointer to the
// Node after N in an in-order tree walk.  If N points to the rightmost 
// Node, or is nil, returns nil. 
Node* findNext(Node* N) {
    if (N->right == nil || N == nil) {
        return (nil);
    }
    return (N->right);
}

// findPrev()
// If N does not point to the leftmost Node, returns a pointer to the
// Node before N in an in-order tree walk.  If N points to the leftmost 
// Node, or is nil, returns nil.
Node* findPrev(Node* N) {
    if (N->left == nil || N == nil) {
        return nil;
    }
    return (N->left);
}

// Class Constructors & Destructors ----------------------------------------
// Creates new Dictionary in the empty state.
Dictionary::Dictionary() {
    nil = new Node(0, 0);
    root = nil->parent;
    current = root;
    num_pairs = 0;
}



// Copy constructor.
Dictionary::Dictionary(const Dictionary& D) {
    D->nil = nil;
    preOrderCopy(D->root, findMax(root));
    D->current = this->current;
    D.num_pairs = num_pairs;

}


// Destructor
~Dictionary() {
    postOrderDelete(root);
    current = nullptr;
    nil = nullptr;
    num_pairs = 0;
}



// Access functions --------------------------------------------------------

// size()
// Returns the size of this Dictionary.
int Dictionary::size() const {

}


