#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=805;

typedef long long LL;
LL dx[maxn], dy[maxn], sum;
int n, task;

int main(){
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int tk=1; tk<=task; tk++){
		scanf("%d", &n);
		for (int i=1; i<=n; i++) cin>>dx[i];
		for (int i=1; i<=n; i++) cin>>dy[i];
		sort( dx+1, dx+n+1 );
		sort( dy+1, dy+n+1 );
		sum = 0;
		for (int i=1, j=n; i<=n; i++, j--){
			sum += (LL)dx[i]*(LL)dy[j];
		}
		cout<<"Case #"<<tk<<": "<<sum<<endl;
	}
	return 0;
}
