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

class Node {
public:
	double prob;
	string feature;
	int L, R;
	int P;

};

vector<Node> nodes;

double getProb(set<string>& fs, double p, int cur) {
	p *= nodes[cur].prob;
	if(SZ(nodes[cur].feature)>0) {
		if(fs.count(nodes[cur].feature)){
			return getProb(fs, p, nodes[cur].L);
		}
		else
			return getProb(fs, p, nodes[cur].R);
	}
	return p;
}


int proc(int p, string str) {
	Node n;
	istringstream is(str);
	is >> n.prob;
	is >> n.feature;
	n.P = p;
	n.L = -1;
	n.R = -1;
	nodes.push_back(n);

	int cur = SZ(nodes) - 1;

	int b = -1;
	int e = 0;
	int cnt = -1;
	bool l = true;
	REP(i, SZ(str)) {
		if(str[i] == '('){
			if(cnt == -1){
				cnt = 1;
				b = i+1;
			}
			else
				++cnt;
		}
		else if(str[i] == ')')
			--cnt;

		if (cnt == 0){
			if(l){
				nodes[cur].L = proc(cur, str.substr(b, i - b));
				cnt = -1;
				l = false;
			}
			else {
				nodes[cur].R = proc(cur, str.substr(b, i - b));
				break;
			}
		}
	}
	return cur;
}

void runCase(int caseNum)
{
	nodes.clear();
	int L;
	cin >> L;

	string s;
	string strTree;
	getline(cin, s);

	REP(i, L) {
		getline(cin, s);
		strTree += s + " ";
	}

	int p1 = strTree.find('(') + 1;
	int p2 = strTree.rfind(')');

	proc(-1, strTree.substr(p1, p2-p1));

	printf("Case #%d:\n",caseNum);

	int A;

	cin >> A;
	getline(cin, s);

	REP(ttt, A) {
		getline(cin, s);
		istringstream is(s);
		string t;
		is >> t;
		int num;
		is >> num;
		set<string> fs;
		REP(i, num) {
			is >> t;
			fs.insert(t);
		}
		printf("%.7f\n", getProb(fs, 1.0, 0)); 
	}

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


