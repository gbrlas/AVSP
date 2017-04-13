#include<iostream>
#include<algorithm>
using namespace std;

__int64 a[1000];
__int64 b[1000];

bool cmp(__int64 a, __int64 b){
	return a > b;
}

int main()
{
	int T,i,n , dd = 1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);	

		for(i =0;  i< n ; i ++)	scanf("%I64d",&a[i]);
		for(i =0;  i< n ; i ++)	scanf("%I64d",&b[i]);

		sort(a,a+n);
		sort(b,b+n,cmp);

		__int64 sum = 0;

		for(i =0; i < n ;  i++)
			sum += a[i]*b[i];
		
		printf("Case #%d: %I64d\n",dd++,sum);
	}
	return 0;
}
