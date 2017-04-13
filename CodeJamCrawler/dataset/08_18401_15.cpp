#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

string getit(void)
{
	int N, M, T, x,y;
	scanf("%d", &N);
	scanf("%d", &M);
	vector< vector<pair<int,int> > > vvp;
	for (int i=0; i<M; i++) {
		vector<pair<int,int> > vp;
		scanf("%d", &T);
		pair<int,int> pii;
		for (int j=0; j<T; j++) {
			scanf("%d %d", &x, &y);
			pii.first = x;
			pii.second = y;
			vp.push_back(pii);
		}
		vvp.push_back(vp);
	}
	for (int i=0; i<(1<<N); i++) {
		int nomatch=0;
		for (int j=0; j<M; j++) {
			int find = 0;
			for (int k=0; k<vvp[j].size(); k++) {
				int x = vvp[j][k].first;
				int y = vvp[j][k].second;
				if ( ((i>>(x-1))&1) == y) {
					find = 1;
					break;
				}
			}
			if (find == 0) {
				nomatch=1;
				break;
			}
		}
		if (nomatch)
			continue;
		string res = "";
		for (int j=0; j<N; j++) {
			if (i & (1<<(j)))
					res += "1 ";
			else
					res += "0 ";
		}
		return res.substr(0, res.length()-1);
	}
	return "IMPOSSIBLE";
}

int main(void)
{
	int ncase;

	scanf("%d", &ncase);
	for (int i=0; i<ncase; i++) {
		string res = getit();
		printf("Case #%d: %s\n", i+1, res.c_str());
	}
	return 0;
}
