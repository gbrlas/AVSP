#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   int TT=1;
   while(t--)
   {
       double C,F,X,Pre_value,Ans,time_taken=0.00000,Frequency=2.000000,next_value;
       cin>>C>>F>>X;
       bool yad=true;
       Pre_value=(double) (C/2.00000);

       while(yad)
       {
           Pre_value=time_taken+(double) X/Frequency;
           time_taken+= (double) C/Frequency;
           Frequency+=F;
           next_value = time_taken + (double)X/Frequency;
           if(next_value>Pre_value) yad=false;
       }
       printf("Case #%d: %.7f\n",TT,Pre_value);
       TT++;
   }
}
