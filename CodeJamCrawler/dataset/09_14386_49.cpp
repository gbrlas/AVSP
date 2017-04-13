#include <cstdio>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


#define Eo(x) { std::cerr << #x << " = " << x << std::endl; }
#define maxn (1 << 7)

typedef long long int64;
typedef double real;

using namespace std;

vector<int> pr[maxn];

vector<int> g[maxn];
int res[maxn];
bool was[maxn];


bool cmp(int a, int b){
	for (int i = 0; i < pr[a].size(); i++)
		if (pr[a][i] >= pr[b][i]) return false;
	return true;
}


bool dfs(int curr){
	if (was[curr]) return false;
	was[curr] = 1;
	for (int i = 0; i < g[curr].size(); i++)
		if (res[g[curr][i]] == -1 || dfs(res[g[curr][i]])){
			res[g[curr][i]] = curr;
			return true;
		}
	return false;
}
int main(){
	int ferlon;
	scanf("%d", &ferlon);
	for (int _ = 0; _ < ferlon; ++_){
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++){
			pr[i].clear();
			for (int j = 0; j < k; j++){
				int tmp;
				scanf("%d", &tmp);
				pr[i].push_back(tmp);
			}
		}
		for (int i = 0; i < n; i++)
			g[i].clear();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (cmp(i, j))
					g[i].push_back(j);
		memset(res, -1, sizeof(res));
		int ans = n;
		for (int i = 0; i < n; i++){
			memset(was, 0, sizeof(was));
			if (dfs(i))
				--ans;
		}
		printf("Case #%d: %d\n", 1 + _, ans);
	}
	return 0;
}
