
#include <iostream>

using namespace std;
typedef unsigned int uint;

int main(){
	uint nt;
	cin >> nt;

	int map[100][100];
	bool mapc[100][100];

	for(uint t=0;t<nt;t++){

		bool res;
		uint n,m;
		cin >> n >> m;
		for(uint i=0;i<n;i++){
			for(uint j=0;j<m;j++){
				cin >> map[i][j];
				mapc[i][j]=false;
			}
		}

		for(uint i=0;i<n;i++){
			int mm=0;
			for(uint j=0;j<m;j++){
				if(mm<map[i][j]){
					mm=map[i][j];
				}
			}
			for(uint j=0;j<m;j++){
				if(mm==map[i][j]){
					mapc[i][j]=true;
				}
			}
		}
		for(uint j=0;j<m;j++){
			int mm=0;
			for(uint i=0;i<n;i++){
				if(mm<map[i][j]){
					mm=map[i][j];
				}
			}
			for(uint i=0;i<n;i++){
				if(mm==map[i][j]){
					mapc[i][j]=true;
				}
			}
		}

		res=true;
		for(uint i=0;i<n;i++){
			for(uint j=0;j<m;j++){
				if(!mapc[i][j]){
					res=false;
				}
			}
		}

		cout << "Case #" << t+1 << ": ";
		if(res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}