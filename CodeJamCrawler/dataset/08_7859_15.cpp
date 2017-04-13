#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;


int main()
{
	ifstream ifs;
	ofstream ofs;
	string buf;
	int n = 0;
//		ifs.open("A-example.in", ios::in);
		ifs.open("A-small-attempt0.in", ios::in);
	//	ifs.open("A-large.in", ios::in);
//		ofs.open("A-example.out", ios::out);
		ofs.open("A-small-attempt0.out", ios::out);
	//	ofs.open("A-large.out", ios::out);
	
	getline(ifs, buf);
	n = atoi(buf.c_str());
	for(int i = 0; i < n; i++)
	{
		vector<int> x;
		vector<int> y;
		int l = 0;
		int m;
		getline(ifs, buf);
		l = atoi(buf.c_str());
		getline(ifs, buf);
		istringstream strm(buf);
		for(int j = 0; j < l; j++)
		{
			strm >> m;
			x.push_back(m);
		}
		getline(ifs, buf);
		istringstream strm2(buf);
		for(int j = 0; j < l; j++)
		{
			strm2 >> m;
			y.push_back(m);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end(), greater<int>());
		m = 0;
		for(int j = 0; j < l; j++)
			m += x[j] * y[j];
		ofs << "Case #" << i + 1 << ": " << m << endl;
	}
	return 0;
}
