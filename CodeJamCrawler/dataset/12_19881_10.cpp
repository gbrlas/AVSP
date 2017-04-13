#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int T;
int A, B;
double probCorr[100000];
double prob[100001];

double findMin(){
	int j = 0;
	double minimum = (double) B + 2.0, probC;
	for(int i = 0; i <= A; ++i){
		probC = 0.0;
		for(j = 0; j < (int) pow((float)2,i) && j <= A ; ++j) probC += prob[j];
		minimum = min(minimum, (1.0-probC)*(double)((2*i)+((2*B)-A+2)) + probC*(double)(B-A+1+(2*i)));
	}
	return minimum;
}

int main() {
	int i, j;
	double result;
	cin >> T;
	for(int t=1; t<=T; ++t) {
		cin >> A >> B;
		for(i = 0; i < A; ++i){ 
			cin >> probCorr[i]; 
			prob[i] = probCorr[0];
		}
		prob[A] = 1.0 - probCorr[0];

		for(i = 0; i <= A; ++i){
			for(j = 1; j < A - i; ++j) prob[i] *= probCorr[j];
			while(j < A) prob[i] *= 1.0 - probCorr[j++];
		}
		result = findMin();
		printf("Case #%d: %.6f\n",t,result);
	}
	return 0;
}
