#define ll long long 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <utility>  
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 

using namespace std; 

#define CLEAR(t) memset((t),0,sizeof(t)) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FORD(i,a,b) for(int i=(a);i>=(b);--i) 
#define REP(i,n) for(int i=0;i<(n);++i) 

int n,s,p;
int t[3];
int tot=0;

int supr,cur;

void f(int ind){
  if(ind==n){
    if(supr == s) tot = max(tot, cur);
  }else{
    int osupr = supr;
    int ocur = cur;
    for(int i=0;i<=10;i++)
      for(int j=max(0,i-2);j<=i;j++)
        for(int k=max(0,i-2);k<=i;k++)
          if(i+j+k == t[ind]){
            if(i>=p)cur++;
            if(i-j==2 || i-k==2)supr++;
            f(ind+1);
            supr = osupr;
            cur = ocur;
          }
  }
}

int main(){
  int Cases; scanf("%d",&Cases);
  REP(xxxx,Cases){
    printf("Case #%d:",xxxx+1);
    scanf("%d%d%d",&n,&s,&p);
    REP(i,n)scanf("%d",&t[i]);
    tot = supr = cur = 0;
    f(0);
    printf(" %d\n",tot);
  }
}
