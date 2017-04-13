#include <cstdio>
#include <cstring>
#include <algorithm>
#define REP(i,n) for(int i = 0;i<n;i++)

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	char s[100];
	REP(z,T) {
		scanf("%s", s);
		printf("Case #%d: ", z+1);
		int len = strlen(s);
		if(len==1) {printf("%s0\n", s); continue;}
		int b = len-2;
		for(;b>=0;b--) {
			if(s[b]<s[b+1]) break;
		}
		if(b==-1) {
			sort(s,s+len);
			for(b=0;b<len;b++) {
				if(s[b]!='0')
					break;
			}
			printf("%c", s[b]);
			s[b]='0';
			printf("%s\n", s);
		}
		else {
			sort(s+b+1,s+len);
			REP(i,len-b-1) if(s[b]<s[b+i+1]) {swap(s[b],s[b+i+1]); break;}
			sort(s+b+1,s+len);
			printf("%s\n", s);
		}
	}
	return 0;
}
