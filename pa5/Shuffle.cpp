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
    
    one.moveFront();
    two.moveFront();
    for (int x = 0; x < one.length(); x++) {
        two.insertAfter(one.peekNext());
        one.moveNext();
        two.moveNext();
    }

    D = two;

}

int main(int argc, char * argv[]){
    int count, c = 0;
    // check command line for correct number of arguments
    if( argc != 2 ){
        cerr << "Usage: " << argv[0] << " (Range of Shuffle)" << endl;
        return(EXIT_FAILURE);
    }
    count = stoi(argv[1]);
    cout << "deck size shuffle count" << endl;
    cout << "-----------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << i+1 + "      ";
        List L, LL;
        for (int j = 0; j < i; j++) {
            L.insertBefore(j);
        }
        
        while(true) {
            shuffle(LL);
            c++;
            if (L == LL) {
                break;
            }
        }
        cout << c << endl;

    }




       


}