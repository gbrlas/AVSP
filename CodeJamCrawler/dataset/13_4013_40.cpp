#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   int T,a[]={1,4,9,121,484},i,j,count,flag,A,B;
   ifstream fin; 
   ofstream fout;
   fin.open("C.in", ios::in);    
   fout.open("ans.txt", ios::out);
   fin>>T;
   
   for(i=0;i<T;i++)
   {
                   fout<<"\nCase #"<<i+1<<": ";
                   count=0;
                   fin>>A>>B;
                   for(j=0;j<5;j++)
                   if(a[j]>=A && a[j]<=B)
                   count++;
                   fout<<count;
                   }
                                              
                                   
                                              
   
} 
