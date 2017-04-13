#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <utility>
#include <cctype>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

//#define X first
#define INF 1000000000
//#define Y second
#define For(A,B) for(int A=0;A<B.size();++A)
#define ll long long
#define ld long double
#define PB push_back
#define sz size()
#define eps 0.0000001 
#define V second
#define P first
#define ull unsigned long long

#define speed first
#define path second


int main() {
	freopen("A-large__.in", "r", stdin);
	//freopen("in.txt", "r", stdin);
	freopen("A-large__.out", "w", stdout);
	int T,t; cin >> T;
	for (t=1; t<= T; t++) {
		int n; 
		double s,r,x,tt;
		cin >> x >> s >> r >> tt >> n;
		vector< pair<int,int> >  v(n);
		int noway = x;
		for (int i=0; i<n; i++){
			int X, Y;
			cin >>X >> Y >> v[i].speed ;
			v[i].path = Y - X;
			noway -= Y-X;
		}
		v.PB(make_pair(0, noway));
		n = v.size(); 
		sort(v.begin(), v.end());
		
		double restime = 0; 
		for (int i=0; i<n; i++) {
			if (tt > 0){
				double needt = ((double)(v[i].path))/(double)(r + v[i].speed);
				if (needt > tt){
					double rast = tt*(double)(r+v[i].speed);
					restime += tt + ((double)(v[i].path - rast)) / (double)(s + v[i].speed);
					tt = 0;
				} else {
					restime += needt;
					tt -= needt;
				}
            } else {
                restime += ((double)v[i].path) / (double)(v[i].speed + s);
			}
		}
		printf("Case #%d: %lf\n", t, restime);
	}
	return 0;
}