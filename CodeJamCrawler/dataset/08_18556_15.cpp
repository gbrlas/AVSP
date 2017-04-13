#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

void main()
{
	ifstream in("A-large.in");
	ofstream out("A-large.out");
	int cnum,num,x,y,t;
	long long s=0;
	in>>cnum;
	for (int i=0;i<cnum;i++)
	{
		vector <int> v1;
		vector <int> v2;
		s=0;
		in>>num;
		for (int k=0;k<num;k++) 
		{
			in>>x;
			v1.push_back(x);
		}
		for (int j=0;j<num;j++) 
		{
			in>>y;
			v2.push_back(y);
		}
		{for (int l=0;l<num-1;l++)
			for (int m=0;m<num-1-l;m++)
				if (v1[m]>v1[m+1])
				{t=v1[m];v1[m]=v1[m+1];v1[m+1]=t;}}
		{for (int l=0;l<num-1;l++)
			for (int m=0;m<num-1-l;m++)
				if (v2[m]>v2[m+1])
				{t=v2[m];v2[m]=v2[m+1];v2[m+1]=t;}}
		for (int n=0;n<num;n++)
		{
			s=s+v1[n]*v2[num-1-n];
		}
		out<<"Case #"<<i+1<<": "<<s<<endl;
	}
}