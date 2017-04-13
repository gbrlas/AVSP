#include <algorithm> 
#include <cassert>
#include <cctype> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <iostream>
#include <map> 
#include <set> 
#include <string> 
#include <sstream>
#include <queue> 
#include <vector> 
using namespace std;

int C, N;
vector <int> X, Y, R;
double ans;


void solve()
{
	if (X.size()==1) ans=R[0];
	else if (X.size()==2) ans = max (R[0], R[1]);
	else
	{
		double curmin = 1000000;
		double cur;
		cur = sqrt((double)(X[0]-X[1])*(X[0]-X[1]) + (Y[0]-Y[1])*(Y[0]-Y[1])) + R[0] + R[1];
		cur = max(cur/2., (double)R[2]);
		if (cur < curmin) curmin = cur;

		cur = sqrt((double)(X[0]-X[2])*(X[0]-X[2]) + (Y[0]-Y[2])*(Y[0]-Y[2])) + R[0] + R[2];
		cur = max(cur/2., (double)R[1]);
		if (cur < curmin) curmin = cur;

		cur = sqrt((double)(X[2]-X[1])*(X[2]-X[1]) + (Y[2]-Y[1])*(Y[2]-Y[1])) + R[2] + R[1];
		cur = max(cur/2., (double)R[0]);
		if (cur < curmin) curmin = cur;
		 ans = curmin;
	}


}

void write(int i)
{
	printf("Case #%d: %lf", i, ans);
	if (i!=C) printf("\n");
}
int main()
{
	freopen("D-small.in", "r", stdin);
	freopen("D-small.out", "w", stdout);
	
	string s;


	scanf("%d",&C);
	int x,y,r;

	
	for (int i=0; i<C; i++)
	{
		X.clear(); Y.clear(); R.clear();
		scanf("%d", &N);
		for (int j=0; j<N; j++)
		{
			scanf ("%d%d%d", &x, &y, &r);
			X.push_back(x);
			Y.push_back(y);
			R.push_back(r);
		}
		solve();
		write(i+1);
	}
	return 0;
}
