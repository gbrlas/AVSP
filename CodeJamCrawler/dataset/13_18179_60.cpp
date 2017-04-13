#include <iostream>
#include <queue>

using namespace std;

struct pos {
	int j, k;
};

int main()
{
    int NC;
	int A, B;
    cin >> NC;
	int board[100][100];
	int linemax[100];
	int colmax[100];

    for (int i = 0; i < NC; i++) {
		int N, M;
		int grow = 0;
		bool result = true;
		cin >> N >> M;
        cout << "Case #" << (i + 1) << ": ";
		int rowmax[100];
		int colmax[100];
		for (int j = 0; j < 100; j++)
			rowmax[j] = colmax[j] = 0;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				cin >> board[j][k];
				if (rowmax[j] < board[j][k]) {
					rowmax[j] = board[j][k];
				}
				if (colmax[k] < board[j][k]) {
					colmax[k] = board[j][k];
				}
					 
			}
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				int v = board[j][k];
				if (v < rowmax[j] && v < colmax[k]) {
					result = false;
					goto output;
				}
			}
output:
		cout << (result ? "YES" : "NO") << endl;
	}
    return 0;
}
