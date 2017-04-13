#include<iostream>
#include<algorithm>
using namespace std;
__int64 L,t,N,C;
int a[1005];
__int64 ans;
int in[1011010];
int tin[1010101];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("B-small-attempt0.out","w",stdout);
	int T,Case=0;
    int i,j;
	__int64 tot,sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d%I64d",&L,&t,&N,&C);
        for(i=0;i<C;i++)
			scanf("%d",&a[i]);
        for(tot=i=0;i<N;i++)
        {
            in[i]=a[i%C];
            tot+=in[i];
        }
        __int64 sy=t/2;
        int flag=0;
        for(sum=i=0;i<N;i++)
        {
            sum+=in[i];
            if(sum>=sy)
            {
				flag=1;
                tin[i]=sum-sy;
                for(j=i+1;j<N;j++)
                    tin[j]=in[j];
                sort(tin+i,tin+N,cmp);
				__int64 tsum=0;
                if(N-i>L)
                {
					for(j=0;j<L;j++)
						tsum+=tin[i+j];
                    ans=(tot-tsum)*2+tsum;
                }
                else
                {
                    for(j=i;j<N;j++)
						tsum+=tin[j];
                    ans=(tot-tsum)*2+tsum;
                }
                break;
            }
        }
        if(!flag)
			ans=tot*2;
        printf("Case #%d: %I64d\n",++Case,ans);
    }
	return 0;
}
