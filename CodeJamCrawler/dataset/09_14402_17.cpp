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

using namespace std; 
typedef long long int64;
typedef double real;


char im[16][16];

int di[4] = {0, -1, 0, 1};
int dj[4] = {-1, 0, 1, 0};

map<vector<pair<int, int> >, int > state;

#define maxn (1 << 20)
vector<pair<int, int> > q[maxn];
int st, fi;
char oO[16][16];
bool was[16][16];
int n, m;
inline bool onbrd(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int i, int j){
	if (!onbrd(i, j)) return;
	if (was[i][j]) return;
	if (!oO[i][j]) return;
	was[i][j] = 1;
	for (int d = 0; d < 4; d++)
		dfs(i + di[d], j + dj[d]);
}

bool isStable(vector<pair<int, int> > gy){
	memset(oO, 0, sizeof(oO));
	memset(was, 0, sizeof(was));
	for (int i = 0; i < (int)gy.size(); i++)
		oO[gy[i].first][gy[i].second] = 1;
	bool flag = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			if (oO[i][j] && !was[i][j]){
				if (flag) return false;
				flag = 1;
				dfs(i, j);
			}
	return true;
}

bool moved(const vector<pair<int, int> > &a, vector<pair<int, int> > & b, int i, int d){
	b = a;
	int x = b[i].first;
	int y = b[i].second;
	if (!onbrd(x + di[d], y + dj[d])) return false;
	if (!onbrd(x - di[d], y - dj[d])) return false;
	if (im[x + di[d]][y + dj[d]] == '#') return false;
	if (im[x - di[d]][y - dj[d]] == '#') return false;

	for (int j = 0; j < (int)b.size(); j++) 
		if (i != j && x + di[d] == b[j].first && y + dj[d] == b[j].second) return false;
	for (int j = 0; j < (int)b.size(); j++) 
		if (i != j && x - di[d] == b[j].first && y - dj[d] == b[j].second) return false;
	b[i] = make_pair(x + di[d], y + dj[d]);
	sort(b.begin(), b.end());
	return true;
}

int main(){
	int ferlon;
	scanf("%d", &ferlon);
	for (int _ = 0; _ < ferlon; ++_){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++){
			scanf("%s", im[i]);
		}
		state.clear();
		vector<pair<int, int> > curr;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (im[i][j] == 'o'){
					curr.push_back(make_pair(i, j));
					im[i][j] = '.';
				}else if (im[i][j] == 'w'){
					curr.push_back(make_pair(i, j));
					im[i][j] = 'x';
				}
		vector<pair<int, int> > goal;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (im[i][j] == 'x'){
					goal.push_back(make_pair(i, j));
				}
		assert(curr.size() == goal.size());
		state[curr] = 0;
		st = fi = 0;
		q[fi++] = curr;
		int res = -1;
		bool ok = 0;
		if (curr == goal){
			res = 0;
			ok = 1;
		}
		for (st = 0; st < fi && !ok; st++){
			vector<pair<int, int> > gy = q[st];
			int dst = state[gy];
			bool st1 = isStable(gy);
			for (int i = 0; i < (int)gy.size() && !ok; i++)
				for (int d = 0; d < 4 && !ok; d++){
					vector<pair<int, int> > tmp;
					if (moved(gy, tmp, i, d)){
						if (st1 || isStable(tmp)){
							if (state.find(tmp) == state.end()){
								if (tmp == goal){
									res = dst + 1;
									ok = 1;
									break;
								}
								state[tmp] = dst + 1;
								q[fi++] = tmp;
								assert(fi < maxn);
							}
						}
					}
				}
		}
		printf("Case #%d: %d\n", _ + 1, res);
	}
	return 0;
}
