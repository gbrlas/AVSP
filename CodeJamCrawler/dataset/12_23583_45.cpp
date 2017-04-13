#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cfloat>
#include<numeric>
#include<vector>
using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin() , (c).end()
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORD(i,a,b) for(int i=int(b)-1; i>=a; i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define pb push_back
#define mp make_pair

int next (int i, int n){
	return (i+1)%n;
}

bool calc (int a, int b){
	vi ma, mb;
	while(a){
		ma.pb(a%10);
		a/=10;
	}
	while(b){
		mb.pb(b%10);
		b/=10;
	}
	if(sz(ma)!=sz(mb)) return false;
	FOR(i,0,sz(ma)){
		FOR(j,0,sz(ma)){
			bool work=true;
			int posb=j, posa=i;
			FOR(k,0,sz(ma)){
				if(ma[posa]!=mb[posb]){
					work=false;
					break;
				}
				posa=next(posa,sz(ma));
				posb=next(posb,sz(ma));
			}
			if(work)
				return true;		
		}
	}
	return false;
}

int main(){
	int tc;
	cin >> tc;
	FOR(tt,0,tc){
		cout << "Case #" << tt+1 << ": ";
		int a,b;
		cin >> a >> b;
		ll erg=0;
		FOR(i,a,b+1){
			FOR(j,i+1,b+1){
				if(calc(j,i)) erg++;
			}
		}
		cout << erg << endl;
	}
	return 0;
}
