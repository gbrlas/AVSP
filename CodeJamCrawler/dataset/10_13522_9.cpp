#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

#define  len 10;

struct node
{
    int a;
	int b;
};

struct p
{
    double x;
	double y;
};

vector<node> data;
vector<pair<double,double> > result;
int N;


bool cmp(node a,node b)
{
	return a.a<b.a;
}

int main()
{
	ifstream fin("A-small-attempt2.in");
	ofstream fout("A-small-attempt2.out");
	int T;
	fin>>T;
    int count=0;
	for(int i=0;i<T;i++)
	{
		fin>>N;
		count=0;
		data.clear();
		result.clear();
		data.resize(N);
		for (int j=0;j<N;j++)
		{
             fin>>data[j].a>>data[j].b;
		}
		sort(data.begin(),data.end(),cmp);
		for (int j=0;j<N;j++)
		{
            double k1=(double)(data[j].b-data[j].a);
			double b1=(double)data[j].a;
			for (int t=j+1;t<N;t++)
			{
				double k2=(double)(data[t].b-data[t].a);
				double b2=(double)data[t].a;
				if(k1==k2)continue;
                double x=(b2-b1)/(k1-k2);
				double y=(b1*k2-b2*k1)/(k2-k1);
				pair<double,double> temp;
				temp=make_pair(x,y);
				if(x>=0 && x<=1 && y>=min(data[t].a,data[t].b) && y<=max(data[t].b,data[t].a))
				{
					if(!result.empty())
					{
						int l;
						for (l=0;l<result.size();l++)
						{
							if(fabs(result[l].first-x)<0.000001 && fabs(result[l].second-y)<0.000001)
								break;
						}
						if(l==result.size())
						{
							count++;
							result.push_back(temp);
						}
					}
					else
					{
						count++;
						result.push_back(temp);
					}
				}
				
				
			}

		}
		fout<<"Case #"<<(i+1)<<": "<<count<<endl;
	}
	//cin.get();
	return 0;
}