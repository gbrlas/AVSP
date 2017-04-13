#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<stdio.h>
using namespace std;

#define SMALL
//#define LARGE

int main()	{

	freopen("1.in","r",stdin);
	
#ifdef SMALL	
	freopen("1_small_1.in","r",stdin);
	freopen("1_small_1.out","w",stdout);
#endif

#ifdef LARGE	
	freopen("1_large.in","r",stdin);
	freopen("1_large.out","w",stdout);
#endif
	
	int tc;
	cin>>tc;
	for(int tt=1; tt<=tc; tt++)	{
		int n, x, ind;
		cin>>n;
		int last[2]={1,1}, cnt[2]={0,0};
		char c;
		int ans = 0;
		for(int i=0;i<n;i++) {
			cin>>c>>x;
			if(c == 'O') ind = 0;
			else ind = 1;
			ans += max(0, abs(last[ind]-x) - cnt[!ind]) + 1;
			cnt[ind] += max(0, abs(last[ind]-x) - cnt[!ind]) + 1;
			cnt[!ind] = 0;
			last[ind] = x;
		}
		cout<<"Case #"<<tt<<": ";
		cout<<ans<<endl;
	}
	

	return 0;
}
