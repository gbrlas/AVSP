#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		
		string s;
		cin >> s;
		vector<int> v;
		for (int i = 0; i < s.size(); ++i)
			v.push_back(s[i] - '0');
		
		//reverse(v.begin(), v.end());
		vector<int> next_v = v;
		next_permutation(next_v.begin(), next_v.end());
		int res = 0;
		if (next_v <= v)
		{
			next_v.resize(0);
			sort(v.begin(), v.end());
			int i;
			for (i = 0; v[i] == 0; ++i);
			next_v.push_back(v[i]);
			for (int j = 0; v[j] == 0; ++j)
				next_v.push_back(0);
			next_v.push_back(0);
			for (++i; i < v.size(); ++i)
				next_v.push_back(v[i]);
		}
		printf("Case #%d: ", t + 1);
		for (int i = 0; i < next_v.size(); ++i)
			printf("%d", next_v[i]);
		printf("\n");
	}
	return 0;
}