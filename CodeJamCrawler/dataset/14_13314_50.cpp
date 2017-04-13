#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point {int x0, y0, x1, y1; };
struct edge { int to, cap, rev; };
typedef vector<edge> node;
typedef vector<node> graph;

int find_flow(int v, int t, int f, graph &g, vector<bool> &used)
{
	if(v == t)
		return f;
	used[v] = true;
	//printf("%d %d %d\n", v, t, f);

	for(int i = 0; i < g[v].size(); ++i) {

		edge &e = g[v][i];
		if(!used[e.to] && e.cap > 0) {
			int d = find_flow(e.to, t, min(f, e.cap), g, used);
			if(d > 0) {
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
		}
	}

	return 0;
}

int calc_max_flow(int s, int t, graph &g)
{
	int flow = 0;
	vector<bool> used(g.size());
	while(true) {
		fill(used.begin(), used.end(), false);
		int f = find_flow(s, t, 10, g, used);
		if(f == 0) break;
		flow += f;
	}
	return flow;
}

void add_edge(int from, int to, int cap, graph &g)
{
	g[from].push_back((edge){to, cap, g[to].size()});
	g[to].push_back((edge){from, 0, g[from].size() - 1});
}

int main()
{
	int test_case_num;

	scanf("%d", &test_case_num);

	for(int test_case = 0; test_case < test_case_num; ++test_case) {

		int w, h, b;
		vector<int> ys;
		vector<point> ps;

		scanf("%d%d%d", &w, &h, &b);
		for(int i = 0; i < b; ++i) {
			point p;
			scanf("%d%d%d%d", &p.x0, &p.y0, &p.x1, &p.y1);
			ps.push_back(p);
			ys.push_back(p.y0);
			if(p.y0 - 1 >= 0) ys.push_back(p.y0 - 1);
			ys.push_back(p.y1);
			for(int j = 0; j < w + 1 && p.y1 + j < h; ++j)
				ys.push_back(p.y1 + j);
		}
		ys.push_back(0);
		ys.push_back(h - 1);

		sort(ys.begin(), ys.end());
		ys.erase(unique(ys.begin(), ys.end()), ys.end());
		h = ys.size();
		for(int i = 0; i < b; ++i) {
			ps[i].y0 = lower_bound(ys.begin(), ys.end(), ps[i].y0) - ys.begin();
			ps[i].y1 = lower_bound(ys.begin(), ys.end(), ps[i].y1) - ys.begin();
		}

		vector<vector<int> > imos;

		imos.resize(w + 1);
		for(int i = 0; i < w + 1; ++i)
			imos[i].resize(h + 1, 0);
		for(int i = 0; i < b; ++i) {
			point &p = ps[i];
			imos[p.x0][p.y0] += 1;
			imos[p.x0][p.y1 + 1] -= 1;
			imos[p.x1 + 1][p.y0] -= 1;
			imos[p.x1 + 1][p.y1 + 1] += 1;
		}

		for(int x = 0; x < w + 1; ++x) {
			for(int y = 1; y < h + 1; ++y) {
				imos[x][y] += imos[x][y - 1];
			}
		}
		for(int y = 0; y < h + 1; ++y) {
			for(int x = 1; x < w + 1; ++x) {
				imos[x][y] += imos[x - 1][y];
			}
		}

		if(false) {
			for(int y = h - 1; y >= 0; --y) {
				for(int x = 0; x < w; ++x) {
					printf("%d", imos[x][y]);
				}
				printf("\n");
			}
		}

		graph g;

		g.resize(w * h * 2 + 2);
		const int ss = w * h * 2 + 0;
		const int tt = w * h * 2 + 1;

		int dx[] = {-1, 0, 0, 1};
		int dy[] = {0, -1, 1, 0};

		for(int x = 0; x < w; ++x) {
			for(int y = 0; y < h; ++y) {
				if(imos[x][y] > 0)
					continue;
				int s = x * h + y;
				add_edge(s * 2 + 0, s * 2 + 1, 1, g);
				for(int dir = 0; dir < 4; ++dir) {
					int nx = x + dx[dir], ny = y + dy[dir];
					if(nx < 0 || nx >= w || ny < 0 || ny >= h)
						continue;
					if(imos[nx][ny] > 0)
						continue;
					int t = nx * h + ny;
					add_edge(s * 2 + 1, t * 2 + 0, 1, g);
					add_edge(t * 2 + 1, s * 2 + 0, 1, g);
				}
			}
		}

		for(int x = 0; x < w; ++x) {
			if(imos[x][0] == 0)
				add_edge(ss, (x * h + 0) * 2 + 0, 1, g);
			if(imos[x][h - 1] == 0)
				add_edge((x * h + h - 1) * 2 + 1, tt, 1, g);
		}

		int ans = calc_max_flow(ss, tt, g);

		printf("Case #%d: %d\n", test_case + 1, ans);
	}

	return 0;
}