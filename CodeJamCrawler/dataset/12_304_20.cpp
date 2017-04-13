#include <cstdio>
#include <algorithm>
#include <set>
#define N 1005
#define mp(a, b) make_pair(a, b)
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
using namespace std;

int t, n, w, l, dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
struct pt{
	int r, i, y, x;
	bool operator < (const pt &T) const{ return r > T.r;}
} p[N];
LL sqr(int a){
	return (LL) a * a;
}
bool cmp(pt a, pt b){ return a.i < b.i;}
set<pair<int, int> > s;
set<pair<int, int> >::iterator it;

int main(){
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("B-out.txt", "w", stdout);
	
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d:", z);
		scanf("%d %d %d", &n, &w, &l);
		fi(i, 0, n) scanf("%d", &p[i].r), p[i].i = i;
		sort(p, p + n);
		s.clear();
		s.insert(mp(0, 0));
		
		fi(i, 0, n){
			for(it = s.begin(); it != s.end(); it++){
				bool ook = 0;
				int y = it->first, x = it->second, ty, tx;
				
				fi(j, 0, 9){
					ty = y + p[i].r * dy[j];
					tx = x + p[i].r * dx[j];
					if(ty < 0 || tx < 0 || ty > l || tx > w) continue;
					
					bool ok = 1;
					fi(k, 0, i) if(sqr(p[k].y - ty) + sqr(p[k].x - tx) < sqr(p[i].r + p[k].r)){
						ok = 0;
						break;
					}
					
					if(ok){
						p[i].y = ty; p[i].x = tx;
						ook = 1;
						break;
					}
				}
				
				if(ook) break;
			}
			
			fi(j, 0, 9) s.insert(mp(p[i].y + p[i].r * dy[j], p[i].x + p[i].r * dx[j]));
		}
		
		sort(p, p + n, cmp);
		fi(i, 0, n) printf(" %d %d", p[i].x, p[i].y);
		puts("");
	}
	
	scanf("\n");
}
