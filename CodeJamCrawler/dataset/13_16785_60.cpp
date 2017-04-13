#include <cstdio>
using namespace std;
int T,N,M,i,j,k,ok,ok1,ok2,ok3,ok4,parcela,x,y,okS1,okS2;
int A[101][101];
int main()
{
    freopen("inputB.in","r",stdin);
    freopen("outputB.out","w",stdout);
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&N,&M);
        for(j=1;j<=N;j++)
        {
            for(k=1;k<=M;k++)
            scanf("%d",&A[j][k]);
        }
        ok=1;
        for(j=1;j<=N && ok;j++)
        {
            for(k=1;k<=M && ok;k++)
            {
                parcela=A[j][k];
                //RIGHT
                x=j;y=k;ok1=1;
                if(y!=M)
                {
                    while(y<M && ok1)
                    {
                        ++y;
                        if(A[x][y]>parcela)
                        ok1=0;
                    }
                }
                //DOWN
                x=j;y=k;ok2=1;
                if(x!=N)
                {
                    while(x<N && ok2)
                    {
                        ++x;
                        if(A[x][y]>parcela)
                        ok2=0;
                    }
                }
                //LEFT
                x=j;y=k;ok3=1;
                if(y!=1)
                {
                    while(y>1 && ok3)
                    {
                        --y;
                        if(A[x][y]>parcela)
                        ok3=0;
                    }
                }
                //UP
                x=j;y=k;ok4=1;
                if(x!=1)
                {
                    while(x>1 && ok4)
                    {
                        --x;
                        if(A[x][y]>parcela)
                        ok4=0;
                    }
                }
                okS1=(ok1==1 && ok3==1);
                okS2=(ok2==1 && ok4==1);
                if(okS1==0 && okS2==0)
                ok=0;
            }
        }
        if(ok)
        printf("Case #%d: YES\n",i);
        else
        printf("Case #%d: NO\n",i);
    }
}
