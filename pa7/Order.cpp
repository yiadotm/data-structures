/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA7
* Order.cpp
* Main executable of the program. It reads in the lines of an input file, each
* line being a (unique) single string, then inserts these strings (as keys)
* into a Dictionary.
*********************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include <fstream>
#include "Dictionary.h"

using namespace std;

int main(int argc, char * argv[]){
    ifstream infile;
    ofstream outfile;
    string line;
    int count = 1;
    if( argc != 3 ){
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return(EXIT_FAILURE);
    }
    // open files for reading and writing 
    infile.open(argv[1]);
    if( !infile.is_open() ){
        cerr << "Unable to open file " << argv[1] << " for reading" << endl;
        return(EXIT_FAILURE);
    }

    outfile.open(argv[2]);
    if( !outfile.is_open() ){
        cerr << "Unable to open file " << argv[2] << " for writing" << endl;
        return(EXIT_FAILURE);
    }
    Dictionary D;
    while (getline(infile, line)) {
        D.setValue(line, count);
        count++;
    }
    
    for (D.begin(); D.hasCurrent(); D.next()) {
        outfile << D.currentKey() << " : " << D.currentVal() << endl;
    }
    outfile << endl;


    outfile << D.pre_string() << endl;
    
    infile.close();
    outfile.close();
    return 0;
}