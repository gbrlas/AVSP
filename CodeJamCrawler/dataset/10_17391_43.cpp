#include <iostream>
using namespace std;
int n,k;
int main(){
	freopen("in.txt","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int tc;
	scanf("%d",&tc);
	for (int ii=1;ii<=tc;ii++){
		printf("Case #%d: ",ii);
		scanf("%d%d",&n,&k);
		int i;
		for (i=0;i<n;i++)
			if (k%2==1) k=k>>1;
			else break;
		if (i==n) printf("ON\n");
		else printf("OFF\n");
	}
	return 0;
}