#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <ctype.h>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define ROF(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define PER(i,a) ROF(i,a-1,0)
#define _m(a,b) memset(a,b,sizeof(a))
#define st first
#define nd second
#define LL long long

typedef pair<int,int> PII;

bool C[15][256];
char S[5001][16];

int main (void) {
	int L,D,N; scanf("%d %d %d",&L,&D,&N);
	REP(i,D) scanf("%s",S[i]);
	FOR(n,1,N) {
		REP(i,L) REP(j,256) C[i][j]=false;
		
		char s[1000]; scanf("%s",s);
		int idx=0;
		REP(i,L) {
			if(s[idx]=='(') {
				idx++;
				while(s[idx]!=')')
					C[i][s[idx++]]=true;
				idx++;
			} else {
				C[i][s[idx++]]=true;
			}
		}
		
		bool tres[5001];
		REP(i,D) tres[i]=true;
		REP(i,D) REP(j,L) {
			if(C[j][S[i][j]]==false) {
				tres[i]=false;
				break;
			}
		}
		
		int res=0;
		REP(i,D) res+=(tres[i]==true);
		
		printf("Case #%d: %d\n",n,res);
	}
	return 0;
}
