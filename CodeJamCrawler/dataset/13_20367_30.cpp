#include <iostream>

using namespace std;


void print_result(int game_no, char code) {
    cout << "Case #" << game_no+1 << ": ";
    switch (code) {
    case 'X':
        cout << "X won";
        break;

    case 'O':
        cout << "O won";
        break;

    case 'D':
        cout << "Draw";
        break;

    case 'I':
        cout << "Game has not completed";
        break;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    char A[4][4];

    for (int i=0; i < n; i++) {
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++)
                cin >> A[j][k];

        char tmp[100];
        cin.getline(tmp, 100);

//        for (int j=0; j<4; j++) {
//            for (int k=0; k<4; k++)
//                cout << A[j][k];
//            cout << endl;
//        }
//        cout<<endl;

        int total_dot_count = 0; bool res_known = false;
        // check for horizontal win
        for (int j=0; j<4 && !res_known; j++) {

            int X_count = 0, O_count = 0, T_count = 0;

            for (int k=0; k<4 && !res_known; k++) {
                if (A[j][k] == 'O') O_count++;
                else if (A[j][k] == 'X') X_count++;
                else if (A[j][k] == 'T') T_count++;
                else if (A[j][k] == '.') total_dot_count++;
            }

//            cout <<"X:"<<X_count<<endl;

            if (X_count == 4 || (X_count == 3 && T_count == 1) ) {
                print_result(i, 'X');
                res_known = true;
                continue;
            }

            if (O_count == 4 || (O_count == 3 && T_count == 1) ) {
                print_result(i, 'O');
                res_known = true;
            }
        }

        for (int k=0; k<4 && !res_known; k++) {
            int X_count = 0, O_count = 0, T_count = 0;
            for (int j=0; j<4 && !res_known; j++) {
                if (A[j][k] == 'O') O_count++;
                else if (A[j][k] == 'X') X_count++;
                else if (A[j][k] == 'T') T_count++;
            }

            if (X_count == 4 || (X_count == 3 && T_count == 1) ) {
                print_result(i, 'X');
                res_known = true;
                continue;
            }

            if (O_count == 4 || (O_count == 3 && T_count == 1) ) {
                print_result(i, 'O');
                res_known = true;
            }
        }


        // diagonal 1
        int X_count = 0, O_count = 0, T_count = 0;
        for (int j=0; j<4 && !res_known; j++) {
            if (A[j][j] == 'O') O_count++;
            else if (A[j][j] == 'X') X_count++;
            else if (A[j][j] == 'T') T_count++;
        }
        if (X_count == 4 || (X_count == 3 && T_count == 1) ) {
            print_result(i, 'X');
            res_known = true;
            continue;
        }
        if (O_count == 4 || (O_count == 3 && T_count == 1) ) {
            print_result(i, 'O');
            res_known = true;
            continue;
        }

        // diagonal 2
        X_count = 0; O_count = 0; T_count = 0;
        for (int j=0; j<4 && !res_known; j++) {
            if (A[j][3-j] == 'O') O_count++;
            else if (A[j][3-j] == 'X') X_count++;
            else if (A[j][3-j] == 'T') T_count++;
        }
        if (X_count == 4 || (X_count == 3 && T_count == 1) ) {
            print_result(i, 'X');
            res_known = true;
            continue;
        }
        if (O_count == 4 || (O_count == 3 && T_count == 1) ) {
            print_result(i, 'O');
            res_known = true;
            continue;
        }





        if (!res_known)
            if(total_dot_count == 0) {
                print_result(i, 'D');
                continue;
            }
            else
                print_result(i, 'I');

    }
}
