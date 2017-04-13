#include "stdafx.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include <string>
#include <map>
using namespace std;
class Welcome
{
public:
	int f(const string &str)
	{
		map<char, vector<int> > a;
		int cnt[20];
		string s="welcome to code jam"; 
		for(int i=0; i<s.length(); i++)
		{
			a[s[i]].push_back(i+1);
			cnt[i+1] = 0;
		}
		cnt[0] = 1;

		for(int i=0; i<str.length(); i++)
		{
			vector<int> v = a[str[i]];
			for(int j=0; j<v.size(); j++)
			{
				cnt[v[j]] += cnt[v[j]-1];
				cnt[v[j]] = cnt[v[j]]%10000;
			}
		}
		return cnt[19];
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
int casecnt;
	fstream fp_in, fp_out;

	fp_in.open("C:\\Documents and Settings\\rxv22\\My Documents\\GCJ\\C-small.in",ios::in);
	fp_out.open("C:\\Documents and Settings\\rxv22\\My Documents\\GCJ\\C-small.out",ios::out);
	fp_in>>casecnt;
	char s[501];
	fp_in.getline(s,501);
	for(int e=1; e<=casecnt; e++)
	{
		char s[501];
		fp_in.getline(s,501);
		string str(s);
		Welcome w;
		int ret = w.f(str);
		char sret[5];
		sprintf(sret,"%04d",ret);
		fp_out<<"Case #"<<e<<": "<<sret<<endl;
		cout<<"Case #"<<e<<": "<<sret<<endl;
	}
	return 0;
}