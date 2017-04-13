#include <iostream>
#include <stdio.h>
using namespace std;

int main (int argc, char *argv[])
{
	freopen("A-input.txt", "r", stdin);
	freopen("A-output.txt", "w", stdout);
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int A, B;
		cin >> A >> B;
		double p[A];
		double p_right = 1;
		for (int j = 0; j < A; j++)
		{
			cin >> p[j];
			p_right *= p[j];
		}
		double k_enter = (B - A + 1) * p_right + (B - A + 1 + B + 1) * (1 - p_right);
		//cout << k_enter << endl;
		double p_backspace = 1;
		double k_backspace = 0;
		for (int j = 0; j < A - 1; j++)
		{
			p_backspace *= p[j];
		}
		k_backspace = p_backspace * (B - A + 3) + (1 - p_backspace) * (B - A + 1 + B + 3);
		//cout << k_backspace << endl;
		for (int j = 1; j < A; j++)
		{
			p_backspace = 1;
			for (int k = 0; k < A - j - 1; k++)
			{
				p_backspace *= p[j];
			}
			k_backspace = min(k_backspace, p_backspace * (B - A + 1 + 2 * (j + 1)) + (1 - p_backspace) * (B - A + 1 + B + 1 + 2 * (j + 1)));
			//cout << k_backspace << endl;
		}
		double k_giveup = B + 2;
		double ans = min(min(k_giveup, k_backspace), k_enter);
		cout.precision(7);
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}

