#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
string s1, s2 ="welcome to code jam"; 
int mem[510][25];
int go(int p1, int p2)
{
	 if(p2 >= s2.length())
		 return 1;
	if(p1 >= s1.length())
		return 0;

	if(mem[p1][p2] != -1)
		return mem[p1][p2];

	int ret = 0;
	if(s1[p1] == s2[p2])
		ret += go(p1 + 1, p2 + 1) % 10000;
	ret += go(p1 + 1, p2) % 10000;

	return mem[p1][p2] = ret % 10000;
}
int main()
{
	ifstream cin("Cs.in");
	ofstream cout("res.txt");
	int n;
	cin >> n;
	getline(cin , s1);

	for(int x = 1; x <= n; x++)
	{
		memset(mem , -1, sizeof(mem));
		getline(cin , s1);
		cout  << "Case #" <<x<<": " << setw(4)<< setfill('0') << go(0,0) % 10000 << endl;
	}

	cout.close();
	return 0;
}