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
#define MAX_TRY 10000000

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	double c, f, x;
	for(int i = 1; i <= t; i++){
		double time = 0, p = 2;
		scanf("%lf%lf%lf", &c, &f, &x);
		double best = x / 2.0;
		
		for(int j = 0; j < MAX_TRY; j++){
			time += c / p, p += f;
			best = min(time + x / p, best);
		}
		printf("Case #%d: %.7lf\n", i, best);
	}
	return 0;
}