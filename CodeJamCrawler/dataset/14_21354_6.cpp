#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define REP(i , a) for (int i = 0; i < (a); ++i)
#define BG begin()
#define ED end()
//#define debug

using namespace std;

int main(int argc, char const *argv[])
{
	int a [4][4] , b[4][4];
	int t , z , x;
	cin >> t;
	REP ( k , t )
	{
		vector<int> v(4);
	  	vector<int>::iterator it;
		cout << "Case #" << k+1 << ": ";
		cin >> z;
		z--;
		REP ( i , 4 )
		{
			REP ( j , 4 )
				cin >> a[i][j];
		}
		cin >> x;
		REP ( i , 4 )
		{
			REP ( j , 4 )
				cin >> b[i][j];
		}
		x--;
		set <int> aa ( a[z] , a[z]+4 );
		#ifdef debug
		for ( set <int> :: iterator it = aa.begin() ; it != aa.end() ; it++ )
			cout << *it << " ";
		cout << endl;
		#endif
		set <int> bb ( b[x] , b[x]+4 );
		#ifdef debug
		for ( set <int> :: iterator it = bb.begin() ; it != bb.end() ; it++ )
			cout << *it << " ";
		cout << endl;
		#endif
		it = set_intersection ( aa.BG , aa.ED , bb.BG , bb.ED , v.BG );
		v.resize(it-v.begin());
		#ifdef debug
		REP ( i , v.size() )
			cout << v[i] << " ";
		#endif
		switch ( v.size() )
		{
			case 0: cout << "Volunteer cheated!" << endl;
				break;
			case 1:cout << v[0] << endl;
				break;
			default:cout << "Bad magician!" << endl;
				break;
		}
	}
	return 0;
}
