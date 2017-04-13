#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	
	freopen ( "B-small-attempt0.in", "r", stdin );
    freopen ( "B-small-attempt0.out", "w", stdout );

	int T;
	scanf ( "%d", &T );
	for ( int t = 1; t <= T; t++ )
	{
		vector <char> s;
		int c, d, n;
		char c1, c2, c3, d1, d2, nn[15];
		scanf ( "%d", &c );
		if ( 1 == c )
			cin >> c1 >> c2 >> c3;
		scanf ( "%d", &d );
		if ( 1 == d )
			cin >> d1 >> d2;
		scanf ( "%d", &n );
		cin >> nn;
		//cout << nn <<endl;
		for ( int i = 0; i < n; i++ )
		{
			int fg = 0;
			if ( 0 == s.size()) {s.push_back( nn[i] );continue;}
			if (( nn[i] == c1 && c2 == s.back() )||( nn[i] == c2 && c1 == s.back() ))
			{
				s.pop_back();
				s.push_back( c3 );
				continue;
			}
			if ( nn[i] == d1 )
			{
				for ( int j = 0; j < s.size(); j++ )
					if ( d2 == s[j] )
					{
						s.clear();
						fg = 1;
					}
			}
			if (fg) continue;
			if ( nn[i] == d2 )
			{
				for ( int j = 0; j < s.size(); j++ )
					if ( d1 == s[j] ) 
					{
						s.clear();
						fg = 1;
					}
			}
			if (fg) continue;
			s.push_back( nn[i] );
		}
		printf ( "Case #%d: [", t );
		if (!s.empty()) printf ( "%c", s[0] );
		for ( int j = 1; j < s.size(); j++ )
			printf ( ", %c", s[j] );
		printf ( "]\n" );
	}
	return 0;
}
