/*
	雛形(GCJ仕様)
 */

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
static const double EPS = 1e-9;
typedef long long ll;

int htable[1000000];
int memoized[1000000];
int base;
set<int> temp;

int ishappy(int number)
{
	if(memoized[number]) return htable[number];
	int n = number;
	int ne = 0;
	int ret = 0;
	while(n > 0)
	{
		int mod = n % base;
		ne += mod * mod;
		n = n / base;
	}
	temp.insert(number);
	if(ne == 1)
	{
		memoized[number] = 1;
		htable[number] = 1;
		ret = 1;
	}
	else if(temp.find(ne) != temp.end())
	{
		memoized[number] = 1;
		htable[number] = 0;
		ret = 0;
	}
	else
	{
		ret = ishappy(ne);
		memoized[number] = 1;
		htable[number] = ret;
	}
	temp.erase(number);
	return ret;
}

int main()
{
	string filename, infile, outfile;
	cin >> filename;
	infile = filename + ".in";
	outfile = filename + ".out";
	ifstream ifs;
	ofstream ofs;
	ifs.open(infile.c_str(), ios::in);
	ofs.open(outfile.c_str(), ios::out);
	int Casenum;
	string b;
	getline(ifs, b);
	Casenum = atoi(b.c_str());
	for(int Casecount = 0; Casecount < Casenum; Casecount++)
	{
		char buf[50];
		int bases[10];
		int i = 0;
		getline(ifs, b);
		strcpy(buf, b.c_str());
		char* token;
		token = strtok(buf, " ");
		while(token != NULL)
		{
			bases[i++] = atoi(token);
			token = strtok(NULL, " ");
		}
		int n = 2;
		while(1)
		{
			temp.clear();
			for(int j = 0; j < i; j++)
			{
				memset(memoized, 0, sizeof(memoized));
				base = bases[j];
				if(!ishappy(n)) goto fail;
			}
			break;
		fail:
			n++;
		}
		ofs << "Case #" << (Casecount + 1) << ": " << n << endl;
	}
}



/*
PRIME_MAXまでの素数表をつくる(Erathosthenesの篩)
 */
#define PRIME_MAX 1000000
char isprime[PRIME_MAX + 1];
void erathosthenes()
{
	for(int i = 2; i <= PRIME_MAX; i++) isprime[i] = 1;
	for(int i = 2; i <= sqrt(PRIME_MAX) + 1; i++)
	{
		if(!isprime[i]) continue;
		for(int j = 2 * i; j <= PRIME_MAX; j += i)
			isprime[j] = 0;
	}
}
