#include <stdio.h>
int a, b, A[5][5], B[5][5], sol, res;
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int runs, tn;
	for (scanf("%d",&tn), runs = 1; runs <= tn; runs++) {
		sol = 0;
		scanf("%d",&a);
		for (int i = 1; i <= 4; i++) for (int j = 1; j <= 4; j++) scanf("%d",&A[i][j]);
		scanf("%d",&b);
		for (int i = 1; i <= 4; i++) for (int j = 1; j <= 4; j++) scanf("%d",&B[i][j]);
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++)
				if (A[a][i] == B[b][j])
					sol++, res = A[a][i];
		}
		if (sol == 0) printf("Case #%d: Volunteer cheated!\n",runs);
		else if (sol == 1) printf("Case #%d: %d\n",runs,res);
		else printf("Case #%d: Bad magician!\n",runs);
	}
	fcloseall();
	return 0;
}