#include <iostream>
using namespace std;
long long py[1050];
long long hum[1050];

int h[1050];

int main()
{	
	int T,r,k,n,cases=0;
	freopen("D:\\C-large.in","r",stdin);
	freopen("D:\\C-large.out","w",stdout);
	scanf("%d",&T);
	int xx=1;
	while (T--)
	{
		int i,j;
		memset(py,0,sizeof(py));
		memset(hum,0,sizeof(hum));
		scanf("%d%d%d",&r,&k,&n);
		for(i=0;i<n;i++) scanf("%d",&h[i]);
		for (i=0;i<n;i++){
			j=i;int ttc=0;long long sum=0;
			while (1){
				ttc++;
				if (sum+h[j]<=k) sum+=h[j];
				else{
					py[i]=j;
					hum[i]=sum;
					break;}
				j++;
				if (j==n) 
					j=0;
				if (ttc==n) {
					py[i]=j;
					hum[i]=sum;
					break;}
			}
		}
		int pos=0;
		long long ans=0;
		while (r--)
		{
			ans+=hum[pos];
			pos=py[pos];
			if (pos==n) pos=0;
		}
		printf("Case #%d: %lld\n",xx++,ans);
	}
	return 0;
}


