// AlienLanguage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "vector"
#include "iostream"
#include "algorithm"
#include "string"
#include "fstream"
using namespace std;

int match(string A, string B)
{
	int j=0;
	for(int i=0;i<A.size();i++,j++)
	{
		if(B[j]=='(')
		{
			int isfound=0;
			while(B[j]!=')')
			{
				if(B[j]==A[i]) isfound=1;
				j++;
			}
			if(isfound==0) return 0;
		}
		else
		{
			if(B[j]!=A[i]) return 0;
		}
	}
	return 1;
}

int main()
{
	int L,D,N;
	cin>>L>>D>>N;
	vector<string> dict;
	for(int i=0;i<D;i++)
	{
		string str;
		cin>>str;
		dict.push_back(str);
	}
	for(int i=0;i<N;i++)
	{
		string str;
		cin>>str;
		int ans=0;
		for(int j=0;j<dict.size();j++)
		{
			if(match(dict[j],str))
				ans++;
		}
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}

