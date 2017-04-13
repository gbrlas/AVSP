#include <stdio.h>
#include <conio.h>

int isIn(int case1[], int case2[]) {
	int sameMember = 0;
	for(int i=0; i<sizeof(case1); i++) {
		for(int j=0; j<sizeof(case2); j++) {
			if(case1[i]==case2[j]) {
				sameMember++;
			}
		}
	}
	return sameMember;
}

int whichSameMember(int case1[], int case2[]) {
	int sameMember = 0;
	for(int i=0; i<sizeof(case1); i++) {
		for(int j=0; j<sizeof(case2); j++) {
			if(case1[i]==case2[j]) {
				return case1[i];
			}
		}
	}
	return sameMember;
}

void main() {
	//
	int roundinput = 0;
	scanf("%d", &roundinput);
	for(int ii=0; ii<roundinput ; ii++) {
		int selectRow1 = 0;
		int selectRow2 = 0;
		
		int case1[4][4];
		int case2[4][4];

		scanf("%d", &selectRow1);
		for(int i=0; i<4; i++) {
			scanf("%d %d %d %d", &case1[i][0], &case1[i][1], &case1[i][2], &case1[i][3] );
		}
		//printf("\n");

		scanf("%d", &selectRow2);
		for(int i=0; i<4; i++) {
			scanf("%d %d %d %d", &case2[i][0], &case2[i][1], &case2[i][2], &case2[i][3]);
		}
		//printf("\n");
		//for(int i=0; i<4; i++) {
		//	for(int j=0; j<4; j++) {
		//		printf("%d ",case2[i][j]);
		//	}
		//}

		if(isIn(case1[selectRow1-1], case2[selectRow2-1])==1) {
			printf("case #%d: %d\n", ii+1, whichSameMember(case1[selectRow1-1], case2[selectRow2-1]));
		}
		if(isIn(case1[selectRow1-1], case2[selectRow2-1])>1) {
			printf("case #%d: Bad magician!\n",ii+1);
		}
		if(isIn(case1[selectRow1-1], case2[selectRow2-1])==0) {
			printf("case #%d: Volunteer cheated!\n",ii+1);
		}
		//printf("case #%d: \n", ii+1);
	}
	//printf("Hello, world\n");

}