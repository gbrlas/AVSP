#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define CLEAR(X) memset(X,0,sizeof(X))

priority_queue<pair<int, int> >pq;

int conv(char *s){
  return ((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
};

int main(){
  int xx;scanf("%d",&xx);
  for(int xxx=1;xxx<=xx;xxx++){
    while(!pq.empty())pq.pop();
    int na,nb;
    int t;
    scanf("%d%d%d",&t,&na,&nb);
    for(int i=0;i<na;i++){
      char x[100],y[100];
      scanf("%s%s",x,y);
      pq.push(make_pair(-conv(x),-2));
      pq.push(make_pair(-conv(y)-t,1));
    };
    for(int i=0;i<nb;i++){
      char x[100],y[100];
      scanf("%s%s",x,y);
      pq.push(make_pair(-conv(x),-1));
      pq.push(make_pair(-conv(y)-t,2));
    };
    int needa,needb;
    needa=needb=0;
    int a,b;
    a=b=0;
    while(!pq.empty()){
      int type= pq.top().second;
      pq.pop();
      if (type==2)a++;
      if (type==1)b++;
      if (type==-1){
        if (b==0)needb++;
        else b--;
      }
      if (type==-2){
        if (a==0)needa++;
        else a--;
      }
    };
    printf("Case #%d: %d %d\n",xxx,needa,needb);
  };
  return 0;
}
