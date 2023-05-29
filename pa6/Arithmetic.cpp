/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA6
* Arithmetic.cpp
* The main executable for this program. Parses the string on line 1 of the input 
* file as a BigInteger, calling it A. Reads and discard line 2, then parses the 
* string on line 3 as a BigInteger, calling it B. Computes the specified 
* operations and write into base 10 digits (including a negative sign, 
* if appropriate) to the output file. 
*********************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include <fstream>
#include "List.h"
#include "BigInteger.h"

using namespace std;

int main(int argc, char * argv[]){
    if( argc != 3 ){
        cerr << "Usage: " << argv[0] << " <INPUT> <OUTPUT>" << endl;
        return(EXIT_FAILURE);
    }
    string x;
    string a, b;
    ifstream infile;
    ofstream outfile;
    infile.open(argv[1], ios::in);
    outfile.open(argv[2], ios::out);
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }    

    infile >> x;
    a = x;
    infile >> x;
    infile >> x;
    b = x;
    cout << a << endl;

    cout << b << endl;
    BigInteger A(a);
    BigInteger B(b);

    outfile << A << endl << endl;

    outfile << B << endl << endl;

    outfile << A + B << endl << endl;

    outfile << A - B << endl << endl;

    outfile << A - A << endl << endl;

    outfile << (BigInteger(3)*A) - (BigInteger(2)*B) << endl << endl;

    outfile << A * B << endl << endl;

    outfile << A * A << endl << endl;
    
    outfile << B * B << endl << endl;

    outfile << (BigInteger(9) * (A * A * A * A)) + (BigInteger(16) * (B * B * B * B * B)) << endl << endl;

    infile.close();
    outfile.close();
    return 0;

}