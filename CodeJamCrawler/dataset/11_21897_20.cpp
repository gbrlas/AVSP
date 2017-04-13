#include <stdio.h>
int main()
{
    long long int n;
    int p_d, p_g, t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
        scanf("%I64d%d%d", &n, &p_d, &p_g);
        int a = p_d, b = 100, temp;
        while (a) { a = b %= temp = a; b = temp; }
        printf("Case #%d: %s\n", i + 1, (((100 / b <= n) && !(p_d < 100 && p_g == 100) && !(p_d > 0 && p_g == 0)) ? "Possible" : "Broken"));
    }
    return 0;
}
