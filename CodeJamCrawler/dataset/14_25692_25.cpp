#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T,r1,r2;
	cin >> T;
	vector<vector<int> > cards1(4,vector<int>(4));
	vector<vector<int> > cards2(4,vector<int>(4));
	for (int I=0; I<T;I++){
		cin >> r1;
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++){
				cin >> cards1[i][j];
			}
		}
		cin >> r2;
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++){
				cin >> cards2[i][j];
			}
		}
		vector<int> solution;
		for (int i=0;i<4;i++){
			for (int j=0;j<4;j++){

				if (cards1[r1-1][i] == cards2[r2-1][j])
					solution.push_back(cards1[r1-1][i]);
			}
		}
		if (solution.size()==0)
			cout << "Case #" << I+1 << ": Volunteer cheated!" << endl;
		else if (solution.size()==1)
			cout << "Case #" << I+1 << ": " << solution[0] << endl;
		else
			cout << "Case #" << I+1 << ": Bad magician!" << endl;
	}

	return 0;
}
