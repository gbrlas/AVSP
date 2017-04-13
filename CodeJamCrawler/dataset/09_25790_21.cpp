#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <memory>
#include <cmath>
#include <numeric>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define MST(G, x) memset(G,x,sizeof(G))
#define FOR(i, a, b) for(i=a; i<b; i++)
#define _FOR(i, a, b)  for(i=a; i>=b; i--)
#define Max 100010

using namespace std;

int N;
struct point
{
   double x, y, r;    
}p[10];


int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("Ds.out", "w", stdout);
    
    int T;
    cin >> T;
    int cas = 0;
    
    while(T --)
    {
       int i, j, k;
       
       cin >> N;   
       
       FOR(i, 0, N)
         cin >> p[i].x >> p[i].y >> p[i].r; 
         
       printf("Case #%d: ", ++ cas);
       
       if(N == 1)  printf("%.10f\n", p[0].r);
       
       if(N == 2)  printf("%.10f\n", max(p[0].r, p[1].r));
       
       if(N == 3)  
       {
          double ans = 1000000000.0;
          FOR(i, 0, 3)
            FOR(j, i+1, 3)
            {
               k = 3 - i - j;
               
               double dis = (p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y);
               dis = sqrt(dis) + p[i].r + p[j].r; 
               dis = max(dis / 2.0, p[k].r);
               ans = min(dis, ans);   
            }  
            
          printf("%.10f\n", ans);
       } 
    }
     
                 
    
    return 0;
}

