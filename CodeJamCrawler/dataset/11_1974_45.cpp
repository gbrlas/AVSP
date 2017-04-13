#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>


#define ff first
#define ss second

using namespace std;

bool Gr(int a, int b)
{
	if (a>b) return true;
	else return false;
}

int main()
{

	vector<long long> Res;
	freopen("inC_L.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int n,m,z;
	long long sum;
	cin>>n;

	for(int i=0;i<n;++i)
	{
		cin>>m;
		vector<int> bag;
		sum=0;
		for(int j=0;j<m;++j)
		{
			cin>>z;
			sum=sum^z;
			bag.push_back(z);
		}
		if (sum) 
			{
				Res.push_back(-1);
				continue;
			}
		
		sort(bag.begin(),bag.end(),Gr);
		sum=0;
		for(int i=0;i<m-1;++i)
		{
			sum+=bag[i];
		}
		Res.push_back(sum);
	}
	for(int i=0;i<Res.size();++i)
	{
		fprintf(stdout,"Case #%i: ",i+1);
		if (Res[i]!=-1)cout<<Res[i]<<endl;
		else cout<<"NO"<<endl;
	}

	
	return 0;
}