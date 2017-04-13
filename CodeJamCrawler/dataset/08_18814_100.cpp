#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "foreach.h"
using namespace std;


void Case()
{
	int n;
	cin >> n;
	vector<long long> v1(n), v2(n);
	foreach (long long& i, v1)
		cin >> i;
	foreach (long long& i, v2)
		cin >> i;
	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());
	long long result = 0;
	for (int i = 0; i < n; ++i)
		result += v1[i] * v2[i];
	cout << result << '\n';
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cout << "Case #" << i << ": ";
		Case();
	}
}
