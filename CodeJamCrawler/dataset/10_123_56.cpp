#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_INT = 0Xffffff;
int testcase, n, m;

int deal(){
	set<string> sp;
	string s, sub;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i){
		cin >> s;
		sp.insert(s);
	}
	int ret = 0;
	for(int i = 0; i < m; ++i){
		cin >> s;
		int before;
		for(int j = 1; j < s.length(); ++j){
			if (s[j] == '/'){
				sub = s.substr(0, j);
				if (sp.find(sub) == sp.end()){
					sp.insert(sub);
					++ret;
				}
			}
		}
		if (sp.find(s) == sp.end()){
			sp.insert(s);
			++ret;
		}

	}
	return ret;
}

int main(){
	//freopen("a.in","r",stdin);
	scanf("%d", &testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{
		printf("Case #%d: %d\n",caseId, deal());
	}
}