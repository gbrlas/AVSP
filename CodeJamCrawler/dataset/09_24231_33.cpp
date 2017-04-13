#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
    freopen( "C-small-attempt0.in","r",stdin);
    freopen( "C-small-attempt0.out","w",stdout);
    char s[]="-welcome to code jam";    
    char st[1000];
    int ans[30],go[150][10]={0};
    int l,i,n,len,Cas=0;
    for( i=1 ; i<=19; i++ )
     if( go[s[i]-' '+1][1] ) 
      if( go[s[i]-' '+1][2] )
          go[s[i]-' '+1][3]=i;
          else go[s[i]-' '+1][2]=i;
      else go[s[i]-' '+1][1]=i;
    scanf("%d",&n);
    gets(st);
    while( n-- )
    {
       gets(st);
       memset( ans , 0 , sizeof( ans ) );
       ans[0]=1;
       len=strlen(st);
       for( i=0 ; i<len ; i++ )
       {
          l=1;
          while( go[st[i]-' '+1][l] )
          {
             ans[go[st[i]-' '+1][l]]=(ans[go[st[i]-' '+1][l]]+ans[go[st[i]-' '+1][l]-1])%10000;
             l++;
          }
       }
       printf("Case #%d: %04d\n",++Cas,ans[19]);
    }
    return(0);
}
