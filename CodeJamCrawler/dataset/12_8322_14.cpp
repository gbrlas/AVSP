#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<memory.h>
using namespace std;

long long D[20000];
long long L[20000];
long long pos[20000];
const long long INF = 2000000000;

int main()	{
	//freopen("a_sample.in","rt",stdin);
	//freopen("a_small.in","rt",stdin);
	//freopen("a_small.out","wt",stdout);
	freopen("a_large.in","rt",stdin);
	freopen("a_large.out","wt",stdout);

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++) cin>>D[i]>>L[i];
		long long TD;
		cin>>TD;
		D[n] = TD;
		L[n] = INF;
		pos[n] = 0;
		for(int i=n-1;i>=0;i--) {
			pos[i] = INF;
			for(int j=i+1;j<n+1;j++) {
				if(D[j]-D[i] > L[i]) break;
				long long curd = min(D[j]-D[i], L[j]);
				if(curd >= pos[j]) {
					pos[i] = D[j]-D[i];
					break;
				}
			}
		}
		cout<<"Case #"<<tt<<": "<<(D[0] >= pos[0]?"YES":"NO")<<endl;
	}

	return 0;
}