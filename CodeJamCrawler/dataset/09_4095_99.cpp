#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define rep(i, n) for(int i = 0, _n = (n); i < _n; ++i)



int main()
{
	ifstream cin("C-small-attempt0.in");
	ofstream cout("output.out");
	int tt;
	cin >> tt;
	const string welcomeStr = "welcome to code jam";
	rep(t, tt)
	{
		string s;
		getline(cin, s);
		if (s.empty()){
			-- t;
			continue;
		}
		int n = welcomeStr.size();
		vector<int> count(n + 1, 0);
		count[0] = 1;
		rep(i, s.size())
		{
			char ch = s[i];
			for(int k = n; k > 0; --k)
			{
				if (welcomeStr[k - 1] == ch)
				{
					count[k] += count[k - 1];
					count[k] %= 10000;
				}
			}
		}

		stringstream ss;
		ss << "0000" << count[n];
		string r = ss.str();
		r = r.substr(r.size() - 4);

		cout << "Case #" << (t + 1) << ": " << r << endl;
	}

	return 0;
}
