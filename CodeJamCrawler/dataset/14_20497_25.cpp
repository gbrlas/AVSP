#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <stdio.h>
#include <utility>
#include <iomanip>
#include <set>
#include <map>
#include <fstream>
using namespace std;
int main()
{
     ofstream myfile;
      ifstream infile;
      infile.open("input.in");
     myfile.open ("out.out");
     double c,x,f;

     int n;
     infile>>n;
     for(int t=0;t<n;t++)
     {
         infile>>c>>f>>x;
         double  time=0 ,time1=0,time2=0;

         double rate=2.0;

         while(true)
         {
             time1=x/rate;
             time2=c/rate+x/(rate+f);
             if(time2<time1)
             {
               time=time+c/rate;
                rate=rate+f;
             }
             else
             {
                 time=time+x/rate;
                 break;
             }
         }
         myfile<< "Case #" << t+1<< ": "  << std::fixed<< setprecision(7)<<time<< endl;
     }

}

