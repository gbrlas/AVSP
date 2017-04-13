#include <cstdio>
#include <algorithm>
using namespace std;

void handlecase(){
  int r,c;
  scanf("%d%d",&r,&c);
  char picture[50][51];
  for(int i=0;i<r;i++){
    scanf("%s",picture[i]);
  }
  bool possible=true;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(picture[i][j]=='#'){
        if(picture[i][j+1]=='#' && picture[i+1][j]=='#' && picture[i+1][j+1]=='#'){
          picture[i][j]='/';
          picture[i][j+1]='\\';
          picture[i+1][j]='\\';
          picture[i+1][j+1]='/';
        } else {
          possible=false;
          break;
        }
      }
    }
    if(possible==false){
      break;
    }
  }
  if(possible){
    for(int i=0;i<r;i++){
      puts(picture[i]);
    }
  } else {
    puts("Impossible");
  }
}

int main(){
  freopen("E:\\A-small-attempt0.in","r",stdin);
  freopen("E:\\A-small-attempt0.out","w",stdout);
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    printf("Case #%d:\n",i);
    handlecase();
  }
  return 0;
}
