#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int mozna[100];

int dp[100][1<<11];
int n, m;

int bitcnt(unsigned int s) {
  int c= 0 ;
  while(s) {
    c+= s&1;
    s>>=1;
  } return c;
}

bool can[1<<10][1<<10];
vector<unsigned int> dozwolone;

int main() {

  int tcase;
  scanf("%d", &tcase);
  for(int zz=0; zz<tcase; zz++) {
    scanf("%d%d", &n,&m);
    memset(mozna, 0, sizeof(mozna));
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
	char c;
	scanf(" %c", &c);
	if(c=='x') mozna[i] |= 1<<j;
      }
    }
    for(int j=0; j<m; j++) mozna[n] |= 1<<j;

    dozwolone.clear();
    for(unsigned int s=0; s<(1<<m); s++) 
      if((s & (s<<1))==0 && (s & (s>>1))==0)
	dozwolone.push_back(s);

    for(vector<unsigned int>::iterator s = dozwolone.begin(); s!=dozwolone.end(); s++) 
      if(((*s) & mozna[0])==0)
	dp[0][*s] = max(dp[0][*s], bitcnt(*s));


    for(int i=0; i<n; i++) {
      for(vector<unsigned int>::iterator z=dozwolone.begin(); z!=dozwolone.end(); z++) if((mozna[i+1] &(*z))==0){
	  for(vector<unsigned int>::iterator s = dozwolone.begin(); s!=dozwolone.end(); s++) {
	    if((((*z)<<1) & (*s)) || (((*z)>>1) & (*s))) continue;
	  dp[i+1][*z] = max(dp[i+1][*z], dp[i][*s] + bitcnt(*z));
	}
      }
    }
    int best = 0;
    for(int s=0; s<(1<<m); s++) best=max(best, dp[n][s]);
    printf("Case #%d: %d\n", zz+1, best);
  }
}
