#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

map<string, int> mapa;

int main() {
	int tcase;
	scanf("%d", &tcase);
	for(int zz=1; zz<=tcase; zz++) {
		mapa.clear();
		int N;
		scanf("%d", &N);
		int przed[340][3];
		int v =0;
		for(int i=0; i<N; i++) {
			char buff[100];
			int A, B;
			scanf(" %s%d%d", buff, &A, &B);
			if(mapa.find(string(buff))!=mapa.end()) {
				przed[i][0] = mapa[buff];
			} else {
				mapa[buff] = v;
				przed[i][0] = v++;
			}
			przed[i][1] = A;
			przed[i][2] = B;
		}

		int best = N+100;
		int ile_kol = mapa.size();
		for(int pie =0; pie<ile_kol; pie++) {
			for(int dru = min(ile_kol-1, pie+1); dru < ile_kol; dru++) {
				for(int trz = min(ile_kol-1, dru+1); trz < ile_kol; trz++) {

					vector<pair<int, int> >  prz;
					priority_queue<int> kol;
					for(int i=0; i< N; i++) {
						if(przed[i][0] == pie
								|| przed[i][0] == dru 
								|| przed[i][0] == trz) {
							prz.push_back(make_pair(przed[i][1], przed[i][2]));
						}
					}
					sort(prz.begin(), prz.end());
					int pos = 0;
					for(; pos < (int)prz.size() && prz[pos].first==1; pos++) {
						kol.push(prz[pos].second);
					}

					if(kol.empty()) continue;
					int sol = 1;
					int mamy = kol.top();
					kol.pop();
					while(mamy != 10000) {
						for(; pos<(int)prz.size() && prz[pos].first <= mamy+1; pos++) {
							kol.push(prz[pos].second);
						}
						if(kol.empty()) {
							break;
						}
						int g = kol.top();
						if(g<=mamy) break;
						mamy = g;
						sol++;
					}
					if(mamy < 10000) continue;

					best = min(best, sol);
				}
			}
		}

		printf("Case #%d: ", zz);
		if(best <= N) {
			printf("%d\n", best);
		} else {
			puts("IMPOSSIBLE");
		}

	}
}
