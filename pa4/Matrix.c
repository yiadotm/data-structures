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
    int NNZ;

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
    M->NNZ = 0;
    return(M);
}


// freeMatrix()
// Frees heap memory associated with *pM, sets *pM to NULL.
void freeMatrix(Matrix* pM) {
    if (pM != NULL && *pM != NULL) {
        makeZero(*pM);
        // printf("Size: %d\n", (*pM)->size);
        for(int i = 1; i <= (*pM)->size; i++) {
            // printf("danee sucks %dx more than toes\n", i);

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
    // int count = 0;
    // for (int i = 1; i<= M->size; i++) {
    //     for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
    //         if (getEntry(get(M->entries[i])) != 0) {
    //             count++;
    //         }
    //     }
        

    // }
    // return count;
    return (M->NNZ);
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

        for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
            Entry E = get(M->entries[i]);
            freeEntry(&E);
        }
        clear(M->entries[i]);
    }
    M->NNZ = 0;
}

// changeEntry()
// Changes the ith row, jth column of M to the value x.
// Pre: 1<=i<=size(M), 1<=j<=size(M)
void changeEntry(Matrix M, int i, int j, double x) {
    assert(i <= size(M) && i >= 1);
    assert(j <= size(M) && j >= 1);

    //assert(!isEmpty(M->entries[a]));
    //printf("i: %d, j: %d, x: %0.1f\n", i, j, x);
    //printf("NNZ: %d\n", NNZ(M));
    // overwrite or append
    if (isEmpty(M->entries[i])) {
        if (x != 0.0) {
            // printf("empty:: i: %d, j: %d, x: %0.1f\n", i, j, x);
            // printf("length: %d\n", length(M->entries[i]));
            append(M->entries[i], newEntry(j, x));
            // printf("length: %d\n", length(M->entries[i]));

            M->NNZ++;
            // printf("i: %d, j: %d, x: %0.1f\n", i, j, x);
            // printf("NNZ: %d\n", NNZ(M));
            return;
        }

    }
    for (moveFront(M->entries[i]); index(M->entries[i]) != -1; moveNext(M->entries[i])) {
        //printf("length: %d, i: %d, index: %d\n", length(M->entries[i]), i, index(M->entries[i]));
        if (getCol(get(M->entries[i])) == j) {
            if (x == 0)  {
                // printf("(%d, %d, %0.1f)\n", i, j, x);
                Entry E = get(M->entries[i]);
                freeEntry(&E);
                delete(M->entries[i]);
                M->NNZ--;
                return;
            }
            // printf("set:: i: %d, j: %d, x: %0.1f, length: %d\n", i, j, x, length(M->entries[i]));
            Entry E = get(M->entries[i]);
            freeEntry(&E);
            set(M->entries[i], newEntry(j, x));
            return;
        }
        // printf("col: %d, (%d, %0.1f) \n", getCol(get(M->entries[i])), j, x);
        if(j < getCol(get(M->entries[i]))) {
            if (x != 0.0) {
                insertBefore(M->entries[i], newEntry(j, x));
                M->NNZ++;
                // printf("i: %d, j: %d, x: %0.1f\n", i, j, x);
                // printf("NNZ: %d\n", NNZ(M));
                return;
            }

        }
        if (j > getCol(back(M->entries[i]))) {
            if (x != 0.0) {
                append(M->entries[i], newEntry(j, x));
                M->NNZ++;
                // printf("i: %d, j: %d, x: %0.1f\n", i, j, x);
                // printf("NNZ: %d\n", NNZ(M));
                return;
            }
        }


        
    }



}
// Matrix Arithmetic operations---------------------------------------------------
// // copy()
// // Returns a reference to a new Matrix object having the same entries as A.
Matrix copy(Matrix A) {
    Matrix C = newMatrix(size(A));
    for (int i = 1; i <= size(A); i++) {
        for (moveFront(A->entries[i]); index(A->entries[i]) != -1; moveNext(A->entries[i])) {
            changeEntry(C, i, getCol(get(A->entries[i])), getEntry(get(A->entries[i])));
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
            // printf("(%d, %d, %0.1f)\n", getCol(get(A->entries[i])), i, getEntry(get(A->entries[i])));
            changeEntry(T, getCol(get(A->entries[i])), i, getEntry(get(A->entries[i])));

            
            
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
            changeEntry(S, i, getCol(get(A->entries[i])), x * getEntry(get(A->entries[i])));
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
    
    if (isEmpty(P)) {
        return 0;
    }
    if (isEmpty(Q)) {
        return 0;
    }
    while (index(P) >= 0 && index(Q) >= 0) {
        // printf("colP: %d, colQ: %d\n", getCol(get(P)), getCol(get(Q)));

        if (getCol(get(P)) < getCol(get(Q))) {
            moveNext(P);
            // printf("here1\n");
        }
        else if (getCol(get(Q)) < getCol(get(P))) {
            moveNext(Q);
            
        }
        if (index(P) == -1 || index(Q) == -1) {
            break;
        }
        // printf("colP: %d, colQ: %d\n", getCol(get(P)), getCol(get(Q)));
        if (getCol(get(P)) == getCol(get(Q))) {
            // printf("indexP: %d, indexQ: %d\n", index(P), index(Q));

            v += getEntry(get(P)) * getEntry(get(Q));
            // printf("%0.1f = %0.1f + %0.1f\n", getEntry(get(Q))+ getEntry(get(P)), getEntry(get(Q)), getEntry(get(P)));
            moveNext(P);
            moveNext(Q);
            // printf("indexP: %d, indexQ: %d\n", index(P), index(Q));

        }
    }
    // printf("\n");
    return v;
}




// add_or_sub()
// Helper function for the sum and diff function
// If test is 1, then sum, else diff
void add_or_sub(List A, List B, Matrix S, int i, int test) {
    moveFront(A);
    moveFront(B);
    if ((isEmpty(A))) {
        while (index(B) >= 0) {
            if (test) {
                changeEntry(S, i, getCol(get(B)), getEntry(get(B)));
                moveNext(B);
            }
            else {
            changeEntry(S, i, getCol(get(B)), -1 * getEntry(get(B)));
            moveNext(B);                
            }
        }
    }
    if (isEmpty(B)) {
        while (index(A) >= 0) {
            changeEntry(S, i, getCol(get(A)), getEntry(get(A)));
            moveNext(A);

        }
    }
        
    while (index(A) >= 0 && index(B) >= 0) {
        if (getCol(get(B)) == getCol(get(A))) {
            if (test) {
            changeEntry(S, i, getCol(get(A)), getEntry(get(A)) + getEntry(get(B)));
            }
            else {
            changeEntry(S, i, getCol(get(A)), getEntry(get(A)) - getEntry(get(B)));

            }
            moveNext(A);      
            moveNext(B);      
        }

        if (index(A) == -1 || index(B) == -1) {
            break;
        }
        // printf("1 indexA: %d, indexB: %d\n", index(A), index(B));
        if (getCol(get(A)) < getCol(get(B))) {
            changeEntry(S, i, getCol(get(A)), getEntry(get(A)));
            moveNext(A);
            // printf("3 indexA: %d, indexB: %d\n", index(A), index(B));

        }
        else if (getCol(get(B)) < getCol(get(A))) {
            if (test) {
                changeEntry(S, i, getCol(get(B)), getEntry(get(B)));
                moveNext(B); 
                // printf("4 indexA: %d, indexB: %d\n", index(A), index(B));

            }
            else {
                changeEntry(S, i, getCol(get(B)), -1 * getEntry(get(B)));
                // printf("entry: %d, %0.1f\n", getCol(get(B)), -1 * getEntry(get(B)));
                moveNext(B);
                // printf("4 indexA: %d, indexB: %d\n", index(A), index(B));
            }
           
        }
        // printf("5 indexA: %d, indexB: %d\n", index(A), index(B));

        // printf("2 indexA: %d, indexB: %d\n", index(A), index(B));


    }
    // printf("6 indexA: %d, indexB: %d\n", index(A), index(B));

    if (index(B) >= 0) {
        while (index(B) >= 0) {
           if (test) {
                changeEntry(S, i, getCol(get(B)), getEntry(get(B)));
                moveNext(B); 
            }
            else {
                changeEntry(S, i, getCol(get(B)), -1 *getEntry(get(B)));
                moveNext(B);
                
            }
        }
        
    }
    // printf("7 indexA: %d, indexB: %d\n", index(A), index(B));

    if (index(A) >= 0) {
        while (index(A) >= 0) {
            changeEntry(S, i, getCol(get(A)), getEntry(get(A)));
            moveNext(A);
        }        
    }

}

// sum()
// Returns a reference to a new Matrix object representing A+B.
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B) {
    assert(size(A) == size(B));
    if (equals(A, B)) {
        return scalarMult(2, A);
    }
    Matrix S = newMatrix(size(A));
    for (int i = 1; i <= size(A); i++) {
        add_or_sub(A->entries[i], B->entries[i], S, i, 1);
        // printf("length[%d]: %d\n", i, length(S->entries[i]));
        
    }
    return S;
}

// diff()
// Returns a reference to a new Matrix object representing A-B.
// pre: size(A)==size(B)
Matrix diff(Matrix A, Matrix B) {
    Matrix D = newMatrix(size(A));
    assert(size(A) == size(B));
        if (equals(A, B)) {
        return D;
    }
    for (int i = 1; i <= size(A); i++) {
        add_or_sub(A->entries[i], B->entries[i], D, i, 0);
        
    }
    return D;    
}



// product()
// Returns a reference to a new Matrix object representing AB
// pre: size(A)==size(B)
Matrix product(Matrix A, Matrix B) {
    assert(size(A) == size(B));
    Matrix bT = transpose(B);
    Matrix P = newMatrix(size(A));
    printf("size: %d\n", NNZ(A));
    for (int i = 1; i <= size(A); i++) {
        // if (isEmpty(bT->entries[i]) || isEmpty(A->entries[i])) {
        //     continue;
        // }
        // printf("length: %d\n", length(bT->entries[i]));
        // printf("col: %d\n",  getCol(back(bT->entries[i])));
        for (int j = 1; j <= size(bT); j++) {
            // printf("product:: i: %d, j: %d  \n", i, j);
            // printf("v: %0.1f\n", vectorDot(A->entries[i], bT->entries[j]));
            // printf("\n");
            // printMatrix(stdout, P);
            // printf("\n");

            changeEntry(P, i, j, vectorDot(A->entries[i], bT->entries[j]));
            // printf("i: %d, j: %d  \n", i, j);
        }

    }
    freeMatrix(&bT);
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
