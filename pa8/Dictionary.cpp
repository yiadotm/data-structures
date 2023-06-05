/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA8
* Dictionary.cpp
* File Implementation of Dictionary ADT
*********************************************************************************/

#include<iostream>
#include<string>
#include <cstdlib>
#include <string.h>
#include "Dictionary.h"

#define BLACK 0
#define RED 1

// Private Constructor --------------------------------------------------------

// Node constructor, black = 0, red = 1;
Dictionary::Node::Node(keyType k, valType v) {
    key = k;
    val = v;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = BLACK;
}


// Helper Functions (Optional) ---------------------------------------------

// inOrderString()
// Appends a string representation of the tree rooted at R to string s. The
// string appended consists of: "key : value \n" for each key-value pair in
// tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        // std::cout << "huh13" << std::endl;
        // std::cout  << "key: " << R->key << " val: " << R->val << std::endl;

        Dictionary::inOrderString(s, R->left);
        s += R->key + " : " + std::to_string(R->val) + "\n";
        // std::cout << s << std::endl;
        Dictionary::inOrderString(s, R->right);
    }
    
}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary::preOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        s += R->key +  "\n";
        Dictionary::preOrderString(s, R->left);
        Dictionary::preOrderString(s, R->right);

    }
}


// BST_insert()
// Inserts a copy of the Node *M into this Dictionary. Used by preOrderCopy().
void Dictionary::BST_insert(Node* M) {
    Node* y = nil;
    Node* x = root;
    Node* z = new Node(M->key, M->val);
    while (x != nil) {
        y = x;
        if (M->key < x->key) {
            x = x->left;
        }
        // else if (M->key < x->key) {
        //     x = M;
        //     return;
        // }
        else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nil) {
        root = z;
    }
    else if (M->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    z->left = nil;
    z->right = nil;
    z->color = RED;
    num_pairs++;
    RB_InsertFixUp(z);
}

// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N) {
    if (R != N) {

        BST_insert(R);
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
        N->parent = nil;
        N->parent->right = nil;
        delete N;

    }
}

// search()
// Searches the subtree rooted at R for a Node with key==k. Returns
// the address of the Node if it exists, returns nil otherwise.
Dictionary::Node* Dictionary::search(Node* R, keyType k) const {
    Node* C = R;
    // std::cout << "bu" << std::endl;

    if (C == nil || k.compare(C->key) == 0) {
        return C;
    }
    else if (k.compare(C->key) < 0) {
        return search(C->left, k);
    }
    else {
        return search(C->right, k);
    }
    // std::cout << "bua" << std::endl;

}


