#include <cstdio>

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	const int dbsize=5;
	int t,a,b,i,j,k,fs[dbsize]={1,4,9,121,484};
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d%d",&a,&b);
		for(i=0;fs[i]<a;i++);
		for(j=i;j<dbsize && fs[j]<=b;j++);
		printf("Case #%d: %d\n",k+1,j-i);
	}
	return 0;
}