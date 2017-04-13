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


#define fill_(x,v) memset(x,v,sizeof(x))
#define for_(i,a,b) for (__typeof(b) i=(a); i<(b); i++)
#define min(x,y) (((x)>(y)) ? (y) :(x))
#define max(x,y) (((y)>(x)) ? (y) :(x)) 
#define ll long long

using  namespace std;

class node
{
public:
		bool value, G, C;
};

node NN[10010];


ll decide (int i, int M, bool V)
{
	
	if (i >= (M-1)/2)
	{
		if (NN[i].value == V)
			return 0;
		else
			return -1;
	}

	if (V == 1)
	{

		if (NN[i].G == 1)
		{
			ll l1 = decide (2*i+1,M,V);
			ll l2 = decide (2*i+2,M,V);


			if (NN[i].C == 0)
			{
				if (l1!=-1 && l2!=-1)
					return l1 + l2;
				else
					return -1;
			}
			else
			{
				if (l1!=-1 && l2 != -1)
				{
					ll A = 1 + min(l1,l2);
					ll B = l1 + l2;
					return min(A, B);
				}
				else if (l1 == -1 && l2 == -1)
					return -1;
				else
					return 1+max(l1,l2);

			}	
		}
		else
		{
		ll l1 = decide (2*i+1,M,V);
		ll l2 = decide (2*i+2,M,V);


		if (l1 == -1 && l2 == -1)
			return -1;
		else if (l1 == -1)
			return l2;
		else if (l2 == -1)
			return l1;
		else
			return min(l1,l2);

		}
	}
	else
	{
		if (NN[i].G == 1)
		{
		ll l1 = decide (2*i+1,M,V);
		ll l2 = decide (2*i+2,M,V);


		if (l1 == -1 && l2 == -1)
			return -1;
		else if (l1 == -1)
			return l2;
		else if (l2 == -1)
			return l1;
		else
			return min(l1,l2);


		}
		else
		{
	
			ll l1 = decide (2*i+1,M,V);
			ll l2 = decide (2*i+2,M,V);


			if (NN[i].C == 0)
			{
				if (l1!=-1 && l2!=-1)
					return l1 + l2;
				else
					return -1;
			}
			else
			{
				if (l1!=-1 && l2 != -1)
				{
					ll A = 1 + min(l1,l2);
					ll B = l1 + l2;
					return min(A, B);
				}
				else if (l1 == -1 && l2 == -1)
					return -1;
				else
					return 1+max(l1,l2);

			}	
		}
	}
}


void everycase (ifstream &fs, ofstream &fs2, int no)
{

	fs2 << "Case #" << no <<": ";

	ll M;
	bool V;

	fs >> M >> V;
	cout << V << endl;

	for_(i,0,M)
	{
		if (i < (M-1)/2)
		{
			fs >> NN[i].G >> NN[i].C;
		}
		else
		{
			fs >> NN[i].value;
		}
	}

	

	ll num = decide (0, M,  V);

	if (num >= 0)	fs2 << num << endl;
	else
		fs2 << "IMPOSSIBLE" << endl;

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
