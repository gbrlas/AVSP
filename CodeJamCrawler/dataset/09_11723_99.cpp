#include <vector> 
#include <map> 
#include <set> 
#include <queue> 
#include <list>
#include <stack> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <fstream>


using namespace std;
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORN(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define REP(i,n) FOR(i, 0, (n)-1)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define INF 1000000000
typedef long long LL;
typedef long double LD;
typedef vector<vector<int> > VII;
typedef vector<int> VI;
typedef pair<int, int> PII;

vector<set<string> > dict;
int L, D, N;
int res ;

void go(string s, vector<vector<char> > &pat) {
	if(SZ(s) == L) {
		res++;
		return;
	}
	REP(i, SZ(pat[SZ(s)])) {
		string n = s + pat[SZ(s)][i];
		if(dict[SZ(s)].count(n))
			go(n, pat);
	}
}

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> L >> D >> N;
	dict = vector<set<string> >(L, set<string>());
	REP(i, D) {
		string w;
		cin >> w;
		REP(j, SZ(w)){
			dict[j].insert(w.substr(0, j + 1));
		}
	}
	REP(k, N){
		res = 0;
		string w;
		cin >> w;
		vector<vector<char> > pat(L, vector<char>() );
		bool inw = false;
		int p = 0;
		REP(i, SZ(w)) {
			if(w[i] == '(') {
				inw = true;
			}
			else if(w[i] == ')') {
				inw = false;
				p++;
			}
			else {
				if(inw){
					pat[p].push_back(w[i]);
				}
				else {
					pat[p].push_back(w[i]);
					p++;
				}
			}
		}
		string s;
		go(s, pat);
		printf("Case #%d: %d\n",k+1, res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


//void runCase(int caseNum)
//{
//
//	printf("Case #%d: %d\n",caseNum, res);
//}

//int main(int argc, char* argv[])
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	int K;
//	cin >> K;
//	REP(k, K){
//		runCase(k+1);
//	}
//	fclose(stdin);
//	fclose(stdout);
//	return 0;
//}


