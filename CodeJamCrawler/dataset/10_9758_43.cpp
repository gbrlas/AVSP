#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define ULL unsigned long long
#define pocz(z) (((z)>0)?prefsums[(z)]:0ll)

int main()
{
	int tst;
	scanf("%d", &tst);
	for(int w=1; w<=tst; ++w)
	{
		int r,k,n;
		scanf("%d%d%d", &r, &k, &n);
		vector<int> groups;
		vector<ULL> prefsums;
		prefsums.resize(2*n+1);
		int a,last=0;
		ULL wyn=0ll;
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &a);
			groups.push_back(a);
			if(i==0) prefsums[i]=a;
			else prefsums[i]=a+prefsums[i-1];
			if(prefsums[i]>wyn && prefsums[i]<=(ULL)k)
			{
				wyn=prefsums[i];
				last=i;
			}
		}
		for(int i=0; i<n; ++i)
		{
			prefsums[n+i]=prefsums[n+i-1]+groups[i];
		}
		//printf("%d %llu\n", last, wyn);
		for(int i=1; i<r; ++i)
		{
			//int il=lower_bound(prefsums.begin()+last, prefsums.end(),k);
			int j;
			//printf("%d\n", last);
			for(j=last+1; j<= n+last; j++)
			{
				if(prefsums[j]-((last+1)==0?0ll:prefsums[last])>(ULL)k) break;
			}
			--j;
			//printf("%llu\n", prefsums[j]-((last+1)==0?0ll:prefsums[last]));
			wyn+=prefsums[j]-((last+1)==0?0ll:prefsums[last]);
			last=j>(n-1)?j-n:j;
		}
		printf("Case #%d: %llu\n", w,wyn);
	}
}
