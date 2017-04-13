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



void runCase(int caseNum)
{
	string s;
	cin >> s;
	char res[1000];
	bool OK = false;
	int b = -1;
	int cc[10];

	memset(cc, 0, sizeof(cc));

	FORN(i, SZ(s) - 1, 1) {
		++cc[s[i] - '0'];
		if(s[i] > s[i-1]){
			b = i-1;
			++cc[s[i-1] - '0'];
			break;
		}
	}

	
	int cnt = 0;
	int cur = 0;
	REP(i, b)
		res[cur++] = s[i];
	if(b >= 0) {
		FOR(i, s[b]-'0' + 1, 9){
			if(cc[i]>0){
				res[cur++] = '0' + i;
				--cc[i];
				break;
			}
		}
		s = "";
		REP(i, 10){
			REP(j, cc[i]){
				s += '0' + i;
			}
		}
	}
	sort(ALL(s));
	if(b == -1) {
		REP(i, SZ(s)) {
			if(s[i] == '0'){
				++cnt;
			}
			else {
				res[cur] = s[i];
				if(!OK) {
					++cnt;
					REP(j, cnt) {
						res[++cur] = '0';
					}
					OK = true;
				}
				++cur;
				res[cur] = 0;
			}
		}
	}
	else{
		REP(i, SZ(s))
			res[cur++] = s[i];
		res[cur] = 0;
	}

	printf("Case #%d: %s\n",caseNum, res);
}

int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int K;
	cin >> K;
	REP(k, K){
		runCase(k+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


