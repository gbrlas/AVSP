#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;



int main(){
  int T, t, i, j, k;
  int R,C;
  char tab[51][51];
  scanf("%d", &T);
  for(t = 1; t <= T; t++){
    scanf("%d%d", &R, &C);
    memset(tab, 0x0, sizeof(tab));
    getchar();
    for(i = 1; i <= R; i++){
      for(j = 1; j <= C; j++){
	tab[i][j] = getchar();
      }
      getchar();
    }
    int f = 1;
    for(i = 1; i <= R &&f; i++){
      for(j = 1; j <= C &&f; j++){
	if(tab[i][j] == '#'){
	  if(tab[i][j+1] == '#' && tab[i+1][j] == '#' && tab[i+1][j+1] == '#'){
	    tab[i][j] = '/';
	    tab[i][j+1] = '\\';
	    tab[i+1][j] = '\\';
	    tab[i+1][j+1] = '/';
	  }
	  else{
	    f = 0;
	    printf("Case #%d:\nImpossible\n", t);
	  }
	}
	
      }
    }


    if(f){
      printf("Case #%d:\n", t);
      for(i = 1; i <= R; i++){
	for(j = 1; j <= C; j++){
	  putchar(tab[i][j]);
	}
	putchar('\n');
      }
    }
      

    // for(k = ; k < ; k++){
    //   printf("\n", );
    // }
  }
  return 0;
}
