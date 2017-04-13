#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
int main()
{
	vector<int> v;
	v.clear();
	ifstream fin("1.txt");
	ofstream fout("2.txt");
	int n;
	fin>>n;
	for(int i=0;i<n;i++)
	{
		v.clear();
		int max,keys,let;
		fin>>max>>keys>>let;
		int inp;
		//cout<<let<<" ";
		for(int j=0;j<let;j++)
		{	
			fin>>inp;
			v.push_back(inp);
			//cout<<v[j]<<" ";
		}
		sort(v.begin(),v.end());
		int ans=0;
		int temp;
		for(int j=let-1;j>=0;j--)
		{
			int t= (let-j-1) / keys;
			int y=t+1;
			//cout<<v[j]<<" ";
			temp = v[j] * y;
			ans+= temp;
		}
		fout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}
