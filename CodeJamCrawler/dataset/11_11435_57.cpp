// aa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream in("test.txt");
	ofstream out("out.txt");

	int T;
	in >> T;
	for(int c=0; c<T; ++c)
	{
		ll L, t, N, C;
		in >> L >> t >> N >> C;
		vector<int> a(C);
		for(int i=0; i<C; ++i)
		{
			in >> a[i];
		}
		vector<int> x(N);
		ll sum = 0, fast = N, totaldist = 0;
		for(int k=0; k<N; ++k)
		{
			x[k] = a[k%C];
			totaldist += x[k];
			if(fast == N)
			{
				sum += x[k];
				if(sum >= t/2)
					fast = k;
			}
		}
		vector<int> poss;
		if(fast != N)
		{
			poss.push_back(sum - t/2);
			for(vector<int>::const_iterator i=x.begin()+fast+1; i != x.end(); ++i)
			{
				poss.push_back(*i);
			}
		}

		sort(poss.begin(), poss.end(), std::greater<int>());
		int j = 0;
		ll fastdist = 0;
		for(vector<int>::const_iterator z=poss.begin(); z != poss.end() && j<L; ++z, ++j)
		{
			fastdist += *z;
		}
		int slowdist = t;
		ll ttime = (totaldist-fastdist)*2  + fastdist;
		out << "Case #" << (c+1) << ": " << ttime << endl;

	}
	return 0;
}

