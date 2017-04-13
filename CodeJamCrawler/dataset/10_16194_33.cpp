#include <stdlib.h>
#include <stdio.h>

typedef struct {
	long number;
	char along;
} guest_t;

//#define SMALL_IN

int main() {
	
	int testcase,caseId, i, j, num_guests;
#ifdef SMALL_IN
	guest_t guests[101];
#else
	guest_t guests[1001];
#endif
	
#ifdef SMALL_IN
	freopen("A-small-practice.in","r",stdin);freopen("A-small-practice.out","w",stdout);
#else
	freopen("A-large-practice.in","r",stdin);freopen("A-large-practice.out","w",stdout);
#endif
	
	scanf("%d",&testcase);
	for (caseId=1;caseId<=testcase;caseId++) {
		printf("Case #%d: ",caseId);
		scanf("%d", &num_guests);
		for(i=0;i<num_guests;i++) {
			scanf("%ld", &(guests[i].number));
			guests[i].along=0;
			for(j=0;j<i;j++) {
				if(guests[i].number==guests[j].number) {
					guests[i].along=1;
					guests[j].along=1;
					break;
				}
			}
		}
		for(j=0;j<i;j++) {
			if(guests[j].along == 0) {
				printf("%ld", guests[j].number);
			}
		}
		printf("\n");
	}
}
