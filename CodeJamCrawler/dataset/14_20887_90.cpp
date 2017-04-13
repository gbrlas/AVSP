#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int i=0; i<T; i++){
		int blocks;
		cin >> blocks;
		double* naomi = new double[blocks];
		double* ken = new double[blocks];
		for(int j=0; j<blocks; j++){
			cin >> naomi[j];
		}
		sort(naomi, naomi+blocks);

		for(int j=0; j<blocks; j++){
			cin >> ken[j];
		}
		sort(ken, ken+blocks);

		int loose = 0;
		int k = 0;
		int y = 0;
		for(int j=0; j<blocks; j++){
			if(naomi[j] < ken[k]){
				loose++;
			}else{
				y++;
				k++;
			}
			if(y+loose >= blocks){
				break;
			}
		}

		int z = 0;
		for(int j=0; j<blocks; j++){
			int k;
			for(k=0; k<blocks; k++){
				if(naomi[j] < ken[k]){
					ken[k] = 0;
					break;
				}
			}
			if(k==blocks){
				z++;
			}
		}
		cout << "Case #" << i+1 << ": " << y << " " << z << endl;
	}
	return 0;
}
