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

int gcd(int a,int b)
{
     if(b==0)
          return a;
     return gcd(b,a%b);
}
int main()
{
    int cases,caseval,n,pg,pd,val,den,games1,games2;
    scanf("%d",&cases);
    caseval=0;
    while(cases--)
    {
         caseval++;
         scanf("%d %d %d",&n,&pd,&pg);
         
         if( (pd>0 && pg==0) || (pd<100 && pg==100) )
         {
              printf("Case #%d: Broken\n",caseval);
              continue;
         }
         val=gcd(pd,100);
         den=100/val;
         games1=den;
         
         if(games1<=n)     
              printf("Case #%d: Possible\n",caseval);
         else printf("Case #%d: Broken\n",caseval);
    }
    return 0;
}
         
