#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,m,l,i,j,k,ans;
int a[5005][30],b[40][40];
char str[30];
char ch;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("alarge.out","w",stdout);
    scanf("%d%d%d\n",&l,&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%s", str);
        for(j=1;j<=l;j++)
            a[i][j]=str[j-1]-'a';
    }
    scanf("\n");
    for(k=1;k<=m;k++)
    {
        memset(b,0,sizeof(b));
        for(i=1;i<=l;i++)
        {
            scanf("%c",&ch);
            if(ch!='(')
                b[i][ch-'a']=1;
            else
            {
                scanf("%c",&ch);
                while(ch!=')')
                {
                    b[i][ch-'a']=1;
                    scanf("%c",&ch);
				}
            }
        }
        scanf("\n");
        ans=0;
        for(i=1;i<=n;i++)
        {
            ans++;
            for(j=1;j<=l;j++)
                if(!b[j][a[i][j]])
                {
				    ans--;
				    break;
		        }
        }
        printf("Case #%d: %d\n",k,ans);
    }
    return 0;
}
