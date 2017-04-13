#include <cstdio>
#include <cstring>
#define REP(i,n) for(int i = 0;i<n;i++)
#define LL unsigned long long

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	char s[1000];
	char t[1000];
	REP(z,T) {
		printf("Case #%d: ", z+1);
		scanf("%s", s);
		int len=strlen(s);
		int d=0, v;
		REP(i,1000) t[i]=-2;
		REP(i,len) t[s[i]]=-1;
		REP(i,1000) if(t[i]==-1) d++;
		if(d==1) d++;
		t[s[0]]=1;
		v=0;
		LL res=0;
		REP(i,len) if(t[s[i]]==-1) {
			if(v==1) v++;
			t[s[i]]=v;
			v++;
		}
		REP(i,len) {
			res*=d;
			res+=t[s[i]];
		}
		printf("%llu\n", res);
	}
	return 0;
}
