#include <stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;
double arr[1002],brr[1002],a[1002],b[1002];
int main()
{
	int t,i,n,j,k;
	int x,count;
	cin>>t;
	for(i=0;i<t;i++) {
		x = 0;
		count=0;
		cin>>n;
		for(j=0;j<n;j++) {
			cin>>arr[j];
			a[j] = arr[j];
		}
		for(j=0;j<n;j++) {
			cin>>brr[j];
			b[j] = brr[j];
		}
		sort(arr,arr+n);
		sort(brr,brr+n);
		sort(a,a+n);
		sort(b,b+n);
		for(j=0;j<n;j++) {
			for(k=0;k<n;k++) {
				if(arr[k] > brr[j]) {
					arr[k] = 0;
					brr[j] = 0;
					x++;
					break;
				}
			}
		}
		for(j=0;j<n;j++) {
			for(k=0;k<n;k++) {
				if(b[k] > a[j]) {
					count++;
					b[k] = 0;
					a[j] = 0;
					break;
				}
			}
		}
		printf("Case #%d: %d %d\n",i+1,x,n-count);
	}
	return 0;
}
