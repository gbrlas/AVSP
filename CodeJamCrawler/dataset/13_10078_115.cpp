#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
#define LARGE 1

int a[200][200];

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small.i", "rt", stdin);
	freopen("b_small.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		bool yes = true;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) {
				bool ok = true;
				for(int k=0;k<n;k++) {
					if(k==i) continue;
					if(a[k][j] > a[i][j]) {
						ok = false;
						break;
					}
				}
				if(ok)
					continue;
				ok = true;
				for(int k=0;k<m;k++) {
					if(k==j) continue;
					if(a[i][k] > a[i][j]) {
						ok = false;
						break;
					}
				}
				if(ok)
					continue;
				yes = false;
				goto END;
			}
		END:
		cout<<"Case #"<<tt<<": ";
		if(yes)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}

	return 0;
}
