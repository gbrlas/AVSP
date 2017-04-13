#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// main
int main(){
	ifstream cin;
	cin.open("magic_tric_test.txt");
	ofstream cout;
	cout.open("magic_tric_sol.txt");
	// store T & proceed
	int T; cin >> T;
	for (int t = 0; t < T; t++){
		// store 1st
		int r1; cin >> r1;
		int a1[4][4];
		for (int i = 0; i<4; i++){
			for (int j = 0; j<4; j++){
				cin >> a1[i][j];
			}
		}
		// store 2nd
		int r2; cin >> r2;
		int a2[4][4];
		for (int i = 0; i<4; i++){
			for (int j = 0; j<4; j++){
				cin >> a2[i][j];
			}
		}
		// get their intersection
		vector<int> s1(4);
		for (int i = 0; i<4; i++){
			s1[i] = a1[r1-1][i];
		}
		sort(s1.begin(), s1.end());
		vector<int> s2(4);
		for (int i = 0; i<4; i++){
			s2[i] = a2[r2-1][i];
		}
		sort(s2.begin(), s2.end());
		vector<int> X;
		int i1=0, i2=0;
		while (i1<4 && i2<4){
			if (s1[i1] < s2[i2]){
				i1++;
			} else if (s1[i1] > s2[i2]){
				i2++;
			} else {
				X.push_back(s1[i1]);
				i1++; i2++;
			}
		}
		// print the result
		cout << "Case #" << (t+1) << ": ";
		if (X.size()==1) cout << X[0] << endl;
		else if (X.size()>1) cout << "Bad magician!" << endl;
		else if (X.size()==0) cout << "Volunteer cheated!" << endl;
	}
	return 0;
}
