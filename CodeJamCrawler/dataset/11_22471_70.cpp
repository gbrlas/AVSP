#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int task, num, n, m, pa[200], pb[200];
int data[110][2], CS=0;
char opt[100];

int main(){
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d", &task); task--;){
		scanf("%d", &num);
		n = m = 0;
		for (int i=1; i<=num; i++){
			scanf("%s", opt);
			if ( opt[0]=='O' ){
				data[i][0] = 0;
				scanf("%d", &pa[++n]);
				data[i][1] = pa[n];
			}else{
				data[i][0] = 1;
				scanf("%d", &pb[++m]);			
				data[i][1] = pb[m];
			}
		}
		int x=1, y=1, np=1, mp=1, nump=1;
		int ret = 0;
		while ( nump<=num ){
			ret++;
//			cout<<x<<' '<<y<<' '<<pa[np]<<' '<<pb[mp]<<endl;
			if ( data[nump][0]==0 && data[nump][1]==x ){
				nump++;
				np++;
				if ( mp<=m ){
					if ( y<pb[mp] ) y++;else
					if ( y>pb[mp] ) y--;
				}
				continue;
			}
			if ( data[nump][0]==1 && data[nump][1]==y ){
				nump++;
				mp++;
				if ( np<=n ){
					if ( x<pa[np] ) x++;else
					if ( x>pa[np] ) x--;
				}
				continue;
			}
			if ( np<=n ){
				if ( x<pa[np] ) x++;else
				if ( x>pa[np] ) x--;
			}
			if ( mp<=m ){
				if ( y<pb[mp] ) y++;else
				if ( y>pb[mp] ) y--;
			}
		}
		printf("Case #%d: %d\n", ++CS, ret);
	}
	return 0;
}
