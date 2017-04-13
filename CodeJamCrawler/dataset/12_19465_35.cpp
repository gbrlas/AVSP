#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int S;
int p;
int a;
int main()
{
    //freopen("B-small-attempt1.in","r",stdin);
    //freopen("B-small-attempt1.out","w",stdout);
    int T,Case=0,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&S,&p);
        int ans=0;
        int sp=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&a);
            int x=a/3;
            int r=a%3;
            if(r==0)
            {
                if(x-1>=0&&x+1<=10)
                {
                    if(x+1>p)
                        ans++;
                    else if(x+1==p)
                    {
                        ans++;
                        sp++;
                    }
                }
                else
                {
                    if(x>=p)
                        ans++;
                }
            }
            else if(r==1)
            {
                if(x+1>=p)
                    ans++;
            }
            else
            {
                if(x+2<=10)
                {
                    if(x+2>p)
                        ans++;
                    else if(x+2==p)
                    {
                        ans++;
                        sp++;
                    }
                }
                else
                {
                    if(x+1>=p)
                        ans++;
                }
            }
        }
        if(S<sp)
            ans-=(sp-S);
        printf("Case #%d: %d\n",++Case,ans);
    }
}
