#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int x, y, ans = 0, cnt = 0;
		int num[20] = {0, };
		scanf("%d", &x);
		for(int i=1; i<=4; i++){
			for(int j=1; j<=4; j++){
				scanf("%d", &y);
				if(i == x) num[y]++;
			}
		}
		scanf("%d", &x);
		for(int i=1; i<=4; i++){
			for(int j=1; j<=4; j++){
				scanf("%d", &y);
				if(i == x) num[y]++;
			}
		}
		for(int i=1; i<=16; i++){
			if(num[i] == 2){
				cnt++;
				ans = i;
			}
		}
		printf("Case #%d: ", t);
		if(cnt == 0) printf("Volunteer cheated!\n");
		else if(cnt == 1) printf("%d\n", ans);
		else printf("Bad magician!\n");
	}
	return 0;
}
