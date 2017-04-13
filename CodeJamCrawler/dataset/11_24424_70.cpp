/*
 * BotTrust.cpp
 *
 */

#include <limits>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

struct bot {
	bot(int pos, int time) :
		pos(pos), time(time) {
	}

	inline void press(int target, int lastpress) {
		time = 1 + max(lastpress, time + abs(pos - target));
		pos = target;
	}

	int pos;
	int time;
};

int main(void) {
	int i, j, t, n, p;
	char r;
	// Read input
	for (i = 1, cin >> t; i <= t; ++i) {
		bot blue(1, 0), orange(1, 0);
		int lastpress = 0;
		for (j = 1, cin >> n; j <= n; ++j) {
			cin >> r >> p;
			if (r == 'O')
				orange.press(p, lastpress);
			else
				blue.press(p, lastpress);
			lastpress = max(blue.time, orange.time);
		}
		// Print the result
		printf("Case #%d: %d\n", i, lastpress);
	}
}
