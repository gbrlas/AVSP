#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 32;

char str[MAXN]; 
int num[MAXN], len, casenum, cnt[MAXN], cop[MAXN];

bool isBig(){
	int i;
	for(i = 0; i < len; i++){
		if(num[i] > cop[i]) return true;
		if(num[i] < cop[i]) return false;
	}
	return false;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d",&casenum);
	for(int ca = 1; ca <= casenum; ca++){
		scanf("%s", str);
		len = strlen(str);
		for(int i = 0; i < len; i++){
			num[i] = str[i] - '0';
			cop[i] = str[i] - '0';
		}
		next_permutation(num, num+len);
		bool ok = isBig();
		printf("Case #%d: ", ca);
		if(ok){
			for(int i = 0; i < len; i++)
				printf("%d", num[i]);
			puts("");
		}
		else {
			memset(cnt, 0, sizeof(cnt));
			for(int i = 0; i < len; i++)
				cnt[num[i]]++;
			int p = -1;
			for(int i = 1; i < 10; i++){
				if(cnt[i] > 0){
					p = i; 
					cnt[i]--;
					break; 
				}
			}
			printf("%d0", p);
			for(int i = 0; i < 10; i++){
				while(cnt[i] > 0){
					printf("%d", i);
					cnt[i]--;
				}
			}
			puts("");
		}
	}	
	return 0;
}
