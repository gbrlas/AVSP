#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int height[1<<8][1<<8];
int row[1<<8];
int col[1<<8];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int m, n; cin >> m >> n;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> height[i][j];
		for (int r = 0; r < m; r++){
			row[r] = 0;
			for (int j = 0; j < n; j++)
				row[r] = max(row[r],height[r][j]);
		}
		for (int c = 0; c < n; c++){
			col[c] = 0;
			for (int i = 0; i < m; i++)
				col[c] = max(col[c],height[i][c]);
		}
		
		bool okay = true;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (height[i][j] < row[i] && height[i][j] < col[j]){
					okay = false;
					break;
				}
			}
			if (!okay) break;
		}
		cout << "Case #" << zz << ": ";
		if (okay) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
