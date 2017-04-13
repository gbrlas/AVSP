#include<iostream>
#include<stdio.h>
#include<math.h>
#define N 105
#define inf 999999999
using namespace std;

double p[N];
int main()
{
	int t,a,b,i,cas=1;
	double ans,ans1,ans2,ans3,tmp,t1,t2;
	freopen("re.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		tmp=1;
		for(i=0;i<a;i++)
		{
			scanf("%lf",&p[i]);
			tmp*=p[i];
		}
		ans1=tmp*(b-a+1)+(1.0-tmp)*(2*b-a+2);
		ans2=b+2;
		ans3=0;
		ans=inf;
		t1=tmp;
		for(i=1;i<a;i++)
		{
			t1=tmp/p[(a-i)]*(1-p[(a-i)]);
			t2=t1+tmp;
			ans3=(b-a+2*i+1)+(1-t2)*(b+1);
			if(ans>ans3)
			ans=ans3;
		}
		ans3=a+b+1;
		if(ans>ans3)
		ans=ans3;
		if(ans1>ans)
		ans1=ans;
		if(ans1>ans2)
		ans1=ans2;
		printf("Case #%d: %lf\n",cas++,ans1);
	}
	return 0;
}
		
