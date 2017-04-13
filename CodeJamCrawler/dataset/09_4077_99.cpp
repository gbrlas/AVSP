#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
#define rep(i,n) for(int i=0,_n=(n);i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)




int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A-small.out");

	int l, d, n;
	cin >> l >> d >> n;

	vector<string> words(d);
	
	rep(i, d) cin >> words[i];

	string s;
	rep(i, n)
	{
		vector<int> patter(l, 0);
		cin >> s;
		bool open = false;
		int ind = -1;
		rep(j, s.size())
		{
			if (s[j] == '(')
			{
				open = true;
				++ind;
				continue;
			}
			if (s[j] == ')')
			{
				open = false;
				continue;
			}
			if (! open)
			{
				++ ind;
			}
			int let = s[j] - 'a';
			patter[ind] |= (1 << let);
		}
		int matchCount = 0;
		rep(k, d)
		{
			bool match = true;
			rep(j, words[k].size())
			{
				int let = words[k][j] - 'a';
				if (!(patter[j] & (1 << let)))
				{
					match = false;
					break;
				}
			}
			if (match) ++ matchCount;
		}

		cout << "Case #" << (i  + 1)<< ": " << matchCount << '\n';

	}

	return 0;
}