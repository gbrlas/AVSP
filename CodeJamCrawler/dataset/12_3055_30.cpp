#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cassert>

using namespace std;

int s,m;
pair<int,int> moves[1<<15];

int dx[6] = {-1,-1,0,0,1,1};
int dy[6] = {-1,0,-1,1,0,1};

bool out(int x, int y){ //true if outside
	if (x <= 0 || y <= 0 || x >= 2* s || y >= 2* s) return true;
	if (x <= s && y >= x+s) return true;
	if (x >= s && y <= x-s) return true;
	return false;
}

bool is_side(int x, int y){
	return (x==1 || y==1 || x-y==s-1 || x==2*s-1 || y==2*s-1 || y-x==s-1);
}

int side(int x, int y){ //-1 if no side
	if (x == 1){
		if (y > 1 && y < s) return 1;
		return -1;
	}
	if (y == 1){
		if (x < s) return 2;
		return -1;
	}
	if (x-y == s-1){
		if (y == s) return -1;
		return 3;
	}
	if (x == 2*s-1){
		if (y < 2*s-1) return 4;
		return -1;
	}
	if (y == 2*s-1){
		if (x > s) return 5;
		return -1;
	}
	if (y-x == s-1)
		return 6;
	return -1;
}

int par[40000000];
int rank[40000000];
bool on_side[40000000][8];
bool occ[40000000];

int init(){
	memset(par,0,sizeof(par));
	memset(rank,0,sizeof(rank));
	memset(on_side,false,sizeof(on_side));
	memset(occ,false,sizeof(occ));
}

int make_set(int x){
	par[x] = x;
	rank[x] = 0;
}

