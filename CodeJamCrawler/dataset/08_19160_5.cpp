// algoSLN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("e:\\test.in");
	int n;
	fin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		int seNum;
		fin >> seNum;
		map<string,int> seName;
		vector<string> seNameVec;
		getline(fin, s);
		for (int j = 0; j < seNum; j++)
		{
			getline(fin, s);
			seName[s] = 0;
			seNameVec.push_back(s);
		}

		int quNum;
		fin >> quNum;
		vector<string> quName;
		getline(fin, s);
		for (int j = 0; j < quNum; j++)
		{
			getline(fin, s);
			quName.push_back(s);
		}

		int count = 0;
		int res = 0;
		for (int j = 0; j < quNum; j++)
		{
			string namestr = quName[j];
			if (seName[namestr] == 0)
			{
				count++;
				seName[namestr] = 1;
			}

			if (count == seNum)
			{
				res++;
				count=1;
				for (int k = 0; k < seNum; k++)
				{
					seName[seNameVec[k]] = 0;
				}
				seName[namestr] = 1;
			}
		}
		cout <<"Case #" <<i+1<<": "<<res<<endl;

	}
	
	system("PAUSE");
	return 1;
}

