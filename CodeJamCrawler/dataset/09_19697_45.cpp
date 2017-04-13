#include <set>
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
#ifndef _DEBUG
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int t = 1; t <= n; t++)
	{
		string s;
		cin >> s;
		if(!next_permutation(s.begin(), s.end()))
		{
			s += '0';
			sort(s.begin(), s.end());
			int p = 0;
			while(s[p] == '0')
				p++;
			swap(s[0], s[p]);
		}
		cout << "Case #" << t << ": " << s << endl;
	}
	return 0;
}