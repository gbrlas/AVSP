#include <cmath>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
	Gap(dist[v]); 
      else
	Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

int main() {
  int T; cin >> T;
  for(int caseNum = 1; caseNum <= T; caseNum++) {
    int W, H, B;
    cin >> W >> H >> B;
    int river[W][H];
    for(int x = 0; x < W; x++) {
      for(int y = 0; y < H; y++) {
        river[x][y] = 0;
      }
    }

    for(int b = 0; b < B; b++) {
      int X0, X1, Y0, Y1;
      cin >> X0 >> Y0 >> X1 >> Y1;
      for(int x = X0; x <= X1; x++) {
        for(int y = Y0; y <= Y1; y++) {
          river[x][y] = 1;
        }
      }
    }
    
    int start = 2 * W * H;
    int end = start + 1;
    PushRelabel pr(2 + 2 * W * H);
    for(int x = 0; x < W; x++) {
      pr.AddEdge(start, x, 1);
      pr.AddEdge(x + (H - 1) * W + H * W, end, 1);
      for(int y = 0; y < H; y++) {
        if(river[x][y] == 1) {
          continue;
        }
        pr.AddEdge(x + y * W, x + y * W + H * W, 1);
        if(x > 0 && river[x-1][y] == 0) {
          pr.AddEdge(x + y * W + H * W, x - 1 + y * W, 1);
        }
        if(x < W - 1 && river[x+1][y] == 0) {
          pr.AddEdge(x + y * W + H * W, x + 1 + y * W, 1);
        }
        if(y > 0 && river[x][y-1] == 0) {
          pr.AddEdge(x + y * W + H * W, x + (y - 1) * W, 1);
        }
        if(y < H - 1 && river[x][y+1] == 0) {
          pr.AddEdge(x + y * W + H * W, x + (y + 1) * W, 1);
        }
      }
    }
    cout << "Case #" << caseNum << ": " << pr.GetMaxFlow(start, end) << endl;
  }
}
