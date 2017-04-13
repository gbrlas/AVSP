#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

static const int size=128;
static const int mod=10007;

static int tbl[size][size];
static int cno[size][size];
static int CNO=0;

int dp(int i,int j,int X,int Y)
{
   if (i==X && j==Y)
      return 1;
   if (i>=X || j>=Y)
      return 0;
   if (cno[i][j]==CNO)
      return tbl[i][j];
   cno[i][j]=CNO;
   return tbl[i][j]=(dp(i+2,j+1,X,Y)+dp(i+1,j+2,X,Y))%mod;
}
int main()
{
   int i,j,k,n,X,Y,R;
   int t,T;
   for (cin>>T,t=1;t<=T;++t) {
      ++CNO;

      cin>>X>>Y>>R;
      while (R--) {
         cin>>i>>j;
         cno[i][j]=CNO;
         tbl[i][j]=0;
      }
      printf("Case #%d: %d\n",t,dp(1,1,X,Y));
   }
}
