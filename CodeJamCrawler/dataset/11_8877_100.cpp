#include <cstdio>
#include <algorithm>

using namespace std;

int be2i(char be){
  switch(be){
    case 'Q':
      return 0;
    case 'W':
      return 1;
    case 'E':
      return 2;
    case 'R':
      return 3;
    case 'A':
      return 4;
    case 'S':
      return 5;
    case 'D':
      return 6;
    case 'F':
      return 7;
    default:
      return -1;
  }
}

void print_save(char* save,int saven){
  printf("[");
  for(int i=0;i<saven;i++){
    if(i!=0){
      printf(", ");
    }
    printf("%c",save[i]);
  }
  printf("]\n");
}

void handlecase(){
  char comb[8][8];
  fill( (char*)comb, (char*)comb+64, '\0');
  bool oppose[8][8];
  fill( (bool*)oppose, (bool*)oppose+64, false);
  int c,d,n;
  scanf("%d",&c);
  char rull[4];
  for(int i=0;i<c;i++){
    scanf("%s",rull);
    int ba=be2i(rull[0]),bb=be2i(rull[1]);
    comb[ba][bb]=rull[2];
    comb[bb][ba]=rull[2];
  }
  scanf("%d",&d);
  for(int i=0;i<d;i++){
    scanf("%s",rull);
    int ba=be2i(rull[0]),bb=be2i(rull[1]);
    oppose[ba][bb]=true;
    oppose[bb][ba]=true;
  }
  scanf("%d",&n);
  char invoke[200];
  scanf("%s",invoke);
  char save[200];
  int saven=0;
  int have[8];
  fill(have,have+8,0);
  for(int i=0;i<n;i++){
    int ni=be2i(invoke[i]);
    if(saven==0){
      save[saven]=invoke[i];
      saven++;
      have[ni]++;
    } else {
      int nl=be2i(save[saven-1]);
      if( nl>=0 && comb[ni][nl]!='\0' ){
        save[saven-1]=comb[ni][nl];
        have[nl]--;
      } else {
        bool clear=false;
        for(int j=0;j<8;j++){
          if(have[j]!=0){
            if(oppose[ni][j]){
              saven=0;
              fill(have,have+8,0);
              clear=true;
              break;
            }
          }
        }
        if(!clear){
          save[saven]=invoke[i];
          saven++;
          have[ni]++;
        }
      }
    }
  }
  print_save(save,saven);
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
