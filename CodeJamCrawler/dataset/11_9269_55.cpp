#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define FOR(i,s,n) for(int(i)=(s);(i)<(n);(i)++)
#define DFOR(i,s,n) for(int(i)=(s);(i)>(n);(i)--)
#define SZ(v) (int)(v).size()
#define RESET(v,n) memset((v),(n),sizeof((v)))
#define PII pair<int,int>
#define PFF pair<double,double>
#define eps 1e-8
#define isEQF(f,a) (abs((f)-(a)) < eps)
#define LL long long
#define DEBUG puts("OK")
#define x first
#define y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
using namespace std;

int mx[4] = {-1,0,1,0};
int my[4] = {0,1,0,-1};

inline void OPEN(string s) {
	freopen((s+ ".in").c_str(), "r",stdin );
	freopen((s+".out").c_str(), "w",stdout);
}

int main() {
	int n;
	scanf("%d",&n);
	FOR(ii,0,n) {
		bool cancomb[255][255];
		bool oppose[255][255];
		bool canOppose[255];
		char combine[255][255];
		char magic[110];
		int nCombine,nOppose, nMagic;
		
		RESET(cancomb,false);
		RESET(oppose,false);
		RESET(canOppose,false);
		
		scanf("%d", &nCombine);
		FOR(i,0,nCombine){
			char comb[10];
			scanf("%s",comb);
			cancomb[comb[0]][comb[1]] = true;
			cancomb[comb[1]][comb[0]] = true;
			combine[comb[0]][comb[1]] = comb[2];
			combine[comb[1]][comb[0]] = comb[2];
			// cout << comb[0] << comb[1] << combine[comb[0]][comb[1]];
			// cout << comb[1] << comb[0] << combine[comb[1]][comb[0]];
		}
		
		scanf("%d", &nOppose);
		FOR(i,0,nOppose) {
			char comb[10];
			scanf("%s",comb);
			canOppose[comb[0]] = true;
			canOppose[comb[1]] = true;
			oppose[comb[0]][comb[1]] = true;
			oppose[comb[1]][comb[0]] = true;
		}
		scanf("%d",&nMagic);
		scanf("%s",magic);
		int i=0;
		string ans = "";
		while (i < nMagic) {
			if (ans.size()>0 && cancomb[ans[ans.size()-1]][magic[i]]) {
				ans[ans.size()-1] = combine[ans[ans.size()-1]][magic[i]];
				i++;
			} else {
				bool opposing = false;
				for (int j=ans.size()-1; j>=0; j--) {
					if (oppose[magic[i]][ans[j]]) {
						ans = "";
						opposing = true;
						break;
					}
				}
				if (!opposing) {
					ans+=magic[i];
				}
				i++;
			}
		}
		
		printf("Case #%d: [",ii+1);
		int k =0;
		FOR(i,0,ans.size()) {
			k++;
			if (k!=1) {
				cout << ", ";
			}
			cout << ans[i];
		}
		printf("]\n");
	}
	return 0;
}
