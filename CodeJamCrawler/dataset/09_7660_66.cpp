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
#define MAXL 600

typedef long long ll;
const int inf = (1<<29);
string welcome = "welcome to code jam";
char buf[MAXL];
int n1,n2;
int pd[1000][1000];
int f(int i1,int i2){
   if(i1 >= n1)return 1;
   if(i2 >= n2)return 0;
   if(pd[i1][i2] != -1)return pd[i1][i2];

   if(welcome[i1] != buf[i2])return pd[i1][i2] = (f(i1,i2+1));
   else return pd[i1][i2] = (f(i1+1,i2+1) + f(i1,i2+1))%10000;
}
int main(){
   int n;
   int test = 1;
   scanf("%d\n",&n);
   FOR(i,n){
   memset(pd,-1,sizeof(pd));
      fgets(buf,MAXL,stdin);
      n1 = welcome.size();
      n2 = strlen(buf)-1;
      printf("Case #%d: %04d\n",test++,f(0,0));
   }
   return 0;
}
