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
		cout << "Case #" << tt << ": ";
		int L,N,C; ll t;
		cin >> L >> t >> N >> C;
		int anzr=N/C;
		vector<pii > a (C);
		FOR(i,0,C){
			int tmp;
			cin >> tmp;
			a[i]=make_pair(-tmp*2,anzr);
		}
		FOR(i,0,N%C)
			a[i].second++;
		
//		FOR(i,0,C)
//			cout << a[i].first << " " << a[i].second << endl;
		
		int erg=0, cnt=0;	
		while(true){
			if(a[cnt].second==0)
				break;
			erg-=a[cnt].first;
			if(erg>t){
				a.push_back(make_pair(t-erg,1));
				erg=t;
			}
			a[cnt].second--;
			cnt++;
			cnt%=C;
			if(erg==t)
				break;
		}
		
		sort(all(a));
//		cout << erg << endl;
		FOR(i,0,sz(a)){
//			cout << -a[i].first << " " << a[i].second << endl;
			if(L>a[i].second){
				erg-=a[i].first/2*a[i].second;
				L-=a[i].second;
			}
			else{
				erg-=L*a[i].first/2;
				erg-=(a[i].second-L)*a[i].first;
				L=0;
			}
		}
		cout << erg << endl;
	}
	return 0;
}
