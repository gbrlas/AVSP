#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

typedef long long ll;

const double PI = atan(1.0) * 4.0;
const int inf = 1000000009;
const double eps = 1e-8;

#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)

using namespace std;

class Gate {
    public:
	bool isAnd;
	bool canChange;
	
	int to[2];	
};

int main() {
    int caseN;
    scanf("%d", &caseN);

    // TODO: check long long carefully.

    for (int cas = 1; cas <= caseN; ++cas) {
	printf("Case #%d: ", cas);

	int M, V;
	cin >> M >> V;

	Gate g[M + 1];

	int gN = (M-1) / 2;
	int G, C;
	for (int i = 0; i < gN; ++i) {	   
	    cin >> G >> C;
//	    cout << G << " " << C << endl;
	    g[i + 1].isAnd = (G == 1);
	    g[i + 1].canChange = (C == 1);
	}

	for (int i = gN; i < M; ++i) {
	    cin >> C;
//	    cout << C << endl;
	    g[i + 1].to[C] = 0;
	    g[i + 1].to[1 - C] = -1;
	}

	for (int i = gN; i >= 1; --i){
	    // and.
	    int v;
	    g[i].to[0] = g[i].to[1] = inf;
	    if (g[i].isAnd) {
		if (g[2*i].to[0] != -1 && g[2*i+1].to[0] != -1) g[i].to[0] = min(g[i].to[0], g[2*i].to[0] + g[2*i+1].to[0]);
		if (g[2*i].to[0] != -1 && g[2*i+1].to[1] != -1) g[i].to[0] = min(g[i].to[0], g[2*i].to[0] + g[2*i+1].to[1]);
		if (g[2*i].to[1] != -1 && g[2*i+1].to[0] != -1) g[i].to[0] = min(g[i].to[0], g[2*i].to[1] + g[2*i+1].to[0]);
		if (g[2*i].to[1] != -1 && g[2*i+1].to[1] != -1) g[i].to[1] = min(g[i].to[1], g[2*i].to[1] + g[2*i+1].to[1]);
	    } else {
		if (g[2*i].to[0] != -1 && g[2*i+1].to[0] != -1) g[i].to[0] = min(g[i].to[0], g[2*i].to[0] + g[2*i+1].to[0]);
		if (g[2*i].to[0] != -1 && g[2*i+1].to[1] != -1) g[i].to[1] = min(g[i].to[1], g[2*i].to[0] + g[2*i+1].to[1]);
		if (g[2*i].to[1] != -1 && g[2*i+1].to[0] != -1) g[i].to[1] = min(g[i].to[1], g[2*i].to[1] + g[2*i+1].to[0]);
		if (g[2*i].to[1] != -1 && g[2*i+1].to[1] != -1) g[i].to[1] = min(g[i].to[1], g[2*i].to[1] + g[2*i+1].to[1]);
	    }

	    if (g[i].canChange) {
		if (!g[i].isAnd) {
		    if (g[2*i].to[0] != -1 && g[2*i+1].to[0] != -1) g[i].to[0] = min(g[i].to[0], g[2*i].to[0] + g[2*i+1].to[0] + 1);
		    if (g[2*i].to[0] != -1 && g[2*i+1].to[1] != -1) g[i].to[0] = min(g[i].to[0], g[2*i].to[0] + g[2*i+1].to[1] + 1);
		    if (g[2*i].to[1] != -1 && g[2*i+1].to[0] != -1) g[i].to[0] = min(g[i].to[0], g[2*i].to[1] + g[2*i+1].to[0] + 1);
		    if (g[2*i].to[1] != -1 && g[2*i+1].to[1] != -1) g[i].to[1] = min(g[i].to[1], g[2*i].to[1] + g[2*i+1].to[1] + 1);
		} else {
		    if (g[2*i].to[0] != -1 && g[2*i+1].to[0] != -1) g[i].to[0] = min(g[i].to[0], g[2*i].to[0] + g[2*i+1].to[0] + 1);
		    if (g[2*i].to[0] != -1 && g[2*i+1].to[1] != -1) g[i].to[1] = min(g[i].to[1], g[2*i].to[0] + g[2*i+1].to[1] + 1);
		    if (g[2*i].to[1] != -1 && g[2*i+1].to[0] != -1) g[i].to[1] = min(g[i].to[1], g[2*i].to[1] + g[2*i+1].to[0] + 1);
		    if (g[2*i].to[1] != -1 && g[2*i+1].to[1] != -1) g[i].to[1] = min(g[i].to[1], g[2*i].to[1] + g[2*i+1].to[1] + 1);
		}
	    }
	    

	    if (g[i].to[0] == inf) g[i].to[0] = -1;
	    if (g[i].to[1] == inf) g[i].to[1] = -1;
	}

	if (g[1].to[V] == -1) cout << "IMPOSSIBLE" << endl;
	else cout << g[1].to[V] << endl;
    }

    return 0;
}
