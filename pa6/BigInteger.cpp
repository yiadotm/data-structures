/********************************************************************************* 
* Danee Dang, dudang
* 2023 Spring CSE101 PA6
* BigInteger.h
* File Implementation of BigInteger ADT
*********************************************************************************/
#include<iostream>
#include<string>
#include <math.h>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include"List.h"
#include "BigInteger.h"


int power = 1; 
long base = pow(10, power);
// Class Constructors & Destructors -------------------------------------------
// BigInteger()
// Constructor that creates a new BigInteger in the zero state: 
// signum=0, digits=().
BigInteger::BigInteger() {
    signum = 0;
    digits = List();
}

// BigInteger()
// Constructor that creates a new BigInteger from the long value x.
BigInteger::BigInteger(long x) {

    long y = x;
    if (y < 0) {
        
        signum = -1;
        y *= -1;
    }
    else {
        signum = 1;
    }
   
    if (y == 0) {
        digits.insertAfter(x);
    }
    else {
        while (y > 0) {
            if (y < base) {
                digits.insertAfter(y);
                break;
            }
            long i = y % base;

            if (i == 0) {
                // digits.insertAfter(0);
                y = (y / base);
                continue;
            }

            // y = (y / base);
            // std::cout << "i: " << y << " % " << base << " = " << i << std::endl;
            digits.insertAfter(i);
            // if (i < base) {
            //     for (int j = (log10(i) + 1); j < power; j++) {
            //         digits.insertAfter(0);
            //     }
            // }
            y = (y - i)/base;
            
            // std::cout << "y: " << y << std::endl;
            
        }
    }

}


// BigInteger()
// Constructor that creates a new BigInteger from the string s.
// Pre: s is a non-empty string consisting of (at least one) base 10 digit
// {0,1,2,3,4,5,6,7,8,9}, and an optional sign {+,-} prefix.
BigInteger::BigInteger(std::string s) {
    if (s.length() == 0) {
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    }
    if (s.length() == 1 && !isdigit(s[0])) {
        throw std::invalid_argument("BigInteger: Constructor: not a number");
    }

    // std::cout << "s[0]: " << s[0] << std::endl;
    // std::cout << "s[1]: " << s[1] << std::endl;

    // if (strcmp(c, "-") == 0) {
    //     signum = -1;
    // }
    // else {
    //     signum = 1;
    // }
    // char* s_temp = new char[s.length() + 1];
    // char* end;
    signum = 1;
    int signcheck = 0;
    if (s[0] == '-') {
        signum = -1;
        signcheck = 1;
       
    }
    if (s[0] == '+') {
        signum = 1;
        signcheck = 1;
    }    
    // unsigned int stop = 0;
    // if (signcheck) {
    //     stop = 1;
    // }
    std::string c = "";
    int left = 0;
    for (unsigned int i = 1; i < s.length(); i++) {
            if (!isdigit(s[i])) {
                throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
                break;
            }      
    }
    for (unsigned int i = s.length(); i > 1; i-= power) {
        if (signcheck && i > 0) {
            if (!isdigit(s[i-1])) {
                throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
                break;
            }
        }

        c = s.substr(i - power, power);
        // std::cout << "c: " << c << std::endl;

        if (std::stol(c) == 0) {
            digits.insertAfter(0);

        }
        else {
            digits.insertAfter(std::stol(c));

        }
        // std::cout << "left: " << i - power << std::endl;
        if ((int)(i - power) <= power) {
            left = i - power;
            
        }


        

    }
    // std::cout << "c: " << c << std::endl;
    if (left > 0) {
        c = s.substr(signcheck, left);
        // std::cout << "c: " << c << std::endl;
        digits.insertAfter(std::stol(c));
    }




    std::cout << std::endl << this->digits << std::endl << std::endl;
    // strcpy(s_temp, s.c_str());
    // long long str = strtoll(s_temp, &end, 10);
    // BigInteger B = BigInteger(str);
    // this->digits = B.digits;
    // this->signum = B.signum;

}

// BigInteger()
// Constructor that creates a copy of N.
BigInteger::BigInteger(const BigInteger& N) {
    signum = N.signum;
    digits = N.digits;

}


// Access functions --------------------------------------------------------

// sign()
// Returns -1, 1 or 0 according to whether this BigInteger is positive, 
// negative or 0, respectively.
int BigInteger::sign() const {
    return (signum);
}

