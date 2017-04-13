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

int main(){
	int tc;
	cin >> tc;
	FOR(tt,0,tc){
		cout << "Case #" << tt+1 << ": ";
		int N, S, p;
		cin >> N >> S >> p;
		int erg =0;
		FOR(i,0,N){
			int t;
			cin >> t;
			bool sup=false, mat=false;
			FOR(k,p,11){
				int tact=t-k;
				if(tact<0) continue;
				int a,b;
				if(tact%2==1){
					a=(tact-1)/2+1;
					b=(tact-1)/2;
				} else {
					a=b=tact/2;
				}
				if(abs(k-b)>2 || abs(k-a)>2) continue;
				if(a<11 && b<11){
					if(abs(k-a)<=1 && abs(b-k)<=1){
						mat=true;
						break;
					}
					if(abs(k-a)==2 || abs(k-b)==2){
						sup=true;
					}
				}
			}
			if(mat) erg++;
			if(!mat && sup && S){
				S--;
				erg++;
			}
		}
		cout << erg << endl;
	}
	return 0;
}
