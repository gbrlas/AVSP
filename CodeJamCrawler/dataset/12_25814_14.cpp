#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;
 
struct SV{
  long long d;
  long long l;
};

SV v[10000];
long long best[10000];

int main(){
  int jcase;
  int N;
  long long D;
  freopen("A-small-attempt1.in", "r", stdin);
  freopen("A-small-attempt1.out", "w", stdout);

  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%lld %lld", &v[i].d, &v[i].l);
    for(int i=0; i<N; i++) best[i] = -50000000000LL;
    scanf("%lld", &D);
    
    best[0] = v[0].d;
    
    for(int i=0; i<N; i++){
      //if(best[i] == -1) break;
      for(int j=i+1; j<N; j++){
//        printf("i=%d j=%d v[i].d=%lld best[i]=%lld v[j].d = %lld\n", i, j, v[i].d, best[i], v[j].d);
        if(v[i].d + best[i] >= v[j].d){
          long long temp;
          if(v[j].d - v[i].d > v[j].l) temp = v[j].l;
          else temp = v[j].d - v[i].d;
          
          if(temp > best[j]) best[j] = temp;
//          printf("i=%d best[%d]=%lld\n", i, j, best[j]);
        }
        else break;
      }
    }
    
    printf("Case #%d: ", icase+1);
    bool yes=false;
    for(int i=0; i<N; i++){
      if(v[i].d + best[i] >= D){
        yes = true;
        break;
      }
    }
    if(yes) printf("YES\n");
    else printf("NO\n");
  }
  getch();
}
