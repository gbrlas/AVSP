#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


int main(){
  int T = 1, t, i, j, k;
  int J[100], V[100], n, O[100];
  char oponentes[100][100], c;
  long double wp[100], owp[100], oowp[100], rpi[100];

  scanf("%d", &T);
  for(t = 1; t <= T; t++){
    memset(oponentes, 0x0, sizeof(oponentes));
    memset(J, 0x0, sizeof(J));
    memset(V, 0x0, sizeof(V));
    memset(O, 0x0, sizeof(O));

    scanf("%d", &n);
    //    printf("N: %d\n", n);
    getchar();
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	c = getchar();
	//	putchar(c);
	if(c != '.'){
	  J[i]++;
	  oponentes[i][j] = -1;
	  if(c == '1'){
	    V[i]++;
	    oponentes[i][j] = 1;
	  }
	}
      }//j
      getchar();
      wp[i] = ((long double)V[i])/J[i];
      //      printf("\n(%d %.9Lf) ", V[i], wp[i]);
    }
    //    putchar('\n');


    int v;
    for(i = 0; i < n; i++){
      owp[i] = 0;
      for(j = 0; j < n; j++){
	v = 0;
	if(oponentes[i][j]){
	  for(k = 0; k < n; k++){
	    if(k != i && oponentes[j][k] == 1)
	      v++;
	  }
	}
	owp[i] += ((long double) v)/(J[j]-1);
      }
      owp[i] = owp[i]/J[i];
      //printf("%Lf ", owp[i]);
    }
    //    putchar('\n');



    for(i = 0; i < n; i++){
      oowp[i] = 0;
      for(j = 0; j < n; j++){
	if(oponentes[i][j])
	  oowp[i] += owp[j];
      }
      oowp[i] = oowp[i]/J[i];
      //printf("%Lf ", oowp[i]);
    }
    //    putchar('\n');

    for(i = 0; i < n; i++){
      rpi[i] = wp[i]/4 + owp[i]/2 + oowp[i]/4;
    }

    printf("Case #%d:\n", t);

    for(k = 0; k < n; k++){
      printf("%.9Lf\n", rpi[k]);
    }
  }
  return 0;
}
