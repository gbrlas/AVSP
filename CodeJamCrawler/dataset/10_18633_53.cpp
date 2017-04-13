#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll doit(int R, int k, int N, vector<int> &g)
{
	int gidx = 0;
	int nk = 0;
	int gsize = g.size();
	while (nk+g[gidx] < k) {
		nk += g[gidx++];
		if (gidx == gsize)
			break;
	}
	if (gidx == g.size())
		return 1ll*nk*R;

	gidx = 0;
	vector<int> nks;
	while (true) {
		nk = 0;
		while (nk+g[gidx] <= k) {
			nk += g[gidx++];
			if (gidx >= gsize)
				gidx -= gsize;
		}
		nks.push_back(nk);
		if (nks.size() == R) {
			ll res = 0;
			for (int i=0; i<nks.size(); i++)
				res += nks[i];
			return  res;
		}
		if (gidx == 0) {
			ll res = 0;
			for (int i=0; i<nks.size(); i++)
				res += nks[i];
			res *= R/nks.size();
			for (int i=0; i<R%nks.size(); i++)
				res += nks[i];
			return res;
		}
	}
}

int main(void)
{
	int T;
	cin>>T;
	vector<int> g;
	for (int i=1; i<=T; i++) {
		int R, k, N, gi;
		cin>>R; cin>>k; cin>>N;
		g.clear();
		for (int j=0; j<N; j++) {
			cin>>gi;
			g.push_back(gi);
		}
		ll res = doit(R, k, N, g);
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
}
