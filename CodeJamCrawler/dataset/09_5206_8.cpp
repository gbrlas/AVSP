#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <math.h>

using namespace std;

int main() {
	string filename;
	cin >> filename;
	string infile = filename + ".in", outfile = filename + ".out";
	ifstream inf(infile.c_str());
	ofstream outf(outfile.c_str());

	int tc;
	string line;
	getline(inf, line);
	istringstream iss(line);
	iss >> tc;

	for (int t = 1; t <= tc; t++) {
		getline(inf, line);
		map<char, unsigned int> base;

//		if(line.length() == 1){
//			outf << "Case #" << t << ": " << 0 << endl;
//			//cout << "Case #" << t << ": " << 0 << endl;
//			continue;
//		}

		base[line[0]] = 1;
		bool zero_flag = false;
		unsigned int b = 2;

		for (int i = 1; i < line.size(); i++) {
			if (!zero_flag) {
				if (!base.count(line[i])) {
					base[line[i]] = 0;
					zero_flag = true;
				}
			} else {
				if (!base.count(line[i])) {
					base[line[i]] = b++;
				}
			}
		}
		//cout <<line <<": "<< b<< endl;
		unsigned long long r = 0;
		for (int i = 0; i < line.size(); i++) {
			r += base[line[i]]*pow(b, line.size()-1-i);
		}

		outf << "Case #" << t << ": " << r << endl;
//		cout << "Case #" << t << ": " <<line << ": ";
//		for (int i = 0; i < line.size(); i++) {
//			cout << base[line[i]];
//		}
//		cout <<"("<<b<<")";
//		cout <<": "<< r << endl;
	}

	return 0;
}
