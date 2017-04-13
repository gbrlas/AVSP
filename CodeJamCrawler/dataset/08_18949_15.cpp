#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	ifstream cin("A-large.in");
	ofstream cout("A-largeout.out");
	int n;
	cin>>n;
	for (int i = 1; i <=n ; i++)
	{
		int p, k, l;
		cin>>p>>k>>l;
		vector<int> v;
		v.reserve(l);
		for (int j = 0; j < l; j++)
		{
			int t;
			cin>>t;
			v.push_back(t);
		}
		sort(v.begin(), v.end(), greater<int>());

		long long q = 0;
		for (int j = 0; j < v.size(); j++)
		{
			q += v[j]*(j/k + 1);
		}

		cout<<"Case #"<<i<<": "<<q<<endl;

	}
	return 0;
}