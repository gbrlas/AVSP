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
	ifstream fin("C:\\A-large.in");//B-small-attempt2.in
	ofstream fout("C:\\output13.txt");
	int t;
	fin>>t;
	int total=t;
	int n;
	while(t--)
	{
		fin>>n;
		vector<long long> first(n);
		vector<long long> second(n);
		FOR(i,0,n)
			fin>>first[i];
		FOR(i,0,n)
			fin>>second[i];
		sort(all(first),greater<int>());
		sort(all(second));
		long long final=0;
		FOR(i,0,n)
			final+=(first[i]*second[i]);
		fout<<"Case #"<<(total-t)<<": "<<final<<endl;
	}
}



