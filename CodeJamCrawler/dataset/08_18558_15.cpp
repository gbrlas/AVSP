#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void main()
{
	ifstream in("A-large.in");
	ofstream out("A-large.out");
	long long casenumber,t,p,k,num,f,res;
	in>>casenumber;
	for (int i=1;i<=casenumber;i++)
	{
		vector <int> freq;
		res=0;
		in>>p>>k>>num;
		for (int k=0;k<num;k++) 
		{
			in>>f;
			freq.push_back(f);
		}

		for (int l=0;l<num-1;l++)
			for (int m=0;m<num-1-l;m++)
				if (freq[m]<freq[m+1])
				{t=freq[m];freq[m]=freq[m+1];freq[m+1]=t;}
		for (int j=0;j<freq.size();j++)
		{
			res=res+freq[j]*(j/k+1);
		}
		out<<"Case #"<<i<<": "<<res<<endl;
	}
}