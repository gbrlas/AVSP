#include <iostream>

using namespace std;

int main(){

	int test_cases;

	while(cin >> test_cases){

		for (int i = 1; i <= test_cases; i++){
			int first_choice, second_choice;
			int table_1[4][4];
			int table_2[4][4];
			int chosen_number = 0, equal_numbers = 0;
			
			cin >> first_choice;

			for (int j = 0; j < 4; j++){
				for (int k = 0; k < 4; ++k){
					cin >> table_1[j][k];
				}
			}

			cin >> second_choice;

			for (int j = 0; j < 4; j++){
				for (int k = 0; k < 4; ++k){
					cin >> table_2[j][k];
				}
			}

			for (int j = 0; j < 4; ++j){
				int num = table_1[first_choice-1][j];
				
				for (int k = 0; k < 4; ++k){
					if(num==table_2[second_choice-1][k]){
						chosen_number = num;
						equal_numbers++;
					}
				}				
			}

			if(equal_numbers == 1){
				cout << "Case #"<< i <<": "<< chosen_number << endl;
			} else if(equal_numbers > 1){
				cout << "Case #"<< i <<": Bad magician!" << endl;				
			} else{
				cout << "Case #"<< i <<": Volunteer cheated!" << endl;
			}
		}

	}

	return 0;
}