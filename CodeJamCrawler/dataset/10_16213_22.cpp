#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SMALL_IN
#define D_DEBUG

int main() {
	
	int testcase,caseId, i, j;
	
#ifdef SMALL_IN
	freopen("B-small.in","r",stdin);freopen("B-small.out","w",stdout);
#else
	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
#endif
	
	scanf("%d",&testcase);
	for (caseId=1;caseId<=testcase;caseId++) {
		printf("Case #%d: ",caseId);
		scanf("%d%d%lld%d", &N,&K,&B,&T);
	
		printf("\n");
		fflush(stdout);
	}
}
