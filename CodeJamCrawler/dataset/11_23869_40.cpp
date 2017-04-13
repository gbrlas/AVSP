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
		int r,c;
		cin >> r >> c;
		vector<string> plate(r);
		getline(cin,plate[0]);
		FOR(i,0,r)
			getline(cin,plate[i]);
		FOR(i,0,r-1){
			FOR(j,0,c-1){
				if(plate[i][j]=='#'){
					if(plate[i][j+1]=='#' && plate[i+1][j]=='#' && plate[i+1][j+1]=='#'){
						plate[i][j]='/'; 
						plate[i][j+1]='\\';
						plate[i+1][j]='\\'; 
						plate[i+1][j+1]='/';
					}	
				}
			}
		}
		bool work=true;
		FOR(i,0,r)
			FOR(j,0,c)
				if(plate[i][j]=='#')
					work=false;
		cout << "Case #" << tt << ":\n";
		if(!work)
			cout << "Impossible\n";
		else
			FOR(i,0,r)
				cout << plate[i] << endl;
	}
	return 0;
}
