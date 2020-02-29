// Test more addition
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


a1=9; b1=38, c1=4;  sgn=true;
GMPfrac Frac1(a1,b1,c1,sgn);

//a=9; b=38, c=31010001001;  sgn=true;
a2=9; b2=38, c2=31;  sgn=true;
GMPfrac Frac2(a2,b2,c2,sgn);

Frac2.JumpToFloat();

cout << "ASSIGNED FRAC1 AND FRAC2  --- They are\n";
Frac1.Show();  Frac2.Show(); 
cout <<"**********************************\n";

GMPfrac Frac3;

Frac3=Frac1+Frac2;  //note Frac3 MUST be declared beforehand, cannot do GMPfrac Frac3=Frac1+Frac2;   
Frac3.Show();


//Reset Frac2
Frac2.SetFrac(a2,b2,c2,sgn);

bool set_true=true;  bool set_false=false;

Frac2.SetSign(set_false);
Frac1.JumpToFloat();
Frac3=Frac1+Frac2;
cout << "ASSIGNED FRAC1 AND FRAC2  --- They are\n";
Frac1.Show();  Frac2.Show(); 
Frac3.Show();

//Reset Frac1
Frac1.SetFrac(a1,b1,c1,sgn);
Frac1.SetSign(set_false); Frac2.SetSign(set_true);
Frac1.JumpToFloat(); Frac2.JumpToFloat();
Frac3=Frac1+Frac2;
cout << "ASSIGNED FRAC1 AND FRAC2  --- They are\n";
Frac1.Show();  Frac2.Show(); 
cout << "Showing Frac3\n";
Frac3.Show();


verbose_out.close();
}






