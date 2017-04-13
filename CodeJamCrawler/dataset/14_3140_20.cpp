#include <cstdio>
#include <algorithm>

using namespace std;

int T,N,cap;
int A[10005];
bool used[10005];

int main(){
  scanf("%d",&T);
  for(int cc = 1 ; cc <= T ; cc++){
    scanf("%d %d",&N,&cap);
    for(int d = 1 ; d <= N ; d++){
      scanf("%d",&A[d]);
      used[d] = false;
    }
    sort(A+1,A+1+N);
    int sol = 0;
    for(int c = N ; c ; c--){
      if(used[c])
	continue;
      sol++;
      for(int d = c-1 ; d ; d--){
	if(used[d])
	  continue;
	if(A[c]+A[d] <= cap){
	  used[c] = used[d] = true;
	  // printf("%d %d\n",c,d);
	  break;
	}
      }
    }
    printf("Case #%d: %d\n",cc,sol);
  }
}
