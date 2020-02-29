//Test a few  constructors

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


// declare Frac1 using default constructor

bool sgn=true;
mpz_class a, b, B, c;
GMPfrac Frac1; 


B=27; c=7;
GMPfrac Frac2(B,c,sgn);

a=9; b=37, c=5; 
GMPfrac Frac3(a,b,c,sgn);

B=212; c=8;
GMPfrac Frac4(B,c,sgn);

a=9; b=38, c=4; 
GMPfrac Frac5(a,b,c,sgn);

GMPfrac* NewFrac1=new GMPfrac;

delete NewFrac1;
  
verbose_out.close();
}






