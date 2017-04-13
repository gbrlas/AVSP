#include <vector>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > res;

bool solve(int l,int w, vector<pair<int,int> > rad)
{
	res.clear();
	int maxr=rad[0].first;
	int curw=-rad[0].first;
	int curl=-rad[0].first;
	int i;
	for(i=0;i<rad.size();i++)
	{
		if(curw+rad[i].first<=w)
		{
			res[rad[i].second]=make_pair(curw+rad[i].first,curl+maxr);
			curw+=2*rad[i].first;
		}
		else
		{
			curw=-rad[i].first;
			curl+=2*maxr;
			maxr=rad[i].first;
			i--;
			continue;
		}
	}
	return curl<=l;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		int n;
		int l,w;
		scanf("%d%d%d",&n,&l,&w);
		vector<pair<int,int> > rad(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&rad[i].first);
			rad[i].second=i;
		}
		sort(rad.rbegin(),rad.rend());
		bool rev=0;
		res.clear();
		res.resize(n);
		if(!solve(l,w,rad))
		{
			if(!solve(w,l,rad))
				fprintf(stderr,"WA!\n");
			rev=1;
		}
		printf("Case #%d:",test);
		for(int i=0;i<n;i++)
		{
			if(rev)
				printf(" %d.0 %d.0",res[i].first,res[i].second);
			else
				printf(" %d.0 %d.0",res[i].second,res[i].first);
		}
		puts("");

	}
	return 0;
}
