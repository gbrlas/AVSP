#include <cstdio>
#include <algorithm>
#include <vector>

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

char buffer[21], buffer2[21];

void solve() {
	
	int l = strlen(buffer), n = atoi(buffer);
	vector <int> nrs;
	
	sort(buffer, buffer + l);
	do {
		nrs.push_back(atoi(buffer));
	} while ( next_permutation(buffer, buffer + l) );
	
	sort(nrs.begin(), nrs.end());
	FOR(i,0,nrs.size()) {
		if (nrs[i] == n) {
			if (i != nrs.size() - 1) {
				printf("%d\n", nrs[i+1]);
			}
			else {
				FOR(i,0,nrs.size()) {
					sprintf(buffer, "%d", nrs[i]);
					buffer2[0] = buffer[0];
					buffer2[1] = '0';
					FOR(j,1,strlen(buffer))
						buffer2[j+1] = buffer[j];
					buffer2[strlen(buffer)+1] = '\0';
					nrs[i] = atoi(buffer2);
				}
				sort(nrs.begin(), nrs.end());
				FOR(i,0,nrs.size()) if (nrs[i] > n) { printf("%d\n", nrs[i]); return;}
			}
		}
	}
}

int main() {
	int n;

	scanf("%d", &n);
	FOR(i,0,n) {
		buffer[0] = '\0';
		scanf("%s", buffer);
		printf("Case #%d: ", i+1);
		solve();
	}

	return 0;
}