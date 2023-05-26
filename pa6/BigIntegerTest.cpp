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

// int main(){
//     BigInteger A;
//     BigInteger B(7402779357);
//     BigInteger C("-0041085449");
//     BigInteger D(34556);
//     cout << "A: 0\nA: " << A << endl;
//     cout << "Signum of A: " << A.sign() << endl << endl;
//     cout << "B: 7402779357\nB: " << B << endl;
//     cout << "Signum of B: " << B.sign() << endl << endl;
//     cout << "C: -0041085449\nC: " << C << endl;
//     cout << "Signum of C: " << C.sign() << endl << endl;
//     cout << "D: 34556\nD: " << D << endl;
//     cout << "Signum of D: " << D.sign() << endl << endl;

//     cout << "A.compare(B): " << (A.compare(B)) << endl << endl;
//     cout << "B.compare(C): " << (B.compare(C)) << endl << endl;
//     cout << "C.compare(A): " << (C.compare(A)) << endl << endl;
//     cout << "C.compare(C): " << (C.compare(C)) << endl << endl;
//     D.makeZero();
//     cout << "D after makeZero: " << D << endl;
//     cout << "Signum of D: " << D.sign() << endl << endl;

//     C.negate();
//     cout << "C after negate: " << C << endl;
//     cout << "Signum of C: " << C.sign() << endl << endl;    

//     List L, LL, S;
//     L.insertBefore(882133);
//     // L.insertBefore(-90);
//     // L.insertBefore(9);
//     // L.insertBefore(73);
//     // L.insertBefore(0);
//     // L.insertBefore(-500);
//     // L.insertBefore(7);

//     // LL.insertBefore(23);
//     // LL.insertBefore(-70);
//     // LL.insertBefore(-46);

//     S.insertBefore(74);
//     S.insertBefore(43);
//     S.insertBefore(69);
//     S.insertBefore(39);
//     S.insertBefore(0);
//     S.insertBefore(8);
//     // S.insertBefore(7);

//     // L.insertBefore(88);
//     // L.insertBefore(21);
//     // L.insertBefore(33);

//     // LL.insertBefore(65);
//     // LL.insertBefore(91);
//     // LL.insertBefore(79);


//     cout << "L: " << L << endl << endl;
//     // cout << "LL: " << LL << endl << endl;
//     cout << "S: " << S << endl << endl;
//     // normalizeList(L, 100);
//     // normalizeList(LL, 100);
//     // normalizeList(S, 10);
//     cout << "B - C: " << B.sub(C) << endl << endl;
//     // cout << "L after normalize: " << L << endl << endl;
//     // cout << "S after normalize: " << S << endl << endl;
//     // cout << "-71 % 100 = " << (100 + (-71 % 100)) % 100 << endl << endl;
//     return 0;
// }

int main(){

   string s1 = "91287346670000043892345634563400005619187236478";
   //string s2 = "-330293847502398475";
   string s3 = "9876545439000000345634560000000002000034565430000000006543654365346534";
   //string s4 = "9876545439000000000000000100000000000006543654365346534";
   string s5 = "98765454390000034563456191872363456345619187236000456456345756780000065436543";
   //string s6 = "9876545439000000000000000000000000000006543";
   string s7 = "-123456";

   //BigInteger N;
   BigInteger A = BigInteger(s1);
   BigInteger B = BigInteger(s3);
   BigInteger C = BigInteger(s5);

   cout << endl;

   cout << "A = " << A << endl;
   cout << "B = " << B << endl;
   cout << "C = " << C << endl;
   cout << endl;

   BigInteger D = A+B;
   BigInteger E = B+A;
   BigInteger F = D-E;
//    BigInteger G = 53234*A + 29384747*B + 928374*C;
//    BigInteger H = A*B;
//    BigInteger I = B*A;
//    BigInteger J = G*H*I;

   cout << "(A==B) = " << ((A==B)?"True":"False") << endl;
   cout << "(A<B)  = " << ((A<B)? "True":"False") << endl;
   cout << "(A<=B) = " << ((A<=B)?"True":"False") << endl;
   cout << "(A>B)  = " << ((A>B)? "True":"False") << endl;
   cout << "(A>=B) = " << ((A>=B)?"True":"False") << endl << endl;

   cout << "D = " << D << endl;
   cout << "E = " << E << endl;
   cout << "(D==E) = " << ((D==E)?"True":"False") << endl;
   cout << "F = " << F << endl;
//    cout << "G = " << G << endl;
//    cout << "H = " << H << endl;
//    cout << "I = " << I << endl;
//    cout << "(H==I) = " << ((H==I)?"True":"False") << endl;
//    cout << "J = " << J << endl << endl;

   cout << endl;

   A += B;
   B -= C;
//    C *= J;
   cout << "A = " << A << endl;
   cout << "B = " << B << endl;
//    cout << "C = " << C << endl;
   cout << endl;

//    cout << A*B*C*D*E*G*H*I*J << endl << endl;

   cout << endl;

   // test exceptions
   try{
      BigInteger J = BigInteger("");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      BigInteger J = BigInteger("+");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      BigInteger J = BigInteger("12329837492387492837492$4982379487293847");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      BigInteger J = BigInteger("5298374902837409+82734098729287349827398");
   }catch( std::invalid_argument& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }

   cout << endl;

   return EXIT_SUCCESS;
}
