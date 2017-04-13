#include<iostream>
#include<string>
using namespace std;

const int maxl=15+2,maxd=5000+2,maxn=500+2;
int l,d,n;
char s[maxl*30],a[maxd][maxl];
bool f[maxl][26];

int main()
{
    scanf("%d%d%d\n",&l,&d,&n);
    for (int i=1;i<=d;i++) scanf("%s\n",a[i]);
    
    for (int i=1;i<=n;i++)
    {
        scanf("%s\n",s);
        
        memset(f,false,sizeof(f));
        int tot=0,k=0;
        for (int j=0;j<strlen(s);j++)
        {
            if (tot==0) k++;
            if (s[j]=='(') tot++; else
            if (s[j]==')') tot--; else f[k][s[j]-'a']=true;
        }
        
        int ans=0;
        for (int j=1;j<=d;j++)
        {
            bool flag=true;
            for (int k=0;k<l;k++)
            if (!f[k+1][a[j][k]-'a']) 
            {
               flag=false;
               break;
            }
            
            if (flag) ans++;
        }
        
        printf("Case #%d: %d\n",i,ans);
    }
    
}
