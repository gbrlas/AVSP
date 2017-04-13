#include <iostream>
#include <vector>
using namespace std;

#define INF 1<<30

struct Node {
  int g,c,v;
};

int calc (int, int, vector<Node> &);

void value (int k, int m, vector<Node> & nodes) {

  if (k > m)
    return;
  value(2*k, m, nodes);
  value(2*k+1, m, nodes);
  nodes[k].v = (nodes[k].g == 1 ? nodes[2*k].v&nodes[2*k+1].v : nodes[2*k].v|nodes[2*k+1].v);
}

int calcChange (int k, int m, vector<Node> & nodes) {

  //printf("calcChange %d %d  %d %d\n", k, nodes[k].g, nodes[2*k].v, nodes[2*k+1].v);
  if (nodes[k].g == 1) { //AND
    if (nodes[2*k].v == 1 && nodes[2*k+1].v == 1)
      return min(calc(2*k, m, nodes), calc(2*k+1, m, nodes));
    else if (nodes[2*k].v == 0 && nodes[2*k+1].v == 0) {
      int a = calc(2*k, m, nodes);
      int b = calc(2*k+1, m, nodes);
      if (a == INF || b == INF)
	return INF;
      return a+b;
    }
    else if (nodes[2*k].v == 1)
      return calc(2*k+1, m, nodes);
    return calc(2*k, m, nodes);
  }
  else { //OR
    if (nodes[2*k].v == 0 && nodes[2*k+1].v == 0)
      return min(calc(2*k, m, nodes), calc(2*k+1, m, nodes));
    else if (nodes[2*k].v == 1 && nodes[2*k+1].v == 1) {
      int a = calc(2*k, m, nodes);
      int b = calc(2*k+1, m, nodes);
      if (a == INF || b == INF)
	return INF;
      return a+b;
    }
    else if (nodes[2*k].v == 1)
      return calc(2*k, m, nodes);
    return calc(2*k+1, m, nodes);
  }
}

int calc (int t, int m, vector<Node> & nodes) {

  //printf("calc %d\n", t);
  if (t > m)
    return INF;
  int change = calcChange(t, m, nodes);
  //printf("calc %d: %d\n", t, change);
  if (nodes[t].c == 1) {
    if ((nodes[2*t].v^nodes[2*t+1].v) == 1) {
      //printf("calc change %d: %d\n", t, 1);
      return min(change, 1);
    }
    nodes[t].g = 1-nodes[t].g;
    int cc = calcChange(t, m, nodes);
    if (cc != INF)
      change = min(change, cc+1);
    nodes[t].g = 1-nodes[t].g;
  }
  //printf("calc change %d: %d\n", t, change);
  return change;
}

int main () {

  int N, c = 0, M, V, m;
  scanf("%d", &N);
  while (N--) {
    scanf("%d %d", &M, &V);
    vector<Node> nodes(M+1);
    m = (M-1)/2;
    int k = 1;
    for (; k <= m; ++k)
      scanf("%d %d", &nodes[k].g, &nodes[k].c);
    for (; k <= M; ++k)
      scanf("%d", &nodes[k].v);
    value(1, m, nodes);
    int res = (V == nodes[1].v ? 0 : calc(1, m, nodes));
    printf("Case #%d: ", ++c);
    if (res == INF)
      printf("IMPOSSIBLE\n");
    else
      printf("%d\n", res);
  }
}
