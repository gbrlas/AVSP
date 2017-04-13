#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.txt","w",stdout);
	int T,flag,ca,su;
	long long L,P,C,mu;
	scanf("%d",&T);
	for(ca=1;ca<=T;++ca)
	{
		flag=0;
		su=0;
		cin>>L>>P>>C;
		mu=P/L;
		while(P)
		{
			if(mu>C||P>L*C)++su;
			else break;
			C*=C;
		}
		printf("Case #%d: ",ca);
		cout<<su<<endl;
	}
		fclose(stdin);
	fclose(stdout);
	return 0;
}
