#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int getit(vector<char> vr, vector<int> vp)
{
	int N = vr.size();
	int ot = 0, op = 1;
	int bt = 0, bp = 1;
	int t = 0;
	for (int i=0; i<N; i++) {
		int r = vr[i];
		int p = vp[i];
		if (r == 'O') {
			t = max(ot+abs(p-op), t)+1;
			ot = t;
			op = p;
		} else {
			t = max(bt+abs(p-bp), t)+1;
			bt = t;
			bp = p;
		}
	}
	return t;
}
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		int N;
		char R; int P;
		cin>>N;
		vector<char> vr;
		vector<int> vp;
		for (int j=0; j<N; j++) {
			cin>>R; cin>>P;
			vr.push_back(R);
			vp.push_back(P);
		}
		cout<<"Case #"<<i<<": "<<getit(vr, vp)<<endl;
	}
}
