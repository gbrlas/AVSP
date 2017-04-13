// Qualifying Round Problem A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string infile("A-small-attempt0.in"), outfile("A-small.out");
    ifstream in;
	vector<pair<int, int> > cases;
	vector<int> result;
	in.open(infile.c_str(), ios::in);

	int T, N, K;
	in >> T;

	for(int i = 0;i < T; i++) {
		in >> N >> K;
        cases.push_back(pair<int, int>(N, K));
	}

	in.close();


	for(int i = 0; i < T; i++) {
		int opval = int(pow(2.0, cases[i].first));
		result.push_back(cases[i].second% opval == (opval-1));
	}


    ofstream out;
	out.open(outfile.c_str(), ios::out);

	for(int i = 0; i < T; i++) {
		out << "Case #" << i + 1 << ": " << (result[i] ? "ON" : "OFF") << endl;
	}

	out.close();

	return 0;
}

