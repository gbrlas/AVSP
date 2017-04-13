#include <iostream>

using namespace std;


int T,r;
unsigned long int x1[1001],x2[1001],y1[1001],y2[1001];
bool bact[101][101];

int main(){
	cin >> T;
	for (int t=1; t<=T; t++){
		cin >> r;
		// init
		for (int x=0; x<=100; x++)
			for (int y=0; y<=100; y++)
				bact[x][y] = false;
		// ranges
		bool next = false;
		for (int i=0; i<r; i++){
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
			for (unsigned long int x=x1[i]; x<=x2[i]; x++)
				for (unsigned long int y=y1[i]; y<=y2[i]; y++) {
					bact[x][y] = true;
					next = true;
				}
		}
		// reproduce
		unsigned long int sol = 0;
		while (next){
			sol ++;
			next = false;
			for (unsigned long int x=100; x>=1; x--)
				for (unsigned long int y=100; y>=1; y--){
					if (bact[x][y] && (x==0 || !bact[x-1][y]) && (y==0 || !bact[x][y-1])) 
						bact[x][y] = false; else
					if (!bact[x][y] && (x!=0 && bact[x-1][y]) && (y!=0 && bact[x][y-1])) 
						bact[x][y] = true;
					if (bact[x][y])
						next = true;
				}
		}
		// output
		cout << "Case #" << t << ": " << sol << endl;
	}
	return 0;
}