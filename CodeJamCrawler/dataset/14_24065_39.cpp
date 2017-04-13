#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstdlib>
#define mp make_pair
#define pb push_back
#define NAME ""

using namespace std;

typedef long double ld;
typedef long long ll;

const int nmax = 1e5 + 3;
const ld pi = M_PI;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;

int t, ans1, a[5][5];
bool used[20];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		cin >> ans1;
		ans1--;
		for (int i = 0; i < 16; i++)
			used[i] = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				cin >> a[i][j];
				a[i][j]--;
			}
		for (int j = 0; j < 4; j++)
			used[a[ans1][j]] = true;
		cin >> ans1;
		ans1--;
		for (int i = 0 ; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				cin >> a[i][j];
				a[i][j]--;
			}
		int ind = -1;
		for (int j = 0; j < 4; j++)
		{
			if (used[a[ans1][j]])
			{
				if (ind == -1)
					ind = j;
				else
					ind = -2;
			}
		}
		if (ind == -2)
			cout << "Case #" << q + 1 << ": Bad magician!\n";
		else if (ind == -1)
			cout << "Case #" << q + 1 << ": Volunteer cheated!\n";
		else
			cout << "Case #" << q + 1 << ": " << a[ans1][ind] + 1 << endl;
	}	
}