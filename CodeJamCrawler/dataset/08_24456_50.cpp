#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<fstream>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define all(a) (a).begin(),(a).end()
ifstream fin;
ofstream fout;

int main()
{
	int t;
	//char p;
	fin.open("C:\\A-small-attempt1.in");
	fout.open("C:\\output19.txt");
	fin>>t;
	string str;
	int n=0,q=0;
	int total=t;
	while(t--)
	{
		fin>>n;
		vector<string> engine(n,"");
		fin.ignore();
		int switches=0;
		FOR(i,0,n)
			getline(fin,engine[i],'\n');
		fin>>q;
		if(q==0)
		{
			int p=0;
			fout<<"Case #"<<total-t<<": "<<p<<endl;
			continue;
		}
		fin.ignore();
		vector<string>queries(q,"");
		FOR(j,0,q)
			getline(fin,queries[j],'\n');
		int currsearchengine=-1;
		int done=0;
		int curri=0;
		int maxi;
		while(!done)
		{
			maxi=-999;
			FOR(l,0,n)
			{
				if(l==currsearchengine)
					continue;
				if(find(queries.begin()+curri,queries.end(),engine[l])==queries.end())
				{
					fout<<"Case #"<<total-t<<": "<<switches<<endl;
					done=1;
					break;
				}
				int firstindex=find(queries.begin()+curri,queries.end(),engine[l])-(queries.begin());
				if(maxi<firstindex)
				{
					maxi=firstindex;					
				}
			}
			if(done!=1 && maxi!=-1)
			{
			 currsearchengine=(find(all(engine),queries[maxi])-engine.begin());
			 curri=maxi;
			 switches++;
			}
		}
	}
}

