#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ifstream cin("B-small-attempt0.in");
	ofstream cout("output.txt");
	int tc;
	cin >> tc;
	
	for (int t = 1; t <= tc; ++t)
	{
		string s;
		cin >> s;

		cout << "Case #" << t << ": ";

		bool isDec = true;
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] > s[i - 1])
			{
				isDec = false;
				break;
			}
		}

		if (isDec)
		{
			int sI = 0;
			for (int i = 1; i < s.size(); ++i)
			{
				if (s[i] < s[sI] && s[i] != '0')
				{
					sI = i;
				}
			}

			char c = s[sI];
			s.erase(s.begin() + sI);
			s.push_back('0');
			sort(s.begin(), s.end());
			s = c + s;
			cout << s << endl;
		}
		else
		{
			next_permutation(s.begin(), s.end());
			cout << s << endl;
		}
	}


	return 0;
}