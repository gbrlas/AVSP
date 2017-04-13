#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define dis(x1,y1,x2,y2) sqrt(((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const int oo = 1000000000;
const double E = 2.7182818284590452353602874713527;
const double pi = 3.1415926535897932384626433832795;
using namespace std;

int r[1001],pp[1001];
double x[1001],y[1001];

bool cmp(int a,int b)
{
   return r[a]>r[b];
}

int main()
{
   freopen("b.in","r",stdin);
   freopen("b.out","w",stdout);
   int t;
   cin>>t;
   //srand((unsigned)time(NULL));
   for (int q=1;q<=t;q++)
   {
      int n,a,b;
      cin>>n>>a>>b;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&r[i]);
         pp[i]=i;
      }
      sort(pp+1,pp+n+1);
      for (int i=1;i<=n;i++)
         while (1)
         {
            x[pp[i]]=1.*rand()*rand()/32767/32767*a;
            y[pp[i]]=1.*rand()*rand()/32767/32767*b;
            for (int j=1;j<i;j++)
               if (dis(x[pp[i]],y[pp[i]],x[pp[j]],y[pp[j]])<r[pp[i]]+r[pp[j]]+eps)
                  goto end;
            break;
            end:;
         }
      printf("Case #%d:",q);
      for (int i=1;i<=n;i++)
         printf(" %lf %lf",x[i],y[i]);
      puts("");
   }
   return 0;
}
