/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA5
* ListTest.cpp
* File that tests List ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

using namespace std;

int main(){

   int i, n=10;
   List A, B;
   // cout << "here1\n";
   for(i=1; i<=n; i++){
      A.insertAfter(i);
      // cout << "here3\n";
      B.insertBefore(i);
   }
   cout << endl << "insertBefore(), insertAfter(), position()" << endl;
   cout << "--------------------------" << endl;
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl << endl;
   A.moveFront();
   B.moveFront();
   A.moveNext();
   B.moveNext();
   cout << endl << "moveFront() and moveNext()" << endl;
   cout << "--------------------------" << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B.position() = " << B.position() << endl << endl;
   A.moveBack();
   B.moveBack();
   A.movePrev();
   B.movePrev();
   cout << endl << "moveBack() and movePrev()" << endl;
   cout << "--------------------------" << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B.position() = " << B.position() << endl;

   cout << endl << "setBefore() and setAfter()" << endl;
   cout << "--------------------------" << endl;

   A.setBefore(6);
   A.setAfter(10);
   B.setBefore(23);
   B.setAfter(64);
   cout << "A = " << A << endl;
   cout << "B = " << B << endl;

   cout << endl << "eraseBefore() and eraseAfter()" << endl;
   cout << "--------------------------" << endl;
   A.eraseBefore();
   A.eraseAfter();
   B.eraseBefore();
   B.eraseAfter();

   cout << "A = " << A << endl;
   cout << "B = " << B << endl;

   cout << endl << "findNext() and findPrev()" << endl;
   cout << "--------------------------" << endl;
   A.moveFront();
   B.moveBack();
   cout << "A.findNext(6) = " << A.findNext(6) << endl;
   cout << "B.findPrev(2) = " << B.findPrev(2) << endl;

   return( EXIT_SUCCESS );
}
