#include <stdio.h>
#include <stdlib.h>

#define BAD_MAGICIAN "Bad magician!"
#define CHEATER "Volunteer cheated!"
#define CASE_STR "Case #%d: "

#define ROW 4
#define COL 4

void __run_magician(const int _test_id) {

	int row_a = 0;
	int row_b = 0;

	int deck_a[ROW][COL];
	int deck_b[ROW][COL];

	int i;
	int j;

	scanf("%d", &row_a);
	row_a--;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			scanf("%d", &(deck_a[i][j]));

	scanf("%d", &row_b);
	row_b--;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			scanf("%d", &(deck_b[i][j]));

	int _uniq[ROW];
	for (i = 0; i < ROW; i++)
		_uniq[i] = 0;

	int idx = 0;

	for (i = 0; i < COL; i++) {

		int val = deck_a[row_a][i];
		for (j = 0; j < COL; j++) {
			if (val == deck_b[row_b][j])
				_uniq[idx++] = val;
		}
	}

	printf(CASE_STR, _test_id);
	switch (idx) {
	case 0:
		printf("%s\n", CHEATER);
		break;
	case 1:
		printf("%d\n", _uniq[0]);
		break;
	default:

		printf("%s\n", BAD_MAGICIAN);
		break;
	}
}

int main() {

	int test_case = 0;

	scanf("%d", &test_case);
	int i;

	for (i = 1; i <= test_case; i++)
		__run_magician(i);

	return 0;

}