// compare()
// Returns -1, 1 or 0 according to whether this BigInteger is less than N,
// greater than N or equal to N, respectively.
int BigInteger::compare(const BigInteger& N) const {
    if (signum > N.signum) {
        // std::cout << "1" << std::endl;
        return 1;
    }
    if (signum < N.signum) {
        // std::cout << "2" << std::endl;
        return -1;
    }
    if (digits.length() < N.digits.length()) {
        // std::cout << "3" << std::endl;
        return -1;
    }
    if (digits.length() > N.digits.length()) {
        // std::cout << "4" << std::endl;
        return 1;
    }
    List d = digits;
    List dN = N.digits;
    d.moveBack();
    dN.moveBack();
    for (int i = 0; i < digits.length(); i++) {
        if (d.peekPrev() < dN.peekPrev()) {
            // std::cout << "5" << std::endl;
            return -1;
        }
        else if (d.peekPrev() > dN.peekPrev()) {
            // std::cout << "6" << std::endl;
            return 1;
        }
        else {
            d.movePrev();
            dN.movePrev();
        }
    }
    return 0;

}

// Manipulation procedures -------------------------------------------------

// makeZero()
// Re-sets this BigInteger to the zero state.
void BigInteger::makeZero() {
    signum = 0;
    digits.clear();
}

// negate()
// If this BigInteger is zero, does nothing, otherwise reverses the sign of 
// this BigInteger positive <--> negative. 
void BigInteger::negate() {
    if (signum == 0) {
        return;
    }
    signum = signum * -1;
}


// BigInteger Arithmetic operations ----------------------------------------

// negateList()
// Changes the sign of each integer in List L. Used by sub().
void negateList(List& L) {
    for (L.moveFront(); L.position() < L.length(); L.moveNext()) {
        long long x = L.peekNext();
        L.setAfter(x * -1);
    }
}

// sumList()
// Overwrites the state of S with A + sgn*B (considered as vectors).
// Used by both sum() and sub().
void sumList(List& S, List A, List B, int sgn) {
    // List copyA = A;
    // List copyB = B;
    // normalizeList(copyA);
    // normalizeList(copyB);
    // B.moveFront();
    // A.moveFront();
    // if (B.sign() < 0) {
    //     if (sgn == 1) {
    //         sgn = -1;
    //     }
    //     if (sgn == -1) {
    //         sgn = 1;
    //     }
    //     negateList(B);
        
    // }
    
    // if (A.front() < 0) {
    //     if (sgn == 1) {
    //         sgn = -1;
    //     }
    //     if (sgn == -1) {
    //         sgn = 1;
    //     }
    //     negateList(A);
    // }

    S.clear();
    if (A.length() == 0) {
        S = B;
        if (sgn == -1) {
            negateList(S);
        }
        return;
    }

    if (B.length() == 0) {
        S = A;
        return;
    }

    A.moveBack();
    B.moveBack();
    while (A.position() > 0 && B.position() > 0) {
        if (A.position() != 1 && A.peekPrev() == 0 && (A.peekPrev() != A.back())) {
            A.movePrev();
        }
        if (B.position() != 1 && B.peekPrev() == 0 && (B.peekPrev() != B.back())) {
            B.movePrev();
        }
        S.insertAfter(A.peekPrev() + sgn * B.peekPrev());
        // std::cout << "add: " << A.peekPrev() << " + " << sgn * B.peekPrev() << std::endl;
        A.movePrev();
        B.movePrev();
    }

    if (A.position() != 0) {
        while (A.position() > 0) {
            S.insertAfter(A.peekPrev());
            A.movePrev();
        }
    }

    if (B.position() != 0) {
        while (B.position() > 0) {
            S.insertAfter(sgn * B.peekPrev());
            B.movePrev();
        }
    }

    // std::cout << S << std::endl;
}

// normalizeList()
// Performs carries from right to left (least to most significant
// digits), then returns the sign of the resulting integer. Used
// by add(), sub() and mult().
int normalizeList(List& L) {
    int sgn = 1;
    long long carry = 0;
    // std::cout << sgn << std::endl;
    if (L.front() < 0) {
        sgn = -1;
        negateList(L);
        // cout << L << endl;
        normalizeList(L);
    }
    // cout << "here" << endl;
    for (L.moveBack(); L.position() > 0; L.movePrev()) {
        long long old = L.peekPrev();
        long long newValue;
        long long subtract = old + carry;

        if (subtract < 0) {
            // newValue = -1 * old;
            // newValue = ((newValue + carry) % base);
            newValue = ((base + ((subtract) % base)) % base);
            if (newValue > 0 && newValue < base) {
                if (L.position() == 1) {
                    L.setBefore(subtract);
                    break;
                }
                carry = old / base;
                // cout << "carry = (-1)old / base: " << carry << " = " << -1 * old << " / " << base << endl;
                if (carry == 0) {
                    carry = -1;
                }
            }
            else {
                if (newValue < base) {
                    if (L.position() == 1) {
                        L.setBefore(subtract);
                        break;
                    }
                }
                carry = subtract / base;
            }
            
            // carry = (base + ((subtract) % base)) % base;

        }
        else {
            newValue = subtract % base;
            carry = subtract / base;
            // carry = (base + (subtract % base)) % base;

            
        }

        L.setBefore(newValue);
        // carry = subtract / base;
        // std::cout << "position: " << L.position() << ", old: " << old << ", subtract: " << subtract << ", new: " << newValue << ", carry: " << carry << std::endl;
    }
    // std::cout << L << std::endl;
    // std::cout << "position: " << L.position() << ", carry: " << carry << std::endl;
    if (carry > 0) {
        // std::cout << "here" << std::endl;
        L.insertBefore(carry);
    }

    return sgn;
}


