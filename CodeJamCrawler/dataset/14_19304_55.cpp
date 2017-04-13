#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>

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

double func(double c, double f, double x, int k) {
    if (k==0) return 0;
    double res = 0;
    for (int i=0; i<k; ++i) {
        res += c / (2.0 + (double)i*f);
    }
    return res;
}

double getRes(double c, double f, double x) {
	double res = x/2.0;
	double thresh = (x*f - 2.0*c) / (c*f);
	int k = max(0, (int)thresh);
	cout << "k=" << k << endl;
	double opt = (x / (2.0 + (double)k * f) + func(c, f, x, k));
	if (res > opt) res = opt;
	return res;
}



int main() {
    //const char* input_file = "test-cookie.txt";
    //const char* input_file = "small-cookie.in";
    const char* input_file = "large-cookie.in";
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
                cout << casenums << endl;
            } else {
                if (cnum >= casenums) break;

                double c, f, x;
                fin >> c >> f >> x;
                cout << c << f << x << endl;
                linenum ++;
                cnum++;
                cout << cnum << endl;
                //if (fout.good()) fout << "Case #" << cnum << ": " << getRes(c, f, x) << endl;
                if (fout.good()) fout << "Case #" << cnum << ": " << setiosflags(ios::fixed) << setprecision(7) << getRes(c, f, x) << endl;
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



