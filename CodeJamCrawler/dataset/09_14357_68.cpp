#include <cstdio>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


typedef long long int64;
typedef double real;

int d[10];
char s[1 << 10];


int main(){
	int ferlon;
	scanf("%d", &ferlon);
	for (int _ = 0; _ < ferlon; ++_){
		scanf("%s", s);
		memset(d, 0, sizeof(d));
		int len = strlen(s);
		for (int i = 0; s[i]; i++)
			d[s[i] - '0']++;
		assert(s[0] != '0');
		printf("Case #%d: ", _ + 1);
		if (std::next_permutation(s, s + len)){
			puts(s);
		}else{
			d[0]++;
			for (int i = 1; i < 10; i++) if (d[i]){
				printf("%d", i);
				d[i]--;
				break;
			}
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < d[i]; j++)
					printf("%d", i);
			puts("");
		}
	}
	return 0;
}
