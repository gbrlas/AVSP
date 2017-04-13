#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <cstdio>
#include <utility>

using namespace std;

int solve ()
{
	vector < pair < bool , int > > a;
	int n;
	
	cin >> n;
	
	
	for (int i = 0; i < n; ++i)
	{
		char ch;
		int t;
		
		cin >> ch >> t;
		
		a.push_back(make_pair(ch == 'O', t));
	}
	
	int o_task = -1, b_task = -1, task = 0;
	int o_curr = 1, b_curr = 1;
	int time;
	
	do
	{
		++b_task;
	} while (a[b_task].first && b_task < n);

	do
	{
		++o_task;
	} while (!a[o_task].first && o_task < n);

	for (time = 0; task < a.size(); ++time)
	{	
		bool f = false;

		if (a[task].first)
		{
			if (o_curr == a[task].second)
				f = true;
			else
			{
				if (o_curr < a[task].second)
					++o_curr;
				else
					--o_curr;
			}
			
			if (f)
			{
				do
				{
					++o_task;
				} while (!a[o_task].first && o_task < n);
			}
						
			if (b_task != n && a[b_task].second != b_curr)
				if (b_curr < a[b_task].second)
					++b_curr;
				else
					--b_curr;
		}
		else
		{
			if (b_curr == a[task].second)
				f = true;
			else
			{
				if (b_curr < a[task].second)
					++b_curr;
				else
					--b_curr;
			}
			
			if (f)
			{
				do
				{
					++b_task;
				} while (a[b_task].first && b_task < n);
			}
			
			if (a[o_task].second != o_curr && o_task != n)
				if (o_curr < a[o_task].second)
					++o_curr;
				else
					--o_curr;		
		}
		
		task += f;
	}
	
	return time;
}

int main ()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int n;
	
	cin >> n;
	
	for (int i = 0; i < n; ++i)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
		
	return 0;
}
