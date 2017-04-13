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
	ifs.open("A-large.in", ios::in);
	ofs.open("A-large.out", ios::out);
	getline(ifs, buf);
	n = atoi(buf.c_str());
	for(int i = 0; i < n; i++)
	{
		getline(ifs, buf);
		int S = atoi(buf.c_str());
		string engines[100];
		int queries[1000];
		for(int j = 0; j < S; j++)
			getline(ifs, engines[j]);
		getline(ifs, buf);
		int Q = atoi(buf.c_str());
		for(int j = 0; j < Q; j++)
		{
			getline(ifs, buf);
			for(int k = 0; k < S; k++)
			{
				if(engines[k] == buf)
				{
					queries[j] = k;
					break;
				}
			}
		}
		unsigned int table[100 * 1000];
		memset((unsigned int*)table, 1001, sizeof(int) * 100 * 1000);
		int min = 1001;
		for(int k = 0; k < S; k++)
			table[k] = 0;
		table[queries[0]] = 1001;
		for(int k = 0; k < (Q - 1); k++)
		{
			for(int l = 0; l < S; l++)
			{
				if(table[l + k * S] == 1001)
					continue;
				for(int m = 0; m < S; m++)
				{
					if(m != l)
						if(table[m + (k + 1) * S] > table[l + k * S] + 1)
							table[m + (k + 1) * S] = table[l + k * S] + 1;
				}
				if(queries[k + 1] != l)
					if(table[l + (k + 1) * S] > table[l + k * S])
						table[l + (k + 1) * S] = table[l + k * S];
			}
			/*
			for(int l = 0; l < S; l++)
				cout << table[l + k * S] << ", ";
			cout << endl;
				*/
		}
		for(int k = 0; k < S; k++)
		{
			if(table[k + (Q - 1) * S] < min)
				min = table[k + (Q - 1) * S];
		}
//		cout << min << endl;
		ofs << "Case #" << i + 1 << ": " << min << endl;
	}
	return 0;
}
