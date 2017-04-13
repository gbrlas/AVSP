#include <stdio.h>

int gcd(int a, int b)
{
	int r = 0;
	while (b != 0){
	r = a % b;
	a = b;
	b = r;
	}
	return a;
}

int is_power_of_two(int a)
{
	while (a > 1) {
		if (a % 2 != 0) {
			return 0;
		}
		a /= 2;
	}
	return 1;
}

int main()
{
	int T, ca;
	int a, b, g;
	int n, impossible;

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &T);
	for (ca = 1; ca <= T; ca++) {
		n = 0;
		impossible = 0;
		scanf("%d/%d", &a, &b);
		if (a > b) {
			impossible = 1;
			goto _out;
		}	
		g = gcd(a, b);
		a = a / g;
		b = b / g;
		if (!is_power_of_two(b)) {
			impossible = 1;
			goto _out;
		}		
		//printf("a=%d b=%d\n", a, b);
		while (b > 1) {
			n++;
			if ((a > b / 2)) {
				//printf("a=%d, b=%d, ok\n", a, b);
				break;
			}
			b = b / 2;	
		} 
_out:
		if (impossible) {
			printf("Case #%d: impossible\n", ca);
		} else {
			printf("Case #%d: %d\n", ca, n);
		}
	}
	return 0;
}

