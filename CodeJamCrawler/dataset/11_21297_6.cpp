#include <stdio.h>
#include <stdlib.h>

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void gcd(int a, int b, int &d)
{
	if (!b) d = a;
	else gcd(b, a % b, d);
}

void gcd_(int a, int b, int &d)
{
	int t = 1, c;
	if (a < b) swap(a, b);
	while(b)
	{
		if (!a & 1){ a = a / 2; c = 0;} else c = 1;
		if (!b & 1){ b = b / 2; d = 0;} else d = 1;
		if (!c && !d) t <<= 1;
		else a = a - b;
		if (a < b) swap(a, b);
//		printf("a = %d, b = %d\n", a, b);
	}
	d = t * a;
}
//ax + by = gcd(a,b)
void gcd_E(int a, int b, int &d, int &x, int &y)
{
	int a1, b1;
	if (!b){d = a; x = 1; y = 0; return;}
	gcd_E(b, a % b, d, y, x);
	y = y - x * (a / b);
}

void linear_multians(int a, int b, int c, int &x, int &y)
{
	int d;
	if (a >= b) gcd_E(a, b, d, x, y);
	else gcd_E(b, a, d, y, x);
	if (c % d != 0) {x = 0; y = 0;return;}
	x = x * c / d;
	y = y * c / d;
	//{x + k * b / d}, {y - k * a / d}, k = -inf...+inf
}

int mod(int a, int b)
{
	return (a % b + b) % b;
}

int inv(int a, int n)
{
	int d, x, y;
	if (a >= n) gcd_E(a, n, d, x, y);
	else gcd_E(n, a, d, y, x);
	if (d != 1) return -1;// gcd(a,n) = 1
	return mod(x, n);
}

int linear_mod_equation(int a, int b, int n, int x)
{
	//ax = b (mod n)
	//x = inv(a/d) * b/d mod (n / d)
	int i, d, y, ans, sol;
	if (a >= n) gcd_E(a, n, d, x, y);
	else gcd_E(n, a, d, y, x);
	//ax + ny = d
	//a'x + n'y = 1
	ans = sol = mod(x * b / d, n);
	for (i = 1; i < d; i++){
		sol = mod(sol + n / d, n);
		if (ans > sol || ans <= 0) ans =  sol;
	}
	return ans;
}

int f[101] = {0};

int main(){
	int i, j, k, T, N, Pg, Pd;
	freopen("A_s.in","r", stdin);
	freopen("A.out","w",stdout);
	f[1] = 100;
	for (i = 2; i <= 100; i++){
		f[i] = linear_mod_equation(i, 0, 100, 0);
//		printf("%d: %d\n", i, f[i]);								//
	}
	scanf("%d", &T);
	for (i = 1; i <= T; i++){
		scanf("%d %d %d", &N, &Pd, &Pg);
		printf("Case #%d: ", i);
//		printf("%d %d %d", N, Pd, Pg);								//
		if (Pg == 0 && Pd > 0) printf("Broken\n");
		else if (Pg == 0 && Pd == 0) printf("Possible\n");
		else if (Pg == 100 && Pd < 100) printf("Broken\n");
		else if (Pd == 0)printf("Possible\n");
		else{
			if (f[Pd] != 0 && f[Pd] <= N) printf("Possible\n");
			else printf("Broken\n");
		}
	}
//    system("pause");
    return 0;
}
	
