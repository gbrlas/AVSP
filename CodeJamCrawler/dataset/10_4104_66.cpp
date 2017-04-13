#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	int opt=0;
	int n,k;
	while(test--)
	{
		opt++;
		scanf("%d%d",&n,&k);
		int nn=pow(2.00,n);
		if(k>nn)
		k=k%nn;
		nn--;
		if(nn==k)
		printf("Case #%d: ON\n",opt);
		else
		printf("Case #%d: OFF\n",opt);
	}
	return 0;
}
