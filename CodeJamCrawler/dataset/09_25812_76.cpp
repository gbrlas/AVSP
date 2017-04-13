#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int maze[101][101];
int n, m;
bool visit[101][101];
bool v[101][101];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
void dfs(int x, int y, vector< pair<int, int> > &flow) {
    int lowest = 0x7fffffff; 
    int tx, ty;
    for (int i = 0; i < 4; ++i) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (visit[xx][yy]) continue;
        if (maze[xx][yy] >= maze[x][y]) continue;
        if (lowest > maze[xx][yy]) {
            tx = xx, ty = yy;
            lowest = maze[xx][yy];
        }
    }
    if (lowest != 0x7fffffff) {
        visit[tx][ty] = true;
        flow.push_back(make_pair(tx, ty));
        dfs(tx, ty, flow);
    }
}
struct Node{
    vector<pair<int, int> >list;
}flow[500];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
bool ccmp(const Node&a, const Node&b) {
    for (int i = 0; i < a.list.size() && i < b.list.size(); ++i) {
        if (a.list[i] != b.list[i]) return cmp(a.list[i], b.list[i]);
    }
    return a.list.size() > b.list.size();
}
void Union(vector< pair<int, int> >&a, vector< pair<int,int> > &b) {
    for(int i = 0; i < b.size(); ++i) {
        a.push_back(b[i]);
    }
}
bool xcmp(const pair<int,int> &a, const pair<int,int>&b) {
    return maze[a.first][a.second] > maze[b.first][b.second];
}
int main() {
//	freopen("a.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        vector< pair<int, int> >sink;
        vector< pair<int, int> >seq;
        scanf("%d%d", &n, &m);
		int i;
        for ( i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &maze[i][j]);
                seq.push_back(make_pair(i, j));
            } 
        }
        memset(v, 0, sizeof(v));
        sort(seq.begin(), seq.end(), xcmp);
        int count = 0;
        for ( i = 0; i < seq.size(); ++i) {
            pair<int,int> p = seq[i];
            if (v[p.first][p.second]) continue;
            v[p.first][p.second] = true;
            vector< pair<int, int> >list;
            list.push_back(p);
            memset(visit, 0, sizeof(visit));
            visit[p.first][p.second] = true;
			int j;
            dfs(p.first, p.second, list);
            
            bool ok = false;
            for ( j = 0; j < count; ++j) {
                if (list[list.size() - 1] == flow[j].list[flow[j].list.size() - 1]) {
                    Union(flow[j].list, list);
                    ok = true;
                    break; 
                }
            }
            if (!ok) {
                flow[count++].list = list;
            }
        }
       
        for ( i = 0; i < count; ++i) {
            sort(flow[i].list.begin(), flow[i].list.end(), cmp);
			flow[i].list.erase(unique(flow[i].list.begin(), flow[i].list.end()), flow[i].list.end()); 
        }
        sort(flow, flow + count, ccmp);
        for ( i = 0; i < count; ++i) {
            for (int j = 0; j < flow[i].list.size();++j) {
                pair<int, int> p = flow[i].list[j];
                if (maze[p.first][p.second] > 'z' || 
                       maze[p.first][p.second] < 'a') {
                    maze[p.first][p.second] = i + 'a';
                }
            }
        }
        printf("Case #%d:\n", kase);
        for ( i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%c%c", maze[i][j], j == m - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
