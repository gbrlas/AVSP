#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 1010
int main()
{
	int dataset, n, ans1, ans2, t = 1;
	int i, j, k;
	double a[MAX], b[MAX];
	
	scanf("%d", &dataset);
	while(dataset--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		for(i = 0; i < n; i++)
			scanf("%lf", &b[i]);
		
		sort(a, a+n);
		sort(b, b+n);
		
		ans1 = ans2 = 0;
		for(i = 0, j = 0; i < n && j < n; ){
			if(b[j] > a[i]){
				i++; j++;
			}
			else{
				ans2++;
				j++;
			}
		}
			
		for(i = n-1, j = n-1; i >= 0 && j >= 0; ){
			if(a[i] > b[j]){
				i--; j--;
				ans1++;
			}
			else{
				j--;
			}
		}
		printf("Case #%d: %d %d\n", t++, ans1, ans2);
	}
	return 0;
}
