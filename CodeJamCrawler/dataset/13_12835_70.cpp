#include <stdio.h>
#define SQUARE 4

int main() {
	char input[SQUARE][SQUARE];
	int input_num;

	int low_count_o;
	int low_count_x;
	int column_count_o;
	int column_count_x;
	int diagonal_count_o;
	int diagonal_count_x;
	int diagonal_count2_o;
	int diagonal_count2_x;
	int flag_end;
	int flag_output;

	int i,j;
	int hoge;

	int *fuga;
/*
	printf("diagonal_count_o  : %p\n", &diagonal_count_o);
	printf("diagonal_count_x  : %p\n", &diagonal_count_x);
	printf("diagonal_count2_o : %p\n", &diagonal_count2_o);
	printf("diagonal_count2_x : %p\n", &diagonal_count2_x);
	printf("flag_output       : %p\n", &flag_output);
	printf("flag_end          : %p\n", &flag_end);
	printf("hoge              : %p\n", &hoge);
*/
	fuga = &diagonal_count_o;
	fuga = &diagonal_count_x;
	fuga = &diagonal_count2_o;
	fuga = &diagonal_count2_x;
	fuga = &flag_output;
	fuga = &flag_end;
	fuga = &hoge;

	scanf("%d", &input_num);

	hoge = 1;
	while(input_num--) {
		printf("Case #%d: ", hoge);
		hoge = hoge + 1;

		for(i = 0; i < SQUARE; i++)
			scanf("%s", input[i]);

		diagonal_count_o = 0;
		diagonal_count_x = 0;
		diagonal_count2_o = 0;
		diagonal_count2_x = 0;

		flag_output = 0;
		flag_end = 0;

		for(i = 0; i < SQUARE; i++) {
			low_count_o = 0;
			low_count_x = 0;
			column_count_o = 0;
			column_count_x = 0;

			/* diagonal */
			if(input[i][i] == 'O')
				diagonal_count_o++;
			else if(input[i][i] == 'X')
				diagonal_count_x++;
			else if(input[i][i] == 'T') {
				diagonal_count_o++;
				diagonal_count_x++;
			}

			if(input[i][SQUARE - i - 1] == 'O')
				diagonal_count2_o++;
			else if(input[i][SQUARE - i - 1] == 'X')
				diagonal_count2_x++;
			else if(input[i][SQUARE - i - 1] == 'T') {
				diagonal_count2_o++;
				diagonal_count2_x++;
			}

			for(j = 0; j < SQUARE; j++) {
				/* low */
				if(input[i][j] == 'O')
					low_count_o++;
				else if(input[i][j] == 'X')
					low_count_x++;
				else if(input[i][j] == 'T') {
					low_count_o++;
					low_count_x++;
				}
				else
					flag_end = 1;

				/* column */
				if(input[j][i] == 'O')
					column_count_o++;
				else if(input[j][i] == 'X')
					column_count_x++;
				else if(input[j][i] == 'T') {
					column_count_o++;
					column_count_x++;
				}
			}

			if(low_count_o == SQUARE || column_count_o == SQUARE || diagonal_count_o == SQUARE || diagonal_count2_o == SQUARE) {
				printf("O won\n");
				flag_output = 1;
				break;
			}
			else if(low_count_x == SQUARE || column_count_x == SQUARE || diagonal_count_x == SQUARE || diagonal_count2_x == SQUARE) {
				printf("X won\n");
				flag_output = 1;
				break;
			}
		}

		if(!flag_output) {
			if(!flag_end)
				printf("Draw\n");
			else
				printf("Game has not completed\n");
		}
	}

	return 0;
}

