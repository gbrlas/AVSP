#include <iostream>
#include <vector>

using namespace std;

void print_grid(const vector<char> &grid, int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i * C + j] >= '0' && grid[i * C + j] <= '8') {
                cout << '.';
            } else {
                cout << grid[i * C + j];
            }
        }
        cout << endl;
    }   
}

bool next_permutation(vector<char> &v) {
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] == '*' && v[i + 1] == ' ') {
            int elements = 0;
            for(int j = 0; j < i; j++) {
                if(v[j] == '*') elements++;
            }
            for(int j = 0; j <= i; j++) {
                v[j] = (j < elements ? '*' : ' ');
            }
            v[i + 1] = '*';
            return true;
        }
    }
    return false;
}

int mines_in_neighborhood(const vector<char> &grid, int r, int c, int R, int C) {
    int mines = 0;
    for(int nr = r - 1; nr <= r + 1; nr++) {
        for(int nc = c - 1; nc <= c + 1; nc++) {
            if( nr == -1 || nc == -1 ||
                nr == R  || nc == C  ||
               (nr == r  && nc == c)) continue;
            if(grid[nr * C + nc] == '*') mines++;
        }
    }
    return mines;
}

void click(vector<char> &grid, int r, int c, int R, int C) {
    if(grid[r * C + c] != ' ') return;

    int mines = mines_in_neighborhood(grid, r, c, R, C);
    grid[r * C + c] = '0' + mines;

    if(mines == 0) {
        for(int nr = r - 1; nr <= r + 1; nr++) {
            for(int nc = c - 1; nc <= c + 1; nc++) {
                if( nr == -1 || nc == -1 ||
                    nr == R  || nc == C  ||
                   (nr == r  && nc == c)) continue;
                click(grid, nr, nc, R, C);
            }
        }
    }
}

vector<char> find_winning_click(const vector<char> &grid, int R, int C) {
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(grid[r * C + c] != ' ') continue;

            vector<char> clicked(grid);
            click(clicked, r, c, R, C);
            clicked[r * C + c] = 'c';

            bool winner = true;
            for(int i = 0; i < clicked.size(); i++) {
                if(clicked[i] == ' ') {
                    winner = false;
                    break;
                }
            }

            if(winner) {
                return clicked;
            }
        }
    }

    return vector<char>();
}

vector<char> solve(int R, int C, int M) {
    vector<char> grid(R * C, ' ');
    for(int i = 0; i < M; i++) grid[i] = '*';

    vector<char> winning;

    do {
        winning = find_winning_click(grid, R, C);
        if(winning.size() != 0) break;
    } while(next_permutation(grid));

    return winning;
}

int main() {
    int cases;
    cin >> cases;

    for(int current_case = 1; current_case <= cases; current_case++) {
        int R, C, M;
        cin >> R >> C >> M;

        vector<char> solution = solve(R, C, M);

        cout << "Case #" << current_case << ": " << endl;
        if(solution.size() == 0) {
            cout << "Impossible" << endl;
        } else {
            print_grid(solution, R, C);
        }
    }

    return 0;
}