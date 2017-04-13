#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
 
double sol() {
	double C, F, X, f = 2, tfarm = 0;
	scanf("%lf%lf%lf", &C, &F, &X);
	int farm = 1;
	double out = tfarm + X / f, newans;
	while(true) {
		tfarm += C / f;
		f += F;
		newans = tfarm + X / f;
		if(newans < out) {
			out = newans;
		} else {
			break;
		}
	}
	return out;
}
 
int main() {

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		printf("Case #%d: %.7lf\n", t, sol());
	}
	return 0;
}

