#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

double opt[100][100];
double avail[100][100];
bool ok[100][100];
int f[100][100], c[100][100];

int main(){
	int t;
	cin >> t;
	
	for(int qq=1; qq<=t; ++qq){
		int h, n, m;
		cin >> h >> n >> m;
		
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cin >> c[i][j];
				opt[i][j] = 99999999;
			}
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cin >> f[i][j];
				
				avail[i][j] = max(0.0, (50+h-c[i][j]) / 10.0);
				ok[i][j] = (c[i][j]-h >= 50);
			}
		}
		
		opt[0][0] = -99999999;
		
for(int rr=0; rr<n*m; ++rr){
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				for(int k=0; k<4; ++k){
					int ii = i+d[k][0], jj = j+d[k][1];
					if(ii<0 || jj<0 || ii>=n || jj>=m) continue;
					
					if(c[ii][jj] - f[ii][jj] < 50) continue;
					if(c[ii][jj] - f[i][j] < 50) continue;
					if(c[i][j] - f[ii][jj] < 50) continue;
					
					double T = max(ok[ii][jj] ? -99999999 : avail[ii][jj], opt[i][j]);
					double k = T + 1;
					if((h-T*10) - f[i][j] < 19.999999) k+=9;
					
					if(k < opt[ii][jj]) opt[ii][jj] = k;
					
				}
			}
		}
	
/*		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				cout << opt[i][j] << '\t';
			} cout << '\n';
		}
		system("pause");*/
}
		
		printf("Case #%d: %.7lf\n", qq, max(0.0,opt[n-1][m-1]) );
		
	}
	
	return 0;
}
