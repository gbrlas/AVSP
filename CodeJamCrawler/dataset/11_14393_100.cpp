// 2011Qual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "string"
#include "iostream"
#include "vector"
#include "algorithm"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N;
		cin>>N;
		int pos1=1, pos2=1;
		int t1=0, t2=0;
		for(int i=0;i<N;i++)
		{
			char ch;
			int k;
			cin>>ch>>k;
			if(ch=='O')
			{
				t1+=abs(k-pos1)+1;
				t1=max(t1,t2+1);
				pos1=k;
			}
			else
			{
				t2+=abs(k-pos2)+1;
				t2=max(t1+1,t2);
				pos2=k;
			}
		}
		cout<<"Case #"<<tc+1<<": "<<max(t1,t2)<<endl;
	}
	return 0;
}

