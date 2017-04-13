#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <set>
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

set<double> getSet(string line) {
    //cout << line << endl;
    set<double> res;
    istringstream ss(line);
    string s;
    while (getline(ss, s, ' ')) {
        double d;
        stringstream ds(s);
        ds >> d;
        res.insert(d);
    }
    return res;
}

int getRes1(set<double> nao, set<double> ken) {
    int res = 0;
    auto inao = nao.begin();
    auto iken = ken.begin();
    vector<int> bigger;
    while(inao != nao.end() && iken != ken.end()) {
        if (*inao > *iken) iken++;
        else {
            bigger.push_back(distance(ken.begin(), iken));
            inao++;
        }
    }
    for (auto i : bigger) cout << i << " ";
    cout << endl;

    for (int i=0; i<bigger.size(); ++i) {
        res = max(res, (i+1) - bigger[i]);
    }
	return max(0, (int)nao.size() - res);
}

int getRes2(set<double> nao, set<double> ken) {
	int res = 0;
	bool flag = false;
	for (auto wnao : nao) {
        flag = false;
        for (auto wken : ken) {
            if (wken > wnao) {
                ken.erase(wken);
                flag = true;
                break;
            }
        }
        if (flag == false) {
            res++;
            ken.erase(*ken.begin());
        }
	}
	return res;
}


int main() {
    //const char* input_file = "test-war.txt";
    const char* input_file = "small-war.in";
    //const char* input_file = "large-cookie.in";
    const char* output_file = "aout.out";
    ifstream fin(input_file);
    ofstream fout(output_file);

    int casenums = 0, cnum = 0;

    if (fin.is_open()) {
        int linenum = 0;
        string line;
        while (fin.good()) {
            if (linenum == 0) {
                getline(fin, line);
                casenums = stringToInt(line);
                cout << casenums << endl;
            } else {
                if (cnum >= casenums) break;
                getline(fin, line);
                int num = stringToInt(line);
                getline(fin, line);
                set<double> nao = getSet(line);
                getline(fin, line);
                set<double> ken = getSet(line);
                linenum ++;
                cnum++;
                cout << cnum << endl;
                if (fout.good()) fout << "Case #" << cnum << ": " << getRes1(nao, ken) << " " << getRes2(nao, ken) << endl;
                //if (fout.good()) fout << "Case #" << cnum << ": " << setiosflags(ios::fixed) << setprecision(7) << getRes(c, f, x) << endl;
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



