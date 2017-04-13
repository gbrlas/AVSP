// C1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
//#include <ofstream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fp_in;
	ofstream fp_out;
	fp_in.open("D:\\Ravi\\A-small.in.txt",ios::in);
	fp_out.open("D:\\Ravi\\A-small.out.txt",ios::out);

	int ca;
	fp_in>>ca;
	for(int i=1; i<=ca; i++)
	{
		int a[200];
		for(int j=0;j<200;j++)
			a[j]=-1;

		char bt[100];
		fp_in>>bt;
		string in=bt;
		int val=-1;
		a[in[0]]=1;
		string ret = "1";
		for(int j=1;j<in.size();j++)
		{
			if(a[in[j]] == -1)
			{
				val++;
				if(val==1)
					val++;
				a[in[j]] = val;
			}
			char c = a[in[j]]+'0';
			ret += c;
		}
		int base;
		if(val<=0)
			base = 2;
		else
			base = val+1;

		__int64 res=0;
		for(int j=0; j<ret.length(); j++)
		{
			res = res*base+ ret[j]-'0';
		}
		cout<<"Case #"<<i<<": "<<res<<endl;
		fp_out<<"Case #"<<i<<": "<<res<<endl;
	}
	return 0;
}

