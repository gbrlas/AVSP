#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int mem[500][19];
string s, 	t = "welcome to code jam"; 
int getNumOfThis(int ps, int pt)
{
	if (pt == t.length())
		return 1;
	if (ps == s.length())
		return 0;
	if(mem[ps][pt] != -1)
		return mem[ps][pt];

	mem[ps][pt] = 0;
	if (s[ps] == t[pt])
		mem[ps][pt] += getNumOfThis(ps+1, pt+1) % 10000;

	mem[ps][pt] += getNumOfThis(ps+1, pt) % 10000;
	return mem[ps][pt];
}

int solve(string s)
{
	return getNumOfThis(0, 0);

}
int main()
{
//	ifstream cin("C-small-attempt0.in");
	ifstream cin("C-large.in");
	ofstream cout("5.txt");
	int N, ans;
	cin >> N;
	cin.get();
	memset(mem, -1, sizeof(mem));
	for (int i = 1; i <= N; i++)
	{
		getline(cin, s);
		ans = solve(s) % 10000;

		cout << "Case #" << i << ": ";
		if(ans < 10)
			cout << "000";
		else
		if(ans < 100)
			cout << "00";
		else
		if(ans < 1000)
			cout << "0";
		cout << ans << endl;
		memset(mem, -1, sizeof(mem));
	}


	return 0;
}