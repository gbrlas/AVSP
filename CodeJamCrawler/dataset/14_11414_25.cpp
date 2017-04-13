#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
//#define LARGE 1

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small.i", "rt", stdin);
	freopen("b_small.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		double c,f,x;
		cin>>c>>f>>x;
		double best = x/2.0;
		double cur = 0.0, temp;
		for(double r=2;;r+=f) {
			cur += c/r;
			temp = cur + x/(r+f);
			if(temp > best)
				break;
			best = temp;
		}
		cout.precision(7);
		cout.setf(ios::fixed);
		cout << "Case #" << tt << ": " << best << endl;
	}

	return 0;
}
