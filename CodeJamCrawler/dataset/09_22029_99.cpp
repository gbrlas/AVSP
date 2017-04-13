#include <cstdio>
#include <string>
using namespace std;

char str[5010][20];
char pat[10240];
int mask[30], L, D, N;


void init(const char *s){
	memset(mask, 0, sizeof(mask));
	int t = -1;
	for(int i = 0; s[i]; i++){
		++t;
		if(s[i] == '('){
			for( ++i; s[i] != ')'; ++i){
				mask[t] |= (1<<(s[i] - 'a'));
			}
		}
		else {
			mask[t] |= (1<<(s[i] - 'a'));
		}
	}
}

int main(){
	int cnt;
	freopen("A-small-attempt0.in", "r",stdin);
	freopen("A-small-attempt0.out", "w",stdout);
	scanf("%d %d %d", &L, &D, &N);
	for(int i = 0; i < D; i++)
		scanf("%s", str[i]);
	for(int ca = 1; ca <= N; ca++){
		scanf("%s", pat);
		init(pat);		
		cnt = 0;
		for(int i = 0; i < D; i++){
			int j;
			for(j = 0; j < L; j++){
				if( (mask[j]&(1<<(str[i][j]-'a'))) == 0){
					break;
				}
			}
			if(j >= L) cnt++;
		}
		printf("Case #%d: %d\n", ca, cnt);
	}
	return 0;
}
