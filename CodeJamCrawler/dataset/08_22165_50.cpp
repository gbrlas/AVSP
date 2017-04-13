#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll mmod(ll x) {
	while (x < 0 ) x += 3LL * (ll)1e9;
	return x%3;

}

ll mmod(ll X, ll M) {
	while(X  <  0) X += 1LL * M * (ll)1e8;
	return X % M;
}

int main() {
	int tcase;
	scanf("%d", &tcase);
	ll how[3][3];
	for(int zz=0; zz<tcase; zz++) {
		int n;
		ll A, B, C, D, x0, y0, M;
		memset(how, 0, sizeof(how));
		scanf("%d%Ld%Ld%Ld%Ld%Ld%Ld%Ld", &n, &A, &B, &C, &D, &x0, &y0, &M);
		ll X, Y;
		X = x0;
		Y = y0;
		how[mmod(X)][mmod(Y)]++;
		for(int i=1; i<n; i++) {
			X = mmod(A*X + B, M) ;
			Y = mmod(C*Y + D, M) ;
			how[mmod(X)][mmod(Y)] ++;
		}
		ll sum = 0;
		for(int x1=0; x1<3; x1++)
			for(int y1=0;y1 < 3; y1++) {
				for(int x2 =0; x2<3; x2++) {
					for(int y2=0; y2<3; y2++) {
						for(int x3=0;x3<3; x3++) if(mmod(x1+x2+x3)==0) 
							for(int y3=0;y3<3;y3++) if(mmod(y1+y2+y3)==0) {
								ll v = 0;
								int ilep = 0;
								v = how[x1][y1];
								how[x1][y1]--;
								if(how[x2][y2]<=0) {
									how[x1][y1]++;
									continue;
								}
								v *= how[x2][y2];
								how[x2][y2]--;
								if(how[x3][y3] <= 0) {
									how[x1][y1]++;
									how[x2][y2]++;
									continue;
								}
								v *= how[x3][y3];
								how[x3][y3]--;
								/*if(x1==x2 && y1==y2) ilep++;
								if(x1==x3 && y1==y3) ilep++;
								if(x2==x3 && y2==y3) ilep++;
								if(ilep == 1) v /= 2;
								if(ilep > 1) v/=6;*/
								how[x1][y1]++;
								how[x2][y2]++;
								how[x3][y3]++;
								sum += v;


							}
					}
				}
			}
		printf("Case #%d: %Ld\n", zz+1, sum/6);
	}
}
