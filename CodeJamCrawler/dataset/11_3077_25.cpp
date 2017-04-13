#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int i, cs, tc, n, k, mn, sum, res;
	
	freopen( "C-large.in", "r", stdin );
	freopen( "clarge.out", "w", stdout);

	cin >> tc;

	for( cs = 1 ; cs <= tc ; cs++ )
	{
		cin >> n;
		mn = 10000000;
		for( i = res = sum = 0 ; i < n ; i++ )
		{
			cin >> k;
			res = res ^ k;
			sum += k;
			if( mn > k ) mn = k;
		}
		
		if( res ) cout << "Case #" << cs << ": NO" << endl;
		else cout << "Case #" << cs << ": " << sum - mn << endl;
	}

}
