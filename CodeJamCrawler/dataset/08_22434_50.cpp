#include <stdio.h>
#include <iostream>

using namespace std;

struct interval {
  int ini, end, t;
  interval(int ini=0, int end=0, int t=0): ini(ini), end(end), t(t){};
};
bool operator< (const interval &a, const interval &b){
  if (a.ini < b.ini) return true;
  if (a.ini > b.ini) return false;
  if (a.end < b.end) return true;
  if (a.end > b.end) return false;
  return a.t < b.t;
}

interval I[1000];
int vis[1000];
int n, m, t, add;

void visit(int i){
  vis[i] = 1;
  for (int j=i+1; j<n+m; j++){
    if (vis[j] == 0 && I[j].ini >= I[i].end + add && I[j].t != I[i].t)
      return visit(j);
  }
}

int main (){


  int h1, m1, h2, m2, cases = 1;

  scanf("%d", &t);

  while(t--){

    memset(vis,0,sizeof(vis));

    scanf("%d %d %d",&add, &n, &m);
    
    for (int i=0; i<n; i++){
      scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
      I[i] = interval(h1*60 + m1, h2*60 + m2, 0);
    }
    for (int i=0; i<m; i++){
      scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
      I[i+n] = interval(h1*60 + m1, h2*60 + m2, 1);
    }
    sort(I, I+n+m);

    int freq[] = {0,0};
    for (int i=0; i<n+m; i++){
      if (vis[i] == 0){
	freq[I[i].t]++;
	visit(i);
      }
    }
    printf("Case #%d: %d %d\n",cases++, freq[0], freq[1]);

  }

  return 0;
}
