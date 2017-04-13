// C2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fp_in;
	ofstream fp_out;
	fp_in.open("D:\\Ravi\\B-small.in.txt",ios::in);
	fp_out.open("D:\\Ravi\\B-small.out",ios::out);

	int ca;
	fp_in>>ca;
	for(int i=1; i<=ca; i++)
	{
		int p, q;
		fp_in>>p>>q;
		vector<int> v;
		for(int j=0;j<q;j++)
		{
			int val;
			fp_in>>val;
			v.push_back(val);
		}
		
		int maxcost = 10000;
		do
		{
			vector<pair<int, int> > groups;
			groups.push_back(pair<int,int>(1,p));
			int cost = 0;
			for(int j=0; j<v.size(); ++j)
			{
				for(vector<pair<int,int> >::iterator k=groups.begin(); k!=groups.end(); k++)
				{
					int a = k->first;
					int b = k->second;
					if(v[j]>=a && v[j]<=b)
					{
						groups.erase(k);
						if(a != v[j])
						{
							groups.push_back(pair<int, int>(a,v[j]-1));
							cost += v[j]-a;
						}
						if(b != v[j])
						{
							groups.push_back(pair<int, int>(v[j]+1, b));
							cost += b-v[j];
						}
						break;
					}
				}
			}
			if(maxcost>cost)
				maxcost = cost;
		} 
		while(next_permutation(v.begin(), v.end()));
		cout<<"Case #"<<i<<": "<<maxcost<<endl;
		fp_out<<"Case #"<<i<<": "<<maxcost<<endl;
	}

	return 0;
}

