#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>

using namespace std;
typedef long long LL;

int a[1010], b[1010], next[1010];

inline int go(int i)
{
    if (i<0) return 0;
    return b[i];
}
int main()
{
    FILE *fi=fopen("theme park.in","r");//, *fo=fopen("theme park.out","w");
    ofstream fo("theme park.out");
    int test;
    fscanf(fi,"%d",&test);
    int c=0;
    while (test>0)
    {
          c++;
          fo<<"Case #"<<c<<": ";
//          fprintf(fo,"Case #%d: ",c);
          test--;
          int r, k, n;
          fscanf(fi,"%d %d %d",&r,&k,&n);
          for (int i=0;i<n;i++)
              fscanf(fi,"%d",&a[i]);
          b[0]=a[0];
          for (int i=1;i<n;i++)
              b[i]=a[i]+b[i-1];
          for (int i=0;i<n;i++)
          {
              int e=go(n-1)-go(i-1);
              if (e>=k)
              {
                                     int j=i;
                                     for (j=i;j<n;j++)
                                         if (go(j)-go(i-1)>k) break;
                                     if (j==i) j++;
                                     next[i]=j-1;
              }
              else
              {
                  int j=0;
                  for (j=0;j<i;j++)
                      if (e+go(j)>k) break;
                  if (j==0) j=n;
                  next[i]=j-1;
              }
          }
          long long ret=0;
          int cur=0;
          if (n==1)
          {
                   ret=(long long)a[0]*r;
                   goto end;
          }
          for (int i=0;i<r;i++)
          {
              int e=go(next[cur])-go(cur-1);
              if (next[cur]<cur) e+=go(n-1);
              if (next[cur]<cur) ret+=(long long) go(n-1)+go(next[cur])-go(cur-1);
              else ret+=(long long) go(next[cur])-go(cur-1);
              cur=next[cur]+1;
              if (cur>=n || cur<0) cur=0;
          }
          end:;
          fo<<ret<<endl;
//          fprintf(fo,"%lld\n",ret);
    }
}
