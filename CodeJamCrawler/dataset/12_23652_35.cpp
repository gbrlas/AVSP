#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

static const char* map = "yhesocvxduiglbkrztnwjpfmaq";

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
		printf("Case #%d: ", c);
		for (auto& ch : line) {
			if (ch == ' ')
				continue;
			ch = map[ch - 'a'];
		}
		printf("%s\n", line.c_str());
	}
	return 0;
}
