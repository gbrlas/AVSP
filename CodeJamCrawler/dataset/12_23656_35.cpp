#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	// Take the first arg as an input file
	ifstream in(argv[1]);
	if (!in.good()) {
		fprintf(stderr, "bad input file\n");
		return 1;
	}
	string line;
	getline(in, line);
	int cases = atoi(line.c_str());
	for (int c = 1; c <= cases; ++c) {
		getline(in, line);
		// Tokenize the string
		list<string> tokens;
		istringstream iss(line);
		copy(istream_iterator<string>(iss), istream_iterator<string>(),
				back_inserter<list<string>>(tokens));
		int googlers = atoi(tokens.front().c_str());
		tokens.pop_front();
		int surprising = atoi(tokens.front().c_str());
		tokens.pop_front();
		int p = atoi(tokens.front().c_str());
		tokens.pop_front();
		int answer = 0;
		// For each googler, see if they could have had a best result of p
		for (int g = 0; g < googlers; ++g) {
			int total = atoi(tokens.front().c_str());
			tokens.pop_front();
			if (total < max((p - 2), 0) * 2 + p)
				continue;

			if (total < max((p - 1), 0) * 2 + p) { // It would need to be surprising
				if (surprising > 0) {
					// There could be a best result of p, but it would have
					// to be part of a surprising triplet
					--surprising;
					++answer;
				}
			}
			else {
				// We have a non-surprising with a possible best of p
				++answer;
			}
		}
		printf("Case #%d: %d\n", c, answer);
	}
	return 0;
}
