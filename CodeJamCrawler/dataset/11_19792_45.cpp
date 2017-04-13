// Author: Osvald Ivarsson

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); \
		it != (v).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pic;
typedef vector<int> vi;

int leftOrRight(int current, int button) ;
int get_next_for(vector<pic> buttons, char ch);
bool solve( int tc ) {
	int t;
	cin >> t;
	pic temp;
	vector<pic> buttons;
	for( int i = 0; i < t; i++ ) {
		cin >> temp.first >> temp.second;
		buttons.push_back(temp);
	}
	int time = 0;
	int current_orange = 1, current_blue = 1, next_blue = -1, next_orange = -1;
	while(buttons.size() > 0) {
		next_blue = get_next_for(buttons, 'B');
		next_orange = get_next_for(buttons, 'O');	
		if(buttons[0].first == 'O') { // orange
			if(current_orange == buttons[0].second) {
				buttons.erase(buttons.begin());
			}
			else {
			//	cout << "current_orange = " << current_orange << ", buttons[0].second = " << buttons[0].second << endl;
				current_orange += leftOrRight(current_orange, buttons[0].second);
			}
			current_blue += leftOrRight(current_blue, next_blue);
		}
		else { // blue
			if(current_blue == buttons[0].second) {
				buttons.erase(buttons.begin());
			}
			else {
				current_blue += leftOrRight(current_blue, buttons[0].second);
			}
			current_orange += leftOrRight(current_orange, next_orange);
		}


		time++;
	}
	cout << "Case #" << tc+1 << ": " << time << endl;

	return true;
}

int leftOrRight(int current, int button) {
	if(current < button) {
		return 1;
	}
	else if(current > button) {
		return -1;
	}
	else {
		return 0;
	}
}

int get_next_for(vector<pic> buttons, char ch) {
	for(int i = 0; i < buttons.size(); i++) {
		if(buttons[i].first == ch) {
			return buttons[i].second;
		}
	}	
	return -1;
}

int main() {
	int n;
	cin >> n;
	for( int i = 0; i < n && solve( i ); ++i );
	return 0;
}
