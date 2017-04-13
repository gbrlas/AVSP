#include <iostream>

using namespace std;


int T, p;
unsigned long int cost[11][2049];
unsigned long int sol[11][2049][11];
int miss[11][2049];
int oo = 204800000;

int main(){
	cin >> T;
	for (int t=1; t<=T; t++){

		cin >> p;
		// n
		int n = 1 << p;
		// miss
		for (int i=0; i<n; i++)
			cin >> miss[p][i];
		// matches and cost
		int m = n;
		for (int r=p-1; r>=0; r--){
			m = m >> 1;
			for (int i=0; i<m; i++){
				cin >> cost[r][i];
			}			
		}
		// base
		for (int i=0; i<n; i++){
			for (int j=0; j<p-miss[p][i]; j++)
				sol[p][i][j] = oo;
			for (int j=p-miss[p][i]; j<=p; j++)
				sol[p][i][j] = 0;
			sol[p][i][p+1] = 0;
		}
		// solve
		m = n;
		for (int r=p-1; r>=0; r--){
			m = m >> 1;
			for (int i=0; i<m; i++){
				sol[r][i][p+1] = 0;
				for (int j=0; j<=p; j++){
					sol[r][i][j] = (j > 0) ? sol[r][i][j-1] : oo;
					unsigned long int go = cost[r][i] + sol[r+1][i*2][j+1] + sol[r+1][i*2+1][j+1];
					if (sol[r][i][j] > go)
						sol[r][i][j] = go;
					unsigned long int no = sol[r+1][i*2][j] + sol[r+1][i*2+1][j];
					if (sol[r][i][j] > no)
						sol[r][i][j] = no;
				}
			}			
		}
		// output
		cout << "Case #" << t << ": " << sol[0][0][0] << endl;
	}
	return 0;
}