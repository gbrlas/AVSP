#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int N;
double A[1005],B[1005];
set<double> S;

int main(){
  int T;
  scanf("%d",&T);
  for(int cc = 1 ; cc <= T ; cc++){
    S.clear();
    scanf("%d",&N);
    for(int c = 1 ; c <= N ; c++)
      scanf("%lf",&A[c]);
    for(int c = 1 ; c <= N ; c++){
      scanf("%lf",&B[c]);
      S.insert(B[c]);
    }
    sort(A+1,A+1+N), sort(B+1,B+1+N);
    // for(int c = 1 ; c <= N ; c++)
    //   printf("%lf ",A[c]);
    // printf("\n");
    // for(int c = 1 ; c <= N ; c++)
    //   printf("%lf ",B[c]);
    // printf("\n");
    int s1,s2;
    s1 = s2 = 0;
    for(int c = 1, d = 1 ; c <= N ; c++){
      if(A[c] > B[d])
	s1++,d++;
      set<double>::iterator it = S.upper_bound(A[c]);
      if(it == S.end())
	s2++;
      else
	S.erase(it);
    }
    printf("Case #%d: %d %d\n",cc,s1,s2);
  }
}
