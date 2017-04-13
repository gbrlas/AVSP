#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#if 0
#define D(X) {cerr<<"DUMP " << #X << "='" << (X) << "'" << endl;}
#else
#define D(X)
#endif

using namespace std;
struct route
{
	int start;
	int end;
	bool fromA;
	bool used;
};

bool operator<(const struct route &a, const struct route &b)
{
	if(a.start != b.start)
		return a.start < b.start;
	return a.end < b.end;
}
int turn;
int NA,NB;

int getRoute(string in)
{
	int a,b;
	sscanf(in.c_str(),"%d:%d",&a,&b);
	return a*60 + b;
}

int main()
{
	int N;cin >> N;
	for(int cs=1;cs<=N;cs++)
	{
		cin >> turn;
		cin >> NA >> NB;
		vector<route> time;
		D(turn)
		for(int i=0;i<NA;i++)
		{
			string in;
			route r;
			cin >> in;
			r.start = getRoute(in);
			cin >> in;
			r.end = getRoute(in);
			r.fromA = true;
			r.used = false;

			time.push_back(r);
		}
		for(int i=0;i<NB;i++)
		{
			string in;
			route r;
			cin >> in;
			r.start = getRoute(in);
			cin >> in;
			r.end = getRoute(in);
			r.fromA = false;
			r.used = false;

			time.push_back(r);
		}
		sort(time.begin(),time.end());
		
		int numfromA = 0;
		int numfromB = 0;
		for(int i=0;i<time.size();i++)
		{
			if(time[i].used)
				continue;
			bool curfromA = time[i].fromA;
			if(curfromA)
				numfromA ++;
			else
				numfromB ++;

			time[i].used = true;
			int curtime = time[i].end + turn;
			D(curtime)
			
			for(int j=i+1;j<time.size();j++)
			{
				if(time[j].used)continue;
				if(time[j].start < curtime)continue;
				if(time[j].fromA == curfromA)continue;

				time[j].used = true;
				curfromA = time[j].fromA;
				curtime = time[j].end + turn;
			}
		}
		cout << "Case #" << cs << ": " << numfromA << " " << numfromB << endl;
	}
	return 0;
}
