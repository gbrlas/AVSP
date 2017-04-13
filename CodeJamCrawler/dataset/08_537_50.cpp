#include <stdio.h>
#define st first
#define nd second

#include <algorithm>

using namespace std;

int main (void) {
	int TC=1;
	int N;
	while (scanf("%d",&N)!=EOF) {
		while (N--) {
			int T;
			scanf ("%d",&T);
			int NA,NB;
			scanf ("%d %d",&NA,&NB);
			int a,b,c,d;
			pair<int, pair<int,int> > D[NA+NB];
			for (int i=0;i<(NA+NB);i++) {
				scanf ("%d:%d %d:%d",&a,&b,&c,&d);
				D[i].st=a*60+b;
				D[i].nd.st=c*60+d;
				D[i].nd.nd=(i<NA?0:1);
			}
			sort (D,D+NA+NB);
			int nD=0,nTA=0,nTB=0;
			int F[NA+NB];
			memset (F,0,sizeof(F));
			while (nD<NA+NB) {
				int i=0;
				while (i<(NA+NB)&&F[i]) i++;
				
				if (D[i].nd.nd==0) nTA++;
				else nTB++;
				
				do {
					nD++;
					F[i]=1;
					for (int j=i+1;j<(NA+NB)&&nD<(NA+NB);j++) {
						if (F[j]) continue;
						if (D[i].nd.nd-D[j].nd.nd) {
							if (D[i].nd.st+T<=D[j].st) {
								i=j;
								break;
							}
						}
					}
				} while (nD<(NA+NB)&&i<(NA+NB)&&F[i]==0);
			}
			
			printf ("Case #%d: %d %d\n",TC++,nTA,nTB);
		}
	}
	return 0;
}
