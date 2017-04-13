#include <cstdio>
#include <algorithm>
#define N 1005
#define M 1000002013
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, m;
LL ans;
struct odp{
	int a, b;
	bool operator < (const odp &T) const{
		return a < T.a;
	}
} l[N], r[N];

LL fuck(int x){
	return (LL) x * (x - 1) / 2;
}

int main(){
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		ans = 0;
		scanf("%*d %d", &m);
		fi(i, 0, m){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			l[i].a = a;
			r[i].a = b;
			l[i].b = c;
			r[i].b = c;
			ans = (ans - fuck(b - a) % M * c % M) % M;
		}
		
		sort(l, l + m);
		sort(r, r + m);
		
		fi(i, 0, m){
			int j = m - 1;
			while(l[j].a > r[i].a) j--;
			while(r[i].b){
				int x = min(r[i].b, l[j].b);
				r[i].b -= x;
				l[j].b -= x;
				ans = (ans + fuck(r[i].a - l[j].a) % M * x % M) % M;
				j--;
			}
		}
		
		ans = (ans + M) % M;
		printf("Case #%d: %I64d\n", z, ans);
	}
	scanf("\n");
}
