#include <stdio.h>
#include <string.h>


static int compare(const char a[51], const char b[51])
{
	int l_s;
	int l_d;
	l_s = strlen(a);
	l_d = strlen(b);
	int i;
	int ret;

	if (l_s > l_d) {
		return 1;
	} else if (l_s < l_d) {
		return -1;
	}

	for (i = 0; i < l_s; i ++) {
		if (a[i] != b[i]) break;
	}

	ret = (i == l_s) ? 0 : (a[i] > b[i]) ? 1 : (a[i] < b[i]) ? -1 : -2;
	if (ret == -2) {
		printf("%d Exception\n", __LINE__);
	}
	return ret;
}



static int sub(const char s[51], const char d[51], char out[51])
{
	char src[51];
	char dest[51];
	int tmp;
	int i;
	int l_s;
	int l_d;

	char *psrc;
	char *pdest;

	char t_str[51];
	int t_len;

	// NOTE: To keep arguments from over-writing
	strcpy(src, s);
	strcpy(dest, d);

	// Find minimal constant
	tmp = compare(src, dest);
	if (tmp < 0) { // dest - src
		psrc = dest;
		pdest = src;
	} else { // src - dest
		psrc = src;
		pdest = dest;
	} 

	// Get the length of constant
	l_s = strlen(psrc);
	l_d = strlen(pdest);

	t_len = 0;
	while (l_d > 0) {
		l_d --;
		l_s --;

		tmp = psrc[l_s] - pdest[l_d];
		if (tmp < 0) {
			i = l_s - 1;
			while (i >= 0 && psrc[i] - '1' < 0) {
				psrc[i] = '9';
				i --;
			}
			if (i < 0) {
				// EXCEPTION
				printf("%d: exception\n", __LINE__);
				return -1;
			}

			psrc[i] = (psrc[i] - '1') + '0';
			tmp += 10;
		}

		t_str[t_len++] = tmp + '0';
	}

	while (l_s-- > 0) {
		t_str[t_len++] = psrc[l_s];
	}

	//t_str[t_len] = '\0';
	// Eliminate first ZERO
	while (t_len > 0 && t_str[--t_len] == '0');

	while (t_len >= 0) {
		*out++ = t_str[t_len];

		t_len --;
	}
	*out = '\0';

	return 0;
}


static int rem(const char a[51], const char b[51], char o[51])
{
	char tmp[51];
	int ret;

	ret = compare(a, b);
	if (ret == 0) {
		strcpy(o, "0");
		return 0;
	} else if (ret < 0) {
		//printf("%d exception %s %s ret %d\n", __LINE__, a, b, ret);
		return -1;
	}

	strcpy(o, a);
	do {
		strcpy(tmp, o);
		sub(tmp, b, o);
		//printf("tmp = %s, o = %s, b = %s\n", tmp, o, b);
	} while (compare(o, b) > 0);

	return 0;
}



static int gcd(char t[][51], int N, char out[51])
{
	char a[N][51];
	char tmp[N][51];
	register int i;
	register int j;
	register int k;
	int do_exit;

	for (i = 0; i < N; i ++) {
		strcpy(tmp[i], t[i]);
	}

	//printf("GCD invoked\n");
	do_exit = 0;
	do {
		k = 0;
		for (i = 0; i < N; i ++) {
			for (j = i + 1; j < N; j ++) {
				sub(tmp[i], tmp[j], a[k]);
				//printf("%s - %s = %s\n", tmp[i], tmp[j], a[k]);
				k ++;
			}
		}

		for (i = 0; i < k; i ++) {
			strcpy(tmp[i], a[i]); // Keep clone
			//printf("[%s]", a[i]);
		}
		//printf("\n");

		// check the result
		for (i = 0; i < k; i ++) {
			//printf("%s\n", a[i]);
			if (compare(a[i], "0") == 0) {
				do_exit = 1;
			} else if (compare(a[i], "1") == 0) {
				strcpy(out, "1");
				do_exit = 1;
				break;
			} else {
				// I know, this code can be executed several times..
				strcpy(out, a[i]);
			}
		}
	} while (do_exit == 0 && k > 1);

	//printf("Result: (%s)", out);
	//for (i = 0; i < k; i ++) {
		//printf("[%s]", a[i]);
	//}
	//printf("\n");

	return 0;
}



int main(int argc, char *argv[])
{
	int nr_of_tc;
	int i;
	char t[1000][51];
	int N;
	int idx;
	char r[51];
	char g[51];

	scanf("%d\n", &nr_of_tc);

	for (i = 0; i < nr_of_tc; i ++) {
		scanf("%d", &N);
		for (idx = 0; idx < N; idx ++) {
			scanf("%s", t[idx]);
		}

		gcd(t, N, g);

		if (strcmp(g, "1")) {
//			printf("Try to get remainder t %s gcd %s\n", t[0], g);

			for (idx = 0; idx < N; idx ++) {
				if (compare(t[idx], g) > 0) {
					if (rem(t[idx], g, r) < 0) {
						printf("%d exception t:%s g:%s r:%s\n", __LINE__, t[0], g, r);
						return -1;
					}
				}
			}

			//printf("GCD %s\n", g);
			//printf("Remainder %s\n", r);
			sub(g, r, r);
		} else {
			strcpy(r, "0");
		}
		printf("Case #%d: %s\n", i+1, r);
	}

	return 0;
}



// End of a file
