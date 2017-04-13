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
	FOR(t,0,tc){
		int C;
		cin >> C;
		vector<vector<char> > combine (26,vector<char>(26,' '));
		vector<vector<bool> > opp (26,vector<bool>(26,false));
		while(C--){
			string in;
			cin >> in;
			combine[in[0]-'A'][in[1]-'A']=in[2];
			combine[in[1]-'A'][in[0]-'A']=in[2];
		}
		cin >> C;
		while(C--){
			string in;
			cin >> in;
			opp[in[0]-'A'][in[1]-'A']=true;
			opp[in[1]-'A'][in[0]-'A']=true;
		}
		int N; string to, erg="";
		map<char,int> ex;
		cin >> N >> to;
		FOR(i,0,N){
//			cout << to[i] << " " << erg;
			bool cl=false;
			if(sz(erg)>0 &&combine[to[i]-'A'][erg[sz(erg)-1]-'A']!=' '){
				ex[erg[sz(erg)-1]]--;
				FORIT(it,ex){
					if(it->second==0)
						continue;
					if(opp[(it->first) -'A'][combine[to[i]-'A'][erg[sz(erg)-1]-'A']-'A']==1){
//						cout << it->first << " " << combine[to[i]-'A'][erg[sz(erg)-1]-'A'] << " " << opp[it->first -'A'][combine[to[i]-'A'][erg[sz(erg)-1]-'A']-'A'] << endl;
						cl=true;
					}
				}
				erg[sz(erg)-1]=combine[to[i]-'A'][erg[sz(erg)-1]-'A'];
				ex[erg[sz(erg)-1]]++;
				
			}
			else{
				erg+=to[i];
				FORIT(it,ex){
					if(it->second==0)
						continue;
					if(opp[to[i]-'A'][it->first -'A'])
						cl=true;
				}
				ex[to[i]]++;
			}
//			cout << " " << cl;
			if(cl){
				ex.clear();
				erg="";
			}
//			cout << " " << erg << endl;
		}
		cout << "Case #" << t+1 << ": [";
		FOR(i,0,sz(erg)-1){
			cout << erg[i] << ", ";
		}
		if(sz(erg)>0)
			cout << erg[sz(erg)-1];
		cout << "]\n";
	}
	return 0;
}
