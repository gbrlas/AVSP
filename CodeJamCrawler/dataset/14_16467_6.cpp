#include <iostream>
using namespace std;

int main(void)
{
	int T;
	int row_selected1, row_selected2;
	int row1[4], row2[4];
	// take test cases n row_selected1
	cin >> T;
	
	// create two matrix
	int m1[4][4], m2[4][4];
	
	int cases = 1;
	int num;
	while (cases <= T) {
		// take matrix first input
		cin >> row_selected1;
		num = -1;
		
		// take first matrix m1
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				cin >> m1[i][j];
				if (i + 1 == row_selected1)
					row1[j] = m1[i][j];
			}
			
		// take row_selected2
		cin >> row_selected2;
		
		// take second matrix m2
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				cin >> m2[i][j];
				if (i + 1 == row_selected2)
					row2[j] = m2[i][j];
			}

		// intersection of row1 and row2
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (row1[i] == row2[j]) {
					if (num != -1)
						num = -10;			// -10 means bad magician
					else
						num = row1[i];
				}
				if (num == -10)
					break;
			}
			
			if (-10 == num) 
				cout << "Case #" << cases++ << ": Bad magician!" << endl;
			else if (-1 == num)
				cout << "Case #" << cases++ << ": Volunteer cheated!" << endl;
			else
				cout << "Case #" << cases++ << ": " << num << endl;
	}
	
	return 0;
}