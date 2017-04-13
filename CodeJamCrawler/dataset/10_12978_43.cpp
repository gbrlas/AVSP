#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int  printout(long snapper,long input);
int main()
{
   ifstream ifile("Number.in");
   
   ofstream ofile("ofile.in",ios::app);
   int temp;
   ifile>>temp;
  
   long  temp2;
   long temp3;
   long x;
   for(int k=1;k<=temp;k++)
   {
             ifile>>temp2;
             ifile>>temp3;
             x=printout(temp2,temp3);
             if(x==0)
             ofile<<"Case #"<<k<<": ON"<<endl;
             else
             ofile<<"Case #"<<k<<": OFF"<<endl;
                          
              
   }
 //   system("pause");
    return 0;
}


int  printout(long snapper,long input)
{     
       
    long temp1;
    temp1=pow(2,snapper);
    input=input+1;
    
    if(fmod(input,temp1)!=0)
    return 1;
    else
    return 0;
 
}
