#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int nt,nteste=1,n,pd,pg,flag;
	scanf("%d",&nt);
	while (nt--) {
		scanf("%d %d %d",&n,&pd,&pg);

		printf("Case #%d: ",nteste++);

		if (pd != 100 && pg == 100) printf("Broken\n");
		else if (pg == 0) {
			if (pd == 0) printf("Possible\n");
			else printf("Broken\n");
		}

		else {
			flag=0;
			for (int i=1; i<=n; i++) {
				if ((i*pd)%100 == 0)	{ flag=1;	break; }	
			}

			if (flag) printf("Possible\n");
			else printf("Broken\n");

		}

	}

	return 0;
}
