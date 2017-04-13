using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

int main()
{
    long long int cases,caseval,num,minnum,xval,sum,i,x;
    scanf("%lld",&cases);
    caseval=0;
    while(cases--)
    {
         caseval++;
         scanf("%lld",&num);
         minnum=-1;
         xval=0;
         sum=0;
         for(i=1;i<=num;i++)
         {
              scanf("%lld",&x);
              sum += x;
              xval = xval^x;
              if(minnum==-1 || minnum>x)
                   minnum=x;
         }
         
         if(xval!=0)
              printf("Case #%lld: NO\n",caseval);
         else
         {
              sum = sum - minnum;             
              printf("Case #%lld: %lld\n",caseval,sum);
         }
    }
    return 0;
}
