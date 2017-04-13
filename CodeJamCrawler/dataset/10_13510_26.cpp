#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<string> e;
vector<string>  data;
vector<string> temp; 

int M,N;

int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int T;
	fin>>T;
    int count=0;
	for(int i=0;i<T;i++)
	{
        e.clear();
		data.clear();
		count=0;
		fin>>N>>M;
		e.resize(N);
		data.resize(M);
		for (int j=0;j<N;j++)
		{
			fin>>e[j];
		}
		for (int j=0;j<M;j++)
		{
			fin>>data[j];
		}
		for(int j=0;j<N;j++)
		{
			string tmp;
			int k=1;
			while ( k<e[j].size())
			{
                if(e[j][k]=='/')
				{
					tmp=e[j].substr(0,k);
					e.push_back(tmp);
				}
				k++;
			}
		}
		for (int j=0;j<M;j++)
		{
            temp.clear();
			string tmp;
			int k=1;
			while ( k<data[j].size())
			{
				if(data[j][k]=='/')
				{
					tmp=data[j].substr(0,k);
					temp.push_back(tmp);
				}
				k++;
			}
			if(k==data[j].size())
				temp.push_back(data[j]);
			int t;
			for(t=0;t<temp.size();t++)
			{
				vector<string>::iterator iter=find(e.begin(),e.end(),temp[t]);
				if(iter==e.end())
					break;
			}
			count+=(temp.size()-t);
			for (int l=t;l<temp.size();l++)
			{
				e.push_back(temp[l]);
			}
		}
		 fout<<"Case #"<<(i+1)<<": "<<count<<endl;

	}
	//cin.get();
	return 0;
}