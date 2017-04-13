#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool isValid(vector<vector<int> >& v) {
	int n = v.size();
	int m = v[0].size();
	if (n == 1 || m == 1) return true;
	
	vector<int> maxy(n, 0),  maxx(m, 0); 
	for (int y = 0; y < n; ++y) 
	for (int x = 0; x < m; ++x) {
		if ( v[y][x] > maxy[y]) maxy[y] = v[y][x];
		if ( v[y][x] > maxx[x]) maxx[x] = v[y][x];
	}
	
	for (int y = 0; y < n; ++y) 
	for (int x = 0; x < m; ++x) {
		if ( v[y][x] < maxy[y] && v[y][x] < maxx[x]) return false;
	}
	return true;
}

void solve(void) {
	ifstream f("data.txt");
	string line;
	getline(f, line);
	int numCases = atoi(line.c_str());	
	ofstream f2("out.txt");
	
	for (int i = 0; i < numCases; i++) {
		getline(f, line);
		char *p = strtok((char *)line.c_str(), " ");
		int n = atoi(p);
		p = strtok(NULL, " ");
		int m = atoi(p);
		vector<vector<int> > v(n, vector<int>(m, 0));
		for (int y = 0; y < n; ++y) {
			getline(f, line);
			p = strtok((char *)line.c_str(), " ");
			v[y][0] = atoi(p);
			for (int x = 1; x < m; ++x) {
				p = strtok(NULL, " ");
				v[y][x] = atoi(p);
			}
		}
		if ( isValid(v) ) 
			f2 << "Case #" << i+1 << ": " << "YES" << endl;
		else
			f2 << "Case #" << i+1 << ": " << "NO" << endl;		
	}
	
	f.close();
	f2.close();	
}

int main() {
	solve();
	return 0;
}
