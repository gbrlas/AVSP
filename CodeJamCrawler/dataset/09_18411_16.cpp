// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
char entry[40][40];

int cal(int N) {
	int a[40];
	int i, j, k;
	for (i = 0; i < N; i++) {
		a[i] = 0;
		for (j = N-1; j >= 0; j--) {
			if (entry[i][j] == '1') {
				a[i] = j;
				break;
			}
		}
		printf("%d,", a[i]);
	}
	printf("\n");

	int count = 0;
	while(1) {
		bool swap = false;
		for (i = 0; i < N-1; i++) {
			if (a[i]>i) {
				for (j=i+1;j<N;j++){
					if(a[j]<=i)break;
				}
				if (j==N) printf("some error\n");
				int tmp=a[j];
				for(k=j;k>i;k--)a[k]=a[k-1];
				a[i] = tmp;
				count+=j-i;
				swap =true;
				printf("swap %d, %d\n", i, j);
				break;
			}
		}
		if (!swap) return count;
	}
	return 0;
}

int main()
{
	FILE *rp = fopen("in.txt", "r");
	FILE *wp = fopen("out.txt", "w");
	int T, N;
	int i, j, k;
	fscanf(rp, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(rp, "%d", &N);
		printf("N=%d\n", N);
		for (j = 0; j < N; j++) {
			char s[50];
			fscanf(rp, "%s", s);
			for (k = 0; k < N; k++) {
				entry[j][k] = s[k];				
			}
		}
		int ret = cal(N);
		fprintf(wp, "Case #%d: %d\n", i+1, ret);
	}
	fclose(rp);
	fclose(wp);
	return 0;
}
