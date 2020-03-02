#include <stdio.h>  //standard input output
#include <iostream> // input output (cin cout etc)
#include <fstream>  //file stream
#include <stdlib.h> //string conversion + malloc and calloc
#include <math.h>
/* 
Sizes of types for g++ compiler
char=1 byte
short int = 2 bytes
int = 4 bytes
long int=4 bytes
long long int=8 bytes
check your compiler to see if they same for you!
*/
#include "C:\myIncludez\GMPfrac_Headers\GMPfrac.h"

//We are using C++ interface for GMP

using namespace::std;


typedef unsigned char uchar;
typedef unsigned short int biguchar;
typedef  float Tfloat;


 main(){


ofstream verbose_out;
bool showit=false; bool printit=true;
verbose_out.open("test1.out",ios::out);
//Inspect values using ShowVerbose() (to std out) or PrintFracVerbose() to file test1.dat

bool sgn;
mpz_class a1,b1,c1;
mpz_class a2,b2,c2;

mpz_class ZERO; mpz_class ONE;


ZERO=0; ONE=1;

int nterms=90;
sgn=true;

mpz_class avec[nterms+1],bvec[nterms+1];

//MUST initialise

for(int i=0;i<=nterms;i++){
  cout << "a and b vecs " << i << endl;
  avec[i]=1;  bvec[i]=2;   }


//Exception is
bvec[0]=1;

GMPfrac numer; GMPfrac b_term;

GMPfrac FRAC0(bvec[nterms-1],avec[nterms],bvec[nterms],sgn);

GMPfrac Sequence[nterms+1];

Sequence[0]=FRAC0;

// i must start at 1.

for(int i=1; i<=nterms;i++){

   numer.SetFrac(avec[nterms-i],ZERO,ONE,sgn);
   b_term.SetFrac(bvec[nterms-i],ZERO,ONE,sgn);

   Sequence[i]=b_term+numer/Sequence[i-1];

}


for(int i=0;i<=nterms;i++){
    cout << "For i=" << i << endl;
    Sequence[i].Show();
}
cout << "Sequence Ended\n";

verbose_out.close();
}






