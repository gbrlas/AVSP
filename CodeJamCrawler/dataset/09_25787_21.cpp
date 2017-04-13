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

int N, ans;
int row[50];

void dfs(int k, int depth)
{
   if(k == N)  return ;  
      
   if(row[k] <= depth)  dfs(k+1, depth+1);
   
   else
   {
      int i = k, j;
      while(row[++i] > depth) ;
      ans += i - k;
      
      for(j=i; j>k; j--)  row[j] = row[j-1];
      dfs(k+1, depth + 1); 
   }
}

int main()
{
   freopen("A-large.in", "r", stdin);
   freopen("As.out", "w", stdout);
   
   int T;
   cin >> T;
   int cas = 0;
   
   while(T --)
   {
      int i, j, k;
      char ch;
      
      cin >> N;
      getchar();
      MST(row, 0);
      
      FOR(i, 0, N)
      {
         FOR(j, 0, N)
         {
            ch = getchar();
            if(ch == '1')  row[i] = j;    
         }  
         getchar();  
      }    
      
        
      ans = 0;
      dfs(0, 0);
      
      printf("Case #%d: %d\n", ++cas, ans);
   } 
     
                 
    
    return 0;
}

