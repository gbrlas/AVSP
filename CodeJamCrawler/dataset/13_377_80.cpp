#include <stdio.h>

#define MAX_SIZE 100

/* The pattern is possible if for every entry a[i, j], we have:
 *	a[i, j] is the maximum element of the i-th row, or 
 *		the maximum element of the j-th column.
 */

int isPossiblePattern(int grid[][MAX_SIZE], int numRow, int numCol);
int findMaxValue(int grid[][MAX_SIZE], int startR, int endR, int startC, int endC);

int main(void)
{
	int T, caseId, yard[MAX_SIZE][MAX_SIZE], numRow, numCol, r, c;

	freopen("in.txt", "r", stdin);
	freopen("out.out", "w", stdout);

	caseId = 1;
	scanf("%d", &T);
	while(caseId <= T)
	{
		scanf("%d %d", &numRow, &numCol);

		for(r = 0; r < numRow; r++)
			for(c = 0; c < numCol; c++)
				scanf("%d", &yard[r][c]);

		printf("Case #%d: %s\n", caseId, 
			isPossiblePattern(yard, numRow, numCol) ? "YES" : "NO");
		caseId++;
	}
	return 0;
}

int isPossiblePattern(int grid[][MAX_SIZE], int numRow, int numCol)
{
	int maxRow[MAX_SIZE], maxCol[MAX_SIZE], row, col;

	for(row = 0; row < numRow; row++)
		maxRow[row] = findMaxValue(grid, row, row, 0, numCol - 1);
	for(col = 0; col < numCol; col++)
		maxCol[col] = findMaxValue(grid, 0, numRow - 1, col, col);

	for(row = 0; row < numRow; row++)
		for(col = 0; col < numCol; col++)
			if(grid[row][col] != maxRow[row] && grid[row][col] != maxCol[col])
				return 0;

	return 1;
}

/* Find the maximum value of the submatrix grid[startR ... endR][startC ... endC] */
int findMaxValue(int grid[][MAX_SIZE], int startR, int endR, int startC, int endC)
{
	int row, col, max = -1;

	for(row = startR; row <= endR; row++)
		for(col = startC; col <= endC; col++)
			if(max < grid[row][col])
				max = grid[row][col];

	return max;
}
