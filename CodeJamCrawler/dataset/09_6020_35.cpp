#ifdef WIN32
#pragma warning (disable: 4514 4786)
#endif
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;
int T,n;
string number;
const string max="999999999999999999999";
void main()
{
	int i,j,pos,post;
	char var,one;
	string temp,ret;
	bool flag;
	ifstream fin("AP.in");
	ofstream fout("AP.out");
	fin>>T;
	for (i=1;i<=T;i++)
	{
		flag=false;
		fin>>number;temp=number;
        n=number.length();
		for(j=0;j<n-1;j++)
		{
			if (number[j]<number[j+1]) {
				flag=true;pos=j;
			}
		}
        if (!flag) 
		{
			sort(number.begin(),number.end());
			number='0'+number;
            for (j=1;j<n+1;j++) {
				if (number[j]!='0') {
					number[0]=number[j];number[j]='0';
					break;
				}
            }
		}
		else
		{
			one=number[pos+1];post=pos+1;
			for (j=pos+2;j<n;j++) {
				if (number[j]<one&&number[j]>number[pos]) {
					one=number[j];
					post=j;
				}
			}
			number[post]=number[pos];number[pos]=one;
			sort(number.begin()+pos+1,number.end());
		}
		fout<<"Case #"<<i<<": "<<number<<endl;
	}
	fin.close();
	fout.close();
}
