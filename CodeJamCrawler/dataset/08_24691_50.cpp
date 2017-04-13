#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int parse_time(const string& s)
{
	return ((s[0]-'0') * 10 + s[1]-'0')*60 + (s[3]-'0')*10 + s[4]-'0';
}	

struct Event
{
	int start_time;
	int end_time;
	int pos;
	int type;

	bool operator<(const Event& x) const
	{
		if (start_time < x.start_time) return true;
		if (start_time > x.start_time) return false;
		if (type <x.type) return true;
		if (type > x.type) return false;
		return false;
	}
};

struct Event d[1000];

int main()
{
	int N;
	cin >> N;
	int cases = 0;
	while (N--)
	{
		int T;
		cin >> T;
		int NA, NB;
		cin >> NA >> NB;
		int free[2];
		int maxx[2];
		free[0]=free[1] = 0;
		maxx[0] = maxx[1] = 0;
		int n = NA + NB;
		string s1, s2;
		for (int i=0; i<n; i++)
		{
			cin >> s1 >> s2;
			d[i].start_time = parse_time(s1);
			d[i].end_time = parse_time(s2);
			if (d[i].end_time < d[i].start_time) d[i].end_time += 1440;
			if (i < NA) d[i].pos = 0; else d[i].pos = 1;
			d[i].type = 2;
		}
		int m = n;
		for (int i=0; i<m; i++)
		{
			d[n].start_time = d[i].end_time + T;
			d[n].type = 0;
			d[n].pos = 1- d[i].pos;
			n++;
		}

		sort(d, d+n);

		for (int i=0; i<n; i++)
		{
			switch (d[i].type)
			{
			case 0:
				free[d[i].pos]++;
				break;
			case 2:
				if (free[d[i].pos] > 0) free[d[i].pos] --;
				else
				{
					maxx[d[i].pos]++;
				}
				break;
			}
		}
		cout << "Case #" << ++cases << ": " << maxx[0] << " " << maxx[1] << endl;
	}
	return 0;
}
