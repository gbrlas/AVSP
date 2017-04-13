#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#define VERBOSE 0

using namespace std;

int main() {
    int T;
    char table[4][4];

    ifstream fin("A-large.in");
    ofstream fout("output.txt");
    fin >> T;
    for (int t = 1; t <= T; t++) {
        char c;

        bool flagCompleted = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                fin >> c;
                table[i][j] = c;
                if (c == '.')
                    flagCompleted = false;
            }
        }

        if (VERBOSE)
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cout << table[i][j];
                }
                cout << endl;
            }

        char win = '.';

        for (int i = 0; i < 4 && win == '.'; i++) {
            for (int j = 0; j < 4 && win == '.'; j++) {
                int k;

                if (i==0) {
                    char s = table[0][j];
                    if (s != '.') {
                        if (s=='T')
                            s = table[1][j];

                        if (s != '.')
                        {

                            for (k = 1; k < 4; k++) {
                                if (table[k][j] != s && table[k][j] != 'T') {
                                    break;
                                }
                            }
                            if (k==4)
                                win = s;
                        }

                    }
                }

                if (j==0) {
                    char s = table[i][0];
                    if (s != '.') {
                        if (s=='T')
                            s = table[i][1];
                        if (s != '.') {
                            for (k = 1; k < 4; k++) {
                                if (table[i][k] != s && table[i][k] != 'T') {
                                    break;
                                }
                            }
                            if (k==4)
                                win = s;
                        }
                    }
                }

                if (j==0 && i==0) {
                    char s = table[0][0];
                    if (s != '.') {
                        if (s=='T')
                            s = table[1][1];
                        if (s != '.')
                        {
                            for (k = 1; k < 4; k++) {
                                if (table[k][k] != s && table[k][k] != 'T') {
                                    break;
                                }
                            }
                            if (k==4)
                                win = s;
                        }

                    }
                }



                if (j==0 && i==3) {
                    char s = table[0][3];

                    if (s != '.') {
                        if (s=='T')
                            s = table[1][2];

                        if (s != '.')
                        {

                            for (k = 1; k < 4; k++) {

                                if (table[k][3-k] != s && table[k][3-k] != 'T') {
                                    break;
                                }
                            }

                            if (k==4)
                                win = s;
                        }
                    }
                }

            }
        }


        string result = "";

        if (flagCompleted && win == '.') {
            result = "Draw";
        }
        else if (win != '.') {
            stringstream ss;
            string s;
            ss << win;
            ss >> s;
            result = s + " won";
        }
        else if (!flagCompleted && win == '.') {
            result = "Game has not completed";
        }



        fout << "Case #" << t << ": " << result << endl;
        cout << "Case #" << t << ": " << result << endl;

    }

    fin.close();


    return 0;
}
