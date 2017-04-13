#include<stdio.h>
#include<math.h>

int s[10000001];
int a[20];

bool check(long long x)
{
	int i,l;
	l=0;
	while (x>0)
	{
		l++;
		a[l]=x%10;
		x=x/10;
	}
	for (i=1;i<=l;i++)
		if (a[i]!=a[l+1-i]) return false;
	return true;
}

int main()
{
	int t,p;
	int i,j;
	long long a,b;
	s[0]=0;
	for (i=1;i<=10000000;i++)
	{
		if (check(i)&&check(i*(long long)i)) s[i]=s[i-1]+1;
		else s[i]=s[i-1];
	}
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%lld%lld",&a,&b);
		i=(int)sqrt((double)a);
		while (i*(long long)i>=a) i--;
		j=(int)sqrt((double)b);
		while (j*(long long)j>b) j--;
		printf("Case #%d: %d\n",p,s[j]-s[i]);
	}
	return 0;
}

