#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

int p, w;

vector<int> graph[1<<10];;
bool adj[1<<10][1<<10];
int dist[1<<10][1<<10];
int threat[1<<10][1<<10];
bool visited[1<<10][1<<10];

struct cmp{
	bool operator()(const pair<int,int>& p1, const pair<int,int>& p2){
		if (dist[p1.first][p1.second]==dist[p2.first][p2.second]){
			if (threat[p1.first][p1.second] == threat[p2.first][p2.second]){
				return p1 < p2;	
			}
			return threat[p1.first][p1.second] > threat[p2.first][p2.second];
		}	
		return dist[p1.first][p1.second] < dist[p2.first][p2.second];
	}		
};

pair<int,int> dijkstra(){
	memset(dist,0x3f3f3f3f,sizeof(dist));
	memset(threat,0,sizeof(threat));
	memset(visited,false,sizeof(visited));
	set<pair<int,int>, cmp> q;
	q.insert(make_pair(0,0));
	dist[0][0] = 0;
	threat[0][0] = 0;
	for (int k = 0; k < p; k++)
		if (adj[0][k])
			threat[0][0]++;
	while (!q.empty()){
		pair<int,int> pr = *(q.begin()); q.erase(q.begin());
		int curr = pr.first, prev = pr.second;
		visited[curr][prev] = true;
		if (adj[curr][1]) return pr;
		for (int i = 0; i < graph[curr].size(); i++){
			int next = graph[curr][i];
			if (visited[next][curr]) continue;
			int d = dist[curr][prev]+1;
			if (dist[next][curr] < d) continue;
			int th = threat[curr][prev];
			for (int k = 0; k < p; k++){
				if (k == next || k == curr || k == prev) continue;
				if (adj[next][k] && !adj[curr][k] && !adj[prev][k]) th++;
			}
			th--;
			if (dist[next][curr] == d && threat[next][curr] >= th) continue;
			q.erase(make_pair(next,curr));
			dist[next][curr] = d;
			threat[next][curr] = th;
			q.insert(make_pair(next,curr));
		}
	}
	return make_pair(-1,-1);
}

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		cin >> p >> w;
		memset(adj,false,sizeof(adj));
		for (int i = 0; i < p; i++)
			graph[i].clear();
		for (int i = 0; i < w; i++){
			int x,y; char c;
			cin >> x >> c >> y;
			adj[x][y] = adj[y][x] = true;
			graph[x].push_back(y);
			graph[y].push_back(x);	
		}
		pair<int,int> ans = dijkstra();
		int curr = ans.first,prev = ans.second;
		cout << "Case #" << zz << ": " << dist[curr][prev] << " " << threat[curr][prev] << endl;
	}
	
	return 0;
}
