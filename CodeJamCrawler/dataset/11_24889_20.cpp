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

long long int gcd(long long int a,long long int b)
{
     if(b==0)
          return a;
     return gcd(b,a%b);
}
int main()
{
    long long int cases,caseval,n,pg,pd,val,den,games1,games2;
    scanf("%lld",&cases);
    caseval=0;
    while(cases--)
    {
         caseval++;
         scanf("%lld %lld %lld",&n,&pd,&pg);
         
         if( (pd>0 && pg==0) || (pd<100 && pg==100) )
         {
              printf("Case #%lld: Broken\n",caseval);
              continue;
         }
         val=gcd(pd,100);
         den=100/val;
         games1=den;
         
         if(games1<=n)     
              printf("Case #%lld: Possible\n",caseval);
         else printf("Case #%lld: Broken\n",caseval);
    }
    return 0;
}
         
