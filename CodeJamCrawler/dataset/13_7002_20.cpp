#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	
    int T;
    cin >> T;

    string temp;
    getline(cin, temp);

    for (int t = 0; t != T; ++t) {        
        string winner = "draw";
        string board[4];
        for (int i = 0; i != 4; ++i) {
            getline(cin, board[i]);
        }
        
        getline(cin, temp);

        // check each row
        for (int i = 0; i != 4; ++i) {
            int count = 0;
            if (board[i][0] != '.') {
                if (board[i][0] == board[i][1]) count++;
                if (board[i][1] == board[i][2]) count++;
                if (board[i][2] == board[i][3]) count++;
                if (count == 3 || count == 2 && board[i].find('T') != string::npos) { winner = board[i][0]; break;}
            }
        }        

        // check each column
        for (int i = 0; i != 4; ++i) {
            bool foundT = false;
            int count = 0;
            if (board[0][i] != '.') {
                if (board[0][i] == board[1][i]) count++;
                if (board[1][i] == board[2][i]) count++;
                if (board[2][i] == board[3][i]) count++;
                for (int j = 0; j != 4; ++j) {
                    if (board[j][i] == 'T') { foundT = true;}
                }
                if (count == 3 || count == 2 && foundT) { winner = board[0][i]; break;}
            }
        }
        
        // check diagonal 1 (top left to bottom right)
        int count = 0;
        bool found = false;
        if (board[0][0] == 'T' || board[1][1] == 'T' || board[2][2] == 'T' || board[3][3] == 'T') {found = true;}
        if (board[0][0] != '.') {            
            if (board[0][0] == board[1][1]) count++;
            if (board[1][1] == board[2][2]) count++;
            if (board[2][2] == board[3][3]) count++;
            if (count == 3 || count == 2 && found) { winner = board[0][0];}
        }

        // check diagonal 2 (top right to bottom left)
        count = 0;
        found = false;
        if (board[0][3] == 'T' || board[1][2] == 'T' || board[2][1] == 'T' || board[3][0] == 'T') {found = true;}
        if (board[0][3] != '.') {            
            if (board[0][3] == board[1][2]) count++;
            if (board[1][2] == board[2][1]) count++;
            if (board[2][1] == board[3][0]) count++;
            if (count == 3 || count == 2 && found) { winner = board[0][3];}
        }

        bool foundBlank=false;
        for (int i = 0; i != 4; ++i) {
            for (int j = 0; j != 4; ++j) {
                if (board[i][j] == '.') {
                    foundBlank = true;
                    break;
                }
            }
        }

        cout << "Case #" << t+1 << ": ";
        if (winner == "O") {
            cout << "O won" << endl;
        }
        else if (winner == "X") {
            cout << "X won" << endl;
        }
        else if (winner == "draw" && foundBlank) {
            cout << "Game has not completed" << endl;
        }
        else {
            cout << "Draw" << endl;
        }
        
    }
    return 0;    
}