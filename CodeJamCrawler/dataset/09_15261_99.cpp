#include <iostream>
#include <string>

using namespace std;

int L, D, N;
const int NABC = 'z'-'a'+1;
string *dict; 

bool *ext;

void readinput()
{
	cin >> L >> D >> N;
	dict = new string[D];
	ext = new bool[L*NABC];

	for(int d=0; d<D; d++)
		getline(cin >> ws, dict[d]);
}

void processexp(string &exp)
{
	for(int i=0; i<L*NABC; i++) ext[i] = false;
	bool *base = ext;
	bool inpar = false;
	for(int i=0; i<exp.length(); i++)
	{
		char c = exp[i];
		if (c == '(')
			inpar = true;
		else if (c == ')')
		{
			inpar = false;
			base+=NABC;
		}
		else
		{
			base[c-'a'] = true;
			if (!inpar)
				base+=NABC;
		}
	}
}

bool checkword(string &word)
{
	for(int i=0; i<word.length(); i++)
		if (!ext[i*NABC + word[i]-'a'])
			return false;
	return true;
}

int getresult()
{
	int cnt=0;
	for (int d=0; d<D; d++)
		if (checkword(dict[d]))
			cnt++;
	return cnt;
}

int main()
{
	readinput();
	
	for(int n=0; n<N; n++)
	{
		string exp;
		getline(cin >> ws, exp);
		processexp(exp);
		int res = getresult();
		cout << "Case #" << n+1 << ": " << res << endl;
	}

	return 0;
}
