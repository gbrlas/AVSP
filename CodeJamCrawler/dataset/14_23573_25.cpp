#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <iomanip>

#define min(x,y) (((x) < (y)) ? (x) : (y))
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define abs(x) (((x) > 0) ? (x) : -(x))
#define INF 1e9

using namespace std;

double best(double C, double F, double X){
	double maxTime = X / 2;	//the best is <= maxTime, the time needed when we don't buy any farms
	int k = 0;
	double elapsed = 0;
	double best = maxTime;
	
	if(X <= C){
		return X / 2;
	}
	
	int N = 1e6;
	
	while(N > 0){
		//we suppose we've bought a farm in each of t = C/2, ..., C/(2 + (k - 1)F)
		elapsed += C / (2 + k * F);
		
		//don't buy any farm
		double dontBuy = elapsed + (X - C) / (2 + k * F);
		best = min(dontBuy, best);

		N--;
		k++; 
	}
	
	return best;
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		double C, F, X;
		cin >> C >> F >> X;
		cout << setprecision(10);
		cout << "Case #" << (i + 1) << ": " << best(C, F, X) << endl;
	}

	return 0;
}
