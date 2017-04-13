#include <cstdio>
#include <algorithm>
using namespace std;
int surmax[31],normax[31];
int sc[101];
int main(){
  fill(surmax,surmax+31,-1);
  fill(normax,normax+31,-1);
  normax[0] = 0,normax[1] = 1,normax[29] = 10,normax[30] = 10;
  for(int i=2;i<=28;++i){
    if(i%3==0){
      normax[i] = i/3;
      surmax[i] = i/3+1;
    }
    if(i%3==1){
      normax[i] = (i-1)/3+1;
      surmax[i] = (i-1)/3+1;
    }
    if(i%3==2){
      normax[i] = (i-2)/3+1;
      surmax[i] = (i-2)/3+2;
    }
  }
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;++t){
    int ans = 0;
    int n,s,p;
    scanf("%d%d%d",&n,&s,&p);
    for(int i=0;i<n;++i) scanf("%d",&sc[i]);
    int cnt = 0;
    int dbl = 0; //両方OK
    int son = 0; //surprise only
    int non = 0; //normal only
    for(int i=0;i<n;++i){
      if(surmax[sc[i]]==-1) cnt+=normax[sc[i]]>=p;
      else{
	if(normax[sc[i]]>=p) ++dbl,++cnt;
	if(surmax[sc[i]]>=p&&normax[sc[i]]<p) ++son,++cnt;
	if(surmax[sc[i]]<p) ++non;
      }
    }
    ans = cnt;
    if(son>s) ans -= son-s;
    printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}
