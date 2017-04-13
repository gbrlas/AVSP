#include<iostream>
#include<cstring>
using namespace std;

int test;
int a[300];
char s[62];
bool v[300];
long long ans,t;

int main()
{
    freopen("a.in","r",stdin);   
    freopen("a.out","w",stdout); 
    
    scanf("%d\n",&test);
    
    for (int i=1;i<=test;i++)
    {
        scanf("%s",s);
        
        ans=0;
        memset(v,false,sizeof(v));
        v[s[0]]=true;
        a[s[0]]=1;
        
        int now=-1;
        for (int j=1;j<strlen(s);j++)
        if (!v[s[j]])
        {
           ++now;
           if (now==1) ++now;
           v[s[j]]=true;
           a[s[j]]=now;
        }
        
        if (now<1) now=1;
        
        t=1;
        for (int j=strlen(s)-1;j>=0;j--)
        {
            ans+=a[s[j]]*t;
            t=t*(now+1);
        }
        
        printf("Case #%d: %I64d\n",i,ans);
    }
}
