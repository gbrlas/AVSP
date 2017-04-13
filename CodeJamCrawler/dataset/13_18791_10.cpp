#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

int stringToInt (const string &text) {
    stringstream ss(text);
    int res;
    return ss >> res ? res : 0;
}

template <typename T>
void stringToArray(const string &text, const int &size, T nums[]) {
    string tmp = "";
    int counter = 0;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            nums[counter] = (T) stringToInt(tmp);
            counter++;
            tmp = "";
        }
        else tmp += text[i];
    }
    nums[counter] = (T) stringToInt(tmp);
}

int getCount(const int A, const int N, vector<int> &motes) {
    sort(motes.begin(), motes.end());
    vector<int> vals(N+1, A);
    vector<int> counter(N+1,0);
    for (int i=0; i<N; ++i) {
        if (vals[i] > motes[i]) {
            vals[i+1] = vals[i]+motes[i];
            counter[i+1]= counter[i];
        } else {
            int ifdelete = N-i;
            int ifinsert = 0, j = 0;
            for (j=vals[i]; j<=motes[i]; j+=(j-1)) {
                ifinsert++;
                if (ifinsert > ifdelete) break;
            }

            if (ifinsert >= ifdelete) return counter[i] + ifdelete;
            counter[i+1] = counter[i]+ifinsert;
            vals[i+1] = j+motes[i];
            cout << i << " + " << vals[i+1] << endl;
        }
    }
    return counter[N];
}

int main() {
    //const char* input_file = "atest.txt";
    const char* input_file = "asmall.in";
    //const char* input_file = "alarge.in";
    const char* output_file = "aout.out";
    ifstream fin(input_file);
    ofstream fout(output_file);

    int casenums = 0, cnum = 0;

    if (fin.is_open()) {
        int linenum = 0;
        string line;
        while (fin.good()) {
            if (linenum == 0) {
                fin >> casenums;
            } else {
                if (cnum >= casenums) break;


                int A = 0, N = 0;
                fin >> A >> N;
                vector<int> motes(N, 0);
                for (int i = 0; i < N; ++i) fin >> motes[i];
                int res = getCount(A, N, motes);


                linenum ++;
                cnum++;
                cout << cnum << endl;
                if (fout.good()) fout << "Case #" << cnum << ": " << res << endl;
                //if (fout.good()) fout << "Case #" << cnum << ": " << setiosflags(ios::fixed) << setprecision(6) << res << endl;
                else cout << "I/O error when writting into " << output_file << endl;
            }
            linenum++;
        }
        fin.close();
    }
    else cout << "Unable to open " << input_file << endl;

    fout.close();
    return 0;
}
