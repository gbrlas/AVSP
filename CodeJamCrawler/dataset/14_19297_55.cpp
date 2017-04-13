/*
 * codejamMagic.cpp
 *
 *  Created on: Apr 11, 2014
 *      Author: XY
 */

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

string getRes(vector<int> &nums) {
	bool hasFound = false;
	int res = 0;
	for (int i = 1; i < 17; ++i) {
		if (nums[i] == 2) {
			if (hasFound) {
				return "Bad magician!";
			} else {
				hasFound = true;
				res = i;
			}
		}
	}
	if (hasFound) {
            ostringstream convert;
            convert << res;
            return convert.str();
	} else return "Volunteer cheated!";
}


int main() {
    //const char* input_file = "atest.txt";
    const char* input_file = "small-magic.in";
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
                cout << casenums << endl;
            } else {
                if (cnum >= casenums) break;

                int ans, a, b, c, d;
				vector<int> nums(17, 0);
				cout << "Here" << endl;
				for (int k = 0; k < 2; ++k) {
                    cout << k << endl;
					fin >> ans;
					cout << ans << endl;
					for (int j = 0; j < 4; ++j) {
						fin >> a >> b >> c >> d;
						if ((j + 1) == ans) {
							nums[a]++;
							nums[b]++;
							nums[c]++;
							nums[d]++;
						}
					}
				}
                linenum ++;
                cnum++;
                cout << cnum << endl;
                if (fout.good()) fout << "Case #" << cnum << ": " << getRes(nums) << endl;
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



