/*
 * main.cpp
 *
 *  Created on: Apr 12, 2014
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "DeceitfulWar.h"


using namespace std;

int main( int argc, char* argv[] ) {
	if (argc != 2) return 1;
	
	ifstream ifs(argv[1]);
	string line;
	
	int case_num = 0;
	if (getline(ifs, line)) { 
		istringstream si(line);
		si >> case_num;
	}
	
	for (int i = 1; i <= case_num; i++) {
		DeceitfulWar m;
		cout << "Case #" << i << ": " << m.solve(m.readCase(ifs)) << endl;
	}
}


