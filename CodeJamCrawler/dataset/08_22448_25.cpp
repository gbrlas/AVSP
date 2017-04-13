#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAXM 2100
#define INF 1 << 29

typedef pair<int, int> pii;

vector<pii> adj[MAXM];

int main (){

  int t,n,m,cases=1;
  scanf("%d",&t);

  while (t--){

    scanf("%d %d",&n, &m);

    int s = (1 << n);

    for (int i=0; i<m; i++){

      int k;
      scanf("%d",&k);
      adj[i].clear();

      for (int j=0; j<k; j++){
	int a, b;
	scanf("%d %d",&a, &b);
	a--;
	adj[i].push_back(pii(a,b));
      }
    }

    bool sat, allsat;
    int k;
    int best = INF, bestk;
    for (k=0; k<s; k++){

      allsat = true;
      
      for (int i=0; i<m; i++){
	
	sat = false;
	
	for (int j=0; j<adj[i].size(); j++){

	  int a = adj[i][j].first;
	  int b = adj[i][j].second;

	  int r = 0;
	  if (((1 << a) & k)) r = 1;

	  if (r == b){
	    sat = true;
	    break;
	  }
	}

	if (sat == false){
	  allsat = false;
	  break;
	}
      }

      if (allsat == true){
	int minor = __builtin_popcount(k);
	//printf("k:%d\n",k);
	if (best > minor){
	  bestk = k;
	  best = minor;
	}
      }

    }

    printf("Case #%d:",cases++);
    if (best < INF){
      for (int i=0; i<n; i++){
	int r = 0;
	if ((1 << i) & bestk) r = 1;
	printf(" %d", r);
      }
      printf("\n");
    }
    else
      printf(" IMPOSSIBLE\n");
  }

  return 0;
}
