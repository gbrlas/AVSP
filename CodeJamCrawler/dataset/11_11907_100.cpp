#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int cases, n;
int color, pt;
int btime, otime, bpt, opt;

int main() {
	//freopen("A-small-attempt0.in", "r", stdin);
	//freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		scanf("%d", &n);
		btime = otime = color = 0;
		bpt = opt = 1;
		for(int i = 0; i < n; ++i) {
			scanf("%s%d", &color, &pt);
			if(color == 'O') {
				if(otime + abs(pt - opt) < btime)
					otime = btime;
				else
					otime += abs(pt - opt);
				++otime;
				opt = pt;
			}
			else {
				if(btime + abs(pt - bpt) < otime)
					btime = otime;
				else
					btime += abs(pt - bpt);
				++btime;
				bpt = pt;
			}
		}
		printf("Case #%d: %d\n", I, max(otime, btime));
	}
	return 0;
}
