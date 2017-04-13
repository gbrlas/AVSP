#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int N = 2007;
const int X = 1000000000;

int t[N];
vector<int> prev[N];

int ans[N];
int ka[N];

void test(int _){
	int n;
	scanf("%d", &n);
	for(int i=1; i<n; i++) scanf("%d", t + i);
	for(int i=2; i<=n; i++) prev[i].clear();
	for(int i=1; i<=n; i++) ans[i] = 0;
	for(int i=1; i<=n; i++) ka[i] = 0;

	stack<int> best;
	best.push(n+1);
	bool fail = false;
	for(int i=1; i<n; i++){
		while(best.top() == i) best.pop();
		if(t[i] > best.top()){
			fail = true;
		}
		best.push(t[i]);
		prev[t[i]].push_back(i);
	}	
	for(int i=2; i<=n; i++) reverse(prev[i].begin(), prev[i].end());

	if(fail){
		printf("Case #%d: Impossible\n", _);
		return;
	}

	queue<int> kol;
	kol.push(n);
	int tick = 0;

	ans[n] = X;

	while(!kol.empty()){
		int t = kol.front();
		kol.pop();
		while(!prev[t].empty()){
			int u = prev[t].back();
			prev[t].pop_back();
			if(ans[u]) continue;
			tick = (tick+1) * (t-u);
			ans[u] = ans[t] - tick;
			kol.push(u);
		}
	}

	printf("Case #%d: ", _);
	for(int i=1; i<=n; i++){
		printf("%d%c", ans[i], " \n"[i==n]);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		test(i);
	}
}
