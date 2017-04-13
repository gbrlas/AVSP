#include <cstdio>
#include <utility>
#include <iostream>
using namespace std;
const int maxn=200;

typedef pair <int, int> PI;
PI d[2][maxn];
int num[2], ret[2], fnd[2][maxn];
int t, n, m, task, ret1, ret2, o;

int find( int lim, int o ){
	for (int i=1; i<=num[o]; i++)
	if ( !fnd[o][i] && lim<=d[o][i].first ) return i;
	return -1;
}

int read(){
	char ch;
	while ( scanf("%c", &ch), !('0'<=ch && ch<='9') );
	int sum = ch-'0';
	scanf("%c", &ch); 
	sum = sum*10+ch-'0';
	sum *= 60;
	scanf("%c", &ch);
	scanf("%c", &ch);
	int sum2=ch-'0';
	scanf("%c", &ch);
	sum2 = sum2*10+ch-'0';
	sum += sum2;
	return sum;
}

int main() {	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n", &task);
	for (int tk=1; tk<=task; tk++){
		memset( fnd, 0, sizeof(fnd) );
		scanf("%d%d%d\n",&t, &n, &m);
		for (int i=1; i<=n; i++){
			int a, b;
			a = read(); b = read();
			d[0][i] = make_pair( a, b );
//			cout<<i<<' '<<a<<' '<<b<<endl;
		}
		for (int i=1; i<=m; i++){
			int a, b;
			a = read(); b = read();
			d[1][i] = make_pair( a, b );
//			cout<<i<<' '<<a<<' '<<b<<endl;
		}
		sort( d[0]+1, d[0]+n+1 );
		sort( d[1]+1, d[1]+m+1 );
		num[0] = n, num[1] = m;
		ret[0] = ret[1] = 0;
		while ( find(0,0)!=-1 || find(0,1)!=-1 ){
//			cout<<find( 0, 0 )<<' '<<find( 0, 1 )<<endl;
//			cout<<d[1][find(0,1)].first <<' '<< d[0][find(0,0)].first<<endl;
			int o;
			if ( find(0,0)==-1 || find(0,1)!=-1 && d[1][find(0,1)].first < d[0][find(0,0)].first )
				o = 1;else o = 0;
			ret[o]++;
			int T=0;
			while ( true ){
				int tmp = find(T,o);
				if ( tmp == -1 ) break;
				fnd[o][tmp] = true;
				T = d[o][tmp].second + t;
				o ^= 1;
			}
//			for (int i=1; i<=num[0]; i++)cout<<fnd[0][i]<<' ';cout<<endl;
//			for (int i=1; i<=num[1]; i++)cout<<fnd[1][i]<<' ';cout<<endl;cout<<endl;
		}
		printf("Case #%d: %d %d\n", tk, ret[0], ret[1]);
	}
	return 0;
}
