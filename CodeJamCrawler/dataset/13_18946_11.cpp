#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
using namespace std;


int solve()
{
	string s;
	unsigned long long int r, t;
	int n, m;
	unsigned long long int count = 0;
	
	cin >> s;
	istringstream istr(s);
	istr >> r;	//atoi‘ã‚í‚è
	cin >> s;
	istringstream istr2(s);
	istr2 >> t;

	while(1)
	{
		if(count*(2*count + 2*r - 1) > t)
			break;
		count++;
	}
	count--;

	


	return count;
}



void main()
{
	int m;
	string s;
	unsigned long long int hoge;

	cin >> s;
	istringstream istr(s);
	istr >> m;

	for(int i = 0; i < m; i++)
	{
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
	}
}