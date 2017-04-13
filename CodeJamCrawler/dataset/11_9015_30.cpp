#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

const int INF=10000000;

int cardn[10001];
int cards[1000];

void handlecase(){
  fill(cardn,cardn+10001,0);
  int n;
  scanf("%d",&n);
  if(n==0){
    printf("0\n");
    return;
  }
  for(int i=0;i<n;i++){
    int numb;
    scanf("%d",&numb);
    cardn[numb]++;
  }
  int starts[1000];
  int startn=0;
  for(int i=1;i<=10000;i++){
    if(cardn[i]>cardn[i-1]){
      for(int j=0;j<cardn[i]-cardn[i-1];j++){
        starts[startn]=i;
        startn++;
      }
    }
  }
  int d=0;
  while(true){
    bool longer=true;
    for(int i=0;i<startn;i++){
      if(starts[i]+d<=10000&&cardn[starts[i]+d]>0){
        cardn[starts[i]+d]--;
      } else {
        longer=false;
        break;
      }
    }
    if(longer==false){
      break;
    }
    d++;
  }
  printf("%d\n",d);
}

int main(){
  freopen("E:\\B-large.in","r",stdin);
  freopen("E:\\B-large.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
