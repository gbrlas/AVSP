#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>


using namespace std;

int main()
{
	int tc, t = 0;
	char tmp[2048];
	for (cin >> tc; t < tc; t++)
	{
		cin.getline(tmp, 2048);
		string s, s2;
		cin >> s;
		s2 = s;
		string ss = s;
		sort(ss.begin(), ss.end());
		int z = 0;
		for (z = 0; z < ss.size(); z++ )
			if (ss[z] != '0') break;
		if (z != 0) {
			if (z != ss.length() - 1)
				ss = ss[z] + string(z, '0') + ss.substr(z + 1);
			else 
				ss = ss[z] + string(z, '0');
		}
		if (next_permutation(s.begin(), s.end()))
			s2 = s;
		else {
			if (s.length() != 1)
				s2 = ss.substr(0, 1) + "0" + ss.substr(1);
			else
				s2 = ss + "0";
			
		}
		cout << "Case #" << t + 1 << ": " << s2 << endl;
	}
	return 0;
}

