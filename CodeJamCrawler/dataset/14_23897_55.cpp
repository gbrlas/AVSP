#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define _MOD 1000000007
#define lld long long int

using namespace std;

int A[5][5];
int B[5][5];

int main(){
	int t, a, b;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%d", &a);
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				scanf("%d", &A[j][k]);
		scanf("%d", &b);
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				scanf("%d", &B[j][k]);
				
		int answer = 0;
		int possible = 0;
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				if(A[a - 1][j] == B[b - 1][k])
					answer = A[a - 1][j], possible++;
					
		printf("Case #%d: ", i);
		if(possible == 0)
			printf("Volunteer cheated!\n");
		else if(possible > 1)
			printf("Bad magician!\n");
		else printf("%d\n", answer);
	}
	return 0;
}