#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include <sdsl/suffix_arrays.hpp>
#include <algorithm>
#include "./includeFiles/simple_compression.cpp"
#include "./includeFiles/csafunction.cpp"
#include "./includeFiles/simple_decompression.cpp"
using namespace std;
using namespace sdsl;
using std:: chrono:: milliseconds;
using std:: chrono:: duration_cast;
using std:: chrono:: system_clock;
int main()
{

cout<<"No of Iterations: ";
int ite;
cin>>ite;
int n=ite;
string mystring;
cin>>mystring;
const char* const inFilename = "englishtext"; 


 countstring(inFilename,mystring);
 cout << "Computed number of matches using naive approach"<<endl;
 countstring2(inFilename,mystring);
 cout << "Computed matches using fundamental preprocessing"<<endl;
char* const outFilename = createOutFilename_orDie(inFilename);
    compress_orDie(inFilename, outFilename);

    decompress(outFilename);

    printf("%s correctly decoded (in memory). \n", outFilename);
const char* const decompressedfile ="englishtext"; 


countstring(decompressedfile,mystring);

auto millisec1=duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
cout<<"time before function call"<<millisec1<<endl;


  do{
 csafunction(inFilename,mystring);
if(ite-1!=0){
cout<<"enter new string: ";
cin>>mystring;}
ite--;
}while (ite>0);

auto millisec2=duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
cout<<"time after function call"<<millisec2<<endl;;
double  average=0.0;
average=(double)((millisec2-millisec1)/(n));
cout<<"average"<<average;

    return 0;


}

