/*
 * a.cpp
 *
 *  Created on: 08.05.2011
 *      Author: 1
 */

#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int a[1024];
bool v[32];
int n;

void Solve()
{
	memset(v, 0, sizeof(v));
	cin >> n;
	long long summ = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		summ += a[i];
		for(int j = 0; j < 30; j++)
		{
			bool bit = (a[i] & (1 << j)) != 0;
			v[j] ^= bit;
		}
	}

	int m = a[0];
	for(int i = 1; i < n; i++)
	{
		m = min(m, a[i]);
	}

	bool ok = 1;
	for(int i = 0; i < 30; i++)
	{
		if(v[i])
			ok = 0;
	}

	if(ok)
	{
		cout << (summ - m);
	}
	else
	{
		cout << "NO";
	}
}

int main()
{
	freopen("c:\\gcj\\in.txt", "r", stdin);
	freopen("c:\\gcj\\out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cout << "Case #" << (i + 1) << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}
