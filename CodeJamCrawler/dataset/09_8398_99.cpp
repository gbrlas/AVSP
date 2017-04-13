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
	char b[100] = {0};
	string dic[5000];
	int l = 0;
	int d = 0;
	int n = 0;
	ifs.open("A-small.in", ios::in);
	ofs.open("A-small.out", ios::out);
	getline(ifs, buf);
	sprintf(b, "%s", buf.c_str());
	l = atoi(strtok(b, " "));
	d = atoi(strtok(NULL, " "));
	n = atoi(strtok(NULL, " "));
	for(int i = 0; i < d; i++)
	{
		getline(ifs, buf);
		dic[i] = buf;
	}
	for(int i = 0; i < n; i++)
	{
		int c = 0;
		getline(ifs, buf);
		for(int j = 0; j < d; j++)
		{
			string::iterator it = buf.begin();
			for(int k = 0; k < l; k++)
			{
				if(*it == '(')
				{
					bool flg = false;
					while((*(++it)) != ')')
						if(*it == (dic[j])[k]) flg = true;
					if(!flg) goto unmatched;
				}
				else
					if(*it != (dic[j])[k]) goto unmatched;
				it++;
			}
//			cout << dic[j] << endl;
			c++;
		unmatched:;
		}
		ofs << "Case #" << i + 1 << ": " << c << endl;
	}
	return 0;
}
