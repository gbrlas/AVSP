/*
X 352 XT 348
O 316 OT 321
*/

#include <stdio.h>

char arr[4][4];

/*
read_case() {
	int i, j;

	for(i=0; i<4; i++)
	for(j=0; j<4; j++) {
		printf("%d%d",i, j);
		scanf("%c", &arr[i][j]);
		printf("%c", arr[i][j]);
	}

}
*/

check_status() {
	
	int i,j;
	int sum_row[4], sum_col[4], sum_diag[2], empty_cell=0;
	sum_diag[0] = 0; sum_diag[1] = 0;
[root@localhost codejam]# :
[root@localhost codejam]# more  1tttt.c
/*
X 352 XT 348
O 316 OT 321
*/

#include <stdio.h>

char arr[4][4];

/*
read_case() {
	int i, j;

	for(i=0; i<4; i++)
	for(j=0; j<4; j++) {
		printf("%d%d",i, j);
		scanf("%c", &arr[i][j]);
		printf("%c", arr[i][j]);
	}

}
*/

check_status() {
	
	int i,j;
	int sum_row[4], sum_col[4], sum_diag[2], empty_cell=0;
	sum_diag[0] = 0; sum_diag[1] = 0;
	
	for (i=0;i<4;i++) {
		sum_row[i] = 0;  sum_col[i] = 0;
	for (j=0;j<4;j++) {
		sum_row[i] += arr[i][j];
		sum_col[i] += arr[j][i];


		if(arr[i][j]=='.')
			empty_cell++;
	}
	}

	sum_diag[0] = arr[0][0] + arr[1][1] + arr[2][2] + arr[3][3];
	sum_diag[1] = arr[0][3] + arr[1][2] + arr[2][1] + arr[3][0];


	//printf("DIAG = %d %d\n", sum_diag[0], sum_diag[1]);
	// if XXXX / XXXT sum is '352 / 348', OOOO/OOOT sum is '316 / 321'.

	for(i=0;i<4;i++) {

		//printf("ROW/COL %d = %d/%d\n", i, sum_row[i], sum_col[i]);

		if(sum_row[i] == 352 || sum_row[i] == 348 || sum_col[i] == 352 || sum_col[i] == 348) {
			return 1;
		} else if(sum_row[i] == 316 || sum_row[i] == 321 || sum_col[i] == 316 || sum_col[i] == 321) {
			return 2;
		}
	}

	if(sum_diag[0] == 352 || sum_diag[0] == 348 || sum_diag[1] == 352 || sum_diag[1] == 348) {
		return 1; // X
	} else if(sum_diag[0] == 316 || sum_diag[0] == 321 || sum_diag[1] == 316 || sum_diag[1] == 321) {
		return 2; // O
	}

	if(empty_cell == 0) {
		return 3; // Draw.
	} else {
		return 4; // Game has not completed.
	}
}


int main() {

	int i, n, ret=0, j, k;
	char str[10], *op_str[]={"NULL", "X won", "O won", "Draw", "Game has not completed"};

	scanf("%d", &n);

	for (i=1; i<=n; i++) {

		//read_case();
		for(j=0;j<4;j++) {
			scanf("%s", &str);

			for(k=0;k<4;k++)
				arr[j][k] = str[k];
		}
		
		ret=check_status();

		printf("Case #%d: %s\n", i, op_str[ret]);

	}
}

