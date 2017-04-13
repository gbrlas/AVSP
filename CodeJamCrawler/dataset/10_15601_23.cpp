#include <iostream>
#include <iomanip>
using namespace std;

int T, n, K;
char board[51][51];
bool red = false, blue = false;


void add_win(char color){
	if (color == 'R')
		red = true;
	else
		if (color == 'B')
			blue = true;
}

int main(){
	cin >> T;
	for (int t=1; t<=T; t++){
		// input
		cin >> n >> K;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++)
				cin >> board[i][j];
		}
		// rotate
		for (int i=n; i>=1; i--){
			for (int j=n; j>=1; j--){
				if (board[i][j] != '.'){
					int k = j;
					while (k < n && board[i][k+1] == '.'){
						board[i][k+1] = board[i][k];
						board[i][k] = '.';
						k++;
					}
				}
			}
		}
		// find who wins
		blue = false; red = false;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (board[i][j] != '.'){
					// right
					int k = 1;
					while (k < K && j+k <= n && board[i][j+k] == board[i][j]) k++;
					if (k == K)
						add_win(board[i][j]);
					// down
					k = 1;
					while (k < K && i+k <= n && board[i+k][j] == board[i][j]) k++;
					if (k == K)
						add_win(board[i][j]);
					// right-down
					k = 1;
					while (k < K && i+k <= n && j+k <= n && board[i+k][j+k] == board[i][j]) k++;
					if (k == K)
						add_win(board[i][j]);
					// left-down
					k = 1;
					while (k < K && i+k <= n && j-k >= 1 && board[i+k][j-k] == board[i][j]) k++;
					if (k == K)
						add_win(board[i][j]);
				}
			}
		}
		// output
		cout << "Case #" << t << ": ";
		if (blue && red)
			cout << "Both";
		else if (!blue && red)
			cout << "Red";
		else if (blue && !red)
			cout << "Blue";
		else
			cout << "Neither";
		cout << endl;
	}
	return 0;
}
