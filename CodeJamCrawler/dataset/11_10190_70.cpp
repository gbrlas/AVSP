#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long

using namespace std;


int a[256][256];
bool rem[256][256];
int t, n, c, d, e, k, l;
string s, w;
char x, y, z;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d\n", &t);
	
	for (int i = 0; i < t; i++)
	{
		w.clear();
		
		for (char g = 'A'; g <= 'Z'; g++)
			for (char h = 'A'; h <= 'Z'; h++)
			{
				a[g][h] = 0;
				rem[g][h] = false;
			}
		
		scanf("%d ", &c);
		
		for (int j = 0; j < c; j++)
		{
			scanf("%c%c%c ", &x, &y, &z);
			a[x][y] = z;
			a[y][x] = z;
		}
		
		scanf("%d ", &d);
		
		for (int j = 0; j < d; j++)
		{
			scanf("%c%c ", &x, &y);
			rem[x][y] = true;
			rem[y][x] = true;
		}
		
		
		scanf("%d ", &c);
		getline(cin, s);
		
		w += s[0];
		e = 0;
		
		cout << "Case #" << i + 1 << ": ";
		
		for (int j = 1; j < s.size(); j++)
		{
			x = s[j];
			
			if (w.size() == 0)
			{
				w += x;
				e = 0;
				continue;
			}
			
			
			if (e >= 0 && a[x][w[e]])
			{
				x = a[x][w[e]];
				w.erase(e, e + 1);
				w += x;
			}
			else
						
			if (e >= 0)
			{
				for (l = e; l >= 0; --l)
					if (rem[x][w[l]]) break;
					
				if (rem[x][w[l]])
				{
					w.clear();
					e = -1;
				}
				else
				{
					w += x;
					e++;
				}
			}
		}
		
		cout << '[';
		for (int j = 0; j < int(w.size()) - 1; j++)
			cout << w[j] << ", ";
		if (w.size())
			cout << w[w.size() - 1];
		cout << "]\n";
	}
	
	return 0;
}
