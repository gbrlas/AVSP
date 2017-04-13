#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int m, int n)
{
	while (m > 0) {
		int t = m;
		m = n%m;
		n = t;
	}
	return n;
}
int main(void)
{
	int C;
	cin>>C;
	for (int i=1; i<=C; i++) {
		int N;
		cin>>N;
		vector<int> t(N);
		for (int j=0; j<N; j++)
			cin>>t[j];

		sort(t.begin(),t.end());
		int res;
		if (N == 2) {
			int d = t[1] - t[0];
			if (t[0]%d == 0)
				res = 0;
			else
				res = d - t[0]%d;
		} else {
			int d1 = t[1] - t[0];
			int d2 = t[2] - t[1];
			int d = gcd(d1, d2);
			if (t[0]%d == 0)
				res = 0;
			else
				res = d - t[0]%d;
		}
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
}
