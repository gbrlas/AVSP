#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
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
#include <climits>
using namespace std;

#define FOR(i,a,b) for (int i=(a),_n=(b); i <= _n; i++) 
#define FORIT(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())

#define D(X) {cerr << "DUMP: "<< #X << " = '" << (X) << "'" << endl;}

int main()
{
	int numInputs;
	cin >> numInputs;
	D(numInputs)
	FOR(cs,1,numInputs)
	{
		D(cs);
		long long N,M,A;
		
		cin >> N >> M >> A;
		D(N);
		D(M);
		for(long long x1=0;x1<=1;x1++)
		for(long long y1=0;y1<=1;y1++)
		for(long long x2=0;x2<=N;x2++)
		for(long long y2=0;y2<=M;y2++)
		for(long long x3=0;x3<=N;x3++)
		{
			if(x2-x1 != 0)
			{
				long long t = A - (x1*y2 - x2*y1-x3*y2 + x3*y1);
				if(t % (x2-x1) != 0)
					continue;
				long long y3 = t / (x2-x1);
				if(y3 <= M && y3 >= 0)
				{
					cout << "Case #" << cs << ": " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
					goto outt;
				}
			}
		}
		
		cout << "Case #" << cs << ": IMPOSSIBLE" << endl;
		
		outt:
			long long a;
			a = 5;
	}
	return 0;
}
