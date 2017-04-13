#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		vector<int> possible(17, 0);
		for (int j = 0; j < 2; j++) {
			int answer;
			scanf("%d", &answer);
			for (int r = 1; r <= 4; r++) {
				for (int s = 1; s <= 4; s++) {
					int number;
					scanf("%d", &number);
					if (r == answer) {
						possible[number]++;
					}
				}
			}
		}
		int possible_count = 0, result = -1;
		for (int j = 1; j <= 16; j++) {
			if (possible[j] == 2) {
				possible_count++;
				result = j;
			}
		}
		if (possible_count == 0) {
			printf("Case #%d: Volunteer cheated!\n", i);
		} else if (possible_count == 1) {
			printf("Case #%d: %d\n", i, result);
		} else {
			printf("Case #%d: Bad magician!\n", i);
		}
	}
	return 0;
}