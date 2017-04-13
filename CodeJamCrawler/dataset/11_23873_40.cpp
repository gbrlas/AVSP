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

int main(){
	int tc;
	cin >> tc;
	FOR(tt,1,tc+1){
		int n,l,h;
		cin >> n >> l >> h;
		vi notes (n);
		FOR(i,0,n)
			scanf("%i",&notes[i]);
		cout << "Case #" << tt << ": ";
		bool work=true;
		FOR(j,l,h+1){
			work=true;
			FOR(i,0,n){
				if(notes[i]%j!=0 && j%notes[i]!=0)
					work=false;
			}
			if(work){
				cout << j << endl;
				break;
			}
		}
		if(!work)
			cout << "NO\n";
	}
	return 0;
}
