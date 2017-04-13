#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
int  printout(int snapper,int input);
int main()
{
   ifstream ifile("Number.in");
   ofstream ofile("ofile.in",ios::app);
   double temp;
   ifile>>temp;
  
   int temp2;
   int temp3;
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
       return 0;
}


int  printout(int snapper,int input)
{     
       
    double temp1;
    temp1=pow(2,snapper);
    input=input+1;
    
    if(fmod((double)input,temp1)!=0)
    return 1;
    else
    return 0;
 
}
