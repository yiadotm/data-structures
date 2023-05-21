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

    // List L;
    // L.insertBefore(1);
    // L.insertBefore(-2);
    // L.insertBefore(3);
    // L.insertBefore(-4);
    // L.insertBefore(5);
    // L.insertBefore(-6);
    // L.insertBefore(7);
    // cout << "L: " << L << endl;
    // negateList(L);
    // cout << "L after negate: " << L << endl << endl;
    
    return 0;
}
