#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


int main()
{

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	
	int t;
	cin >> t;
	for(int test=0; test<t; test++)
	{
		
		int n;
		cin >> n;
		vector<int> orange, blue;
		vector<char> q(n);
		int posO = 1, posB = 1;
		for(int i=0; i<n; i++)
		{
			int temp;
			cin >> q[i] >> temp;
			
			if(q[i]=='O')
			{
				orange.push_back(labs(temp - posO));
				posO = temp;
			}
			else
			{
				blue.push_back(labs(temp - posB));
				posB = temp;
			}
		}
		orange.push_back(-100);
		blue.push_back(-100);

		int res = 0, io = 0, ib = 0;
	

		for(int i=0;i<n; i++)
		{
			if(q[i]== 'O')
			{
				int inc = 1;
				if(orange[io] > 0)
					inc += orange[io];
				res += inc;
				blue[ib] -= inc;
				++io;
			}
			else
			{
				int inc = 1;
				if(blue[ib] > 0)
					inc += blue[ib];
				res += inc;
				orange[io] -= inc;
				++ib;
			}
		}
		cout << "Case #" << test+1 << ": " << res << "\n";
	}

	return 0;
}