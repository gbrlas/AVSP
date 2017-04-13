#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef stringstream SS;

#define pb(x) push_back(x)
#define ins(x) insert(x)
#define sz size()
#define len length()

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a),_d=((a)<(b))?1:-1; _d*i<=_d*(b); i+=_d)
#define FOREACH(it,s) for (typeof((s).begin()) it = (s).begin(); it != (s).end(); ++it)
#define SORT(x) (sort((x).begin(),(x).end()))
#define UNIQ(x) ((x).erase(unique((x).begin(),(x).end()),(x).end()))

#define INF 2147450751

int tc;
map<char, int> simbol;
vector<int> numero;
int main(){
	cin >> tc;
	
	string code;
	for(int cs=1; cs<=tc; cs++){
		simbol.clear();
		numero.clear();
		int k =0;

		cin >> code;
		REP(i, code.sz){
			if(simbol.find(code[i]) == simbol.end()){
				if(k == 0){
					simbol[code[i]] = 1;
				} else if(k == 1){
					simbol[code[i]] = 0;
				} else {
					simbol[code[i]] = k;
				}
				k++;
			}	
			numero.pb(simbol[code[i]]);			
		}
			
		k = (k < 2) ? 2 : k;

		int pot = 1;
		int total = 0;
		for(int i=(int)numero.sz-1; i>=0; i--){
			total += numero[i] * pot;
			pot *= k;
		}

		cout << "Case #" << cs << ": " << total << endl;
	}
	
	return(0);
}


