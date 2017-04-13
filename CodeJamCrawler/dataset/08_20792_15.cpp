#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>


#define fill_(x,v) memset(x,v,sizeof(x))
#define for_(i,a,b) for (__typeof(b) i=(a); i<(b); i++)
#define min(x,y) (((x)>(y)) ? (y) :(x))
#define max(x,y) (((y)>(x)) ? (y) :(x)) 
#define ll long long 

using  namespace std;


void everycase (ifstream &fs, ofstream &fs2, int no)
{
	fs2 << "Case #"<<no<<": ";
	int P, K, L;
	fs >> P >> K >> L;

	if (L > P * K)
	{
		fs2 << "Impossible" << endl;
		return;
	}
	vector <int> v;
	for (int i = 0; i < L; i++)
	{
		int current;
		fs >> current;
		v.push_back (current);
	}

	sort (v.rbegin (), v.rend ());


	ll sum(0);
	for_(i,0,L)
	{
		sum += (ll)v[i]*(i/K + 1);
	}
	fs2 << sum << endl;

}

/*The main program. */

int main (int argc, char **argv)
{
	ifstream fs (argv[1]);
	ofstream fs_out ("output", ios::out);
	string s;
	int num_cases;
	fs >> num_cases;

	for (int i = 1; i <= num_cases; i++)
	{
		everycase (fs, fs_out, i);
	}

	
	fs.close ();
	fs_out.close ();
}
