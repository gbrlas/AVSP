#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int T , N;
	int L[1010] , P[1010];
	cin >> T;
	for( int t = 1; t <= T; ++t )
	{
		cin >> N;
		vector < pair < int , int > > v;
		for(int i = 0; i < N; ++i)
			cin >> L[i];
		for(int i = 0; i < N; ++i)
		{
			cin >> P[i];
			v.push_back( make_pair( 100-P[i] , i ) );
		}
		sort( v.begin() , v.end() );
		cout << "Case #"<<t<<":";
		for(int i = 0; i < N; ++i)
			cout << " " << v[i].second ;
		cout << "\n";
		
	}
	return 0;
}