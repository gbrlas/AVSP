#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n;
double a[1010], b[1010];

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%lf",a+i);
		for (int i=0; i<n; ++i)
			scanf("%lf",b+i);
		sort(a,a+n);
		sort(b,b+n);
		int ans1=0,ans2=0;
		int i1=0,i2=0;
		for (int i=0; i<n; ++i){
			if (a[i1]>b[i2]){
				++i1;++i2;++ans1;
			} else ++i1;
		}
		i1=i2=0;
		/*for (int i=0; i<n; ++i)
			printf("%f ", a[i]);
		printf("\n");
		for (int i=0; i<n; ++i)
			printf("%f ", b[i]);
		printf("\n");*/
		for (i1=0; i1<n; ++i1){
			while (b[i2]<a[i1] && i2<n) ++i2;
			if (i2==n) break;
			++i2;
		}
		ans2=n-i1;
		printf("Case #%d: %d %d\n", T,ans1,ans2);
	}
}
