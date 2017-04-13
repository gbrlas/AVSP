#include<iostream>
#include<fstream>
using namespace std;
int judge(long long a,long long b)
{
	for(int i=0;i<a;i++)
	{
		if(b%2==1)b/=2;
		else return 0;
	}
	return 1;
}
int main()
{
	int T,ca=1;
	long long n,m;
	freopen("A-small-attempt3.in","r",stdin);
	freopen("A-small-attempt3.txt","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&n,&m);
		if(judge(n,m))
		printf("Case #%d: ON\n",ca);
		else printf("Case #%d: OFF\n",ca);
		ca++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
