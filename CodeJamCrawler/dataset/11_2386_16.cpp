#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef pair<int,int> joft;

int main()
{
	int t;
	cin>>t;
	for(int tn = 0;tn<t;tn++) {
		int n;
		cin>>n;
		vector<int> in;
		for(int i=0;i<n;i++) {
			int temp;
			cin>>temp;
			in.push_back(temp);
		}
		vector<joft> calc;
		sort(in.begin(),in.end());
		for(int i=0;i<in.size();i++) {
			int mind = -1;
			for(int j=0;j<calc.size();j++)
				if(calc[j].first==in[i]-1)
					if(mind == -1 || calc[mind].second>calc[j].second)
						mind = j;
			if(mind == -1)
				calc.push_back(joft(in[i],1));
			else 
				calc[mind] = joft(in[i],calc[mind].second+1);
		}
		int ans = 100000;
		for(int i=0;i<calc.size();i++)
			ans = min(ans,calc[i].second);
		if(n==0)
			ans = 0;
		cout<<"Case #"<<tn+1<<": "<<ans<<endl;


	}

}
