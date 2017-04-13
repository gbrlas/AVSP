#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

vector<string> board;
int r;
int c;

bool cover(int row, int col)
{
    if (row+1 == r || col+1 == c)
        return false;
    if ( (board[row+1][col] != '#') || (board[row][col+1] != '#') || (board[row+1][col+1] != '#') )
        return false;
    board[row][col] = '/';
    board[row][col+1] = '\\';
    board[row+1][col] = '\\';
    board[row+1][col+1] = '/';
    return true;
}

void solve(int t)
{
    cin >> r;
    cin >>c;

    board.clear();
    for(int i = 0; i < r; ++i)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }
    
    for(int row = 0; row < r; ++row)
    {
        for(int col = 0; col < c; ++col)
        {
            if (board[row][col] != '#')
                continue;
            if (!cover(row,col))
            {
                cout << "Case #" << t+1 << ":" << endl;
                cout << "Impossible" << endl;
                return;
            }
        }
    }
    
    cout << "Case #" << t+1 << ":"<< endl;
    copy(board.begin(), board.end(), ostream_iterator<string>(cout, "\n"));
}


int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
        solve(i);
}