// shiftList()
// Prepends p zero digits to L, multiplying L by base^p. Used by mult().
void shiftList(List& L, int p) {
    L.moveBack();
    for (int i = 0; i < p; i++) {
        L.insertBefore(0);
    }
}

// scalarMultList()
// Multiplies L (considered as a vector) by m. Used by mult().
void scalarMultList(List& L, ListElement m) {
    for (L.moveFront(); L.position() < L.length(); L.moveNext()) {
        L.setAfter(L.peekNext() * m);
    }
}


// add()
// Returns a BigInteger representing the sum of this and N.
BigInteger BigInteger::add(const BigInteger& N) const {
    BigInteger S;
    if (this->signum == -1 && N.signum == 1) {
        // std::cout << "here1" << std::endl;
        sumList(S.digits, N.digits, this->digits, -1);
    }
    if (this->signum == 1 && N.signum == 1) {
        // std::cout << "here2" << std::endl;
        sumList(S.digits, this->digits, N.digits, 1);
    }
    if (this->signum == 1 && N.signum == -1) {
        // std::cout << "here3" << std::endl;
        sumList(S.digits, this->digits, N.digits, -1);
    }
    if (this->signum == -1 && N.signum == -1) {
        // std::cout << "here4" << std::endl;
        sumList(S.digits, this->digits, N.digits, 1);
    }
    // std::cout << "this: " << this->digits << std::endl;
    // std::cout << "this sign: " << this->signum << std::endl;
    // std::cout << "N: " << N.digits << std::endl;
    // std::cout << "N sign: " << N.signum << std::endl;
    // std::cout << "S: " << S.digits << std::endl;
    if (S.digits.length() != 0) {
        S.signum = normalizeList(S.digits);
    }
    
    // std::cout << this->digits << "    " << N.digits << "    " << S.digits << std::endl;
    return S;
}

// sub()
// Returns a BigInteger representing the difference of this and N.
BigInteger BigInteger::sub(const BigInteger& N) const {
    BigInteger S;
    if (this->signum == 1 && N.signum == 1) {
        sumList(S.digits, this->digits, N.digits, -1);
    }
    if (this->signum == -1 && N.signum == 1) {
        sumList(S.digits, this->digits, N.digits, 1);
        negateList(S.digits);
    }
    if (this->signum == 1 && N.signum == -1) {
        sumList(S.digits, this->digits, N.digits, 1);
    }        
    if (this->signum == -1 && N.signum == -1) {
        sumList(S.digits, N.digits, this->digits, -1);
    }       
    // std::cout << S.signum << std::endl;

    S.signum = normalizeList(S.digits);
    // std::cout << S.digits << std::endl;
    return S;
}

// mult()
// Returns a BigInteger representing the product of this and N. 
BigInteger BigInteger::mult(const BigInteger& N) const {
    BigInteger S;
    BigInteger copyN;
    BigInteger current;
    copyN.digits = N.digits;
    copyN.signum = N.signum;
    current.digits = this->digits;
    current.signum = this->signum;
    S.signum = 1;

    if (this->digits.length() == 0 && N.digits.length() == 0) {
        return S;
    }
    int shift = 0;
    copyN.digits.moveBack();

    while (copyN.digits.position() > 0) {
        // std::cout << copyN.digits.position() << std::endl;

        current.digits = this->digits;
        shiftList(current.digits, shift);
        // std::cout << "here12" << std::endl;
        scalarMultList(current.digits, copyN.digits.movePrev());
        // std::cout << "current after mult: " << current.digits << std::endl;
        if (S.digits.length() == 0) {
            // std::cout << "here23" << std::endl;
            S.digits = current.digits;
            // std::cout << "here23" << std::endl;
        }
        else {
            // std::cout << S.sign() << std::endl;
            // std::cout << S.digits << std::endl;
            // std::cout << current.sign() << std::endl;
            // std::cout << current.digits << std::endl;
            S = S.add(current);
            // std::cout << "here24353" << std::endl;
        }
        // std::cout << S.digits.front() << std::endl;
        normalizeList(S.digits);
        // std::cout << "S after normalize: " << S.digits << std::endl;
        shift++;
        
    } 
    if (this->signum == -1 && N.signum == 1) {
        S.signum = -1;
    }
    if (this->signum == 1 && N.signum == -1) {
        S.signum = -1;
    }
    if (this->signum == -1 && N.signum == -1) {
        S.signum = 1;
    }
    if (this->signum == 1 && N.signum == 1) {
        S.signum = 1;
    }   
    return S;

}

