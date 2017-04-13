#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#define ll long long 

using namespace std;


string sa, sb, s, w;
int a, b, x, t;
int ans;
map < string, bool > my;


string str(int a)
{
	string s;
	
	while (a)
	{
		s += (a % 10 + '0');
		a /= 10;
	}
	
	reverse(s.begin(), s.end());
	
	return s;
}


string recycle(string s, int x)
{
	reverse(s.begin(), s.begin() + x);
	reverse(s.begin() + x, s.end());
	reverse(s.begin(), s.end());
	
	return s;
}


int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
   
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;
		ans = 0;
		
		sa = str(a);
		sb = str(b);
		
		my.clear();
		
		for (int x = a; x <= b; x++)
		{
			s = str(x);
				
			for (int l = 1; l < s.size(); l++)
			{
				w = recycle(s, l);
				
				
				
				if (s < w && w <= sb && w[0] != '0' && my.find(s + w) == my.end())
				{
					ans++;
					//~ cout << s << ' ' << w << endl;
					my[s + w] = 1;
				}
			}
		}
		
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
}
