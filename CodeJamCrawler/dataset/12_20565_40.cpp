# include <iostream>
# include <string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	string pat = "yhesocvxduiglbkrztnwjpfmaq";

	string s;
	getline(cin, s);
	for (int i = 0; i < T; ++i)
	{
		getline(cin, s); //cin >> s;
		for (int j = 0; j < s.length(); ++j)
			s[j] = (s[j] != ' ') ? pat[int(s[j] - 'a')] : ' ';
		cout << "Case #" << i +1 << ": " << s << endl;
	}

	return 0;
}