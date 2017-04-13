// ScalarProduct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "vector"
#include "string"
#include "iostream"
#include "sstream"
#include "stdio.h"
#include "math.h"
#include "algorithm"
#include "fstream"
using namespace std;


int main()
{
	ofstream fout("c:\\Scalar.txt");
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int n;
		cin>>n;
		vector<int> vx,vy;
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			vx.push_back(tmp);
		}
		for(int j=0;j<n;j++)
		{
			int tmp;
			cin>>tmp;
			vy.push_back(tmp);
		}
		sort(vx.begin(),vx.end());
		sort(vy.rbegin(),vy.rend());
		int ans=0;
		for(int j=0;j<n;j++)
			ans+=vx[j]*vy[j];
		fout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}