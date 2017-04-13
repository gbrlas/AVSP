#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
int appearance(string input, string phrase, int i, int j) {
	if (j == phrase.length())
		return 1;
	if (i == input.length())
		return 0;
	while (input[i++] != phrase[j])
		if (i == input.length())
			return 0;
	return (appearance(input, phrase, i, j) + appearance(input, phrase, i, j+1)) % 10000;
}
int main(int argc, char **argv) {
	ifstream fin(argv[1]);
	char buffer[512];
	int N;
	fin.getline(buffer, 512);
	sscanf(buffer, "%d", &N);
	string phrase("welcome to code jam");
	for (int n = 0; n < N; n++) {
		fin.getline(buffer, 512);
		string input(buffer);
		cout << "Case #" << n+1 << ": ";
		cout.width(4);
		cout.fill('0');
		cout << appearance(input, phrase, 0, 0);
		cout << endl;
	}
	return 0;
}
