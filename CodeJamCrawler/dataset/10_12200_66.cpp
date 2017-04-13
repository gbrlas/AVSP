#include<iostream>
using namespace std;
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("Aout.txt","wt",stdout);
	long long tc,n,k;
	cin>>tc;
	for(int t=1; t<=tc;t++)
	{
		//scanf("%d %d",&n,&k);
		cin>>n>>k;
		printf("Case #%d: ",t);
		if( ( k & (1ll<<n)-1 ) == (1ll<<n)-1)
			printf("ON\n");
		else printf("OFF\n");
	}
}