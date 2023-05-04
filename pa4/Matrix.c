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
        // makeZero(*pM);
        // printf("Size: %d\n", (*pM)->size);
        for(int i = 1; i <= (*pM)->size; i++) {
            // printf("danee sucks %dx more than toes\n", i);
            for (moveFront((*pM)->entries[i]); index((*pM)->entries[i]) != -1; moveNext((*pM)->entries[i])) {
                // printf("i = what\n", i);
                Entry E = get((*pM)->entries[i]);
                freeEntry(&E);

            }

            freeList(&((*pM)->entries[i]));
            (*pM)->entries[i] = NULL;
        }
        free(((*pM)->entries));
        (*pM)->entries = NULL;
        free(*pM);
        *pM = NULL;
    }
}

// Access functions ---------------------------------------------------
// size()
// Return the size of square Matrix M.
int size(Matrix M) {
    assert(M!=NULL);
    return (M->size);
}
// getEntry()
// get the entry value at entry E
double getEntry(Entry E) {
    assert(E!=NULL);
    return (E->value);
}

// getCol()
// get the col at entry E
int getCol(Entry E) {
    assert(E!=NULL);
    return (E->col);
}

// NNZ()
// Return the number of non-zero elements in M.
int NNZ(Matrix M) {
    assert(M!=NULL);
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

    Matrix copyA = copy(A);
    Matrix copyB = copy(B);
    for (int i = 1; i <= size(A); i++) {
        moveFront(copyA->entries[i]);
        moveFront(copyB->entries[i]);
        if (length(copyA->entries[i]) != length(copyB->entries[i])) {
            freeMatrix(&copyA);
            freeMatrix(&copyB);
            return 0;
        }
        for (int j = 0; j < length(copyA->entries[i]); j++) {
            if (getEntry(get(copyA->entries[i])) != getEntry(get(copyB->entries[i]))) {
                freeMatrix(&copyA);
                freeMatrix(&copyB);
                return 0;
            }
            moveNext(copyA->entries[i]);
            moveNext(copyB->entries[i]);
        }

    }
    freeMatrix(&copyA);
    freeMatrix(&copyB);
    return 1;
}
// Manipulation procedures---------------------------------------------------
// makeZero()
// Re-sets M to the zero Matrix state.
void makeZero(Matrix M) {
    if (NNZ(M) == 0) {
        return;
    }
    for (int i = 1; i <= size(M); i++) {
        // for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
        //     // printf("i = what\n", i);
        //     delete((M->entries[i]));
        // }
        int len = length(M->entries[i]);
        for (int j = 0; j < len; j++) {
            deleteFront(M->entries[i]);
        }
    }
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
    for (int i = 1; i <= size(A); i++) {
        for (moveFront(A->entries[i]); index(A->entries[i]) != -1; moveNext(A->entries[i])) {
            append(C->entries[i], newEntry(getCol(get(A->entries[i])), getEntry(get(A->entries[i]))));
        }
    }
    return C;
}
// transpose()
// Returns a reference to a new Matrix object representing the transpose
// of A.
Matrix transpose(Matrix A) {
    Matrix T = newMatrix(size(A));
    for (int i = 1; i <= size(A); i++) {
        for (moveFront(A->entries[i]); index(A->entries[i]) != -1; moveNext(A->entries[i])) {
            append(T->entries[getCol(get(A->entries[i]))], newEntry(i, getEntry(get(A->entries[i]))));
        }
    }   
    return T;
}

