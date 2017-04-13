#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include<sstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include<queue>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  a.begin(),a.end()
#define ESP (1e-9)
#define N 450
#define inf 1000000007
#define sz(a) int(a.size())
#define pii pair<int,int>
#define vi vector<int>
char s[4][4];
int main()
{
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int i,j,k,n,m,T,ca=0;
  scanf("%d",&T);
  while(T--)
  {
   for(i=0;i<4;i++)
   scanf("%s",s[i]);
   printf("Case #%d: ",++ca);
   bool f3=0;
   for(i=0;i<4;i++)for(j=0;j<4;j++)
   if(s[i][j]=='.')f3=1;
   bool f1=0,f2=0;
   for(i=0;i<4;i++)
   {
    int p=0,q=0,t=0;
    for(j=0;j<4;j++)
    if(s[i][j]=='X')p++;
    else if(s[i][j]=='O')q++;
    else if(s[i][j]=='T')t++;
    if(p+t==4){f1=1;}
    if(q+t==4){f2=1;}
   }
   for(j=0;j<4;j++)
   {
    int p=0,q=0,t=0;
    for(i=0;i<4;i++)
    if(s[i][j]=='X')p++;
    else if(s[i][j]=='O')q++;
    else if(s[i][j]=='T')t++;
    if(p+t==4){f1=1;}
    if(q+t==4){f2=1;}
   }
   int p=0,q=0,t=0;
   for(i=0,j=0;i<4&&j<4;i++,j++)
   if(s[i][j]=='X')p++;
   else if(s[i][j]=='O')q++;
   else if(s[i][j]=='T')t++;
   if(p+t==4){f1=1;}
    if(q+t==4){f2=1;}
    p=0,q=0,t=0;
    for(i=0,j=3;i<4&&j>=0;i++,j--)
    if(s[i][j]=='X')p++;
    else if(s[i][j]=='O')q++;
    else if(s[i][j]=='T')t++;
    if(p+t==4){f1=1;}
    if(q+t==4){f2=1;}
      if(f1==1&&f2==0)puts("X won");
      else if(f1==0&&f2==1)puts("O won");
      else if(!f1&&!f2&&!f3)puts("Draw");
      else puts("Game has not completed");
  }
  return 0;
}
