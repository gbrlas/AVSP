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

vector <int> a;
vector <int> b;

long long minValue = 0;


void p(int level)
{
	if (level == a.size() - 1) {
		long long sum = 0;
		for (int i = 0; i < a.size(); i++) {
			sum += (a[i] * b[i]);
		}
		if (minValue > sum) {
			minValue = sum;
		}
	}
	for (int i = level; i < a.size(); i++) {
		int temp;
		temp = a[level];
		a[level] = a[i];
		a[i] = temp;

		p(level + 1);

		temp = a[level];
		a[level] = a[i];
		a[i] = temp;
	}
}

int findMin() {
	int n = 0;
	a.clear();
	b.clear();
	minValue = 0x7fffffff;
	cin>>n;
	for (int i = 0;i < n; i++) {
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	for (int i = 0;i < n; i++) {
		int temp;
		cin>>temp;
		b.push_back(temp);
	}
	p(0);
	return minValue;
}

int main()
{
	int t;
	cin>>t;
	for (int i = 1; i <= t; i++) {
		int rslt = findMin();
		cout<<"Case #"<<i<<": "<<rslt<<endl;
	}
	return 0;
}
