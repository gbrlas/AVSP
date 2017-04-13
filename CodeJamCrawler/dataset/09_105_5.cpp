#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int N;
int plant[1005][3];
double d[1005][1005];

double compute(){
	int mi = 0, mj = 0;
	double md = 1000000.0;
	for(int i = 0; i < N; ++i){
		for(int j = i+1; j < N; ++j){
			int dx = (plant[i][0] - plant[j][0]);
			int dy = (plant[i][1] - plant[j][1]);
			double dt = sqrt(1.0*(dx * dx + dy * dy)) + plant[i][2] + plant[j][2];
			if (md > dt){
				md = dt;
				mi = i;
				mj = j;
			}
		}
	}
	if (1==N)
		return 1.0 * plant[0][2];
	if (2==N)
		return (plant[0][2] > plant[1][2] ? plant[0][2] : plant[1][2]) * 1.0;
	if (3==N){
		int ii = 3 - mi - mj;
		md = md/2;
		if(md > plant[ii][2])
			return md;
		return plant[ii][2] *1.0;
	}
	return 1.0;
}

int main()
{
	int C, prob = 1;
	for(cin >>C; C--;){
		cin >> N;
		for(int i = 0; i < N; ++i)
			cin >> plant[i][0] >> plant[i][1] >> plant[i][2];
		printf("Case #%d: %.6f\n", prob++, compute());

	}
	return 0;
}