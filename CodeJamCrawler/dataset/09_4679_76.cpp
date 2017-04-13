#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int L, D, N;

vector <string> dict;
string s;

bool Find(char c , int i, int & mask)
{
	bool flag = false;
	for(int x = 0; x < dict.size(); x++)
		if(dict[x][i] == c && (mask & (1 << x)))
			flag = true; 
		else
			if(mask & (1 << x))
				mask -= (1<<x);

	return flag;

}

int go(int i, int dicI, int mask)
{
	if(i >= s.length())
	{
		if(dicI != L) return 0;

		int ret = 0;
		for(int x = 0; x < D; x++)
			if((1 << x) & mask)
				ret++;
		return ret;
	}
	if(dicI >= L) return 0;

	int nextI;
	if(s[i] == '(')
	nextI = s.find_first_of( ')', i) + 1;
	else
		nextI = i + 1;

	int ret =0;

	int tmp;
	for(int x = i; x < nextI; x++)
	{
		if(s[x] == '(' || s[x] == ')') continue;
	
		tmp = mask;
		if(Find(s[x], dicI, tmp))
		ret += go(nextI, dicI +1, tmp);
	}
	return ret;


}
int main()
{
	ifstream cin("As.in");

	ofstream cout("boo.txt");
	cin >> L >> D >> N;

	int ff = D;
	while(ff--)
	{
		cin >> s;
		dict.push_back(s);
	}

	for(int x = 1; x <= N; x++)
	{
		cin >> s;
		cout << "Case #" <<x <<": " << go(0,0,(1 << D)-1) << endl;
	}

	cout.close();
	return 0;
}