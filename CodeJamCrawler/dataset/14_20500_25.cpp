#include<iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
        freopen("input.in","r",stdin);
        freopen("out.out","w",stdout);
         double C,X,F;

         int T;
         cin>>T;
     for(int i=0;i<T;i++)
     {
         cin>>C>>F>>X;
         double  t=0 ,t1=0,t2=0;

         double R=2.0;

         while(true)
         {
             t1=X/R;
             t2=C/R+X/(R+F);
             if(t2<t1)
             {
               t+=C/R;
               R=R+F;
             }
             else
             {
                 t+=X/R;
                 break;
             }
         }
         cout<< "Case #" << i+1<< ": "  << std::fixed<< setprecision(7)<<t<< endl;
     }

}

