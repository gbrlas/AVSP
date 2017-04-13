#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>

typedef long long ll;

const double PI = atan(1.0) * 4.0;
const int inf = 1000000009;
const double eps = 1e-8;

#define F0(i,n) for(int i=0;i<(n);i++)
#define F1(i,n) for(int i=1;i<=(n);i++)

using namespace std;

int k;
char str[50010];
int p[20];
int len;

int compress(int p[]) {
    char str2[len + 1];

    int offset = 0;
    
    for (int i = 0, j = 0; i < len; ++i, ++j) {
	if (j == k){
	    offset += k;
	    j = 0;
	}
	str2[i] = str[offset + p[j]];
    }
/*    
    for (int i = 0; i < len; ++i)
	printf("%c", str2[i]);
    printf("\n");
*/
    int cnt = 1;
    for (int i = 1; i < len; ++i)
	if (str2[i] != str2[i-1]) cnt++;    
    
    return cnt;
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    // TODO: check long long carefully.

    for (int cas = 1; cas <= caseN; ++cas) {
	printf("Case #%d:", cas);

	scanf("%d %s", &k, str);

	for (int i = 0; i < k; ++i)
	    p[i] = i;

	len = strlen(str);
		

	int cnt = len;
	do {
	   /*
	    for (int i = 0; i < k; ++i)
		printf("%d", p[i]);
	    printf("\n");
	    */
	    
	    cnt = min(cnt, compress(p));
	    
	} while (next_permutation(p, p + k));


	printf(" %d\n", cnt);
    }

    return 0;
}
