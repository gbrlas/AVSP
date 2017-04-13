#include<stdio.h>
#include<algorithm>
using namespace std;

#define NN 1010

int T,N;
double A[NN], B[NN];
bool vA[NN], vB[NN];
bool seen[NN];

double BS(double tgt) {
  int bot=0;
  int top=N;
  double temp=B[0];
  bool v[NN];
  for (int i=0; i<NN; i++) v[i]=false;
  while(true) {
    int mid=(bot+top)/2;
    if (tgt<B[mid]) top=mid;
    else bot=mid+1;
    if (seen[mid]) continue;
    if (v[mid]) return B[mid];
    v[mid]=true;
  }
}

int main() {
  freopen("E.txt","r",stdin);
  freopen("E.out","w",stdout);
  
  scanf("%d",&T);
  for (int tc=0; tc<T; tc++) {
    scanf("%d",&N);
    for (int i=0; i<N; i++) scanf("%lf",&A[i]);
    for (int i=0; i<N; i++) scanf("%lf",&B[i]);
    for (int i=0; i<N; i++) seen[i]=false;
    
    sort(A,A+N);
    sort(B,B+N);
    int X=0, Y=0;
    //printf("A: "); for (int i=0; i<N; i++) printf("%.3lf ",A[i]); puts("");
    //printf("B: "); for (int i=0; i<N; i++) printf("%.3lf ",B[i]); puts("");
    
    for (int i=0; i<N; i++) vA[i]=vB[i]=false;
    for (int i=0; i<N; i++) {
      int id=0;
      for (int j=0; j<N; j++) {
        if (vB[j]==true) continue;
        if (B[j]>A[i]) {id=j; break;}
      }
      if (id==0) {
        for (int j=0; j<N; j++) {
          if (vB[j]==true) continue;
          id=j; 
          break;
        }
      }
      if (A[i]>B[id]) Y++;;
      vB[id]=true;
    }
    
    for (int i=0; i<N; i++) vA[i]=vB[i]=false;
    for (int i=0; i<N; i++) {
      int id=0;
      for (int j=0; j<N; j++) {
        if (vA[j]==true) continue;
        if (A[j]>B[i]) {id=j; break;}
      }
      if (id==0) {
        for (int j=0; j<N; j++) {
          if (vA[j]==true) continue;
          id=j; 
          break;
        }
      }
      if (A[id]>B[i]) X++;
      vA[id]=true;
    }
    printf("Case #%d: %d %d\n",tc+1,X,Y);
  }
  return 0;
}
