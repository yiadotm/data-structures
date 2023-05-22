/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA6
* BigIntegerTest.cpp
* File that tests BigInteger ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include "BigInteger.h"

using namespace std;

// // negateList()
// // Changes the sign of each integer in List L. Used by sub().
// void negateList(List& L) {
//     for (L.moveFront(); L.position() < L.length(); L.moveNext()) {
//         long x = L.peekNext();
//         L.setAfter(x * -1);
//     }
// }

// // sumList()
// // Overwrites the state of S with A + sgn*B (considered as vectors).
// // Used by both sum() and sub().
// void sumList(List& S, List A, List B, int sgn) {
//     S.clear();
//     if (A.length() == 0) {
//         S = B;
//         if (sgn == -1) {
//             negateList(S);
//         }
//         return;
//     }

//     if (B.length() == 0) {
//         S = A;
//         return;
//     }

//     A.moveBack();
//     B.moveBack();
//     while (A.position() > 0 && B.position() > 0) {
//         S.insertAfter(A.peekPrev() + sgn * B.peekPrev());
//         A.movePrev();
//         B.movePrev();
//     }

//     if (A.position() != 0) {
//         while (A.position() > 0) {
//             S.insertAfter(A.peekPrev());
//             A.movePrev();
//         }
//     }

//     if (B.position() != 0) {
//         while (B.position() > 0) {
//             S.insertAfter(sgn * B.peekPrev());
//             B.movePrev();
//         }
//     }

// }
// // scalarMultList()
// // Multiplies L (considered as a vector) by m. Used by mult().
// void scalarMultList(List& L, ListElement m) {
//     for (L.moveFront(); L.position() < L.length(); L.moveNext()) {
//         L.setAfter(L.peekNext() * m);
//     }
// }

int main(){
    BigInteger A;
    BigInteger B(123456);
    BigInteger C("-123456");
    BigInteger D(34556);
    cout << "A: 0\nA: " << A << endl;
    cout << "Signum of A: " << A.sign() << endl << endl;
    cout << "B: 1343545\nB: " << B << endl;
    cout << "Signum of B: " << B.sign() << endl << endl;
    cout << "C: 3545646\nC: " << C << endl;
    cout << "Signum of C: " << C.sign() << endl << endl;
    cout << "D: 3545646\nD: " << D << endl;
    cout << "Signum of D: " << D.sign() << endl << endl;

    cout << "A.compare(B): " << (A.compare(B)) << endl << endl;
    cout << "B.compare(C): " << (B.compare(C)) << endl << endl;
    cout << "C.compare(A): " << (C.compare(A)) << endl << endl;
    cout << "C.compare(C): " << (C.compare(C)) << endl << endl;
    D.makeZero();
    cout << "D after makeZero: " << D << endl;
    cout << "Signum of D: " << D.sign() << endl << endl;

    C.negate();
    cout << "C after negate: " << C << endl;
    cout << "Signum of C: " << C.sign() << endl << endl;    

    List L, LL, S;
    L.insertBefore(1);
    L.insertBefore(2);
    L.insertBefore(3);
    L.insertBefore(4);
    L.insertBefore(5);
    L.insertBefore(6);
    L.insertBefore(7);

    LL.insertBefore(1);
    LL.insertBefore(2);
    LL.insertBefore(3);
    LL.insertBefore(4);
    LL.insertBefore(5);
    LL.insertBefore(6);
    LL.insertBefore(7);

    cout << "L: " << L << endl;
    cout << "LL: " << LL << endl;
    scalarMultList(L, -14);
    cout << "L * 5: " << L << endl << endl;
    
    return 0;
}
