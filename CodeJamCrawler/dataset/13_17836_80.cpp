#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void solve(void) {
	ifstream f("data.txt");
	string line;
	getline(f, line);
	int numCases = atoi(line.c_str());	
	ofstream f2("out.txt");

	int fair[5] = {1, 4, 9, 121, 484};
	
	for (int i = 0; i < numCases; ++i) {
		getline(f, line);
		char *p = strtok((char *)line.c_str(), " ");
		int a = atoi(p);
		p = strtok(NULL, " ");
		int b = atoi(p);
		int count = 0;
		for (int j = 0; j < 5; j++)
			if ( fair[j] >= a && fair[j] <= b ) count ++;
		f2 << "Case #" << i+1 << ": " << count << endl;	
	}
	
	f.close();
	f2.close();		
}

int main() {
	solve();
	return 0;
}
