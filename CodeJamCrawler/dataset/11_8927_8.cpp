#include <cstdio>
#include <algorithm>
using namespace std;

void handlecase(){
  int n;
  scanf("%d",&n);
  int p_a[100][100];  //p_a[i][j]=0 : i lose j, p_a[i][j]=1 : i win j, p_a[i][j]=-1 : no play
  double wp[100],owp[100];
  int owp_n[100];
  fill(owp,owp+n,0.0);
  fill(owp_n,owp_n+n,0);
  for(int i=0;i<n;i++){
    char line[101];
    scanf("%s",line);
    int game_n=0;
    int win_n=0;
    for(int j=0;j<n;j++){
      if(line[j]=='.'){
        p_a[i][j]=-1;
      } else if(line[j]=='0'){
        game_n++;
        p_a[i][j]=0;
      } else if(line[j]=='1'){
        game_n++;
        win_n++;
        p_a[i][j]=1;
      }
    }
    wp[i]=win_n/(double)game_n;
                //printf("wp[%d]=%lf\n",i,wp[i]);
    for(int k=0;k<n;k++){
      if(p_a[i][k]!=-1){
        owp[k]+= (win_n-p_a[i][k])/(double)(game_n-1);
        owp_n[k]++;
      }
    }
  }
  for(int i=0;i<n;i++){
    double oowp=0.0;
    int oowp_n=0;
    for(int j=0;j<n;j++){
      if(p_a[i][j]!=-1){
        oowp+=owp[j]/owp_n[j];
        oowp_n++;
      }
                //printf("owp[%d]=%lf\n",i,owp[i]/owp_n[i]);
                //printf("oowp[%d]=%lf\n",i,oowp/oowp_n);
    }
    printf("%.12lf\n",0.25*wp[i]+0.5*owp[i]/owp_n[i]+0.25*oowp/oowp_n);
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
