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

int a[200000],b[200000];
int f[200000];
int T;
int n,D;

int main(){
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		printf("Case #%d: ",ti);
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
		memset(f,-1,sizeof(f));
		f[0]=a[0];
		bool ff=false;
		scanf("%d",&D);
		for (int i=0;i<n;i++)
		if (f[i]>=0){
			if (f[i]+a[i]>=D) {ff=true;break;}
			for (int j=i+1;j<n&&a[j]<=f[i]+a[i];j++) f[j]=max(f[j],min(b[j],a[j]-a[i]));
		}
		if (ff) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}
