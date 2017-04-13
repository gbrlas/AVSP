#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int t, s, p;
		int a[100];
		scanf("%d%d%d", &t, &s, &p);
		for(int j = 0; j < t; j++){
			scanf("%d", &a[j]);
		}
		sort(a, a + t);
		int cnt = 0;
		for(int j = 0; j < t; j++){
			if(s && a[j] >= (p-1)*3-1 && p >= 2){
				cnt++;
				s--;
			}
			else{
				if(a[j] >= p*3-2) cnt++;
			}
		}
		printf("Case #%d: %d\n", i+1, cnt);
	}
	
	return 0;
}