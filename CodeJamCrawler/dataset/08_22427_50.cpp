#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#define MAXN 123 
#define MAXQ 1234
#define MAXLEN 123
#define INF 1 << 29

map<string, int> memo;
int query[MAXQ];
int pd[MAXN][MAXQ];

int main (){

  int t, n, q, cases = 1;
  string s;

  scanf("%d",&t);
  while (t--){

    scanf("%d ",&n);
    for (int i=0; i<n; i++){
      getline(cin, s, '\n');
      memo[s] = i;
    }

    scanf("%d ",&q);
    for (int i=0; i<q; i++){
      getline(cin, s, '\n');
      query[i] = memo[s];
    }
    
    //Teste
//     for (int i=0; i<q; i++)
//       printf("%d ",query[i]);
//     printf("\n");

    for (int i=0; i<=n; i++)
      for (int j=0; j<=q; j++)
	pd[i][j] = INF;

    for (int i=0; i<n; i++) 
      if (i != query[q-1])
	pd[i][q-1] = 0;
    
    for (int i=q-2; i>=0; i--){
      for (int j=0; j<n; j++){
	if (j == query[i]) continue;
	pd[j][i] = pd[j][i+1];
	for (int k=0; k<n; k++){
	  if (k != j) pd[j][i] = min(pd[j][i], pd[k][i+1] + 1);
	}
      }
    }
    int best = INF;
    for (int i=0; i<n; i++)
      best = min (best, pd[i][0]);
    if (q == 0) best = 0;
    printf("Case #%d: %d\n",cases++,best);
  }

  return 0;
}
