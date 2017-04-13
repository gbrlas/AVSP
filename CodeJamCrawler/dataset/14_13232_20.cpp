#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
//		int n,ans,maxi=0;
		int n,ans;
		scanf("%d",&n);
		vector<int> a(n);
		ans=n*n+n;
		for (int i=0; i<n; ++i) {
			scanf("%d",&a[i]);
//			if (a[i]>a[maxi]) {
//				maxi=i;
//			}
		}
//		a.erase(a.begin()+maxi);
//		--n;
//		for (int k=0; k<=n; ++k) {
//			vector<int> b=a,c=a;
//			sort(b.begin(), b.begin()+k);
//			sort(b.begin()+k, b.end(),greater<int>());
//			int sum=abs(maxi-k);
//			for (int i=0; i<n; ++i) {
//				int j=i;
//				for (; j<n; ++j) {
//					if (b[i]==c[j]) {
//						break;
//					}
//				}
//				sum+=abs(j-i);
//				while (j>i) {
//					int tmp=c[j];
//					c[j]=c[j-1];
//					c[--j]=tmp;
//				}
//			}
//			if (sum<ans) {
//				ans=sum;
//			}
//		}
		vector<int> b(a);
		sort(b.begin(), b.end());
		do{
			int i=1;
			for (; i<n&&b[i-1]<b[i]; ++i);
			for (; i<n&&b[i-1]>b[i]; ++i);
			if (i!=n) {
				continue;
			}
			int sum=0;
			vector<int> c(a);
			for (int i=0; i<n; ++i) {
				int j=i;
				for (; j<n; ++j) {
					if (b[i]==c[j]) {
						break;
					}
				}
				sum+=abs(j-i);
				while (j>i) {
					int tmp=c[j];
					c[j]=c[j-1];
					c[--j]=tmp;
				}
			}
			if (sum<ans) {
				ans=sum;
			}
		}while (next_permutation(b.begin(), b.end()));
		printf("Case #%d: %d\n",iT,ans);
	}
    return 0;
}