#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXN 10010

int main() {
	int flag,nteste=1;
	int nt,n;
	long long int L,H,i,vet[MAXN];
	scanf("%d",&nt);
	while (nt--) {
		scanf("%d %Ld %Ld",&n,&L,&H);
		for (i=0; i<n; i++) scanf("%Ld",&vet[i]);

		for (i=L; i<=H; i++) {
			flag=1;
			for (int j=0; j<n; j++) {
				if ((i>vet[j] && i%vet[j]) || (i<vet[j] && vet[j]%i)) { flag=0; 	break; }
			}

			if (flag) break;			

		}		

		printf("Case #%d:",nteste++);	
		if (flag) printf(" %Ld\n",i);
		else printf(" NO\n");

	}

	return 0;
	
}
