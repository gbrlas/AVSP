#include <iostream>
using namespace std;

short T;
long double k, total, g[1001], sol, amount[1000];
int R;
int n, reach[1000];

int main(){
	cin >> T;
	for (short t=1; t<=T; t++){
		cin >> R >> k >> n;
		total = 0;
		for (int i=0; i<n; i++){
			cin >> g[i];
			if (total < k)
				total += g[i];
		}
		if (total < k)
			sol = total * R;
		else {
			int j = 0;
			for (int i=0; i<n; i++){				
				int left = k - g[i];
				int j = i+1;
				if (j==n) j=0;
				while (left >= g[j] && j != i){
					left -= g[j];
					j++;
					if (j==n) j=0;
				}
				reach[i] = j;
				amount[i] = k - left;
			}

			sol = 0;
			int i = 0;
			for (int r=0; r<R; r++){
				sol += amount[i];
				i = reach[i];
			}
		}
		cout << "Case #" << t << ": " << sol << endl;
	}
	return 0;
}