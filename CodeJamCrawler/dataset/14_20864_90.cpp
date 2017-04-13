#include <iostream>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for(int i=0; i<cases; i++){
		int row1;
		cin >> row1;
		row1 -= 1;
		int first[4][4];
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				cin >> first[j][k];
			}
		}

		int row2;
		cin >> row2;
		row2 -= 1;
		int second[4][4];
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				cin >> second[j][k];
			}
		}

		int answer = 0;
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				if(first[row1][j] == second[row2][k]){
					if(answer == 0){
						answer = first[row1][j];
					}else{
						answer = -1;
					}
				}
			}
		}

		if(answer == -1){
			cout << "Case #" << i+1 << ": Bad magician!" << endl;
		}else if(answer == 0){
			cout << "Case #" << i+1 << ": Volunteer cheated!" << endl;
		}else{
			cout << "Case #" << i+1 << ": " << answer << endl;
		}
	}
	return 0;
}
