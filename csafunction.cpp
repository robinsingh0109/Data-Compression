

#include <sdsl/suffix_arrays.hpp>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using namespace sdsl;

void countstring(const char* filename, string mystring)
{
ifstream myfile (filename);

int flag=0;
int count1=0;
if ( myfile.is_open() ) {
string mychar;
while ( myfile ) {
  mychar+= myfile.get();
}

  for(int i=0;i<((int)mychar.length());i++)
   { string sub;
     for(int j=i;j<(i+((int)mystring.length()));j++){
        sub+=mychar[j];
        }
  if(sub==mystring){
     flag=1;
     count1++;
    }
   }
  
 }
if(flag==1)
	cout<<"count using naive approach:"<<count1<<endl;
else 
	cout<<"Naive approach: pattern not found"<<endl;

myfile.close();	
}

void countstring2(const char* filename, string mystring)
{

ifstream myfile(filename);

if(myfile.is_open()){
string mychar;
while (myfile){
mychar+=myfile.get();
}

cout<<"file loaded to mychar"<<endl;

string s=mystring+'$'+mychar;
cout << "concatenated string initialized"<<endl;

int k=s.length();

   cout<<"k = "<<k<<endl;
    int l,r=0;
    int *z= new int(k);
    for(int i=0;i<k;i++){
       z[i]=0;
    }

    for(int i=1;i<k;i++){
	cout << "i = "<<i<<endl;
        if(i>r){
             int count=0;
            for(int p=0,j=i; p<k,i<k; p++,j++){
                
                if(s[j]==s[p]){
                    count++;
                }
                else{
                    break;
                }
            }
            z[i]=count;
            r=i+z[i]-1;
            l=i;
        }
        else if (i<=r){
                if(z[i-l]<r-i+1){
                    z[i]=z[i-l];
                    
                    
                }
                if(z[i-l]>=r-i+1){
                    int count1=0;
                    for(int m=(r-i+1),n=r+1; m<k,n<k;m++,n++){
                        
                        if(s[n]==s[m]){
                            count1++;
                        }
                        else {
                            break;
                        }
                    }
                    l=i;
                    r=r+count1;
                    z[i]=r-i+1;
                    
                }
            }
            
    }
cout << "Computed Z values"<<endl;
int count3=0;
    for(int i=0; i<k;i++){
        
        if(z[i]==mystring.length()){
            count3++;
         }
    }
cout<<"Number of matches using fundamental preprocessing = "<<count3<<endl;

 delete[] z;


}
}
    







void csafunction(const char* filename, string mystring){

  csa_wt<wt_huff<rrr_vector<63>>,4,8> csa; 
    construct(csa,filename, 1);
    cout << "countofstring : " << count(csa, mystring) << endl;
    
}
