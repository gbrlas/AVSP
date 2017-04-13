#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>


using namespace std;

int main() {
    int T;
    vector<int> list;

    ifstream fin("C-small-attempt2.in");
    ofstream fout("output.txt");
    fin >> T;
    for (int t = 1; t <= T; t++) {
        long long int A,B,result = 0;
        fin >> A;
        fin >> B;

        long long int start = (long long int) floor(sqrt(A));
        long long int end = (long long int) ceil(sqrt(B));

        for (long long int i = start; i <= end; i++) {
            string stringnumber;
            stringstream ss;
            ss << i;
            ss >> stringnumber;
            if( equal(stringnumber.begin(), stringnumber.begin() + stringnumber.size()/2, stringnumber.rbegin()) ) {
                long long int si = (long long int) i*i;
                if (si < A || si > B) {
                    continue;
                }
                string stringnumber2;
                stringstream ss2;
                ss2 << si;
                ss2 >> stringnumber2;
                if( equal(stringnumber2.begin(), stringnumber2.begin() + stringnumber2.size()/2, stringnumber2.rbegin()) ) {
                    result++;
                }

            }


        }
        fout << "Case #" << t << ": " << result << endl;
        cout << "Case #" << t << ": " << result << endl;

    }

    fin.close();


    return 0;
}
