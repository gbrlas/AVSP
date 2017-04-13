#include <iostream>
#include <string.h>

using namespace std;

int a[100];

int main()
{
	int i,n,k,t;
	bool ok;
	int cou;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("getanswer.out","w",stdout);
	a[0] = 1;
	for ( i = 1; i < 31; ++ i)
	{
		a[i] = a[i-1] * 2;
//		cout << a[i] << endl;
	}
	cin >> t;
	for ( i = 1; i <= t; ++ i)
	{
		cin >> n >> k;
		if (k < a[n] - 1)
		{
			cout << "Case #" << i << ": OFF" << endl;
		}
		else
		{
			if (k == a[n] - 1)
			{
				cout << "Case #" << i << ": ON" << endl;
			}
			else
			{
				cou = 0;
				ok = true;
				while (cou < n)
				{
					++ cou;
					if (k % 2 == 0)
					{
						ok = false;
						break;
					}
					k = k / 2;
				}
				if (ok)
				{
					cout << "Case #" << i << ": ON" << endl;
				}
				else
					cout << "Case #" << i << ": OFF" << endl;
			}
		}
	}
				
	return 0;
}

