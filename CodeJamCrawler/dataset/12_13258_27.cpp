#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 10007;

int l[N];
int d[N];
int b[N];

bool test(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", d+i, l+i);
		b[i] = 0;
	}
	int L;
	scanf("%d", &L);
	b[1] = min(d[1], l[1]);
	for(int i=1; i<=n; i++){
		if(d[i] + b[i] >= L) return true;
		int j = i+1;
		while(j <= n && d[i] + b[i] >= d[j]){
			b[j] = max(b[j], min(l[j], d[j] - d[i]));
			j++;
		}
	}

	return false;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		printf("Case #%d: %s\n", i, test()?"YES":"NO");
	}
}
