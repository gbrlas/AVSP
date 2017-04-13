#include <iostream>
#include <vector>

using namespace std;

#define CHEATED      -1
#define BAD_MAGICIAN -2

int solve(int cards[2][4][4], int answers[2]) {
	vector<int> cards_in_both_rows;

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(cards[0][answers[0] - 1][i] == cards[1][answers[1] - 1][j]) {
				cards_in_both_rows.push_back(cards[0][answers[0] - 1][i]);
			}
		}
	}

	if(cards_in_both_rows.size() == 1) return cards_in_both_rows[0];
	if(cards_in_both_rows.size() > 1)  return BAD_MAGICIAN;
	return CHEATED;
}

int main() {
	int cases;
	cin >> cases;

	for(int current_case = 1; current_case <= cases; current_case++) {
		int answers[2];
		int cards[2][4][4];

		for(int i = 0; i < 2; i++) {
			cin >> answers[i];

			for(int j = 0; j < 4; j++) {
				for(int k = 0; k < 4; k++) {
					cin >> cards[i][j][k];
				}
			}
		}

		int solution = solve(cards, answers);
		cout << "Case #" << current_case << ": ";
		if(solution > 0) {
			cout << solution << endl;
		} else if(solution == CHEATED) {
			cout << "Volunteer cheated!" << endl;
		} else {
			cout << "Bad magician!" << endl;
		}
	}

	return 0;
}