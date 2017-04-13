#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
using namespace std;

int getit(vector<int> &values)
{
	int N = values.size();
	int xorsum = 0, sum = 0;
	int minv = 1000001;

	for (int i=0; i<N; i++) {
		xorsum ^= values[i];
		sum += values[i];
		if (values[i] < minv)
			minv = values[i];
	}
	if (xorsum == 0)
		return sum-minv;
	else
		return 0;
}
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		int N, C;
		cin>>N;
		vector<int> values;
		for (int j=0; j<N; j++) {
			cin>>C;
			values.push_back(C);
		}
		cout<<"Case #"<<i<<": ";
		int res = getit(values);
		if (res == 0)
			cout<<"NO"<<endl;
		else
			cout<<res<<endl;
	}
}
