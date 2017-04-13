// C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;

vector<int>  temp;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C-small-attempt0.out");
	int T,R,K,N;
	fin>>T;
	queue<int> q;
	int money;
	for(int i=0;i<T;i++)
	{
		money=0;
		while(!q.empty())
			q.pop();
		fin>>R>>K>>N;
		for(int j=0;j<N;j++)
		{
			int temp;
			fin>>temp;
			q.push(temp);
		}
		int total,time;
		for(int j=0;j<R;j++)
		{
			total=0;
			time=0;
			while(total<=K && time<N)
			{	
				int t=q.front();
				total+=t;
				if(total>K)
				{
					total-=t;
					break;
				}
				q.pop();
				q.push(t);
				time++;
			}
			money+=total;
		}
		fout<<"Case #"<<(i+1)<<": "<<money<<endl;
	}
	cin.get();
	return 0;
}

