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
    long long int cases,arr[2000],i,ans[2000],count,n,caseval=0;
    float c;
    scanf("%lld",&cases);
    while(cases--)
    {
         caseval++;
         scanf("%lld",&n);
         for(i=0;i<n;i++)
         {
              scanf("%lld",&arr[i]);
              ans[i]=arr[i];
         }
         sort(ans,ans+n);
         count=0;
         for(i=0;i<n;i++)
         {
              if(arr[i]!=ans[i])
                   count++;
         }
         c=count;
         printf("Case #%lld: %0.6f\n",caseval,c);
    }
    return 0;
}
