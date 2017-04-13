#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k, p[5];
char str[50001], tt[50001];

int func(char *s) {
	int i, j = 0;
	char last = -1;
	for (i = 0; i < n; i++) {
		if (s[i] != last) j++;
		last = s[i];
	}
	return j;
}

int main() {
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int testcases;
	scanf("%d", &testcases);
	int i, j, ret, z;
	for (z = 0; z < testcases; z++) {
		printf("Case #%d: ", z + 1);
		scanf("%d%s",&k,str);
		n = strlen(str);
		for (i = 0; i < k; i++) p[i] = i;
		ret = n;
		while(1) {
			for (i = 0; i < n; i += k) {
				for (j = 0; j < k; j++) {
					tt[i+p[j]] = str[i+j];
				}
			}
			j = func(tt);
			if (j < ret) ret = j;
			if (!next_permutation(p,p+k)) break;
		}
		printf("%d\n",ret);
	}
	return 0;
}
