/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA7
* DictionaryTest.cpp
* File that tests Dictionary ADT
*********************************************************************************/

#include<iostream>
#include<string>
#include<stdexcept>
#include"Dictionary.h"

using namespace std;

int main(){

   Dictionary A;
   Dictionary B;
   Dictionary C;
   A.setValue("a", 1);   
   A.setValue("b", 2);   
   A.setValue("c", 3);   
   A.setValue("d", 4);   
   A.setValue("e", 5);   
   A.setValue("f", 6);   
   B.setValue("z", 1);
   B.setValue("y", 2);
   B.setValue("x", 3);
   B.setValue("w", 4);
   B.setValue("v", 5);
   C = B;
   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << "B.size() = " << B.size() << endl  << B << endl;
   cout << "C.size() = " << C.size() << endl  << C << endl;

   cout << "A==B is " << (A==B?"true":"false") << endl << endl;
   cout << "Remove b and z" << endl;
   A.remove("b");
   B.remove("z");
   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << "B.size() = " << B.size() << endl  << B << endl;
   cout << "C.size() = " << C.size() << endl  << C << endl;
   cout << "prestring: " << endl;
   cout << A.pre_string() << endl;

   cout << "test begin next and has current" << endl;
   for(A.begin(); A.hasCurrent(); A.next()){
      cout<< A.currentKey() <<", " << A.currentVal() << "  " << endl;
   }
   cout << endl << "test end prev and has current" << endl;
   for(A.end(); A.hasCurrent(); A.prev()){
      cout<< A.currentKey() <<", " << A.currentVal() << "  " << endl;
   }

   return( EXIT_SUCCESS );
}