// GoogleCodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



bool Calc(int N, int K)
{
	vector<bool> state(N);
	vector<bool> power(N+1);
	power[0]=true;	
	while(K>0)
	{
		int i=0;
		while (i<N&&power[i])
		{
			state[i]=!state[i];
			i++;
		}
		i=0;
		while (i<N&&power[i])
		{
			power[i+1]=power[i]&&state[i];
			i++;
		}
		K--;
	}
	int i=0;
	while (i<N)
	{
		if (!power[i])
		{
			return false;
		}
		i++;
	}
	return power[i];
}

int _tmain(int argc, _TCHAR* argv[])
{
// 	if (argc<1)
// 	{
// 		cout<<"Input File Needed"<<endl;
// 		return 0;
// 	}
	fstream _file;
	_file.open("A-small-attempt1.in",ios::in);
	ofstream _ofile;
	_ofile.open("result.txt");
	if(_file)
	{
		int CaseCount,i=1;
		_file>>CaseCount;
		for (int i=1;i<=CaseCount;i++)
		{
			bool result;
			int N,K;
			_file>>N>>K;
			switch (Calc(N,K))
			{			
			case true:
				_ofile<<"Case #"<<i<<": ON"<<endl;
				break;
			case false:
				_ofile<<"Case #"<<i<<": OFF"<<endl;
				break;
			}
		}
		_file.close();
		_ofile.close();
	}
	return 0;
}