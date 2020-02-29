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
mpz_class a,b,B,c;


a=9; b=38, c=4;  sgn=true;
GMPfrac Frac1(a,b,c,sgn);

//a=9; b=38, c=31010001001;  sgn=true;
a=9; b=38, c=31;  sgn=true;
GMPfrac Frac2(a,b,c,sgn);

cout << "ASSIGNED FRAC1 AND FRAC2  --- They are\n";
Frac1.Show();  Frac2.Show(); 
cout <<"**********************************\n";

cout <<"floats are  " << Frac1.ExtractFloat() <<  "    and   " << Frac2.ExtractFloat() << endl;

GMPfrac Frac3;

Frac3=Frac1+Frac2;  //note Frac3 MUST be declared beforehand, cannot do GMPfrac Frac3=Frac1+Frac2;   
Frac3.Show();

bool set_true=true;  bool set_false=false;

Frac2.SetSign(set_false);
Frac3=Frac1+Frac2;
Frac3.Show();


Frac1.SetSign(set_false); Frac2.SetSign(set_true);
Frac3=Frac1+Frac2;
Frac3.Show();

Frac1.SetSign(set_false); Frac2.SetSign(set_false);
Frac3=Frac1+Frac2;
Frac3.Show();

a=18; b=7, c=31;  sgn=true;
Frac1.SetFrac(a,b,c,sgn);
a=10; b=1, c=2;  sgn=true;
Frac2.SetFrac(a,b,c,sgn);

cout << "REASSIGNED FRAC1 AND FRAC2  --- They are\n";
Frac1.Show();  Frac2.Show(); 
cout <<"**********************************\n";

Frac3=Frac1+Frac2;
Frac3.Show();

Frac2.SetSign(set_false);
Frac3=Frac1+Frac2;
Frac3.Show();

Frac1.SetSign(set_false); Frac2.SetSign(set_true);
Frac3=Frac1+Frac2;
Frac3.Show();

Frac1.SetSign(set_false); Frac2.SetSign(set_false);
Frac3=Frac1+Frac2;
Frac3.Show();






verbose_out.close();
}






