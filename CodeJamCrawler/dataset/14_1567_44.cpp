#include <cstdio>
int a[2][5];
int main() {
	int t, r;
	scanf("%d", &t);
	for(int cn=1; cn<=t; ++cn) {
		scanf("%d", &r);
		for(int i=1; i<=4; ++i)
			for(int j=1; j<=4; ++j)
				if( i==r ) 
					scanf("%d", &a[0][j]);
				else scanf("%*d");
		scanf("%d", &r);
		for(int i=1; i<=4; ++i)
			for(int j=1; j<=4; ++j)
				if( i==r ) 
					scanf("%d", &a[1][j]);
				else scanf("%*d");
		int cnt=0, ans=-1;
		for(int i=1; i<=4; ++i)
			for(int j=1; j<=4; ++j)
				if( a[0][i]==a[1][j] ) ++cnt, ans=a[0][i];
		if( cnt==0 ) printf("Case #%d: Volunteer cheated!\n", cn);
		else if( cnt>1 ) printf("Case #%d: Bad magician!\n", cn);
		else printf("Case #%d: %d\n", cn, ans);
	}
}