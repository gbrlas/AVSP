#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ifstream cin("small-A.in");
	ofstream cout("small-A.out");
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{	
		int m; 
		cin>>m;
		vector<int> v1, v2;
		v1.reserve(m);
		v2.reserve(m);
		for (int j = 0; j < m; j++)
		{
			int x;
			cin>>x;
			v1.push_back(x);
		}
		for (int j = 0; j < m; j++)
		{
			int x;
			cin>>x;
			v2.push_back(x);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		long long s = 0;
		for (int j = 0; j < m; j++)
		{
			s+=v1[j]*v2[m-j-1];
		}
		cout<<"Case #"<<i<<": "<<s<<endl;
	}
	return 0;
}