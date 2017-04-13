#include <iostream>
#include <string>
#include <vector>

using namespace std;

void parse (string sz, vector < string > & sz_ptrn)
{
	string sz_result;
	bool f = false;
	
	for (string::iterator it = sz.begin(); it != sz.end(); ++it)
	{
		if (*it == '(')
		{
			sz_result.clear();
			f = true;
		}
		else if (*it == ')') 
			{
				sz_ptrn.push_back(sz_result);
				sz_result.clear();
				f = false;
			}
			else
			{
				sz_result.push_back(*it);

				if (!f)
				{
					sz_ptrn.push_back(sz_result);
					sz_result.clear();
				}
			}
	}
}

void solve ()
{
	vector < string > sz, sz_ptrn;
	string sz_temp;
	bool f;
	int l, d, n, result;

	cin >> l >> d >> n;
	
	
	for (int i = 0; i < d; ++i)
	{
		cin >> sz_temp;
		sz.push_back(sz_temp);
	}
	
	for (int i = 0; i < n; ++i)
	{
		sz_ptrn.clear();
		result = 0;

		cin >> sz_temp;
				
		parse(sz_temp, sz_ptrn);
		
		for (int j = 0; j < d; ++j)
		{
			f = true;
			
			for (int k = 0; k < l; ++k)
				if (sz_ptrn[k].find(sz[j][k]) == string::npos)
				{
					f = false;
					break;
				}
			
			if (f) ++result;
		}
		
		cout << "Case #" << (i + 1) << ": " << result << endl;
	}
}

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	solve();
	
	return 0;
}
