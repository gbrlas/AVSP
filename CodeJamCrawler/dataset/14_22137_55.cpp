#include <iostream>
using namespace std;
void getrow(int * row) {
	int r; cin >> r;
	for (int i=0; i<4; i++) {
		for (int j = 0; j < 4; j++) {
			int x; cin >> x;
			if (i==r-1) row[j]=x;
		}
	}
}
int main() {
	int t; cin >> t;
	for (int c = 1; c <= t; c++) {
		int r1[4],r2[4];
		getrow(r1);
		getrow(r2);
		int numeq =0; //number present on both rows
		int cand = -1; //the card
		for (int i=0; i<4; i++) {
			for (int j = 0; j < 4; j++) {
				if (r1[i]==r2[j]) {
					numeq++;
					cand = r1[i];
				}
			}
		}
		if (numeq==0) {
			cout << "Case #" << c << ": Volunteer cheated!" << endl;
		} else if (numeq==1) {
			cout << "Case #" << c << ": " << cand << endl;
		} else {
			cout << "Case #" << c << ": Bad magician!" << endl;
		}
	}
	return 0;
}
