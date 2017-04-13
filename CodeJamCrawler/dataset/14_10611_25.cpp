#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void doCase() {
	vector<bool> cards(16, false);
	int row1;
	cin >> row1;
	for( int i=1; i<5; ++i ) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if( i == row1 ) {
			cards[a] = true;
			cards[b] = true;
			cards[c] = true;
			cards[d] = true;
		}
	}

	int row2;
	cin >> row2;
	for( int i=1; i<5; ++i ) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if( row2 == i ) {
			int count = 0;
			int solution = 0;
			if( cards[a] ) { ++count; solution = a; }
			if( cards[b] ) { ++count; solution = b; }
			if( cards[c] ) { ++count; solution = c; }
			if( cards[d] ) { ++count; solution = d; }

			if( count == 0 )
				cout << "Volunteer cheated!";
			else if( count == 1 )
				cout << solution;
			else
				cout << "Bad magician!";
		}
	}
}

int main() {
	int T;
	cin >> T;
	for( int i=0; i<T; ++i ) {
		cout << "Case #" << (i+1) << ": ";
		doCase();
		cout << endl;
	}
}
