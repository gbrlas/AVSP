// CodeJam.cpp : Defines the entry point for the console application.
//

//////////////////////////////////////////////////////////////////////////
//	1.Saving the Universe

#include <iostream>
#include <string>
using namespace std;

#define N	20
#define S	100
#define Q	1000
#define MAXC	100



int main()
{
	int	n,
		s,
		q,
		i,
		j,
		k,
		num = 0,
		a[Q],
		eng_sorted[S];
	char	engine[S][MAXC+1],
		query[MAXC+1];

	// input file redirection
	freopen("input.txt", "r", stdin);
	
	// output file redirection
	freopen("output.txt", "w", stdout);

	cin >> n;
	for ( i = 0; i < n; i++ )
	{
		// input a case
		cin >> s;
		cin.get();
		for ( j = 0; j < s; j++ )
			cin.getline( engine[j], MAXC, '\n' );

		for ( j = 0; j < s; j++ )
			eng_sorted[j] = j;
		for ( j = 0; j < s - 1; j++ )
		{
			int min = j;
			for ( k = j + 1; k < s; k++ )
				if ( strcmp( engine[eng_sorted[min]], engine[eng_sorted[k]] ) > 0 )
					min = k;
			k = eng_sorted[j];
			eng_sorted[j] = eng_sorted[min];
			eng_sorted[min] = k;
		}

		cin >> q;
		cin.get();

		for ( j = 0; j < q; j++ )
		{
			cin.getline( query, MAXC, '\n' );
/*			for ( k = 0; k < s; k++ )
				if ( strcmp( query, engine[k] ) == 0 )
				{
					a[j] = k;
					break;
				}
*/
			int min = 0, max = s - 1;
			while ( min != max )
			{
				int mid = ( min + max ) / 2, r;
				if ( ( r = strcmp( query, engine[eng_sorted[mid]] ) ) < 0 )
					max = mid - 1;
				else if ( r > 0 )
					min = mid + 1;
				else
					min = max = mid;
			}
			a[j] = min;
		}

		// process
		num = 0;
		int	used = 0;
		bool	queried_engine[S] = {0};
		
		for ( j = 0; j < q; j++ )
			if ( ! queried_engine[a[j]] )
			{
				used ++;
				if ( used == s )
				{
					num++;
					used = 1;
					memset( queried_engine, 0, sizeof(bool)*S );
				}
				queried_engine[a[j]] = true;
			}


		// output a case
		cout << "Case #" << i + 1 << ": " << num << endl;

	}

	return 0;
}
