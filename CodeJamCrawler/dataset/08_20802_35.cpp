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
#include <string>
#include <string.h>


#define fill_(x,v) memset(x,v,sizeof(x))
#define for_(i,a,b) for (__typeof(b) i=(a); i<(b); i++)
#define min(x,y) (((x)>(y)) ? (y) :(x))
#define max(x,y) (((y)>(x)) ? (y) :(x)) 
#define ll long long

using  namespace std;



ll getsum (ll x1, ll y1, ll x2, ll y2)
{
	ll s = x1*y2 - x2*y1;
	if (s < 0)
		s *= (-1);

	return s;
}


void everycase (ifstream &fs, ofstream &fs2, int no)
{

	fs2 << "Case #" << no <<": ";


	ll N, M, A;

	fs >> N >> M >> A;

	ll d = N * M;

	if (A > N*M)
	{
		fs2 << "IMPOSSIBLE" << endl;
		return;
	}


	for_(x1, 0, N + 1)
		for_(y1, 0, M + 1)
			for_(x2, x1, N+1)
				for_(y2, 0, M+1)
			{
				if (A == getsum (x1,y1,x2,y2))
				{
					fs2 << 0 << " "<< 0 << " "<< x1 << " "<< y1 << " "<< x2 <<" "<<y2 << endl;
					return;
				}
			
			}


	return;
}

int main (int argc, char **argv)
{
	ifstream fs (argv[1]);
	ofstream fs_out ("output", ios::out);
	string s;
	int num_cases;
	fs >> num_cases;
	for (int i = 1; i <= num_cases; i++)
		everycase (fs, fs_out, i);
	fs.close ();
	fs_out.close ();
}
