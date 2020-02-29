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

/**********************************************************************/
//Ranlib Functions USE FORTRAN VERSION OF RANLIB TO
// AVOID POSSIBLE MESS WITH LINKING TO FORTRAN LINPACK
#include "C:\myIncludez\ranlib2.h"

extern "C" {void  setall_( int& , int& ); }
extern "C" {void  getsd_( int&, int&); }
extern "C" {void  getcgn_(int&); }
extern "C" {float  ranf_(); }

#include "C:\myIncludez\GMPfrac_Headers\GMPfrac.h"

//We are using C++ interface for GMP

using namespace::std;

 main(){

      int iseed1,iseed2; //need for random numbers
                          //default values are 1234567890 and 123456789
/*
The seeds can be  initialized  by the  user; the initial values of the
first must lie between 1 and 2,147,483,562, that of the second between
1 and 2,147,483,398. 
*/

      iseed1=112344; iseed2=12324;
      setall_(iseed1,iseed2);   //set the seeds

     // sets these seeds for generator 1, and automatically
     // sets seeds for all other generators, i.e. generator 2, generator 3,...
      int iseed1pt; int iseed2pt;
      getsd_(iseed1pt,iseed2pt);
      cout << "ranlib says the seeds are " << iseed1pt << " and " << iseed2pt << endl;
      int Generator;
      getcgn_(Generator);
      cout << "ranlib says the generator number is " << Generator << endl;


     ofstream verbose_out;
     bool showit=false; bool printit=true;
     verbose_out.open("test1.out",ios::out);
//Inspect values using ShowVerbose() (to std out) or PrintFracVerbose() to file test1.dat

     GMPfrac Frac1,Frac2,Frac3;

     bool sgn;
     mpz_class a,b,B,c;

     float Rana, Ranb, Ranc, Ransign;
     unsigned int ra,rb,rc,rs;

     double  d_eps=1e-10;
     mpf_class eps=mpf_class(d_eps);

     for(int kount=0; kount<10000; kount++){

          if(kount==1){
             cout <<"About to FAIL!\n";
          }

          Rana=ranf_(); Ranb=ranf_(); Ranc=ranf_();  Ransign=ranf_();

          ra=(unsigned int)(Rana*30);
          rb=(unsigned int)(Ranb*100);
          rc=(unsigned int)(Ranc*100+1);

          if(Ransign>0.5){sgn=true;} else {sgn=false;}

          a=mpz_class(ra); b=mpz_class(rb), c=mpz_class(rc); 
          Frac1.SetFrac(a,b,c,sgn);

          Rana=ranf_(); Ranb=ranf_(); Ranc=ranf_();  Ransign=ranf_();

          ra=(unsigned int)(Rana*30);
          rb=(unsigned int)(Ranb*100);
          rc=(unsigned int)(Ranc*100+1);

         if(Ransign>0.5){sgn=true;} else {sgn=false;}

          a=mpz_class(ra); b=mpz_class(rb), c=mpz_class(rc); 
          Frac2.SetFrac(a,b,c,sgn);

          mpf_class fp1,fp2,fp3,fperr;

          cout << "*****************   Frac1   ******************************\n";
          Frac1.Show();  fp1= Frac1.ExtractFloat();
          cout << "*****************   Frac2   ******************************\n";
          Frac2.Show();  fp2= Frac2.ExtractFloat();


          Frac3=Frac1+Frac2;


          cout << "*****************   Frac3   ******************************\n";
          Frac3.Show();  fp3= Frac3.ExtractFloat();
          cout << "*****************  Sum   ******************************\n";
          cout <<  fp1 << "  +  " << fp2 << "  = " << fp3  << endl; 
          fperr=fp1+fp2-fp3;
          if(abs(fperr)>eps){
            cout <<"kount=" << kount << endl;
            cout << "Error = " << fp1+fp2-fp3 << "  eps=" << eps  << endl;
            exit(1);  }
          cout << "*****************  Next  ******************************\n";
       }

      cout <<"RANtest1 competed without error!\n";






verbose_out.close();
}






