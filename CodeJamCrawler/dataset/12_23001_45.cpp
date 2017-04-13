#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, S, p, ans;
int score[100];

int main(){
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		ans = 0;
		scanf("%d %d %d", &N, &S, &p);
		for(int i = 0; i < N; i++){
			scanf("%d", &score[i]);
		}
		sort(score, score + N);
		for(int i = 0; i < N; i++){
			if(score[i] >= p * 3 - 2){
				ans++;
			}else if((score[i] == p * 3 - 4 || (p >= 2 && score[i] == p * 3 - 3)) && S > 0){
				S--;
				ans++;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
