// SnapperChain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int N,K;
		cin>>N>>K;
		int mask=1;
		int lightson=1;
		for(int i=0;i<N;i++)
		{
			if((K&mask)==0) lightson=0;
			mask<<=1;
		}
		if(lightson)
			cout<<"Case #"<<tc+1<<": ON"<<endl;
		else
			cout<<"Case #"<<tc+1<<": OFF"<<endl;

	}
	return 0;
}

