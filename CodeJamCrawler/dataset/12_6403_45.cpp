#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void test(int tn)
{
	int n, s, p;
	cin >> n >> s >> p;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int r = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] % 3 == 0)
		{
			if(a[i] / 3 >= p)
				r++;
			else if(a[i] < 30 && a[i] >= 3 && s > 0 && a[i] / 3 + 1 >= p)
			{
				s--;
				r++;
			}
		}
		else if(a[i] % 3 == 1)
		{
			if(a[i] / 3 + 1 >= p)
				r++;
		}
		else // a[i] % 3 == 2
		{
			if(a[i] / 3 + 1 >= p)
				r++;
			else if(a[i] < 29 && a[i] >= 2 && s > 0 && a[i] / 3 + 2 >= p)
			{
				s--;
				r++;
			}
		}
	}
	cout << "Case #" << tn << ": " << r << "\n";
}
int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)
		test(i);
	return 0;
}
