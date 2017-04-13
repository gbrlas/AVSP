#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

char s[100];
int task, cs=0, n;

int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		printf("Case #%d: ", ++cs);
		scanf("%s", s);
		n = strlen(s);
		if ( !next_permutation(s, s+n) ){
			sort( s, s+n );
			int num = 0;
			while ( s[num]=='0' ) num++;
			printf("%c0", s[num]);
			for (int i=1; i<=num; i++)
				printf("0");
			printf("%s\n", s+num+1);
		}else printf("%s\n", s);
	}
	return 0;
}
