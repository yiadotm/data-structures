/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA4
* Matrix.c
* File Implementation of Matrix ADT
*********************************************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "Matrix.h"
#include "List.h"

// structs --------------------------------------------------------------------
// private Entry type
typedef struct EntryObj* Entry;

//private EntryObj type
typedef struct EntryObj {
    int col;
    double value;


} EntryObj;

// private Matrix type
typedef struct MatrixObj {
    List* entries;
    int size;

} MatrixObj;

// Constructors-Destructors ---------------------------------------------------
// newEntry()
// Returns a reference to an entry
Entry newEntry(int col, double value) {
    Entry E = malloc(sizeof(EntryObj));
    assert( E!=NULL );
    E->col = col;
    E->value = value;

    return (E);
}
// freeEntry()
// Frees heap memory associated with *pE, sets *pE to NULL.
void freeEntry(Entry *pE) {
    if (pE != NULL && *pE != NULL) {
        free(*pE);
        *pE = NULL;
    }
}

// newMatrix()
// Returns a reference to a new nXn Matrix object in the zero state.
Matrix newMatrix(int n) {
    Matrix M = (Matrix)malloc(sizeof(MatrixObj));
    assert(M!=NULL);
    M->entries = (List*)calloc(n+1, sizeof(List));
    for (int i = 1; i <= n; i++) {
        M->entries[i] = newList();

    }
    M->size = n;
    return(M);
}


// freeMatrix()
// Frees heap memory associated with *pM, sets *pM to NULL.
void freeMatrix(Matrix* pM) {
    if (pM != NULL && *pM != NULL) {
        // for(int i = 1; i<= (*pM)->size; i++) {
        //     for (moveFront((*pM)->entries[i]); index((*pM)->entries[i]) != -1; moveNext((*pM)->entries[i])) {
        //         Entry E = get((*pM)->entries[i]);
        //         freeEntry(&E);
        //     }
        //     freeList(&(*pM)->entries[i]);
        //     (*pM)->entries = NULL;
        // }
        makeZero(*pM);
        free(*pM);
        *pM = NULL;
    }
}

// Access functions ---------------------------------------------------
// size()
// Return the size of square Matrix M.
int size(Matrix M) {
    return (M->size);
}
// getEntry()
// get the entry value at entry E
double getEntry(Entry E) {
    return (E->value);
}

// getCol()
// get the col at entry E
int getCol(Entry E) {
    return (E->col);
}

// NNZ()
// Return the number of non-zero elements in M.
int NNZ(Matrix M) {
    int count = 0;
    for (int i = 1; i<= M->size; i++) {
        for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
            if (getEntry(get(M->entries[i])) != 0) {
                count++;
            }
        }
        

    }
    return count;
}
// equals()
// Return true (1) if matrices A and B are equal, false (0) otherwise.
int equals(Matrix A, Matrix B) {
    assert(A!=NULL);
    assert(B!=NULL);
    if (size(A) != size(B)) {
        return 0;
    }
    for (int i = 1; i <= size(A); i++) {
        moveFront(A->entries[i]);
        moveFront(B->entries[i]);
        if (length(A->entries[i]) != length(B->entries[i])) {
            return 0;
        }
        for (int j = 0; j < length(A->entries[i]); j++) {
            if (getEntry(get(A->entries[i])) != getEntry(get(B->entries[i]))) {
                return 0;
            }
            moveNext(A->entries[i]);
            moveNext(B->entries[i]);
        }

    }
    return 1;
}
// Manipulation procedures---------------------------------------------------
// makeZero()
// Re-sets M to the zero Matrix state.
void makeZero(Matrix M) {
    for (int i = 1; i <= size(M); i++) {
        for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
            Entry E = get(M->entries[i]);
            freeEntry(&E);
            
        }
        freeList(&(M->entries[i]));
        M->entries = NULL;
    }
    free(M->entries);
    M->entries = NULL;
    M->size = 0;

}

