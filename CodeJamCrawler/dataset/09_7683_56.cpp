#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include<cctype>
#include<cmath>
#include <sstream>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>

using namespace std;

#define PB(x) push_back(x)
#define MP(x,y) make_pair((x),(y))
#define SZ(a) (int((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define REP(x,a,b) for(int x = (a);x < (b);x++)
#define FOR(x,n) REP(x,0,n)
#define FOREVER while(1)
#define WATCH(x) cout << #x << " = " << (x)

#ifdef DEBUG
#define D(X) X
#else
#define D(X)
#endif
#define MAXL 1000
typedef long long ll;
const int inf = (1<<29);

int main(){
   int test;
   scanf("%d",&test);
   char buf[MAXL];
   char buf2[MAXL];

   FOR(t,test){
      printf("Case #%d: ",t+1);
      scanf("%s",buf);
      strcpy(buf2,buf);
   //   printf("%s ",buf);
      if(next_permutation(buf,buf + strlen(buf)))
         printf("%s\n",buf);
      else {
         sort(buf,buf+strlen(buf));
         int n = 0;
         while(buf[n] == '0')n++;
         printf("%c0",buf[n]);
         buf[n] = '\0';
         printf("%s",buf);
         printf("%s\n",buf+n+1);
      }
   }
   return 0;
}
