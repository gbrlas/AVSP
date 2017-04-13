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

using namespace std;

#define MP make_pair
#define PB push_back

vector<pair<double,int> >p;
int n;
double d;

bool check(double t){
	double la=-1e100;
	for (int z=0;z<p.size();z++){
		double pos=p[z].first;
		int n=p[z].second;
		la=max(la+d,pos-t);
		if (la+(n-1)*d>pos+t) return false;
		la+=(n-1)*d;
	}
	return true;
}

int main(){
	int T,ti=0;
	for(scanf("%d",&T);T--;){
		scanf("%d%lf",&n,&d);
		p.clear();
		for (int i=0;i<n;i++){
			double a;
			int b;
			scanf("%lf%d",&a,&b);
			p.PB(MP(a,b));
		}
		sort(p.begin(),p.end());
		double l=0,r=1e20,m;
		for (int z=0;z<300;z++){
			m=(l+r)/2;
			if (check(m)) r=m;
			else l=m;
		}
		printf("Case #%d: %.10f\n",++ti,r);
	}
    return 0;
}
