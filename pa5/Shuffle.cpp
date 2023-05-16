/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA5
* Shuffle.cpp
* Main execuble of the program.
* Takes an input file and shuffles the numbers based on given and 
* outputs in a output file
*********************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include "List.h"
using namespace std;

void shuffle(List& D) {
    List one, two;
    int n = D.length();
    D.moveFront();
    
    for (int i = 0; i < n/2; i++) {
        // cout << D << endl;
        one.insertBefore(D.peekNext());
        D.moveNext();
    }
    
    for (int j = 0; j < n/2; j++) {
        two.insertBefore(D.peekNext());
        D.moveNext();
    }
    if (n % 2 == 1) {
        two.insertBefore(D.peekNext());
    }
    // cout << "one: ";
    // cout << one << endl;
    // cout << "two: ";
    // cout << two << endl;
    one.moveFront();
    two.moveFront();
    for (int x = 0; x < one.length(); x++) {
        // cout << one.peekNext() << endl;
        two.moveNext();
        // cout << two.position() << endl;
        two.insertAfter(one.peekNext());
        two.moveNext();
        one.moveNext();
        
    }

    D = two;

}

int main(int argc, char * argv[]){
    // List L;
    // for (int i = 0; i < 7; i++) {
    //     L.insertBefore(i);
    // }
    // cout << L << endl;
    // shuffle(L);
    // cout << L << endl;

    int count, c = 0;
    // check command line for correct number of arguments
    if( argc != 2 ){
        cerr << "Usage: " << argv[0] << " (Range of Shuffle)" << endl;
        return(EXIT_FAILURE);
    }
    count = stoi(argv[1]);
    cout << "deck size       shuffle count" << endl;
    cout << "------------------------------" << endl;

    for (int i = 1; i <= count; i++) {
        c = 0;
        cout << i;
        cout << "\t\t";
        
        List L, LL;
        // cout << "herere" << endl;
        for (int j = 0; j < i; j++) {
            L.insertBefore(j);
        }
        LL = L;
        while(true) {
            
            shuffle(LL);
            
            c++;
            // cout << "L: ";
            // cout << L << endl;
            // cout << "LL: ";
            // cout << LL << endl;
            if (L == LL) {
                break;
            }
        }
        cout << c << endl;

    

    }

    return 0;


       


}