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

	
	if (A == N * M)
	{
		fs2 << 0 << " "<<0 << " "<< N << " "<< 0 << " "<< 0 << " "<< M <<endl;
		return;
	}
	ll x1 = A/M+1;
	ll y2 = M;
	ll data = x1*y2 - A;
	ll x2 = 1;
	ll y1 = data;
	fs2 << 0 << " "<<0 << " "<< x1 << " "<< y1 << " "<< x2 << " "<< y2 <<endl;

	cout << "finish" << no << endl;
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
