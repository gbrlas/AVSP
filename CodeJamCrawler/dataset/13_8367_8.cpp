#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int conscons(char *str, int len) {
	int c=0,best=0;
	for (int i=0; i < len; i++) {
		//printf("%c", str[i]);
		if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
			c++;
		}
		else {
			if (c > best) {
				best = c;
			}
			c = 0;
		}
	}
	if (c > best) {
		best = c;
	}
	//printf(" %d",best);
	//printf("\n");
	return best;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t < T; t++) {
		char name[110];
		int n, r=0;
		scanf("%s %d\n", name, &n);
		int len = strlen(name);

		//printf("name: %s\n", name);
		//printf("n: %d\n", n);

		for (int i=0; i <= len-n; i++) {
			for (int j=len; j >= i+n; j--) {
				if (conscons(name+i,j-i) >= n) {
					r++;
				}
			}
		}


		printf("Case #%d: %d\n", t+1, r);
	}
}

// vowels: a,e,i,o,u
// consonants: rest

/*
tsetse
 setse
  etse
   tse
    se

tsets
tset
tse
ts

 setse
 sets
 set
 se

  ets
  et
*/
