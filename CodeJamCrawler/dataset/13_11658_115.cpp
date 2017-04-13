#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long int64;
const int inf = (int)1e9;

int main()
{
	int testSize;

	scanf("%d", &testSize);

	for(int testCaseNum = 0; testCaseNum < testSize; ++testCaseNum) {

		char fld[8][8];

		for(int i = 0; i < 4; ++i)
			scanf("%s", fld[i]);

		bool xwin = false, owin = false;
		bool finished = true;

		int dxs[] = {1, 1, 1, 1, 0, 0, 0, 0, 1, 1};
		int dys[] = {0, 0, 0, 0, 1, 1, 1, 1, -1, 1};
		int sxs[] = {0, 0, 0, 0, 0, 1, 2, 3, 0, 0};
		int sys[] = {0, 1, 2, 3, 0, 0, 0, 0, 3, 0};

		for(int line = 0; line < 10; ++line) {

			bool xw = true;
			bool ow = true;

			int x = sxs[line], y = sys[line], dx = dxs[line], dy = dys[line];

			for(int i = 0; i < 4; ++i) {
				char c = fld[x][y];
				if(c != 'X' && c != 'T') xw = false;
				if(c != 'O' && c != 'T') ow = false;
				x += dx; y += dy;
			}

			if(xw) xwin = true;
			if(ow) owin = true;
		}

		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				if(fld[i][j] == '.')
					finished = false;
			}
		}

		char ansstr[64];

		if(xwin)
			sprintf(ansstr, "X won");
		else if(owin)
			sprintf(ansstr, "O won");
		else if(finished)
			sprintf(ansstr, "Draw");
		else
			sprintf(ansstr, "Game has not completed");

		printf("Case #%d: %s\n", testCaseNum + 1, ansstr);
	}

	return 0;
}

/* ハラスメントに負けず */
/* 0完太陽にも負けず */
/* はやく人権を獲得したい */
