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

int main()
{
//	freopen("in.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string m;
		string ans;
		cin>>m;
		vector <int> v;
		v.push_back(0);
		for(int j=0;j<m.length();j++)					
			v.push_back(int(m[j]-'0'));		
		next_permutation(v.begin(),v.end() );				
		cout<<"Case #"<<i<<": ";
		if(v[0]) {cout<<v[0];}
		for(int j=1;j<v.size();j++)
			cout<<v[j];
		cout<<endl;
	}	
	return 0;
}

