#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ifstream in("B-large.in");
	ofstream out("B-large.out");
	int t = 0;
	in >> t;
	cout << t << endl;	
	
	for (int i = 1; i <= t; i++) {
		int n = 0, m = 0;
		in >> n;
		in >> m;
		vector<vector<int> > lawn(n, vector<int>(m, 0));
		for (int ii = 0; ii < n; ii++) {
			for (int jj = 0; jj < m; jj++) {
				in >> lawn[ii][jj];
				//cout << lawn[ii][jj] << " ";
			}
			//cout << endl;
		}
		
		bool res = true;
		
		vector<vector<bool> > table(n, vector<bool>(m, false));
		vector<int> row_max(n, INT_MIN);
		vector<int> col_max(m, INT_MIN);
		for (int ii = 0; ii < n; ii++) {
			for (int jj = 0; jj < m; jj++) {
				row_max[ii] = max(row_max[ii], lawn[ii][jj]);
				col_max[jj] = max(col_max[jj], lawn[ii][jj]);
			}
		}
		for (int ii = 0; ii < n; ii++) {
			for (int jj = 0; jj < m; jj++) {
				if (lawn[ii][jj] == row_max[ii] || lawn[ii][jj] == col_max[jj]) {
					table[ii][jj] = true;
				}
			}
		}
		for (int ii = 0; ii < n; ii++) {
			for (int jj = 0; jj < m; jj++) {
				if (false == table[ii][jj]) {
					res = false;
					break;
				}
			}
			if (false == res) {
				break;	
			}
		}		
		out << "Case #" << i << ": " << (res == true? "YES" : "NO") << endl;
		//cout << "Case #" << i << ": " << (res == true? "YES" : "NO") << endl;
	}
	
	in.close();
	out.close();
	return 0;	
}
