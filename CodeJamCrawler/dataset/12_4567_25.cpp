#include <stdio.h>
#include <string.h>

int is_recycle(int n, int m)
{
	char n_str[100], m_str[100];
	int n_len, m_len;
	int i;

	memset(n_str, 0, sizeof(n_str));
	memset(m_str, 0, sizeof(m_str));
	sprintf(n_str, "%d", n);
	sprintf(m_str, "%d", m);
	n_len = strlen(n_str);
	m_len = strlen(m_str);
	
	if (n_len != m_len) {
		return 0;
	}
//	printf("%s %s\n", n_str, m_str);
	for (i = 0; i < n_len; i++) {
		if (strcmp(n_str + i, m_str) == 0) {
			return 1;
		}
		n_str[n_len + i] = n_str[i];
	}
	return 0;
}

int main()
{
	int T, i, n, m, b, ret, a;
	freopen("c.txt", "r", stdin);
	freopen("c_out.txt", "w", stdout);
	
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		ret = 0;
		scanf("%d%d", &a, &b);
		for (n = a; n <= b; n++) {
			for (m = n + 1; m <= b; m++) {
				if (is_recycle(n, m)) {	
					ret++;
				}
			}
		}
		printf("Case #%d: %d\n", i, ret);
	}

	return 0;
}	
