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

int main()
{
	ifstream input;
	input.open("A-small-attempt0.in",ios::in);
	ofstream out;
	out.open("a.out",ios::out);

	int count;
	input>>count;

	int* grid= new int[16]();
	int r1,r2;

	for (int i = 1; i <= count; ++i)
	{
		input>>r1;
		int t;
		for (int j = 0; j < 16; ++j)
		{
			input>>t;
			if(j/4+1==r1)
			{
				grid[t-1]=1;
				// cout<<t<<" ";
			}
		}
		// cout<<endl;

		input>>r2;
		for (int j = 0; j < 16; ++j)
		{
			input>>t;
			if(j/4+1==r2)
			{
				grid[t-1]-=2;
				// cout<<t<<" ";
			}
		}
		// cout<<endl;
		for (int j = 0; j < 16; ++j)
		{
			// cout<<grid[j]<<" ";
		}
		// cout<<endl;
		
		int sum=0;
		for (int j = 0; j < 16; ++j)
		{
			sum+= grid[j]==-1;
		}
		// cout<<sum<<endl;

		//printing the output
		out<<"Case #"<<i<<": ";
		if(sum==0) out<<"Volunteer cheated!";
		else if(sum>1) out<<"Bad magician!";
		else
		{
			for (int j = 0; j < 16; ++j)
			{
				if(grid[j]==-1) out<<j+1;
			}
		}
		delete grid;
		grid= new int[16]();

		if(i<count) out<<endl;
	}	

	return 0;
}
