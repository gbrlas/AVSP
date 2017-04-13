#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

#define ll long long

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; ++t) {
		
		int row1;
		int matrix1[6][6];
		scanf("%d", &row1);
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				scanf("%d" , &matrix1[i][j]);
			}
		}
		
		int row2;
		int matrix2[6][6];
		scanf("%d", &row2);
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				scanf("%d", &matrix2[i][j]);
			}
		}
		
		int cnt = 0;
		int ans;
		for(int i = 1; i <= 4; ++i) {
			for(int j = 1; j <= 4; ++j) {
				if(matrix1[row1][i] == matrix2[row2][j]) {
					cnt++;
					ans = matrix1[row1][i];	
				}
			}
		}
		
		printf("Case #%d: ", t);
		if(cnt > 1) {
			puts("Bad magician!");
		} else if(cnt == 0) {
			puts("Volunteer cheated!");
		} else {
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
