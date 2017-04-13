#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int MAX_USED = 1 << 20;
const int MAX_LOL = 1005;
const int INF = 2000000000;

int used[2][2][MAX_USED];
int lol[MAX_LOL];

int main(){
	int num_case = 0;
	scanf("%d", &num_case);
	for(int caseno = 0;caseno < num_case;caseno++){
		int num_lol = 0;
		scanf("%d", &num_lol);
		for(int i = 0;i < num_lol;i++)scanf("%d", &(lol[i]));
		for(int i = 0;i < MAX_USED;i++){
			used[0][0][i] = -INF;
			used[1][0][i] = -INF;
			used[0][1][i] = -INF;
			used[1][1][i] = -INF;
		}
		int cu = 0;
		used[!cu][0][0] = 0;
		int csum = 0;
		for(int i = 0;i < num_lol;i++){
			csum += lol[i];
			for(int j = 0;j < MAX_USED;j++){
				used[cu][1][j] = max(used[!cu][0][j^lol[i]], used[!cu][1][j^lol[i]] + lol[i]);
				used[cu][0][j] = used[!cu][0][j^lol[i]] + lol[i];
			}
			cu = !cu;
		}
		printf("Case #%d: ", caseno+1);
		if(used[!cu][1][0] <= 0)
			printf("NO\n");
		else
			printf("%d\n", used[!cu][1][0]);
	}
}
