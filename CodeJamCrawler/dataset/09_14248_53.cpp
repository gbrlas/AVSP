#include<iostream>
#include<cmath>
using namespace std;
string s="welcome to code jam";
char s1[500];
int H,ans;
int H1=s.size();
void dfs(int k,int t)
{
     int i;
     if(k==H1)
     {
          ans++;
          ans%=1000;
          return ;
     }
     for(i=t;i<H && i+H1-k<=H;i++)
     if(s[k]==s1[i]) dfs(k+1,i+1);
}
int main()
{
    //freopen("c.in","r",stdin);
 // freopen("c.out","w",stdout);
    int n,i,j,h;
    scanf("%d",&n);
    getchar(); 
    for(i=1;i<=n;i++)
    {           
          gets(s1);
          H=strlen(s1);
          ans=0;
          dfs(0,0);
          if(ans==0) h=1;
          else h=(int)log10(ans)+1;
          printf("Case #%d: ",i);
          for(j=1;j<=4-h;j++) printf("0");
          printf("%d\n",ans);          
    }
    return 0;
}
