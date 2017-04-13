
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		string s;
		cin >> s;
		s = "0" + s;
		next_permutation(s.begin(), s.end());
		if (s[0] == '0') s.erase(0, 1);
		cout << "Case #" << i << ": " << s << endl;
	}
	return 0;
}
