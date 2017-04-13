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
#include <string>

using namespace std;


string jam = "welcome to code jam";
string s = "welcome to codejam";
int mem[32][22];

int doit(int pos, int jampos) {
	if(jampos == jam.size()) return 1;
	if(pos == s.size()) return 0;

	int &ret = mem[pos][jampos];
	if(ret!=-1) return ret;
	ret = 0;

	if(s[pos]==jam[jampos]) {
		ret += doit(pos+1, jampos+1);
	}
	ret += doit(pos+1, jampos);

	return ret;
}


int main(){
	int n;
	getline(cin, s);
	n = atoi(s.c_str());
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		memset(mem, -1, sizeof(mem));
		int ans = doit(0,0);
		stringstream ss;
		ss << ans;
		string ret = ss.str();
		while(ret.size() < 4) ret = '0' + ret;
		cout << "Case #" << (i+1) << ": " << ret << endl;
	}

}

