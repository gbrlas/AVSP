#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	int lines;
	cin >> lines;

	for (int i = 0; i < lines; i++) {
		//googlers
		int n;
		cin >> n;
		//surprise
		int s;
		cin >> s;
		//highscore
		int p;
		cin >> p;

		int result = 0;
		int current;
		bool highpass = false;

		for (int j = 0; j < n; j++) {
		cin >> current;
		highpass = false;

		int score1 = current/3;
		int tempscore = current - score1;
		int score2 = tempscore/2;
		int score3 = tempscore - score2;

		int dup;
		if (score1 == score2) dup = score1;
		if (score1 == score3) dup = score1;
		if (score2 == score3) dup = score2;

		//cout << " score1: " << score1;
		//cout << " score2: " << score2;
		//cout << " score3: " << score3 << endl; 

		if (score1 >= p || score2 >= p || score3 >= p)
			highpass = true;

		if (highpass == false && (p-dup) == 1 && current > 1) {
			if (s > 0) {
				highpass = true;
				s--;
			}
		}

		if (highpass == true) result++;
		}

		cout << "Case #" << i+1 << ": " << result;
		cout << endl;
	}		
	
	return 1;
}

