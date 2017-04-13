#include <iostream>
using namespace std;

const int MAXN = 1000 + 100;

bool mark[MAXN];
int t;

void findPal()
{
	for (int i = 1; i < MAXN; i++)
	{
		mark[i] = true;
		int x = i;
		string s;
		while (x > 0)
		{
			s += x % 10 + '0';
			x /= 10;
		}
		for (int j = 0; j < s.size()/2; j++)
			if (s[j] != s[s.size() - j - 1])
				mark[i] = false;
	}
}

int f (int a, int b)
{
	int r = 0;
	for (int i = 1; i <= b; i++)
		if (mark[i] && i * i <= b && i * i >= a && mark[i * i])
			r++;
	return r;
}
	

int main()
{
	findPal();
	cin >> t;
	int a, b;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << f(a, b) << endl;
	}
	return 0;
}