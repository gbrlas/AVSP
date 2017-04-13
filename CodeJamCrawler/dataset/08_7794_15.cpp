#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int N, k, iter, ans;
	ofstream aa;
	ifstream bb;
	aa.open("A-small.out");
	bb.open("A-small.in");
	string s;
	bb >> N;
	iter = 0;
	while(N-->0)
	{
		iter++;
		bb >> k >> s;
		ans = s.size();
		vector<int> g;
		for(int i = 0; i < k; i++)
			g.push_back(i);
		do
		{
			string q = s;
			for(int i = 0; i < s.size(); i += k)
				for(int j = 0; j < k; j++)
					q[i+g[j]] = s[i+j];
			int yeah = 1;
			for(int i = 1; i < s.size(); i++)
				if(q[i] != q[i-1])
					yeah++;
			if(ans > yeah)
				ans = yeah;
		} while(next_permutation(g.begin(), g.end()));
		aa << "Case #" << iter << ": " << ans << endl;
	}
	aa.close();
	bb.close();
	return 0;
}