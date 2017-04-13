#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LL long long

#include <algorithm>

using namespace std;

int main (void) {
	int T,TC=1;
	scanf ("%d",&T);
	while (T--) {
		int n;
		scanf ("%d",&n);
		int V1[n],V2[n];
		for (int i=0;i<n;i++)
			scanf ("%d",&V1[i]);
		for (int i=0;i<n;i++) {
			scanf ("%d",&V2[i]);
			V2[i]=-V2[i];
		}
		sort (V1,V1+n);
		sort (V2,V2+n);
		LL sum=0;
		for (int i=0;i<n;i++)
			sum+=(V1[i]*(-V2[i]));
		printf ("Case #%d: %lld\n",TC++,sum);
	}
	return 0;
}
