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

string R[] = 
{"", "", "027",
"143",
"751",
"935",
"607",
"903",
"991",
"335",
"047",
"943",
"471",
"055",
"447",
"463",
"991",
"095",
"607",
"263",
"151",
"855",
"527",
"743",
"351",
"135",
"407",
"903",
"791",
"135",
"647"};

int main()
{
	freopen("small.in", "rt", stdin);
	int tc = 0;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int k;
		cin >> k;
		cout << "Case #" << t + 1 << ": " << R[k] << endl;
	}
	return 0;
}