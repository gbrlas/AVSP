// TheNextNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string str;
		cin>>str;
		cout<<"Case #"<<i+1<<": ";
		if(next_permutation(str.begin(),str.end()))
		{
			cout<<str;
		}
		else
		{
			str.insert(str.begin(),'0');
			sort(str.begin(),str.end());
			for(int i=0;i<str.size();i++)
			{
				if(str[i]!='0')
				{
					swap(str[0],str[i]);
					break;
				}
			}
			cout<<str;
		}
		cout<<endl;
	}
	return 0;
}

