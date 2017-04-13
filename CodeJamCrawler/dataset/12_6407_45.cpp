#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
string to_s(int n)
{
	char ss[20];
	sprintf(ss, "%d", n);
	return ss;
}
string shift(const string& s, int si)
{
	string r = s;
	for(int i = 0; i < s.size(); i++)
		r[i] = s[(i + si) % s.size()];
	return r;
}
void test(int tn)
{
	int a, b;
	cin >> a >> b;
	string bs = to_s(b);
	int result = 0;
	for(int n = a; n < b; n++)
	{
		string s = to_s(n);
		set<string> used;
		for(int j = 0; j < s.size(); j++)
			if(s[j] >= s[0])
			{
				string r = shift(s, j);
				if(r > s && (r.length() < bs.length() || (r.length() == bs.length() && r <= bs)) && used.find(r) == used.end())
				{
					result++;
					used.insert(r);
				}
			}
	}
	cout << "Case #" << tn << ": " << result << "\n";
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
		test(i);
	return 0;
}
