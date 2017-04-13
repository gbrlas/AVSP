#include <stdio.h>
#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define MAXN 50

int vis[MAXN][MAXN];

int main (){
  
  int L, D, N, cases = 1;

  scanf("%d %d %d", &L, &D, &N);

  string s;
  vector<string> dict;
  for (int i=0; i<D; i++){
    cin >> s;
    dict.push_back(s);
  }

  for (int k=0; k<N; k++){
    
    cin >> s;
    
    //constroi o mapa de automato dessa string
    memset(vis, 0, sizeof(vis));

    for(int i=0, j =0; i<s.length(); i++, j++){

      if (s[i] == '('){
	i++;
	while(s[i] != ')'){
	  vis[j][s[i]-'a'] = 1;
	  i++;
	}
      }
      else {
	vis[j][s[i]-'a'] = 1;
      }
    }

    //para cada string verifica se ela chega ate o
    //final do automato
    int count = 0;
    for (int i=0; i<dict.size(); i++){

      string tmp = dict[i];
      bool ok = 1;
      for (int j=0; j<tmp.length(); j++)
	if (vis[j][tmp[j]-'a'] == 0){
	  ok = 0;
	  break;
	}
      if (ok)
	count++;
    }
    printf("Case #%d: %d\n", k+1, count);
  }

  return 0;
}
