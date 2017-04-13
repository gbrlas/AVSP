#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010
double f1[N],f2[N];
int main(){
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		cnt++;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%lf",&f1[i]);
		for(int i=0;i<n;i++)
			scanf("%lf",&f2[i]);
		sort(f1,f1+n);
		sort(f2,f2+n);
		int ans1=0,ans2=0;
		int count1=0;
		for(int i=0;i<n;i++)
			if(f2[i]>f1[count1]){
				ans2++;
				count1++;
			}
		int count2=0;
		for(int i=0;i<n;i++)
			if(f1[i]>f2[count2]){
				ans1++;
				count2++;
			}
		printf("Case #%d: %d %d\n",cnt,ans1,n-ans2);
	}
	return 0;
}
