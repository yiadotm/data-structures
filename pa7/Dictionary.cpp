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
        s += R->key + ": " + std::to_string(R->val) + " \n";
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
    Node* N = R;
    while (N != nil) {
        if (N->key == k) {
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
Dictionary::Node* Dictionary::findMin(Node* R) {
    while (R != nil) {
        findMin(R->left);
        return R;
    }
    return (nil);
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the 
// rightmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMax(Node* R) {
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
Dictionary::Node* Dictionary::findNext(Node* N) {
    if (N->right == nil || N == nil) {
        return (nil);
    }
    return (N->right);
}

// findPrev()
// If N does not point to the leftmost Node, returns a pointer to the
// Node before N in an in-order tree walk.  If N points to the leftmost 
// Node, or is nil, returns nil.
Dictionary::Node* Dictionary::findPrev(Node* N) {
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





