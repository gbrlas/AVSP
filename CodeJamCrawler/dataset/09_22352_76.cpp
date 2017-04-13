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

typedef long double ld;
typedef long long ll;
#define CLEAR(t) memset((t),0,sizeof(t))
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i) 

char *s="welcome to code jam";
int sl=strlen(s);

int main(){
  char t[555];gets(t);
  int ttt;sscanf(t,"%d",&ttt);
  REP(xxx,ttt){
    gets(t);
    int cnt[20];
    CLEAR(cnt);
    cnt[0]=1;
    for(int i=0;t[i];i++)
      for(int j=sl-1;j>=0;j--)
        if(s[j]==t[i]){
          cnt[j+1]=(cnt[j+1]+cnt[j])%10000;
        }
    printf("Case #%d: %04d\n",xxx+1,cnt[sl]);
  }
}
