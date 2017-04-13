#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int n, t;
vector < pair < int, int > > a, b;
int x, y, l, r, w, q, ans;
char c;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d\n", &t);
	
	for (int i = 0; i < t; i++)
	{
		scanf("%d ", &n);
		
		a.clear();
		b.clear();
		
		for (int j = 0; j < n; j++)
		{
			scanf("%c %d", &c, &w);
			if (j < n - 1)
				scanf(" ");
				
			if (c == 'O')
				a.push_back(make_pair(j, w));
			else
				b.push_back(make_pair(j, w));
		}
		
		a.push_back(make_pair(n, 1000000));
		b.push_back(make_pair(n + 1, 1000000));
		
		x = 1;
		y = 1;
		
		l = 0;
		r = 0;
		ans = 0;
		
		ans = 0;
		
		cout << "Case #" << i + 1 << ": ";
		
		for (int j = 0; j < n; j++)
		{
			if (a[l].first < b[r].first)
			{
				w = a[l].second;
				q = b[r].second;
				
				while (x != w)
				{
					ans++;
					x += (w - x)/abs(w - x);
					
					if (y != q)
						y += (q - y)/abs(q - y);
				}
				
				ans++;
				if (y != q)
					y += (q - y)/abs(q - y);
					
				l++;
			}
			else
			{
				w = a[l].second;
				q = b[r].second;
				
				while (y != q)
				{
					ans++;
					y += (q - y)/abs(q - y);
					
					if (x != w)
						x += (w - x)/abs(w - x);
				}
				
				ans++;
				if (x != w)
						x += (w - x)/abs(w - x);
						
				r++;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
