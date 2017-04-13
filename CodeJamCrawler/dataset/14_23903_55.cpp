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
#define iter set<double>::iterator

using namespace std;

double ken[1002];
double naomi[1002];
set<double> kset;
set<double> nset;

int main(){
	int t, n;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			scanf("%lf", &naomi[j]);
			nset.insert(naomi[j]);
		}
		for(int j = 0; j < n; j++){
			scanf("%lf", &ken[j]);
			kset.insert(ken[j]);
		}
		
		sort(ken, ken + n);
		sort(naomi, naomi + n);
		
		int warScore = n;
		for(int j = n - 1; j >= 0; j--){
			iter it = kset.upper_bound(naomi[j]);
			if(it == kset.end())
				it = kset.begin();
			else warScore--;
			kset.erase(it);
		}
		
		int decScore = 0;
		for(int j = n - 1; j >= 0; j--){
			iter it = nset.upper_bound(ken[j]);
			if(it == nset.end())
				it = nset.begin();
			else decScore++;
			nset.erase(it);
		}
		
		printf("Case #%d: %d %d\n", i, decScore, warScore);
		nset.clear(), kset.clear();
	}
	return 0;
}