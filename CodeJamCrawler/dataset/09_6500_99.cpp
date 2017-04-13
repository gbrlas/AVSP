#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string word = "welcome to code jam";

	string tmp;
	getline(cin, tmp);
	for (int t = 0; t<n; ++t)
	{
		
		string text;
		getline(cin, text);
		int f[510][20];

// 		cout << text << " " << word << endl;
		for (int i = 0; i<text.length(); ++i)
			for (int j = 0; j<word.length(); ++j)
			{
				f[i][j] = 0;
				if (text[i] == word[j])
				{
					
					if (j == 0)
					{
						f[i][j] = 1;
					}
					else
					{
						for (int k = 0; k<i; ++k)
							f[i][j] += f[k][j-1] % 10000;
					}
				}
// 				if (f[i][j] != 0)
// 					cout << "f[" << i << "][" << j << "] = " << f[i][j] << endl;
			}
		int ans = 0;
		for (int i = 0; i<text.length(); ++i)
			ans += f[i][word.length()-1] % 10000;
		ans %= 10000;

		ostringstream tmp;
		tmp << ans;
		string ans_s = tmp.str();
		for (; ans_s.length() < 4; ans_s = '0' + ans_s)
			{}
		
		cout << "Case #" << t+1 << ": " << ans_s << endl;
		
	}
}
