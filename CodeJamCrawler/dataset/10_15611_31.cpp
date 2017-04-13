#include <iostream>

using namespace std;


int T, p;
unsigned long int cost[11][2049];
int miss[2049];
bool assist[11][2049];

int main(){
	cin >> T;
	for (int t=1; t<=T; t++){

		cin >> p;
		// n
		int n = 1 << p;
		// miss
		for (int i=0; i<n; i++)
			cin >> miss[i];
		// matches and cost
		int m = n;
		for (int r=0; r<p; r++){
			m = m >> 1;
			for (int i=0; i<m; i++){
				cin >> cost[r][i];
				assist[r][i] = false;
			}			
		}
		// solve
		unsigned long int sol = 0;
		for (int i=0; i<n; i++){
			int pos = i;
			for (int j=0; j<miss[i]; j++)
				pos = pos >> 1;
			for (int j=miss[i]; j<p; j++){
				pos = pos >> 1;
				if (!assist[j][pos]){
					sol += cost[j][pos];
					assist[j][pos] = true;
				}
			}
		}
		// output
		cout << "Case #" << t << ": " << sol << endl;
	}
	return 0;
}