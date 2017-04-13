#include <stdio.h>
#include <string.h>
#define min(a,b) (a<b?a:b)

int ns;
char s[100][101];
int nq;
int q[1000];
int M[100][1000];

int isNS (char qtemp[]) {
	for (int i=0;i<ns;i++)
		if (strcmp(qtemp,s[i])==0) return i;
	return -1;
}

int main (void) {
	int TC=1;
	int N;
	while (scanf("%d",&N)!=EOF) {
		while (N--) {
			scanf ("%d\n",&ns);
			for (int i=0;i<ns;i++) {
				gets (s[i]);
			}
			scanf ("%d\n",&nq);
			char qtemp[101];
			for (int i=0;i<nq;i++) {
				gets (qtemp);
				q[i]=isNS(qtemp);
			}
			for (int i=0;i<ns;i++) {
				M[i][0]=(i==q[0]?10000:0);
			}
			
			for (int i=1;i<nq;i++) {
				for (int j=0;j<ns;j++) {
					M[j][i]=10000;
					if (j!=q[i]) {
						for (int k=0;k<ns;k++) {
							M[j][i]=min(M[j][i],M[k][i-1]+(j==k?0:1));
						}
					}
				}
			}
			
			int min=10000;
			for (int i=0;i<ns;i++)
				if (M[i][nq-1]<min)
					min=M[i][nq-1];
			printf ("Case #%d: %d\n",TC++,min);	
		}
	}
	return 0;
}
