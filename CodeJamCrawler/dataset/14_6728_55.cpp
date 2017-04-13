#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	int t;
	cin>>t;
	for(int index = 1;index<=t;index++) {
		double c,f,x;
		cin>>c;
		cin>>f;
		cin>>x;
		double nd = (x/c-2/f-1);
		double res;
		if( nd< 0.000001) {
			res = x/2;
		}else {
			int n = floor(nd);
			res =0;
			for(int i=0;i<=n;i++) {
				res+=c/(2+i*f);
			}
			res+=x/(2+(n+1)*f);
		}
		cout<<"Case #"<<index<<": "<<fixed << setprecision(7)<<res<<endl;
	}
}