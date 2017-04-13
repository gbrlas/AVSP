#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <iostream>

#define foreach(i,s,w) for(int i=s;i<w.size();++i)
#define forX(i,m) for(typeof(m.begin())i=m.begin();i!=m.end();++i)

using namespace std;

int height, width;
vector <string> plan;
int mem[10][10][1 << 10][1 << 10];

int Solve(int row, int col, int last, int cur) {
	if(col == width)
		return Solve(row + 1, 0, cur, 0);
	if(row == height)
		return 0;
	if(mem[row][col][last][cur] != -1)
		return mem[row][col][last][cur];
	int result = 0;
	if(plan[row][col] == '.') {
		// sit
		bool left = (col == 0 || !((cur & (1 << (col - 1))) || (last & (1 << (col - 1)))));
		bool right = !(last & (1 << (col + 1)));
		if(left && right)
			result >?= Solve(row, col + 1, last, cur | (1 << col)) + 1;
	}
	{
		// don't sit
		result >?= Solve(row, col + 1, last, cur);
	}
	mem[row][col][last][cur] = result;
	return result;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> height >> width;
		plan.resize(height);
		for(int i = 0; i < height; ++i)
			cin >> plan[i];
		memset(mem, 0xff, sizeof(mem));
		int result = Solve(0, 0, 0, 0);
		printf("Case #%d: %d\n", t + 1, result);
	}
	return 0;
}
