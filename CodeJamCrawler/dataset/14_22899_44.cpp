#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;


    ifstream fin("D-large.in");
    ofstream fout("output.txt");
    fin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        int score = 0;
        int score2 = 0;
        double naomi[1000];
        double ken[1000];


        fin >> N;

        for (int i = 0; i < N; i++) {
            fin >> naomi[i];
        }


        for (int i = 0; i < N; i++) {
            fin >> ken[i];
        }


       std::sort(naomi, naomi+N);
       std::sort(ken, ken+N);



       int i = 0, j = N-1, k = N-1;
       while (i <= j && k >= 0) {

            if (naomi[j] > ken[k]) {
                score++;
                j--;
            }
            else {
                i++;
            }

            k--;

       }



        i = 0, j = 0;
        while (j < N && i < N) {
            while (j < N && naomi[i] > ken[j]) {
                score2++;
                j++;
            }

            i++; j++;
        }



        fout << "Case #" << t << ": " << score << " " << score2 << endl;
        cout << "Case #" << t << ": " << score << " " << score2 << endl;


    }

    fin.close();


    return 0;
}
