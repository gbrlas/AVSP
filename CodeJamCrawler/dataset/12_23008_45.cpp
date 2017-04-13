#include <cstdio>
using namespace std;

int T, a, b, tmp, digit, ans;
int fact[10];

int main(){
	fact[0] = 1;
	fact[1] = 10;
	for(int i = 2; i <= 10; i++){
		fact[i] = 10 * fact[i-1];
	}
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		ans = 0;
		scanf("%d %d", &a, &b);
		tmp = a;
		digit = 1;
		for(int i = 0; i <= 7; i++){
			if(tmp / fact[i] >= 10) digit++;
		}
		for(int i = a; i <= b; i++){
			for(int j = 1; j < digit; j++){
				tmp = i / fact[j] + i % fact[j] * fact[digit - j];
				if(tmp > i && tmp >= a && tmp <= b) ans++;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
