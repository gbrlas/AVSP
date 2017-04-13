#include "../../../template.h"
#include <fstream>

void output_me(pair<char,char> p) {
    cout << p.first << ' ' << p.second << endl;
}


int main(void) {
    ifstream file1, file2;
    vector<string> v1, v2;
    map<char, char> m;
    string s;
    file1.open("sinput.txt");
    while (!file1.eof()) {
        getline(file1, s);
        v1.push_back(s);
    }
    file1.close();
    file2.open("soutput.txt");
    while (!file2.eof()) {
        getline(file2, s);
        v2.push_back(s);
    }
    file2.close();

    for (int i=0; i<v1.size(); i++) {
        for (int j=0; j<v1[i].size(); j++) {
            m.insert(MP(v1[i][j], v2[i][j]));
        }
    }

    //for_each(m.begin(), m.end(), output_me);

    int T;
    cin >> T;
    cin.ignore();
    for (int x=1; x<=T; x++) {
        string ain, aout;
        getline(cin, ain);
        for (int i=0; i<ain.size(); i++) {
            aout = aout + m.find(ain[i])->second;
        }
        cout << "Case #" << x << ": " << aout << endl;
    }
}

