#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cctype>
using namespace std;

int n,m;
vector<int> type[2000], kind[2000];

void solveEasy() {
	int best=-1;
	vector<int> ret;
	for(int i=0;i<(1<<n);i++) {
		int ones=__builtin_popcount(i);
		if(best!=-1&&ones>=best) continue;
		bool ok=1;
		for(int j=0;j<m;j++) {
			bool got=0;
			for(int k=0;k<type[j].size();k++) {
				int idx=type[j][k];
				if(kind[j][k]==0&&!(i&(1<<idx))) { got=1; break; }
				else if(kind[j][k]==1&&(i&(1<<idx))) { got=1; break; }
			}
			if(!got) { ok=0; break; }
		}
		if(!ok) continue;
		vector<int> tmp;
		for(int j=0;j<n;j++) if(i&(1<<j)) tmp.push_back(1);
		else tmp.push_back(0);
		ret=tmp;
		best=ones;
	}
	if(best==-1) { cout<<" IMPOSSIBLE"<<endl; return; }
	for(int i=0;i<n;i++) cout<<' '<<ret[i];
	cout<<endl;
}

int main() {
	int cases;
	cin>>cases;
	int x,y;
	for(int tc=1;tc<=cases;tc++) {
		cin>>n>>m;
		for(int i=0;i<m;i++) {
			int t;
			cin>>t;
			type[i]=vector<int>(t);
			kind[i]=vector<int>(t);
			for(int j=0;j<t;j++) {
				cin>>x>>y;
				x--;
				type[i][j]=x;
				kind[i][j]=y;
			}
		}
		cout<<"Case #"<<tc<<":";
		solveEasy();
	}
}
