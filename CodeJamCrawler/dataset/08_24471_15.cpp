#include <vector>
#include <list>
#include <map>
#include <set>
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
#include<fstream>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define all(a) (a).begin(),(a).end()

int main()
{
	ifstream fin("C:\\A-small-attempt0.in");//B-small-attempt2.in
	ofstream fout("C:\\output.txt");
	int t;
	fin>>t;
	int total=t;
	while(t--)
	{
		int p,k,l;
		fin>>p;
		fin>>k;
		fin>>l;
		vector<long long> v(l);
		int req=0;
		FOR(i,0,l)
			fin>>v[i];
		sort(all(v));
		reverse(all(v));
		long long r=0;
		long long final=0;
		int done=1;
		FOR(i,0,v.size())
		{
			r++;
			req++;
			if(req>p)
			{
				done=0;
				break;
			}
			FOR(j,0,k)
			{
			 if((i+j)>=v.size())
				 break;
			 final+=(r*v[i+j]);
			}
			i+=k;
			i--;
		}
		if(done==0)
		fout<<"Case #"<<(total-t)<<": "<<"IMPOSSIBLE"<<endl;
		else
		fout<<"Case #"<<(total-t)<<": "<<final<<endl;
	}

}