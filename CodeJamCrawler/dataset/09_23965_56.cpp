#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		cout << "Case #" << (t + 1) << ": ";
		int N;
		cin >> N;
		stringstream p;
		p << N;
		char c;
		vector<int> asdf;
		while(p >> c)
		{
			asdf.push_back(c - '0');
		}
		if(next_permutation(asdf.begin(), asdf.end()))
		{
			cerr << "got next_perm " << N << endl;
		}
		else
		{
			cerr << "no next_perm " << N << endl;
			asdf.push_back(0);
			sort(asdf.begin(), asdf.end());
			for(int i = 0; i < asdf.size(); i++)
			{
				if(asdf[i] != 0)
				{
					swap(asdf[0], asdf[i]);
					break;
				}
			}
		}
		copy(asdf.begin(), asdf.end(), ostream_iterator<int>(cout, ""));
		cout << endl;
	}
}
