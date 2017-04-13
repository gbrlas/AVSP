#include <iostream>
#include <string>
using namespace std;

char map[100][100];

int main()
{
	int t,i,j,k,red,blue,n,head,tail,x,y,kk;
	bool flagred,flagblue;
	string st;
	freopen("A-large.in","r",stdin);
	freopen("A-answer.out","w",stdout);
	cin >> t;

	for ( i = 1; i <= t; ++ i)
	{
		cin >> n >> kk;
		for (j = 0; j < n; ++ j)
		{
			cin >> st;
			for (k = 0; k < n; ++ k)
				map[j][k] = st[k];
		}
		for (j = 0; j < n; ++ j)
		{
			head = n - 1;
			tail = n - 1;
			do
			{
				while (map[j][tail] == '.')
				{
					-- tail;
					if (tail < 0) break;
				}
				if (tail < 0) break;
				map[j][head] = map[j][tail];
				-- tail;
				-- head;
			}
			while (tail >= 0);
			for ( k = head; k >= 0; -- k)
				map[j][k] = '.';
		}
		flagred = false;
		flagblue = false;		
		for ( j = 0; j < n; ++ j)
		{
			red = 0;
			blue = 0;
			for ( k = 0; k < n; ++ k)
			{
				if (map[j][k] == 'R')
				{
					++ red;
					if (red >= kk) flagred = true;
				}
				else
					red = 0;
				if (map[j][k] == 'B')
				{
					++ blue;
					if (blue >= kk) flagblue = true;
				}
				else
					 blue = 0;					
			}			
		}
		for ( j = 0; j < n; ++ j)
		{
			red = 0;
			blue = 0;
			for ( k = 0; k < n; ++ k)
			{
				if (map[k][j] == 'R')
				{
					++ red;
					if (red >= kk) flagred = true;
				}
				else
					red = 0;
				if (map[k][j] == 'B')
				{
					++ blue;
					if (blue >= kk) flagblue = true;
				}
				else
					 blue = 0;
			}
		}
		for ( j = 0; j < n; ++ j)
		{
			red = 0;
			blue = 0;
			x = 0;
			y = j;
			for ( k = 0; k <= j; ++ k)
			{
				if (map[x][y] == 'R')
				{
					++ red;
					if (red >= kk) flagred = true;
				}
				else
					red = 0;
				if (map[x][y] == 'B')
				{
					++ blue;
					if (blue >= kk) flagblue = true;
				}
				else
					 blue = 0;
				++ x;
				-- y;
			}
		}
//		cout << flagred << " " << flagblue << endl;
		for ( j = n - 1; j >= 1; -- j)
		{
			red = 0;
			blue = 0;
			x = n - j;
			y = n - 1;		
			for ( k = 0; k < j; ++ k)
			{
				if (map[x][y] == 'R')
				{
					++ red;
					if (red >= kk) flagred = true;
				}
				else
					red = 0;
				if (map[x][y] == 'B')
				{
					++ blue;
					if (blue >= kk) flagblue = true;
				}
				else
					 blue = 0;
				++ x;
				-- y;
			}
		}

		for ( j = 0; j < n; ++ j)
		{
			red = 0;
			blue = 0;
			x = 0;
			y = n - j - 1;
			for ( k = 0; k <= j; ++ k)
			{
				if (map[x][y] == 'R')
				{
					++ red;
					if (red >= kk) flagred = true;
				}
				else
					red = 0;
				if (map[x][y] == 'B')
				{
					++ blue;
					if (blue >= kk) flagblue = true;
				}
				else
					 blue = 0;
				++ x;
				++ y;
			}
		}
		for ( j = n - 1; j >= 1; -- j)
		{
			red = 0;
			blue = 0;
			x = n - j;
			y = 0;		
			for ( k = 0; k < j; ++ k)
			{
				if (map[x][y] == 'R')
				{
					++ red;
					if (red >= kk) flagred = true;
				}
				else
					red = 0;
				if (map[x][y] == 'B')
				{
					++ blue;
					if (blue >= kk) flagblue = true;
				}
				else
					 blue = 0;
				++ x;
				++ y;
			}
		}
		if (flagred && flagblue)
		{
			cout << "Case #" << i << ": Both" << endl;
		}
		else
		if (flagred)
		{
			cout << "Case #" << i << ": Red" << endl;
		}
		else
		if (flagblue)
		{
			cout << "Case #" << i << ": Blue" << endl;
		}
		else
			cout << "Case #" << i << ": Neither" << endl;
	}
}
		
				
		
		
			
				
