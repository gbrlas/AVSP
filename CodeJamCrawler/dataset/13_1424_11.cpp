#include <cstdio>
int main() {
	int T;
	scanf("%d", &T);
	for(int xd=1; xd<=T; ++xd) {
		int r, t;
		scanf("%d%d", &r, &t);
		int ans=0, i=r+1;
		while( t>=i*2-1 ) t-=i*2-1, ++ans, i+=2;
		printf("Case #%d: %d\n", xd, ans);
	}
}
