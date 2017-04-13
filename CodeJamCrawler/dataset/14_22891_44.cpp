#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;


    ifstream fin("A-small-attempt0.in");
    ofstream fout("output.txt");
    fin >> T;
    for (int t = 1; t <= T; t++) {
        string caseresult;

        int ans1;
        int matrix1[4][4];
        int ans2;
        int matrix2[4][4];

        fin >> ans1;
        ans1-=1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                fin >> matrix1[i][j];
            }
        }

        fin >> ans2;
        ans2-=1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                fin >> matrix2[i][j];
            }
        }



        vector<int> first;
        for (int i = 0; i < 4; i++) {
            first.push_back(matrix1[ans1][i]);
        }

        vector<int> second;
        for (int i = 0; i < 4; i++) {
            second.push_back(matrix2[ans2][i]);
        }


        std::vector<int> v(8);
        std::vector<int>::iterator it;

        std::sort (first.begin(),first.end());     //  5 10 15 20 25

        std::sort (second.begin(),second.end());   // 10 20 30 40 50


        it=std::set_intersection (first.begin(),first.end(), second.begin(),second.end(),v.begin());

        v.resize(it-v.begin());                      // 10 20



        if (v.size() == 0) {
            caseresult = "Volunteer cheated!";
        }
        else if (v.size() == 1) {
            caseresult = v.at(0);
        }
        else {
            caseresult = "Bad magician!";
        }





        fout << "Case #" << t << ": ";
        cout << "Case #" << t << ": ";

        if (v.size() == 0) {
            cout << "Volunteer cheated!";
            fout << "Volunteer cheated!";
        }
        else if (v.size() == 1) {
            cout << v.at(0);
            fout << v.at(0);
        }
        else {
            cout << "Bad magician!";
            fout << "Bad magician!";
        }
        fout << endl;
        cout << endl;

    }

    fin.close();


    return 0;
}
