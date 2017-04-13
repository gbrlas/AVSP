#include <iostream>
#include <vector>

using namespace std;

int max_possible(int total, int max_difference) {
	int max_possible = 0;
	for (int a = 0; a <= 10; a++) {
		for (int b = a; b <= 10; b++) {
			int c = total - a - b;
			if (abs(a-b) > max_difference || abs(a-c) > max_difference 
				|| abs(b-c) > max_difference) continue;
			if (c < 0) continue;
			max_possible = max(max_possible, a);
			max_possible = max(max_possible, b);
			max_possible = max(max_possible, c);
		}
	}
	return max_possible;
}

int main() {
	vector<int> max_unsurprising, max_surprising;
	for (int i = 0; i <= 30; i++) {
		max_unsurprising.push_back( max_possible(i, 1) );
		max_surprising.push_back( max_possible(i, 2) );		
	}
	
	int T;
	cin >> T;
	
	for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
		int N, S, p;
		cin >> N >> S >> p;
		int numUnsurprising = 0;
		int numSurprising = 0;
		for (int i = 0; i < N; i++) {
			int total;
			cin >> total;

			if (max_unsurprising[total] >= p) {
				numUnsurprising++;
			}
			else if (max_surprising[total] >= p) {
				numSurprising++;
			}
		}
		cout << "Case #" << caseNumber << ": " << (numUnsurprising + min(numSurprising, S)) << endl;
		
	}
}
