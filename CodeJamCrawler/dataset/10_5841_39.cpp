#include <iostream>
using namespace std;

int sum=0;

int cx(int i,int j)
{
	int tmp;
	if(i==j || !i || !j) return 0;
	if(i<j) {tmp=i;i=j;j=tmp;}
	if(j*2<=i) return 1;
	sum++;
	return cx(i%j,j);
}

int main(){
	freopen("D:\\C-small-attempt0.in","r",stdin);
	freopen("D:\\C-small-attempt0.out","w",stdout);
	int t,T;
	scanf("%d",&t);
	for(T=1;T<=t;T++)
	{
	int i,j,ans=0;
	int a1,a2,b1,b2;
	scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
	for(i=a1;i<=a2;i++)
		for(j=b1;j<=b2;j++)
		{	sum=0;
			if(cx(i,j) && sum%2==0) ans++;
		}
	printf("Case #%d: %d\n",T,ans);
	}
	return 0;
}