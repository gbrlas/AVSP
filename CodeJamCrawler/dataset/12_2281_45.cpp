
#include "stdio.h"
#include "string.h"

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number)

int check[100][2];

void docase() {
	int N, S, p;
	int i,j,k;
	int count = 0;
	scanf("%d %d %d", &N, &S, &p);
	REP(i, N) {
		int t;
		scanf("%d", &t);
		int mid = t/3;
		int res = t%3;
		switch (res){
			case 0:
				if(mid >= p) count++;
				else if(S>0 && mid+1 >= p && mid-1 >= 0) {
					count++;
					S--;
				}
				break;
			case 1:
				if(mid+1 >= p) count++;
				break;
			case 2:
				if(mid+1 >= p) count++;
				else if(S>0 && mid+2 >= p){
					count++;
					S--;
				}
				break;
		}
	}
	printg;
	printf("%d\n", count);
}


int main(int argc, char* argv[]){
	int number_of_test_cases, i;
	scanf("%d\n", &number_of_test_cases);
	REP(i,number_of_test_cases)
		docase();
	return 0;
}