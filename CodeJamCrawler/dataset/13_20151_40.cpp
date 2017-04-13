#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <string>
#include <memory>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;


namespace {

    // numeric_limits<int>::max()

    template<class T> int cSize(const T& c) // returns the size of a container as an int
    {
        return (int)c.size();
    }

    struct Instance {
        Instance(istream& in, int caseNo) : in(in), caseNo(caseNo) {}

        istream& in;
        int caseNo;
        string res;
        char board [4][4];

        void readData() {
            for (int i = 0; i < 4; ++i) {
                string s;
                getline(in, s);
                if (s.empty()) {
                    getline(in, s);
                }
                for (int j = 0; j < 4; ++j) {
                    board[i][j] = s[j];
                }
            }
        }

        bool check(char c) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (board[i][j] != c && board[i][j] != 'T') {
                        goto e1;
                    }
                }
                return true;
            e1:;
            }

            for (int j = 0; j < 4; ++j) {
                for (int i = 0; i < 4; ++i) {
                    if (board[i][j] != c && board[i][j] != 'T') {
                        goto e3;
                    }
                }
                return true;
            e3:;
            }

            for (int i = 0; i < 4; ++i) {
                if (board[i][i] != c && board[i][i] != 'T') {
                    goto e4;
                }
            }
            return true;

        e4:;
            for (int i = 0; i < 4; ++i) {
                if (board[i][3 - i] != c && board[i][3 - i] != 'T') {
                    goto e2;
                }
            }
            return true;

        e2:;
            return false;
        }

        bool isFinished() {
            for (int j = 0; j < 4; ++j) {
                for (int i = 0; i < 4; ++i) {
                    if (board[i][j] == '.') {
                        return false;
                    }
                }
            }
            return true;
        }

        void computeResults() {
            if (check('O')) {
                res = "O won";
                return;
            }
            if (check('X')) {
                res = "X won";
                return;
            }
            if (!isFinished()) {
                res = "Game has not completed";
                return;
            }
            res = "Draw";
        }

        void printResults() {
            cout << "Case #" << caseNo << ": " << res << endl;
            //cout << "=================================\n";
        }

        void solve() {
            readData();
            computeResults();
            printResults();
        }
    };
}



int main(int argc, char**) {

#ifdef READ_FROM_ARGV1
    auto_ptr<ifstream> p;
    istream* in;
    if (argc >= 2) {
        p.reset(new ifstream("/home/ciobi/cpp/QtCreatorTests/Tst01-build-desktop/run/gcj_2013_Q_A.tst")); // the value of argv[1] doesn't matter; as long as in IDE there's an argv[1], the specified file is used; OTOH in CLI redirection works well, as argv[1] doesn't exist; so READ_FROM_ARGV1 isn't really needed, but it's used as a precaution
        in = p.get();
    } else {
        in = &cin;
    }
#else
    istream* in (&cin);
#endif
    int t;
    (*in) >> t;

    for (int i = 0; i < t; ++i) {
        Instance inst (*in, i + 1);
        inst.solve();
    }
    return 0;
}






