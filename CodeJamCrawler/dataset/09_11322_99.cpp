// GCJ09.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int casecnt;
	fstream fp_in, fp_out;

	fp_in.open("D:\\Jam\\R1\\A-small.in",ios::in);
	fp_out.open("D:\\Jam\\R1\\A-small.out",ios::out);

	int l, d, n;
	fp_in>>l>>d>>n;

	vector<string> dict;
	for(int i=0; i<d; i++)
	{
		string str;
		fp_in>>str;
		dict.push_back(str);
	}

	for(int casecnt=1;casecnt<=n;casecnt++)
	{
		string str;
		fp_in>>str;
		bool read = false;
		vector<string> pattern;
		string tmp="";
		for(int i=0; i<str.length(); i++)
		{
			if(str[i] == '(')
			{
				read = true;
			}
			else if(str[i] == ')')
			{
				read = false;
				pattern.push_back(tmp);
				tmp="";
			}
			else if(read)
			{
				tmp += str[i];
			}
			else
			{
				tmp += str[i];
				pattern.push_back(tmp);
				tmp = "";
			}
		}
		int cnt=0;
		for(int i=0; i<dict.size(); i++)
		{
			bool fnd = true;
			for(int j=0; j<dict[i].length(); j++)
			{
				if(pattern[j].find_first_of(dict[i][j]) == string.npos)
				{
					fnd = false;
					break;
				}
			}
			if(fnd)
				cnt++;
		}
		fp_out<<"Case #"<<casecnt<<": "<<cnt<<endl;
		cout<<"Case #"<<casecnt<<": "<<cnt<<endl;
	}
	return 0;
}

