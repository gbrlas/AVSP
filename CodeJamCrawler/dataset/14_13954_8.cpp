#include <string>
#include <map>
#include <math.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <fstream>

using namespace std;

#define fx first
#define sx second

typedef pair<int,int> ii;
typedef vector<int> vec;
typedef vector<ii> vecp;
typedef long long int lli;
typedef unsigned long long int ulli;



int Process(int a, int b, int k)
{
	int o=0;
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			int r=i&j;
			if(r<k) ++o;
		}
	}
	return o;
}

int main()
{
	ifstream input;
	input.open("b0.in",ios::in);
	ofstream out;
	out.open("b.out",ios::out);

	int count;
	input>>count;

	for (int i = 1; i <= count; ++i)
	{
		int a,b,k;
		input>>a>>b>>k;
		int o=Process(a,b,k);

		//printing the output
		out<<"Case #"<<i<<": ";
		out<<o;

		if(i<count) out<<endl;
	}	

	return 0;
}
