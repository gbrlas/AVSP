#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

void handlecase(){
  int l,n,c;
  long long t;
  scanf("%d%lld%d%d",&l,&t,&n,&c);
  int dist[1000];
  for(int i=0;i<c;i++){
    scanf("%d",&dist[i]);
  }
  for(int i=c;i<n;i++){
    dist[i]=dist[i%c];
  }
  long long time[1000][3];
  time[0][0]=dist[0]*2;
  if(dist[0]*2>t){
    time[0][1]=t+(dist[0]*2-t)/2;
  } else {
    time[0][1]=dist[0]*2;
  }
  time[0][2]=time[0][1];
  for(int i=1;i<n;i++){
    for(int j=0;j<=l;j++){
      time[i][j]=time[i-1][j]+dist[i]*2;
      if(j>0){
        long long time2;
        if(time[i-1][j-1]>t){
          time2=time[i-1][j-1]+dist[i];
        } else{
          if(time[i-1][j-1]+dist[i]*2>t){
            time2=t+(time[i-1][j-1]+dist[i]*2-t)/2;
          } else {
            time2=time[i-1][j-1]+dist[i]*2;
          }
        }
        time[i][j]=min(time[i][j],time2);
      }
                  //printf("%d,%d: %lld\n",i,j,time[i][j]);
    }
  }
  printf("%lld\n",time[n-1][l]);
}

int main(){
  freopen("E:\\B-small-attempt0.in","r",stdin);
  freopen("E:\\B-small-attempt0.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
