
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>

using namespace std;
//
int arr[10];
int bb[11][10000];

int squareSum(int x,int base)
{
	int sum=0;
	while(x)
	{
		sum+=(x%base)*(x%base);
		x/=base;
	}
	return sum;
}

int main()
{
	ifstream infile("D:\\A-small-attempt0.in.txt",ios::in);
	ofstream outfile("D:\\result.out.txt",ios::out);
	//
	int T;
	vector<int> Base;
	vector<int> Number;
	infile >> T;
	//
	for(int i=0;i<11;i++)
		for(int j=0;j<10000;j++)
		{
			bb[i][j]=-1;
		}
	//
	infile.ignore();
	for(int i=0;i<T;i++)
	{
		Base.clear();
		Number.clear();
		int t;
		char c[100];
		infile.getline(c,100);
		string s(c);
		stringstream ss(s);
		while(ss.good())
		{
			ss >> t;
			Base.push_back(t);
		}
		Number.resize(Base.size());
		//
		int j=2;
		for(;;j++)
		{
			bool flag=true;
			for(int m=0;m<Base.size();m++)
			{
				set<int> FindC;
				FindC.clear();
				Number[m]=j;
				while(Number[m]!=0&&Number[m]!=1)
				{
					FindC.insert(Number[m]);
					Number[m]=squareSum(Number[m],Base[m]);
					//if(bb[Base[m]][Number[m]]!=-1)
					//{
					//	Number[m]=bb[Base[m]][Number[m]];
					//	break;
					//}
					if(FindC.find(Number[m])!=FindC.end())
					{
						Number[m]=0;
						break;
					}
				}
				if(Number[m]==0)
				{
					//bb[Base[m]][j]=0;
					flag=false;
					break;
				}
				//else
				//{
				//	bb[Base[m]][j]=1;
				//}
			}
			if(flag)
				break;
		}
		outfile << "Case #" << i+1 << ": " << j << endl;
	}
	return 0;
}