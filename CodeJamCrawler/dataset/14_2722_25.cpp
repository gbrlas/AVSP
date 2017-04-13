#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int T , row1 , row2;
vector<int> elements;
unordered_set<int> hashSet;

int main()
{
	//ifstream cin("test.in");
	//ofstream cout("test.out");
	cin >> T;
	for (int test = 0; test < T ; test++) {

		cin >> row1;
		int element;
		for (int row = 0 ; row < 4 ; row++) {
			for (int col = 0; col < 4 ; col++) {
				cin >> element;
				if (row + 1 == row1) {
					hashSet.insert(element);
				}
			}
		}

		cin >> row2;
		for (int row = 0 ; row < 4 ; row++) {
			for (int col = 0; col < 4 ; col++) {
				cin >> element;
				if (row + 1 == row2 && hashSet.find(element) != hashSet.end()) {
					elements.push_back(element);
				}
			}
		}
		cout << "Case #" << test+1 << ": ";
		if (elements.size() == 0) {
			cout << "Volunteer cheated!" << endl;
		} else if (elements.size() > 1) {
			cout << "Bad magician!" << endl;
		} else {
			cout << elements[0] << endl;
		}

		elements.clear();
		hashSet.clear();

	}
    return 0;
}
