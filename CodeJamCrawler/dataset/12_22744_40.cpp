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
#define fo(i,st,end) for(int i=st;i<end;i++)
#define foe(i,st,end) for(int i=st;i<=end;i++)
#define fon(i,end,st)for(int i=end;i>st;i--)
#define fone(i,end,st) for(int i=end;i>=st;i--)
#define pb push_back
#define sz(x) (int)(x).size()
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define Pr pair<int, int>
#define vp vector<Pr>
#define sort(a) sort(a.begin(),a.end())

using namespace std;

int main()
{
	set< pair<string, string> > hh;
	int t, n, m;
	cin >> t;
	int k = 1;
	while(t--)
	{
		stringstream ss1, ss2;
		cin >> n >> m;
		ss1 << n;
    		string s1 = ss1.str();
		ss2 << m;
    		string s2 = ss2.str();
			for(int i = n; i < m; i++)
			{
			stringstream ss;
			ss << i;
    			string v1 = ss.str();
    			for(int j = 1; j < sz(v1); j++)
			{
				if(v1[j] >= v1[0])
				{
					string vv = v1.substr(j) + v1.substr(0, j);
					if(sz(vv)< sz(s2) && vv > v1)
					{
						hh.insert(make_pair(v1, vv));
					}
					else if(sz(vv) == sz(s2) && vv > v1)
					{
						if(vv <= s2)
						{
							hh.insert(make_pair(v1, vv));
						}
					}
				}
			}
		}
		cout << "Case #" << k << ": "<< sz(hh) << endl;
		hh.clear();
		k++;
	}
	return 0;
}
