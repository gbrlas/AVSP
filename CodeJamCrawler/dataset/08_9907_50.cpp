#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

using namespace std;

typedef long double ld;
typedef long long ll;
double EPS = 1e-9;
int INF = 1000000000;

#define BE(v) (v).begin(),(v).end()
#define PB push_back

vector<string> names_;
vector<string> query_;

int mem[1001][101];

int doit(int pos, int cur) {
	if(pos == query_.size()) return 0;
	
	int &ret = mem[pos][cur];
	if(ret!= -1) return ret;
	
	ret = INF;
	for(int i = 0; i < names_.size(); i++){
		if(names_[i] == query_[pos]) continue;
		int t = doit(pos+1, i);
		if(names_[i] != names_[cur]) t++;
		ret = min(ret, t);
	}
	
	return ret;
}


int getopt(vector<string> &names, vector<string> &query) {
	names_ = names;
	query_ = query;
	memset(mem, -1, sizeof(mem));
	
	int ret = INF; 
	for(int i = 0; i < names.size(); i++) ret = min(ret, doit(0, i));
	
	return ret;
}


int main() {
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	for(int cnt = 0; cnt < N; cnt++){
		int temp;
		getline(cin, s);
		temp = atoi(s.c_str());
		vector<string> names;
		for(int i = 0; i < temp; i++){
			getline(cin, s);
			names.push_back(s);
		}
		getline(cin, s);
		temp = atoi(s.c_str());
		vector<string> query;
		for(int i = 0; i < temp; i++){
			getline(cin, s);
			query.push_back(s);	
		}
		
		cout << "Case #" << (cnt+1)<<": " << getopt(names, query) << endl;
	}

}