// scalarMult()
// Returns a reference to a new Matrix object representing xA.
Matrix scalarMult(double x, Matrix A) {
    Matrix S = newMatrix(size(A));
    for (int i = 1; i <= size(A); i++) {
        for (moveFront(A->entries[i]); index(A->entries[i]) != -1; moveNext(A->entries[i])) {
            append(S->entries[i], newEntry(getCol(get(A->entries[i])), x * getEntry(get(A->entries[i]))));
        }
    }    
    return S;
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

// maxlen()
// returns the greater length of 2 lists
int maxlen(List P, List Q) {
    if (length(P) > length(Q)) return length(P);
    return length(Q);
}

// help_sum_diff()
// Helper function for the sum and diff function
// If test is 1, then sum, else diff

Matrix help(Matrix A, Matrix B, int test) {
    assert(size(A) == size(B));
    Matrix S = newMatrix(size(A));
    // for (int i = 1; i <= size(A); i++) {
    //     moveFront(A->entries[i]);
    //     moveFront(B->entries[i]);
    //     // printf("lengthA:%d ", length(A->entries[i]));
    //     // printf("lengthB:%d\n", length(B->entries[i]));
    //     // int max = maxlen(A->entries[i], B->entries[i]);
    //     int colA = getCol(get(A->entries[i]));
    //     int colB = getCol(get(B->entries[i]));
    //     double entryA = getEntry(get(A->entries[i]));
    //     //printf("here3\n");
    //     double entryB = getEntry(get(B->entries[i]));

    //     while (index(A->entries[i]) != -1 && index(B->entries[i]) != -1) {
    //         // Entry E = NULL;
    //         // printf("length: %d, index: %d\n", length(A->entries[i]), index(A->entries[i]));
    //         //  printf("here2\n");
    //         //printf("here4\n");
    //         if (colA == colB) {
    //             if (test) {
    //                 printf("colA: %d, colB: %d, A: %0.1f, B:%0.1f\n", colA, colB, entryA, entryB);
    //                 append(S->entries[i], newEntry(colA, entryA + entryB));
                    
    //             }
    //             else {
    //                 append(S->entries[i], newEntry(colA, entryA - entryB));
    //             }
    //             moveNext(A->entries[i]);
    //             moveNext(B->entries[i]);
    //             colA = getCol(get(A->entries[i]));
    //             colB = getCol(get(B->entries[i]));
    //             entryA = getEntry(get(A->entries[i]));
    //             //printf("here3\n");
    //             entryB = getEntry(get(B->entries[i]));
    //             continue;
    //         }
    //         else if (colA < colB) {
    //                 printf("colA: %d, colB: %d, A: %0.1f, B:%0.1f\n", colA, colB, entryA, entryB);
    //                 append(S->entries[i], newEntry(colA, entryA));
    //                 moveNext(A->entries[i]);
    //                 colA = getCol(get(A->entries[i]));
    //                 entryA = getEntry(get(A->entries[i]));
    //                 continue;
                    
                
                
    //         }
    //         else {
    //             if (test) {
    //                 printf("colA: %d, colB: %d, A: %0.1f, B:%0.1f\n", colA, colB, entryA, entryB);
    //                 append(S->entries[i], newEntry(colB, entryB));
    //                 moveNext(B->entries[i]);
    //                 colB = getCol(get(B->entries[i]));
    //                 entryB = getEntry(get(B->entries[i]));
    //                 continue;
                    
    //             }
    //             else {
    //                 append(S->entries[i], newEntry(colB, -1.0 * entryB));
    //                 moveNext(B->entries[i]);
    //                 colB = getCol(get(B->entries[i]));
    //                 entryB = getEntry(get(B->entries[i]));
    //                 continue;
    //             }                     
    //         }

    //             // append(S->entries[i], E);
    //             // freeEntry(&E);

            

    //     }
        
    // }  

    for (int i = 1; i <= size(A); i++) {
        List rowA = A->entries[i];
        List rowB = B->entries[i];
        List out = S->entries[i];
        moveFront(rowA);
        moveFront(rowB);
        moveFront(out);
        if ((length(rowA) == 0)) {
            while (index(rowB) >= 0) {
                Entry B = newEntry(getCol(get(rowB)), getEntry(get(rowB)));
                append(out, B);
                moveNext(rowA);
            }
        }
        if (length(rowB) == 0) {
            while (index(rowA) >= 0) {
                Entry A = newEntry(getCol(get(rowA)), getEntry(get(rowA)));
                append(out, A);
                moveNext(rowA);
            }
        }
        
        while (index(rowA) >= 0 && index(rowB) >= 0) {
            Entry entryA = get(rowA);
            Entry entryB = get(rowB);
            if (getCol(entryA) > getCol(entryB)) {
                append(out, newEntry(getCol(entryB), getEntry(entryB)));
                moveNext(rowB);
            }
            else if (getCol(entryA) < getCol(entryB)) {
                append(out, newEntry(getCol(entryA), getEntry(entryA)));
                moveNext(rowA);
            }

            if (getCol(entryA) == getCol(entryB)) {
                if (test) {append(out, newEntry(getCol(entryA), getEntry(entryA) + getEntry(entryB))); }
                else { append(out, newEntry(getCol(entryA), getEntry(entryA) - getEntry(entryB))); }
                
                moveNext(rowA);
                moveNext(rowB);
            }


        }
        if (index(rowA) >= 0) {
            append(out,  newEntry(getCol(get(rowA)), getEntry(get(rowA))));
        }
        if (index(rowB) >= 0) {
            append(out,  newEntry(getCol(get(rowB)), getEntry(get(rowB))));
        }

    }
    return S;
}

// sum()
// Returns a reference to a new Matrix object representing A+B.
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B) {
  return help(A, B, 1);
}

// diff()
// Returns a reference to a new Matrix object representing A-B.
// pre: size(A)==size(B)
Matrix diff(Matrix A, Matrix B) {
    return help(A, B, 0);
}



// product()
// Returns a reference to a new Matrix object representing AB
// pre: size(A)==size(B)
Matrix product(Matrix A, Matrix B) {
    assert(size(A) == size(B));
    Matrix bT = transpose(B);
    Matrix P = newMatrix(size(A));
    for (int i = 1; i <= size(A); i++) {
        //printf("size: %d", size(bT));
        for (int j = 1; j <= length(bT->entries[i]); j++) {
            //printf("vectordot: %0.1f\n", vectorDot(A->entries[i], bT->entries[j]));
            append(P->entries[i], newEntry(j, vectorDot(A->entries[i], bT->entries[j])));
            //printf("here2\n");

        }

    }
    return P;


}

// printMatrix()
// Prints a string representation of Matrix M to filestream out. Zero rows
// are not printed. Each non-zero row is represented as one line consisting
// of the row number, followed by a colon, a space, then a space separated
// list of pairs "(col, val)" giving the column numbers and non-zero values
// in that row. The double val will be rounded to 1 decimal point.
void printMatrix(FILE* out, Matrix M) {

    if (NNZ(M) == 0) {
        return;
    }
    for (int i = 1; i <= size(M); i++) {
        if (isEmpty(M->entries[i])) {
            continue;
        }

        fprintf(out, "%d: ", i);

        for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
            if (getEntry(get(M->entries[i])) != 0.0) {
                fprintf(out, "(%d, %0.1f) ", getCol(get(M->entries[i])), getEntry(get(M->entries[i])));
            }
            
        }
        fprintf(out, "\n");

    }
    
}
