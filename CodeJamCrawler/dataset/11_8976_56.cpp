#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

bool centered(char mass[][11],int x,int y,int k){
  int xd=0;
  int yd=0;
  int sig_mas=0;
  for(int i=x;i<x+k;i++){
    for(int j=y;j<y+k;j++){
      if( i==x && j==y ){
        continue;
      } else if( i==x && j==y+k-1 ){
        continue;
      } else if( i==x+k-1 && j==y ){
        continue;
      } else if( i==x+k-1 && j==y+k-1 ){
        continue;
      } else {
        xd += (mass[i][j]-'0')*i;
        yd += (mass[i][j]-'0')*j;
        sig_mas += (mass[i][j]-'0');
      }
    }
  }
  return xd*2==sig_mas*(2*x+k-1) && yd*2==sig_mas*(2*y+k-1);
}

void handlecase(){
  int xd,yd,d;
  scanf("%d%d%d",&xd,&yd,&d);
  char mass[10][11];
  for(int i=0;i<xd;i++){
    scanf("%s",mass[i]);
  }
  int k;
  for(k=min(xd,yd);k>=3;k--){
    bool pos=false;
    for(int i=0;i<=xd-k;i++){
      bool min_pos=false;
      for(int j=0;j<=yd-k;j++){
        if(centered(mass,i,j,k)){
          min_pos=true;
          break;
        }
      }
      if(min_pos){
        pos=true;
        break;
      }
    }
    if(pos){
      break;
    }
  }
  if(k>=3){
    printf("%d\n",k);
  } else {
    printf("IMPOSSIBLE\n");
  }
}

int main(){
  freopen("E:\\B-small-attempt1.in","r",stdin);
  freopen("E:\\B-small-attempt1.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d: ",i);
    handlecase();
  }
  return 0;
}
