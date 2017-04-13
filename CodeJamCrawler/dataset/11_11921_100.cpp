#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int charid[0x80];
map<int, char> chartable;

map<int, int> combine;
int oppose[0x80];
int stack[0x80], spt;

int cases, c, d, n;
char buf[4];

int main() {
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);

	for(int i = 0; i < 26; ++i) {
		charid['A' + i] = (1 << i);
		chartable[1 << i] = 'A' + i;
	}
	scanf("%d", &cases);
	for(int I = 1; I <= cases; ++I) {
		combine.clear();
		memset(oppose, 0, sizeof(oppose));
		scanf("%d", &c);
		for(int i = 0; i < c; ++i) {
			scanf("%3s", buf);
			combine[charid[buf[0]] | charid[buf[1]]] = charid[buf[2]];
		}
		scanf("%d", &d);
		for(int i = 0; i < d; ++i) {
			scanf("%2s", buf);
			oppose[buf[0]] |= charid[buf[1]];
			oppose[buf[1]] |= charid[buf[0]];
		}

		spt = -1;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%1s", buf);
			stack[++spt] = charid[buf[0]];
			while(spt > 0 && combine.find(stack[spt] | stack[spt - 1]) != combine.end()) {
				stack[spt - 1] = combine[stack[spt] | stack[spt - 1]];
				--spt;
			}
			for(int i = 0; i < spt; ++i)
				if(oppose[chartable[stack[spt]]] & stack[i]) {
					spt = -1;
					break;
				}
		}
		printf("Case #%d: [", I);
		for(int i = 0; i <= spt; ++i)
			printf("%c%s", chartable[stack[i]], i != spt? ", " : "");
		printf("]\n");
	}
	return 0;
}
