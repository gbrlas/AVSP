#include<iostream>
#define s(n)scanf("%d\n",&n)
using namespace std;

int dp[505][505];
int t;
string s1;
int len1,len2;
char s2[505];
int cs;

int solve(int pos1,int pos2)
{
    if( pos1 == len1 )return 1;
    if( pos2 == len2 )return 0;
    
    int &d=dp[pos1][pos2];
    if(d!=-1)return d;
    d=0;
    
    if(s1[pos1] == s2[pos2])  
    d+=solve(pos1+1,pos2+1);
    
    d+=solve(pos1,pos2+1);
    
    return d%=10000;
}
main()
{
      freopen("C-small-attempt0.in","r",stdin);
      freopen("C-small-attempt0.out","w",stdout);      
      s(t);
      s1 = "welcome to code jam";
      len1=s1.length();      
      while(t-- > 0 )
      {
         memset(dp,-1,sizeof dp);

         gets(s2);
         len2=strlen(s2);
         int ans=solve(0,0);
         printf("Case #%d: ",++cs);
         printf("%04d\n",ans);
      }

}
