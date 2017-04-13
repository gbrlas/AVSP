#include<cstdio>
int min(int a,int b){
	return a < b ? a : b;
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0;i < t;i++) {
		int n;
		scanf("%d", &n);
		int m = 1<<30;
		int sum = 0;
		int ok = 0;
		for(int j = 0;j < n;j++) {
			int at;
			scanf("%d", &at);
			m = min(m, at);
			sum += at;
			ok ^= at;
		}
		printf("Case #%d: ", i+1);
		if(ok == 0) {
			printf("%d\n", sum - m);
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
