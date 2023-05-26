/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA6
* BigIntegerTest.cpp
* File that tests BigInteger ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include <math.h>
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
// // normalizeList()
// // Performs carries from right to left (least to most significant
// // digits), then returns the sign of the resulting integer. Used
// // by add(), sub() and mult().
// int normalizeList(List& L, int base) {
//     int sgn = 1;
//     long carry = 0;
//     if (L.front() < 0) {
//         sgn = -1;
//         negateList(L);
//         cout << L << endl;
//         normalizeList(L, base);
//     }
//     // cout << "here" << endl;
//     for (L.moveBack(); L.position() > 0; L.movePrev()) {
//         long old = L.peekPrev();
//         long newValue;
//         long subtract = old + carry;
//         if (L.position() == 1) {
//             L.setBefore(subtract);
//             break;
//         }
//         if (subtract < 0) {
//             // newValue = -1 * old;
//             // newValue = ((newValue + carry) % base);
//             newValue = ((base + ((subtract) % base)) % base);
//             if (newValue > 0 && newValue < base) {
//                 carry = old / base;
//                 // cout << "carry = (-1)old / base: " << carry << " = " << -1 * old << " / " << base << endl;
//                 if (carry == 0) {
//                     carry = -1;
//                 }
//             }
//             else {
//                 carry = subtract / base;
//             }
            
//             // carry = (base + ((subtract) % base)) % base;

//         }
//         else {
//             newValue = subtract % base;
//             carry = subtract / base;
//             // carry = (base + (subtract % base)) % base;

            
//         }

//         L.setBefore(newValue);
//         // carry = subtract / base;
//         cout << "position: " << L.position() << ", old: " << old << ", subtract: " << subtract << ", new: " << newValue << ", carry: " << carry << endl;
//     }
//     if (carry > 0) {
//         L.insertBefore(carry);
//     }

//     return sgn;
// }

// // shiftList()
// // Prepends p zero digits to L, multiplying L by base^p. Used by mult().
// void shiftList(List& L, int p) {
//     L.moveBack();
//     for (int i = 0; i < p; i++) {
//         L.insertBefore(0);
//     }
// }

int main(){
    BigInteger A;
    BigInteger B(7402779357);
    BigInteger C("-0041085449");
    BigInteger D(34556);
    cout << "A: 0\nA: " << A << endl;
    cout << "Signum of A: " << A.sign() << endl << endl;
    cout << "B: 7402779357\nB: " << B << endl;
    cout << "Signum of B: " << B.sign() << endl << endl;
    cout << "C: -0041085449\nC: " << C << endl;
    cout << "Signum of C: " << C.sign() << endl << endl;
    cout << "D: 34556\nD: " << D << endl;
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
    L.insertBefore(882133);
    // L.insertBefore(-90);
    // L.insertBefore(9);
    // L.insertBefore(73);
    // L.insertBefore(0);
    // L.insertBefore(-500);
    // L.insertBefore(7);

    // LL.insertBefore(23);
    // LL.insertBefore(-70);
    // LL.insertBefore(-46);

    // S.insertBefore(-8);
    // S.insertBefore(1);
    // S.insertBefore(5);
    // S.insertBefore(8);
    // S.insertBefore(0);
    // S.insertBefore(0);
    // S.insertBefore(7);

    // L.insertBefore(88);
    // L.insertBefore(21);
    // L.insertBefore(33);

    // LL.insertBefore(65);
    // LL.insertBefore(91);
    // LL.insertBefore(79);


    cout << "L: " << L << endl << endl;
    // cout << "LL: " << LL << endl << endl;
    // cout << "S: " << S << endl << endl;
    // normalizeList(L, 100);
    // normalizeList(LL, 100);
    // normalizeList(S, 10);
    cout << "B - C: " << B.sub(C) << endl << endl;
    // cout << "L after normalize: " << L << endl << endl;
    // cout << "S after normalize: " << S << endl << endl;
    // cout << "-71 % 100 = " << (100 + (-71 % 100)) % 100 << endl << endl;
    return 0;
}