// to_string()
// Returns a string representation of this BigInteger consisting of its
// base 10 digits. If this BigInteger is negative, the returned string 
// will begin with a negative sign '-'. If this BigInteger is zero, the
// returned string will consist of the character '0' only.
std::string BigInteger::to_string() {
    int count = 0;
    std::string s = "";
    if (signum == 0) {
        s += std::to_string(0);
        return s;
    }

    if (signum == -1) {
        s += "-";
    }
    for (digits.moveFront(); digits.position() < digits.length(); digits.moveNext()) {
        
        if (digits.peekNext() == 0) {
            count++;
        }        
        // std::cout << "here "  << std::endl;
        if (digits.peekNext() < base && digits.peekNext() != 0 && digits.peekNext() != digits.front()) {
            for (int i = (log10(digits.peekNext()) + 1); i < power; i++) {
                s += "0";
            }
            
        }
        // std::cout << "here2 "  << std::endl;

        s += std::to_string(digits.peekNext());
    }
    if (count == digits.length()) {
        s = "0";
    }
    // std::cout << "digits lengths: " << this->digits.length() << std::endl;
    return s;
}

// // Overriden Operators -----------------------------------------------------

// operator<<()
// Inserts string representation of N into stream.
std::ostream& operator<<( std::ostream& stream, BigInteger N ) {
    return stream << N.BigInteger::to_string();
}

// operator==()
// Returns true if and only if A equals B. 
bool operator==( const BigInteger& A, const BigInteger& B ) {
    if (A.BigInteger::compare(B) == 0) {
        return true;
    }
    return false;
}

// operator<()
// Returns true if and only if A is less than B. 
bool operator<( const BigInteger& A, const BigInteger& B ) {
    if (A.BigInteger::compare(B) == -1) {
        return true;
    }
    return false;
}

// operator<=()
// Returns true if and only if A is less than or equal to B. 
bool operator<=( const BigInteger& A, const BigInteger& B ) {
    int x = A.BigInteger::compare(B);
    if (x == -1 || x == 0) {
        return true;
    }
    return false;
}

// operator>()
// Returns true if and only if A is greater than B. 
bool operator>( const BigInteger& A, const BigInteger& B ) {
    if (A.BigInteger::compare(B) == 1) {
        return true;
    }
    return false;
}

// operator>=()
// Returns true if and only if A is greater than or equal to B. 
bool operator>=( const BigInteger& A, const BigInteger& B ) {
    int x = A.BigInteger::compare(B);
    if (x == 1 || x == 0) {
        return true;
    }
    return false;
}

// operator+()
// Returns the sum A+B. 
BigInteger operator+( const BigInteger& A, const BigInteger& B ) {
    return (A.BigInteger::add(B));
}

// operator+=()
// Overwrites A with the sum A+B. 
BigInteger operator+=( BigInteger& A, const BigInteger& B ) {
    A = A.BigInteger::add(B);
    return (A);
}

// operator-()
// Returns the difference A-B. 
BigInteger operator-( const BigInteger& A, const BigInteger& B ) {
    return (A.BigInteger::sub(B));
}

// operator-=()
// Overwrites A with the difference A-B. 
BigInteger operator-=( BigInteger& A, const BigInteger& B ) {
    A = A.BigInteger::sub(B);
    return (A);
}

// operator*()
// Returns the product A*B. 
BigInteger operator*( const BigInteger& A, const BigInteger& B ) {
    // std::cout << "huh " << std::endl;
    BigInteger S = A.BigInteger::mult(B);
    // std::cout << "huh 2" << std::endl;
    return (S);
}

// operator*=()
// Overwrites A with the product A*B. 
BigInteger operator*=( BigInteger& A, const BigInteger& B ) {
    A = A.BigInteger::mult(B);
    return(A);
}