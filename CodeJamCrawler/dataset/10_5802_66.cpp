#include <iostream>
using namespace std;

int main(){
	freopen("D:\\A-small-attempt2.in","r",stdin);
	freopen("D:\\A-small-attempt2.out","w",stdout);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int mo=1<<n;
		if(k%mo==mo-1) printf("Case #%d: ON\n",i);
		else printf("Case #%d: OFF\n",i);
	}
	return 0;
}