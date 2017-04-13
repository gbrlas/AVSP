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
    int cases,arr[2000],i,ans[2000],count,n,caseval=0;
    float c;
    scanf("%d",&cases);
    while(cases--)
    {
         caseval++;
         scanf("%d",&n);
         for(i=0;i<n;i++)
         {
              scanf("%d",&arr[i]);
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
         printf("Case #%d: %0.6f\n",caseval,c);
    }
    return 0;
}
