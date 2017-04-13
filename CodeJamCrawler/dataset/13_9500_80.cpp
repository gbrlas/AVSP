#include <iostream>
#include <cstdio>
#include <cmath>


using namespace std;

bool ispalindrome(int &number)
{
   int copy = number;
   int reversenumber = 0;
   while(copy!=0)
   {
      reversenumber= reversenumber*10 + copy%10;
      copy/=10;      
   }
   return (number==reversenumber);
}


int main()
{
  
   int t=1;
   cin>>t;
   int *input=new int[t*2];
   int *output=new int[t];
   for(int a=0; a < t*2; a++)
   {
      cin>>input[a];
   }
   
  for(int a=0,out=0; a < t*2; a+=2,out++)
  {
    output[out]=0;
           
     for(int b=ceil(sqrt(input[a])); b <=floor(sqrt(input[a+1])); b++)
     {
              
       if(ispalindrome(b))
       {
          int c=b*b;
          
          if(ispalindrome(c))
          {
             output[out]++;
          }
        }
      }               
   }         
        
        
for(int a=1; a <=t; a++)
{
  cout<<"Case #"<<a<<": "<<output[a-1]<<endl;
}  
      
}

