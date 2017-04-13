#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int index, cc = 0, row1, row2, count, result, nouse;
	int m1[4][4];
	freopen("a.in", "r", stdin);
	freopen("out","w",stdout);
	scanf("%d", &index);
	while (index--) {
		count = 0;
		result = 0;
		scanf("%d", &row1);
		for (int i = 1; i <= 4; i++) {
					for (int j = 0; j < 4; j++)
						scanf("%d", &m1[i-1][j]);
				}
		scanf("%d", &row2);
		for (int i = 1; i <= 4; i++) {
			if (i == row2) {
				int temp = 0;
				for (int j = 0; j < 4; j++) {
					scanf("%d", &temp);
					for (int y = 0; y < 4; y++) {
						if (m1[row1-1][y] == temp) {
							count++;
							result = temp;
						}
					}
				}
			} else {
				for (int j = 0; j < 4; j++)
					scanf("%d", &nouse);
			}
		}
		if (count == 1)
			printf("Case #%d: %d\n", ++cc, result);
		else if (count == 0)
			printf("Case #%d: Volunteer cheated!\n", ++cc);
		else if (count > 1)
			printf("Case #%d: Bad magician!\n", ++cc);

	}
	return 0;
}
