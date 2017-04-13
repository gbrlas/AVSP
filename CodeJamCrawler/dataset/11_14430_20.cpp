// 2011Round1A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
using namespace std;

//Problem A
int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		long long N;
		int Pd,Pg;
		cin>>N>>Pd>>Pg;
		int found=0;
		for(int i=1;i<=min(N,100LL);i++)
		{
			if((i*Pd)%100 == 0)
			{
				found=1;
				break;
			}
		}
		if(found==0)
		{
			cout<<"Case #"<<tc+1<<": Broken"<<endl;
			continue;	
		}
		if(Pd<100 && Pg==100 || Pd>0 && Pg==0)
		{
			cout<<"Case #"<<tc+1<<": Broken"<<endl;
		}
		else
		{
			cout<<"Case #"<<tc+1<<": Possible"<<endl;
		}
	}

	return 0;
}

