#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

//#define DEB

using namespace std;

int U[2099];
int V[2099];
int n, m;
int color[2099];
int edge[8][8];
typedef pair<int, int> PI;

int forward_dist( int u, int v ) {
	if( u == v ) return 0;
	// u->v
	if( v > u ) return v-u;
	return n-(u-v);
}

int ccalc(int u, int v, int w, int& cost ) {
	if( forward_dist( v, w ) >= forward_dist( v, u ) ) return 0;
	cost = forward_dist(v,w);
	return 1;
}

int trace(int from, int _to) {
#ifdef DEB
	cout << "new trace: " << from << ' ' << _to << endl;
#endif
	edge[from][_to] = 1;
	PI p(from, _to);
	int color_mask = 0;
	while (1) {
#ifdef DEB
		cout << "edge " << p.first << ' ' << p.second << endl;
#endif
		color_mask |= 1 << color[p.first];
		color_mask |= 1 << color[p.second];
		int to = -1;
		int cost = -1;
		if (edge[p.second][(p.second + 1) % n] == 0) {
			to = (p.second + 1) % n;
			ccalc(p.first, p.second, (p.second + 1) % n, cost );
		}
		for (int i = 0; i < m; ++i) {
			if (V[i] == p.second) {
				if (U[i] != p.first && edge[p.second][U[i]] == 0) {
					int tmp_cost;
					if( ccalc(p.first,p.second,U[i], tmp_cost ) && tmp_cost > cost ) {
						cost = tmp_cost;
						to = U[i];
					}
				}
			}
			if (U[i] == p.second) {
				if (V[i] != p.first && edge[p.second][V[i]] == 0) {
					int tmp_cost;
					if( ccalc(p.first,p.second,V[i], tmp_cost ) && tmp_cost > cost ) {
						cost = tmp_cost;
						to = V[i];
					}
				}
			}
		}
		if( p.second == from ) break;
		if (cost != -1) {
			edge[p.second][to] = 1;
			p = PI(p.second, to);
		} else break;
	}
	return color_mask;
}

int eval(int colors) {
	memset(edge, 0, sizeof(edge));
	for (int i = 0; i < n; ++i) {
		int to = (i + 1) % n;
		if (edge[i][to])
			continue;
		if (trace(i, to) != (1 << (colors)) - 1)
			return 0;
	}
	for (int i = 0; i < m; ++i) {
		if (edge[U[i]][V[i]] == 0) {
			if (trace(U[i], V[i]) != (1 << (colors)) - 1)
				return 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (edge[V[i]][U[i]] == 0) {
			if (trace(V[i], U[i]) != (1 << (colors)) - 1)
				return 0;
		}
	}
	return 1;
}

int max_color;
int max_color_assign[2099];
void rec(int index, int colors) {
	if (colors + n - index <= max_color)
		return;
	if (index == n) {

#ifdef DEB
		for( int i = 0; i < n; ++i ) {
			cout << color[i] << endl;
		}
		cout << "---colors\n";
#endif

		if (eval(colors)) {
			max_color = colors;
			for( int i = 0; i < n; ++i ) {
				max_color_assign[i] = color[i];
			}
		}
		return;
	}

	// reuse color
	for (int i = 0; i < colors; ++i) {
		color[index] = i;
		rec(index + 1, colors);
	}
	// new color
	color[index] = colors;
	rec(index + 1, colors + 1);
}

int main() {
	int cases;
	cin >> cases;
	for (int caseid = 1; caseid <= cases; ++caseid) {
		cout << "Case #" << caseid << ": ";
		cin >> n >> m;
		assert( n <= 8 );
		for (int i = 0; i < m; ++i) {
			cin >> U[i];
			--U[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> V[i];
			--V[i];
			assert( abs(U[i]-V[i]) > 1 );
			assert( abs(U[i]-V[i]) != n-1 );
		}
		max_color = -1;
		rec(0, 0);
		cout << max_color << endl;
		for( int i = 0; i < n; ++i ) {
			if( i > 0 ) cout << ' ';
			cout << max_color_assign[i]+1;
		}
		cout << endl;
	}
	return 0;
}