int find(int x){
	if (par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

bool merge(int x, int y){ // return false if already same component
	x = find(x);
	y = find(y);
	if (x == y) return false;
	
	if (rank[x] < rank[y]){
		par[x] = y;
		for (int i = 0; i <= 6; i++)
			on_side[y][i] |= on_side[x][i];
		return true;
	}
	else if (rank[x] > rank[y])
		par[y] = x;
	else {
		par[y] = x;
		rank[x]++;
	}
	for (int i = 0; i <= 6; i++)
		on_side[x][i] |= on_side[y][i];
	return true;
}

int check_ring(){ //return time of earliest ring
	init();
	make_set(0);
	for (int x = 1; x < 2*s; x++)
		for (int y = 1; y < 2*s; y++)
			if (!out(x,y)){
				make_set(2*s*x+y);
			}
	memset(occ,false,sizeof(occ));
	for (int i = 0; i < m; i++){
		occ[moves[i].first*2*s+moves[i].second] = true;
	}
	for (int x = 1; x < 2*s; x++)
		for (int y = 1; y < 2*s; y++)
			if (!out(x,y) && !occ[2*s*x+y]){
				if (is_side(x,y)){
					merge(0,2*s*x+y);
				}
				for (int k = 0; k < 6; k++){
					int nx = x + dx[k]; int ny = y + dy[k];
					if (!out(nx,ny) && !occ[2*s*nx+ny])
						merge(2*s*x+y,2*s*nx+ny);
				}
			}
	int earl = m;
	for (int i = m-1; i >= 0; i--){
		int x = moves[i].first, y = moves[i].second;
		occ[2*s*x+y] = false;
		int cnt = 0;
		if (is_side(x,y)){
			if (merge(0,2*s*x+y))
				cnt++;
		}
		for (int k = 0; k < 6; k++){
			int nx = x + dx[k]; int ny = y + dy[k];
			if (!out(nx,ny) && !occ[2*s*nx+ny]){
				if (merge(2*s*x+y,2*s*nx+ny))
					cnt++;
			}
		}
		//cout << "i = " << i << ", cnt = " << cnt << endl;
		if (cnt > 1 && find(2*s*x+y) == find(0)) earl = i;
	}
	return earl;
}

int check_corner(int lim){
	lim = m-1;
	init();
	for (int x = 1; x < 2*s; x++)
		for (int y = 1; y < 2*s; y++)
			if (!out(x,y)){
				make_set(2*s*x+y);
			}
	int cnt[6];
	//set<int> cnt;
	for (int i = 0; i <= lim; i++){
		int x = moves[i].first, y = moves[i].second;
		occ[2*s*x+y] = true;
		for (int k = 0; k < 6; k++){
			int nx = x + dx[k]; int ny = y + dy[k];
			if (!out(nx,ny) && occ[2*s*nx+ny]){
				merge(2*s*x+y,2*s*nx+ny);
			}
		}
		cnt[0] = find(1*2*s+1);
		cnt[1] = find(s*2*s+1);
		cnt[2] = find((2*s-1)*2*s+s);
		cnt[3] = find((2*s-1)*2*s+(2*s-1));
		cnt[4] = find(s*2*s+(2*s-1));
		cnt[5] = find(1*2*s+s);
		sort(cnt,cnt+6);
		for (int k = 0; k < 5; k++)
			if (cnt[k] == cnt[k+1])
				return i;
		/*cnt.clear();
		cnt.insert(find(1*2*s+1));
		cnt.insert(find(s*2*s+1));
		cnt.insert(find((2*s-1)*2*s+s));
		cnt.insert(find((2*s-1)*2*s+(2*s-1)));
		cnt.insert(find(s*2*s+(2*s-1)));
		cnt.insert(find(1*2*s+s));
		if (cnt.size() < 6) return i;*/
	}
	return m;
}

int check_side(int lim){
	lim = m-1;
	init();
	for (int x = 1; x < 2*s; x++)
		for (int y = 1; y < 2*s; y++)
			if (!out(x,y)){
				int ss = side(x,y);
				if (ss == -1){
					make_set(2*s*x+y);
					continue;
				}
				make_set(2*s*x+y);
				on_side[2*s*x+y][ss] = true;
			}
	for (int i = 0; i <= lim; i++){
		int x = moves[i].first, y = moves[i].second;
		occ[2*s*x+y] = true;
		for (int k = 0; k < 6; k++){
			int nx = x + dx[k]; int ny = y + dy[k];
			if (!out(nx,ny) && occ[2*s*nx+ny]){
				merge(2*s*x+y,2*s*nx+ny);
			}
		}
		int cmp = find(2*s*x+y);
		int cnt = 0;
		for (int k = 0; k <= 6; k++){
			if (on_side[cmp][k])
				cnt++;
		}
		/*cout << "checking sides: i = " << i << endl;
		for (int k = 0; k <= 6; k++)
			if (on_side[cmp][k])
				cout << " " << k;
		cout << endl;*/
		if (cnt >= 3) return i;
	}
	return m;
}

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> s >> m;
		//cout << "s = " << s << ", m = " << m << endl;
		//cout << "corners = " << (1*2*s+1) << ", " << (s*2*s+1) << ", " << ((2*s-1)*2*s+s) << ", " << ((2*s-1)*2*s+(2*s-1)) << ", " << (s*2*s+(2*s-1)) << ", " << (1*2*s+s) << endl;
		
		for (int i = 0; i < m; i++){
			int x,y; cin >> x >> y;
			moves[i] = make_pair(x,y);
		}
		int rr = check_ring();
		int cc = check_corner(rr);
		int ss = check_side(min(rr,cc));
		
		//cout << "cc = " << cc << ", ss = " << ss << ", rr = " << rr << endl;
		cc++; ss++; rr++;
		
		cout << "Case #" << zz << ": ";
		if (cc >= m+1 && ss >= m+1 && rr >= m+1)
			cout << "none" << endl;
		else if (cc == ss && ss == rr){
			cout << "bridge-fork-ring in move " << cc << endl;
		}
		else if (cc == ss && cc < rr){
			cout << "bridge-fork in move " << cc << endl;
		}
		else if (cc == rr && cc < ss){
			cout << "bridge-ring in move " << cc << endl;
		}
		else if (ss == rr && ss < cc){
			cout << "fork-ring in move " << ss << endl;
		}
		else if (cc < ss && cc < rr){
			cout << "bridge in move " << cc << endl;
		}
		else if (ss < cc && ss < rr)
			cout << "fork in move " << ss << endl;
		else if (rr < cc && rr < ss)
			cout << "ring in move " << rr << endl;
		else assert(false);
	}
	
	return 0;
}
