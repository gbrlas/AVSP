// ProblemD.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "math.h"
#include "algorithm"
#include "fstream"
#include "sstream"
#include "assert.h"
using namespace std;

double solve()
{
	int N;
	cin>>N;
	int X[10]={};
	int Y[10]={};
	int R[10]={};
	for(int i=0;i<N;i++)
	{
		cin>>X[i]>>Y[i]>>R[i];
	}
	if(N==1)
		return R[0];
	if(N==2)
		return max(R[0],R[1]);
	double ans=-1;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			int dist2=(X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
			double r1 = (sqrt((double)dist2)+R[i]+R[j])/2;
			int k=3-i-j;
			assert(k!=j); assert(k!=i);
			double r2=R[k];
			double t=max(r1,r2);
			if(ans<0 || ans>t)
				ans=t;
		}
	}
	return ans;
}
int main()
{
	int C;
	cin>>C;
	for(int tc=0;tc<C;tc++)
	{
		double ans = solve();
		cout<<"Case #"<<tc+1<<": ";
		printf(" %.8lf\n",ans);
	}
	return 0;
}

