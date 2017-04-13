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
//	ifs.open("B-example.in", ios::in);
//	ifs.open("B-small-attempt1.in", ios::in);
	ifs.open("B-large.in", ios::in);
//	ofs.open("B-example.out", ios::out);
//	ofs.open("B-small-attempt1.out", ios::out);
	ofs.open("B-large.out", ios::out);
	getline(ifs, buf);
	n = atoi(buf.c_str());
	for(int i = 0; i < n; i++)
	{
		getline(ifs, buf);
		int t = atoi(buf.c_str());
		getline(ifs, buf);
		int na, nb;
		int ca = 0;
		int cb = 0;
		sscanf(buf.c_str(), "%d %d", &na, &nb);
		int da[100], aa[100], db[100], ab[100];
		vector<int> a;
		vector<int> b;
		vector<int> fa;
		vector<int> fb;
		for(int j = 0; j < na; j++)
		{
			int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
			getline(ifs, buf);
			sscanf(buf.c_str(), "%d:%d %d:%d", &b1, &b2, &b3, &b4);
			da[j] = b1 * 60 + b2;
			aa[j] = b3 * 60 + b4;
			fa.push_back(da[j]);
			b.push_back(aa[j]);
		}
		for(int j = 0; j < nb; j++)
		{
			int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
			getline(ifs, buf);
			sscanf(buf.c_str(), "%d:%d %d:%d", &b1, &b2, &b3, &b4);
			db[j] = b1 * 60 + b2;
			ab[j] = b3 * 60 + b4;
			fb.push_back(db[j]);
			a.push_back(ab[j]);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(fa.begin(), fa.end());
		sort(fb.begin(), fb.end());
		for(vector<int>::iterator ia = fa.begin(); ia != fa.end(); ia++)
		{
			vector<int>::iterator p = a.end();
			for(vector<int>::iterator it = a.begin(); it != a.end(); it++)
			{
				if((*it + t) <= *ia)
				{
					p = it;
					break;
				}
			}
			if(p == a.end())
				ca++; //new train
			else
				a.erase(p);
		}

		for(vector<int>::iterator ib = fb.begin(); ib != fb.end(); ib++)
		{
			vector<int>::iterator p = b.end();
			for(vector<int>::iterator it = b.begin(); it != b.end(); it++)
			{
				if((*it + t) <= *ib)
				{
					p = it;
					break;
				}
			}
			if(p == b.end())
				cb++; //new train
			else
				b.erase(p);
		}
		ofs << "Case #" << i + 1 << ": " << ca << " " << cb << endl;
	}
}
