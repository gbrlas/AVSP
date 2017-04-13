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
const int MAXN = 55;
int testcase;
int n, k, b, t;
int x[MAXN];
int v[MAXN];
bool bg[MAXN] = {false};

int deal(){
	scanf("%d%d%d%d", &n, &k, &b, &t);
	for(int i = 0; i < n; ++i)
		scanf("%d", &(x[i]));
	for(int i = 0; i < n; ++i){
		scanf("%d", &(v[i]));
		bg[i] = false;
	}

	int xk = 0;
	for(int i = 0; i < n; ++i){
		if (v[i] * t + x[i] >= b){
			bg[i] = true;
			++xk;
		}
		else
			bg[i] = false;
	}
	if (xk < k)
		return -1;
	int ret = 0;
	xk  = 0;
	for(int i = n -1; i >= 0; --i){
		if (!bg[i])
			continue;
		for(int j = i+1; j < n; ++j){
			if (!bg[j])
				++ret;
		}
		if ((++xk) >= k)
			break;
	}
	return ret;
}


int main(){
	//freopen("b.in","r",stdin);
	scanf("%d", &testcase);
	for (int caseId=1;caseId<=testcase;caseId++)
	{	
		printf("Case #%d: ",caseId);
		int ret = deal();
		if (ret < 0)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ret);
	}
}