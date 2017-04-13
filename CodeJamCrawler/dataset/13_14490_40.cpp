
#include<stdio.h>
#include<math.h>

int is_palindrome(unsigned long n) {

	unsigned long new_n = 0, r, num=n;

	if (n<10) return 1;
	
	while (n>0) {
		
		r = (unsigned long)n % 10;
		n = n / 10;

		new_n = new_n*10 + r;
	}

	if (new_n == num)
		return 1;
	
	return 0;
}

int main() {

	int n, i, count;

	unsigned long  sa, sb, a, b;

	scanf("%d", &n);

	for (i=1; i<=n; i++) {

		scanf("%ld %ld", &a, &b);
		sa = sqrt(a);
		sb = sqrt(b);

		if (sa*sa < a) sa++;
		// if (sb*sb < b) sb++;
		
		count = 0;
		while (sa <= sb) {

			if (is_palindrome(sa) && is_palindrome((sa*sa))) {
				count++;
				//printf("\n %ld", sa);
			}

			sa++;
		}
		
		printf("Case #%d: %d\n", i, count);
	}
}


