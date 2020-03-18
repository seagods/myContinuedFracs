#include <stdio.h>  //standard input output
#include <iostream> // input output (cin cout etc)
#include <fstream>  //file stream
#include <stdlib.h> //string conversion + malloc and calloc
#include <math.h>

/*             *************************************    
          USEFUL DOCOMENTATION IN
          /libsMSwin/SOURCES/gmp-6.1.2/doc/gmp/index.htm 
          /libsMSwin/SOURCES/gmp-6.1.2/doc/gmp/GMP-basics.htm etc, 

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

main(){

ofstream writedata_out;
bool showit=false; bool printit=true;
writedata_out.open("ABdata.dat",ios::out);

bool sgn;
mpz_class a1,b1,c1;
mpz_class a2,b2,c2;

mpz_class ZERO; mpz_class ONE;

ZERO=0; ONE=1;

int ntermsmax=90;
int nterms=ntermsmax;
sgn=true;

mpz_class avec[ntermsmax+1],bvec[ntermsmax+1];

//MUST initialise

for(int i=0;i<=ntermsmax;i++){
avec[i]=ZERO;  bvec[i]=ONE;   }

int iopt=1;

cout << "iopt=1, Huygens CF for pi (15 terms max)\n";
cout << "iopt=2, pi=3+1^2||6+3^2||6+5^2||6+7^2||6+...\n";
cout << "iopt=3, pi=0+4||1^2+1||2^2+3|3^2||5+4^2||7+...\n";	
cout << "iopt=4, pi=2+2||1+1*2||1+2*3||1+3*4||1+4*5||1+...";
cout << "iopt=5, pi=2+4||3+1*3||4+3*5||4+5*7||4+7*9||4+...";
cout << "iopt=6, pi=0+4||1+(1^2)||2+3^2||2+5^2||2+...\n";
cout << "iopt=7, 4/pi=1+1^2||2+3^2||2+(5^2)||7^2||2+...\n";
//Brouncker's continued fraction

cout << "iopt=8  e=2+... (a_n=1), (b_n=2,1,1,4,1,1,6,1,1,8,1,1,10...\n";
	

cout << "enter iopt\n"; 
cin >> iopt;
cout << "enter number of terms\n";
cin >> nterms;

int k=0;
//k is for kounting

if(iopt==1 &&  nterms>15){ cout << "nterms must be less than 15 for iopt=1"; exit(0); }
if(nterms>ntermsmax){ cout << "reducing nterms to ntermsmax=" << ntermsmax; nterms=ntermsmax; }
if(iopt>8){ cout << "No series for this value of iopt!\n"; exit(0); }
if(iopt==1){
      for(int i=0;i<nterms;i++){avec[i]=1; }
      avec[0]=0;
      bvec[0]=3; bvec[1]=7; bvec[2]=15; bvec[3]=1; bvec[4]=292;
      bvec[5]=1; bvec[6]=1; bvec[7]=1; bvec[8]=2; bvec[9]=2;
      bvec[10]=3; bvec[11]=1; bvec[12]=14; bvec[13]=2; bvec[14]=1;
           }
if(iopt==2){
   for(int i=0;i<nterms;i++){
      k=2*i-1;  //avec[0] doesn't exist!
      avec[i]=k*k;  bvec[i]=6;
    }
    bvec[0]=3;
    avec[0]=0;
           }
if(iopt==3){
   for(int i=0;i<nterms;i++){
      k=2*i-1;  //avec[0] doesn't exist!
      avec[i]=(i-1)*(i-1);  bvec[i]=k;
    }
    bvec[0]=0;
    avec[0]=0;
    avec[1]=4;
           }

if(iopt==4){
   for(int i=0;i<nterms;i++){
      k=2*i-1;  //avec[0] doesn't exist!
      avec[i]=(i+1)*(i);  bvec[i]=1;
    }
    bvec[0]=2;
    avec[0]=2;
           }
if(iopt==5){
   for(int i=0;i<nterms;i++){
      k=2*i-1;  //avec[0] doesn't exist!
      avec[i]=(k-2)*(k);  bvec[i]=4;
    }
    bvec[0]=2;
    bvec[1]=3;
    avec[0]=0;
    avec[1]=4;
           }
if(iopt==6){
   for(int i=0;i<nterms;i++){
      k=2*i-1;  //avec[0] doesn't exist!
      avec[i]=(k-2)*(k-2);  bvec[i]=2;
    }
    bvec[0]=0;
    bvec[1]=1;
    avec[0]=0;
    avec[1]=4;
           }
if(iopt==7){
   //Brounkers CF for 4/pi
   for(int i=0;i<nterms;i++){
      k=2*i-1;  //avec[0] doesn't exist!
      avec[i]=(k)*(k);  bvec[i]=2;
    }
    bvec[0]=0;
    avec[0]=0;
           }
if(iopt==8){
   //Brounkers CF for 4/pi
   for(int i=0;i<nterms;i++){
      k=2*i-1;  //avec[0] doesn't exist!
      avec[i]=(k)*(k);  bvec[i]=2;
    }
    bvec[0]=0;
    avec[0]=0;
           }


//  -lgmpxx means that we can just use an overloaded <<
//  NOTE: overloaded << doesn't support things like << a+b;
writedata_out << nterms <<  "  " << iopt << endl;
for(int i=0;i<nterms;i++){
     writedata_out << i <<  "  " << avec[i] << "  " <<  bvec[i] << endl;  
    }

writedata_out.close();
}



