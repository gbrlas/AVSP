#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <functional>
#include <ctype.h>
#include <numeric>
#include <sstream>

using namespace std;

bool cmp(long long a, long long b) {
	return a > b;
}

long long f()
{
	long long P, K, L;
	cin>>P>>K>>L;

	vector <long long> c;
	for (int i = 0; i < L; i++) {
		long long temp;
		cin>>temp;
		c.push_back(temp);		
	}

	::sort(c.begin(), c.end(), cmp);

	long long rtn = 0;
	for (int i = 0; i < L; i++) {
		rtn = rtn + ((i / K) + 1) * c[i];
	}
	return rtn;
}

int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		long long rtn = 0;
		rtn = f();
		cout<<"Case #"<<i<<": "<<rtn<<endl;
	}
	return 0;
}