// findMin()
// If the subtree rooted at R is not empty, returns a pointer to the 
// leftmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMin(Node* R) {
    if (num_pairs == 0) {
        return nil;
    }
    if (R != nil) {
        while (R->left != nil) {
            R = R->left;
        }
    }

    return (R);
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the 
// rightmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMax(Node* R) {
    if (num_pairs == 0) {
        return nil;
    }
    if (R != nil) {
        while (R->right != nil) {
            R = R->right;
        }       
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
    if (N == findMin(root) || N == nil) {
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

// RBT Helper Functions (Optional) -----------------------------------------

// LeftRotate()
void Dictionary::LeftRotate(Node* N) {
    Node* y = N->right;
    N->right = y->left;
    if (y->left != nil) {
        y->left->parent = N;
    }
    y->parent = N->parent;
    if (N->parent == nil) {
        root = y;
    }
    else if (N == N->parent->left) {
        N->parent->left = y;
    }
    else {
        N->parent->right = y;
    }
    y->left = N;
    N->parent = y;
}

// RightRotate()
void Dictionary::RightRotate(Node* N) {
    Node* y = N->left;
    N->left = y->right;
    if (y->right != nil) {
        y->right->parent = N;
    }
    y->parent = N->parent;
    if (N->parent == nil) {
        root = y;
    }
    else if (N == N->parent->right) {
        N->parent->right = y;
    }
    else {
        N->parent->left = y;
    }
    y->right = N;
    N->parent = y;
}

// RB_InsertFixUP()
void Dictionary::RB_InsertFixUp(Node* N) {

}

// RB_Transplant()
void Dictionary::RB_Transplant(Node* u, Node* v) {

}
// RB_DeleteFixUp()
void Dictionary::RB_DeleteFixUp(Node* N) {

}

// RB_Delete()
void Dictionary::RB_Delete(Node* N) {

}

// Class Constructors & Destructors ----------------------------------------
// Creates new Dictionary in the empty state.
Dictionary::Dictionary() {
    // std::cout << "default constructor\n";
    nil = new Node("", 0);
    root = nil;
    root->parent = nil;
    root->left = nil;
    root->right = nil;
    current = nil;
    num_pairs = 0;
}



// Copy constructor.
Dictionary::Dictionary(const Dictionary& D) {
    // std::cout << "not default constructor\n";
    this->nil = new Node("", 0);
    if (D.root == D.nil) {
        this->root = this->nil;
    }
    else {
        Node* N = new Node(D.root->key, D.root->val);
        this->root = N;

    }
    this->root->parent = nil;
    this->root->left = nil;
    this->root->right = nil;

    // std::cout << "huh13" << std::endl;
    preOrderCopy(D.root, D.nil);
    // std::cout << "huh14" << std::endl;

    this->current = nil;
    this->num_pairs = D.num_pairs;
    // std::cout << "huh15" << std::endl;


}


// Destructor
Dictionary::~Dictionary() {
    postOrderDelete(root);
    current = nullptr;
    Node* N = nil;
    nil = nullptr;
    num_pairs = 0;
    delete N;
}



// Access functions --------------------------------------------------------

// size()
// Returns the size of this Dictionary.
int Dictionary::size() const {
    // std::cout << "size: " << num_pairs << std::endl;

    if (num_pairs < 0) {
        throw std::length_error("Dictionary: size: num out of bounds");
    }
    // if (num_pairs >= 2) {
    //     return num_pairs+1;
    // }
    // std::cout << "SIZE:: " << num_pairs << "\n";
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
    // std::cout << "CURRENT VAL " << current->val << std::endl;
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
    // std::cout << to_string() << std::endl;
    // std::cout << "huh" << std::endl;
    // Node* N = search(root, k);
    // if (N != nil) {
    //     N->val = v;
    //     return;
    // }

    // std::cout << "huh2" << std::endl;
    Node* y = nil;
    Node* x = this->root;
    Node* z = new Node(k, v);
    z->left = nil;
    z->right = nil;
    // std::cout << "huh6" << std::endl;
    while (x != nil) {
        y = x;
        // std::cout << "hue4h" << std::endl;
        
        if (z->key.compare(x->key) < 0) {
            // std::cout << "1" << std::endl;
            // if (x->left == nullptr) {
            //     std::cout << "5" << std::endl;
            // }
            x = x->left;
            continue;
        }
        else if (z->key.compare(x->key) == 0) {
            // std::cout << "GAMING:::::" << to_string() << std::endl;
            x->val = z->val;
            delete z;
            return;
        }
            // std::cout << "3" << std::endl;
        x = x->right;
        // std::cout << "huh78" << std::endl;
    }
    // std::cout << "huh3" << std::endl;
    z->parent = y;
    if (y == nil) {
        root = z;
        
        // std::cout << "huh7890" << std::endl;
    }
    else if (z->key.compare(y->key) < 0) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    // std::cout << "huh4" << std::endl;
        // std::cout << "size: " << num_pairs << std::endl;

    num_pairs++;

}



// remove()
// Deletes the pair for which key==k. If that pair is current, then current
// becomes undefined.
// Pre: contains(k).
void Dictionary::remove(keyType k) {
    Node* z = search(root, k);
    if (z == nil) {
        return;
    }
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
    // std::cout << to_string() << std::endl;
    if (num_pairs != 0) {
        current = findMin(root);

        
    }
    // std::cout << "key: " << current->key << " val: " << current->val << std::endl;
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
        else if (current == findMax(root)) {
            current = nil;
        }
    }
    else {
        throw std::logic_error("Dictionary: nextl: current is not defined");
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
        else if (current == findMin(root)) {
            current = nil;
        }
    }
    else {
        throw std::logic_error("Dictionary: prev: current is not defined");
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
    // std::cout << "root: " << root->key << " val: " << root->val << std::endl;
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
    std::string thisStr = this->to_string();
    std::string DStr = D.to_string();

    // for (int i = 0; i < thisStr.length(); i++) {
    //     if (thisStr.at(i).compare(DStr.at(i)) != 0) {
    //         return false;
    //     }
    // }
    if (thisStr.compare(DStr) != 0) {
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
    return (A.equals(B));
}


// operator=()
// Overwrites the state of this Dictionary with state of D, and returns a
// reference to this Dictionary.
Dictionary& Dictionary::operator=( const Dictionary& D ) {
    if (this != &D) {
        Dictionary C = D;

        std::swap(root, C.root);
        std::swap(nil, C.nil);
        std::swap(current, C.current);
        std::swap(num_pairs, C.num_pairs);
    }

    return *this;
}
 