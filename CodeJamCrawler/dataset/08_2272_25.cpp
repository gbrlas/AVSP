#include <iostream>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("ooo.txt","w",stdout);
    int cas,ca=1,i,j,k,t,l,a,n,m,tag,temp;
    cin>>cas;
    while(cas--)
    {
        cin>>n>>m>>a;
        tag=0;
        for(i=0;i<=n;i++)
        {
            for(j=i;j>=0;j--)
            {
                for(k=i;k<=n;k++)
                {
                    for(t=0;t<=m;t++)
                    {
                        for(l=0;l<=m;l++)
                        {
                            temp=(k-j)*(t+l)-(i-j)*t-(k-i)*l;
                            if(temp==a)
                            {
                                printf("Case #%d:",ca++);
                                printf(" %d %d %d %d %d %d\n",j,t,i,0,k,l);
                                tag=1;
                                break;
                            }
                        }
                        if(tag)break;
                    }
                    if(tag)break;
                }
                if(tag)break;
            }
            if(tag)break;
        }
        if(!tag)
        {
            printf("Case #%d:",ca++);
            printf(" IMPOSSIBLE\n");
        }
    }
    return 0;
}
        
