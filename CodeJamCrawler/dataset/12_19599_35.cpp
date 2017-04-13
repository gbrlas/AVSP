
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("a.in");
	ofstream out("out.txt");
	int t;
	in >> t;

	for ( int i = 0; i < t; i++ )
	{
		int n, q, p;
		in >> n >> q >> p;
		int cnt = 0, maybe = 0;
		for ( int j = 0; j < n; j++ )
		{
			int k;
			in >> k;
			
			if ( k == 0 )
			{
				if ( p == 0 )
					cnt ++;
			}
			else
			{
				if ( k%3 == 0 )
				{
					if ( k/3 >= p )
						cnt ++;
					else
						if ( k/3+1 >= p )
							maybe ++;
				}
				if ( k%3 == 2 )
				{
					if ( k/3 + 1 >= p )
						cnt++;
					else
						if ( k/3 + 2 >= p )
							maybe++;
				}
				if ( k%3 == 1 )
				{
					if ( k/3+1 >= p )
						cnt++;
				}
			}
		}

		cnt += min(maybe, q);

		out << "Case #" << i+1 << ": " << cnt << "\n";
	}

	return 0;
}