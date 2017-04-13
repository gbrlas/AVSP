#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#define eps 1e-8
using namespace std;

#define MP make_pair
#define PB push_back

int T,ti=0;
int n;
vector<pair<int,int> > a;

int main(){
	for (scanf("%d",&T);T--;){
		double ans=0;
		int len,n;
		double sp,sr,lt;
		scanf("%d%lf%lf%lf%d",&len,&sp,&sr,&lt,&n);
		a.clear();
		for (int i=0;i<n;i++){
			int b,e,w;
			scanf("%d%d%d",&b,&e,&w);
			a.PB(MP(w,e-b));
			len-=e-b;
		}
		a.PB(MP(0,len));
		sort(a.begin(),a.end());
		ans=0;
		for (int z=0;z<a.size();z++){
			int l=a[z].second;
			int w=a[z].first;
			double t=l/(w+sr);
			if (t<lt+eps){
				lt-=t;
				ans+=t;
			}
			else {
				double ls=l-lt*(sr+w);
				ans+=lt+ls/(sp+w);
				lt=0;
			}
		}
		printf("Case #%d: %.10f\n",++ti,ans);
	}
    return 0;
}
