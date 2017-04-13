// I may use the MPIR library. Its website is this,
// http://www.mpir.org/

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;


int main()
{
    freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int t=0;t<T;t++)
	{
		int N;
		scanf("%d",&N);

		vector < pair <int, int> > vp;
		for(int i=0;i<N;i++)
		{
			pair <int, int> tmp;
			scanf("%d %d ",&tmp.first,&tmp.second);
			vp.push_back(tmp);
		}

		ll ret=0;
		for(int i=0;i<N;i++)
		{
			for(int k=i+1;k<N;k++)
			{
				ll tmp = (ll)(vp[i].first-vp[k].first)*(vp[i].second-vp[k].second);
				if(tmp<0)
				{
					ret++;
				}

			}

		}

		fprintf(stderr, "Case #%d: %lld\n",t+1,ret);
		printf("Case #%d: %lld\n",t+1,ret);
	 }

	return 0;
}