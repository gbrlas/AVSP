#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x[100][100];

int main(){
	int cases;
	cin >> cases;
	
	for(int q=1; q<=cases; ++q){
		cout << "Case #" << q << ": ";
		
		int h, w; cin >> h >> w;
		for(int i=0; i<h; ++i){
			for(int j=0; j<w; ++j){
				cin >> x[i][j];
			}
		}
		
		bool good=1;
		
		for(int H=100; H>=1; --H){
			bool b[100][100] = {{0}};
			for(int i=0; i<h; ++i){
				bool cut=1;
				for(int j=0; j<w; ++j) if(x[i][j] > H) {cut=0; break;}
				if(cut) for(int j=0; j<w; ++j) b[i][j] = 1;
			}
			for(int i=0; i<w; ++i){
				bool cut=1;
				for(int j=0; j<h; ++j) if(x[j][i] > H) {cut=0; break;}
				if(cut) for(int j=0; j<h; ++j) b[j][i] = 1;
			}
			
			for(int i=0; i<h; ++i){
				for(int j=0; j<w; ++j){
					if(b[i][j] != (x[i][j] <= H)){
						good = 0;
					}
					//cout << b[i][j];
				} //cout << '\n';
			}
		}
		
		if(good) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
