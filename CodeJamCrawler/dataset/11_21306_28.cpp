#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int n, m;
char map[55][55];
int main(){
	int i, j, k, T, flag;
	freopen("A_l.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d", &T);
	for (k = 1; k <= T; k++){
		scanf("%d%d", &n, &m);
		memset(map, 0, sizeof(map));
		for (i = 1; i <= n; i++){
			scanf("%s", (map[i] + 1));
		}
		flag = 1;
		for (i = 1; i <= n && flag; i++)
			for (j = 1; j <= m && flag; j++){
				if (map[i][j] == '#'){
					if (map[i][j + 1] == '#' && map[i + 1][j] == '#' &&
						map[i + 1][j + 1] == '#'){
						map[i][j] = map[i + 1][j + 1] = 47;
						map[i][j + 1] = map[i + 1][j] = 92;		
					}
					else flag = 0;
				}
			}
		printf("Case #%d:\n", k);
		if (!flag) printf("Impossible\n");
		else{
			for (i = 1; i <= n; i++){
				for (j = 1; j <= m; j++)
					printf("%c", map[i][j]);
				printf("\n");
			}
		}
	}
//    system("pause");
    return 0;
}
