
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf

int length(int a){
	int len = 0;
	while(a){
		a /= 10;
		len++;
	}
	return len;
}

int pow(int p){
	int r = 1;
	while(p){
		r *= 10;
		p--;
	}
	return r;
}

void docase() {
	int A, B;
	char strA[10];
	char strB[10];
	int count = 0;
	scanf("%d %d", &A, &B);
	for(int i=A; i<B; i++){
		int l = length(A);
		for(int j=1; j<l; j++){
			int nv = i%pow(j)*pow(l-j)+i/pow(j);
			if(nv <= B && nv > i) count++;			
		}
	}
	printg("%d\n", count);
}


int main(int argc, char* argv[]){
	int number_of_test_cases, i;
	scanf("%d\n", &number_of_test_cases);
	REP(i,number_of_test_cases)
		docase();
	return 0;
}