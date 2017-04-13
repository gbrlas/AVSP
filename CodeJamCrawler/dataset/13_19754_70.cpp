#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string line;
    int T;
    
    getline(cin, line);
    istringstream in(line);
    in >> T;
    
    for(int t = 1; t <= T; t++) {
        vector<vector<char> > board(4, vector<char>(4));

        for(int i = 0; i < 4; i++) {
            getline(cin, line);
            for(int j = 0; j < 4; j++)
                board[i][j] = line[j];
        }
        getline(cin, line);
 
        char winner = '.';
        
        for(int i = 0; i < 4; i++) {
            bool going = true;
            char cur = board[i][0] == 'T' ? board[i][1] : board[i][0];
            if(cur == '.')
                continue;
                
            for(int j = 1; j < 4; j++)
                going = going && (board[i][j] == cur || board[i][j] == 'T');
            
            if(going) {
                winner = board[i][0] == 'T' ? board[i][1] : board[i][0];
            }
        }
        
        for(int j = 0; j < 4; j++) {
            bool going = true;
            char cur = board[0][j] == 'T' ? board[1][j] : board[0][j];
            if(cur == '.')
                continue;
                
            for(int i = 1; i < 4; i++)
                going = going && (board[i][j] == cur || board[i][j] == 'T');
            
            if(going) {
                winner = board[0][j] == 'T' ? board[1][j] : board[0][j];
            }
        }
        
        bool going = true;
        char cur = board[0][0] == 'T' ? board[1][1] : board[0][0];
        if(cur != '.') {
            for(int i = 1; i < 4; i++)
                going = going && (board[i][i] == cur || board[i][i] == 'T');
            
            if(going) {
                winner = board[0][0] == 'T' ? board[1][1] : board[0][0];
            }
        }
        
        going = true;
        cur = board[0][3] == 'T' ? board[1][2] : board[0][3];
        if(cur != '.') {
            for(int i = 1; i < 4; i++) {
                int x = 4 - i - 1;
                going = going && (board[i][x] == cur || board[i][x] == 'T');
            }
        
            if(going) {
                winner = board[0][3] == 'T' ? board[1][2] : board[0][3];
            }
        }
        
        if(winner == '.') {
            bool found_dot = false;
            
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    if(board[i][j] == '.')
                        found_dot = true;
            
            if(!found_dot)
                cout << "Case #" << t << ": Draw" << endl;
            else
                cout << "Case #" << t << ": Game has not completed" << endl;
        }
        else
            cout << "Case #" << t << ": " << winner << " won" << endl;
    }
}
                
        