// changeEntry()
// Changes the ith row, jth column of M to the value x.
// Pre: 1<=i<=size(M), 1<=j<=size(M)
void changeEntry(Matrix M, int i, int j, double x) {
    assert(i <= size(M) && i >= 1);
    assert(j <= size(M) && j >= 1);
    

        //assert(!isEmpty(M->entries[a]));
        //printf("i: %d, j: %d, x: %0.1f\n", i, j, x);
        if (isEmpty(M->entries[i])) {
            append(M->entries[i], newEntry(j, x));
            return;
        }
        for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
            //printf("length: %d, i: %d, index: %d\n", length(M->entries[i]), i, index(M->entries[i]));
            if(getCol(get(M->entries[i])) > j) {
                prepend(M->entries[i], newEntry(j, x));
                return;
            }
            append(M->entries[i], newEntry(j, x));
            return;
            
        }



}
// Matrix Arithmetic operations---------------------------------------------------
// // copy()
// // Returns a reference to a new Matrix object having the same entries as A.
Matrix copy(Matrix A) {
    Matrix C = newMatrix(size(A));
    for (int i = 1; i < size(A); i++) {
        for (moveFront(A->entries[i]); index(A->entries[i]) != -1; moveNext(A->entries[i])) {
            append(C->entries[i], newEntry(getCol(A->entries[i]), getEntry(A->entries[i])));
        }
    }
    return C;
}
// transpose()
// Returns a reference to a new Matrix object representing the transpose
// of A.
Matrix transpose(Matrix A) {
    Matrix T = newMatrix(size(A));
    for (int i = 1; i < size(A); i++) {
        for (moveFront(A->entries[i]); index(A->entries[i]) != -1; moveNext(A->entries[i])) {
            append(T->entries[getCol(A->entries[i])], newEntry(i, getEntry(A->entries[i])));
        }
    }   
    return T;
}

// scalarMult()
// Returns a reference to a new Matrix object representing xA.
Matrix scalarMult(double x, Matrix A) {
    Matrix S = newMatrix(size(A));
    for (int i = 1; i < size(A); i++) {
        for (moveFront(A->entries[i]); index(A->entries[i]) != -1; moveNext(A->entries[i])) {
            append(S->entries[i], newEntry(getCol(A->entries[i]), x * getEntry(A->entries[i])));
        }
    }    
    return S;
}

// help_sum_diff()
// Helper function for the sum and diff function
// If test is 1, then sum, else diff

Matrix help_sum_diff(Matrix A, Matrix B, int test) {
    assert(size(A) == size(B));
    Matrix S = newMatrix(A);
    for (int i = 1; i < size(A); i++) {
        moveFront(A->entries[i]);
        moveFront(B->entries[i]);

        for (int j = 0; j < length(A->entries[i]); j++) {
            Entry E = NULL;
            if (test) {
                E = newEntry(getCol(A->entries[i]), getEntry(A->entries[i]) + getEntry(B->entries[i]));
            }
            else {
                E = newEntry(getCol(A->entries[i]), getEntry(A->entries[i]) - getEntry(B->entries[i]));
            }

            append(S->entries[i], E);
            freeEntry(&E);
            moveNext(A->entries[i]);
            moveNext(B->entries[i]);
        }
        
    }  
    return S;
}

// sum()
// Returns a reference to a new Matrix object representing A+B.
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B) {
  help_sum_diff(A, B, 1);
}

// diff()
// Returns a reference to a new Matrix object representing A-B.
// pre: size(A)==size(B)
Matrix diff(Matrix A, Matrix B) {
    help_sum_diff(A, B, 0);
}

// vectorDot()
// computes the vector dot product of List P and List Q
double vectorDot(List P, List Q) {
    double v = 0;
    moveFront(P);
    moveFront(Q);
    for (int i = 0; i < length(P); i++) {
        v += getEntry(get(P)) * getEntry(get(Q));
        moveNext(P);
        moveNext(Q);
    }
    return v;
}

// product()
// Returns a reference to a new Matrix object representing AB
// pre: size(A)==size(B)
Matrix product(Matrix A, Matrix B) {
    assert(size(A) == size(B));
    Matrix bT = transpose(B);
    Matrix P = newMatrix(A);
    for (int i = 0; i < size(A); i++) {
        double v = 0;
        
    }

}

// printMatrix()
// Prints a string representation of Matrix M to filestream out. Zero rows
// are not printed. Each non-zero row is represented as one line consisting
// of the row number, followed by a colon, a space, then a space separated
// list of pairs "(col, val)" giving the column numbers and non-zero values
// in that row. The double val will be rounded to 1 decimal point.
void printMatrix(FILE* out, Matrix M) {
    for (int i = 1; i <= size(M); i++) {
        if (isEmpty(M->entries[i])) {
            continue;
        }
        fprintf(out, "%d: ", i);

        for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
            if (getEntry(get(M->entries[i])) != 0) {
                fprintf(out, "(%d, %0.1f) ", getCol(get(M->entries[i])), getEntry(get(M->entries[i])));
            }
            
        }
        fprintf(out, "\n");

    }
    
}
