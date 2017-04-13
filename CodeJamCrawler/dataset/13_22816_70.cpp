#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX = 128;
unsigned int board[MAX][MAX], maxCol[MAX], maxRow[MAX], N, M, T;

int main() {
	ifstream cin;
	cin.open("in.txt");
	ofstream cout;
	cout.open("out.txt");
	cin >> T;
	for (int i = 0; i < T; ++i) {
		// init
		memset(maxCol, 0, sizeof maxCol);
		memset(maxRow, 0, sizeof maxCol);
		// input
		cin >> N >> M;
		for (int y = 0; y < N; ++y)
			for (int x = 0; x < M; ++x) {
				cin >> board[y][x];
				maxCol[x] = (board[y][x] > maxCol[x]) ? board[y][x] : maxCol[x];
				maxRow[y] = (board[y][x] > maxRow[y]) ? board[y][x] : maxRow[y];
			}
		// check
		bool bad = false;
		for (int y = 0; y < N && !bad; ++y)
			for (int x = 0; x < M && !bad; ++x)
				if (board[y][x] != maxCol[x] && board[y][x] != maxRow[y])
					bad = true;
		// output
		cout << "Case #" << (i + 1) << ": ";
		if (bad)
			cout << "NO";
		else
			cout << "YES";
		cout << endl;
	}
	return 0;
}
