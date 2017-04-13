#include <iostream>
using namespace std;

int main(){
	freopen("D:\\C-small-attempt0.in","r",stdin);
	freopen("D:\\C-small-attempt0.out","w",stdout);
	int i,T;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		int r,k,n;
		int j;
		int b[11];
		for(j=0;j<11;j++) b[j]=0;
		scanf("%d%d%d",&r,&k,&n);
		for(j=0;j<n;j++) scanf("%d",&b[j]);
		int ans=0;
		for(j=1;j<=r;j++)
		{
			int sum=0,q=0,t=0,p=0;
			for(t=0;t<=n;t++)
			{
				if(sum>k) break;
				sum+=b[t];
			}
			ans+=sum-b[--t];
			int tm[11];
			for(p=t;p<n;p++)
				tm[q++]=b[p];
			for(p=0;p<t;p++)
				tm[q++]=b[p];
			tm[q]=0;
			for(p=0;p<11;p++)
				if(tm[p]!=0) b[p]=tm[p];
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}