#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w+", stdout);

	int T;
	cin >> T;
	for(int t=0; t < T; ++t)
	{
		int N, L, H;
		cin >> N >> L >> H;
		
		vector<int> n;
		for(int i=0; i < N; ++i)
		{
			int temp;
			cin >> temp;
			n.push_back(temp);
		}

		bool f = true;
		for(int i=L; i <= H; ++i)
		{
			f = true;
			for(int j=0; j < n.size(); ++j)
			{
				if( (n[j] % i != 0) && (i % n[j] != 0 ) )
				{
					f = false;
					break;
				}
			}
			if(f)
			{
				cout << "Case #" << (t+1) << ": ";
				cout << i << endl;
				break;
			}
		}
		if(!f)
			cout << "Case #" << (t+1) << ": NO" << endl;
	}
}