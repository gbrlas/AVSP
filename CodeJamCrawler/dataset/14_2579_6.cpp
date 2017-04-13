#include <iostream>
#include <vector>
using namespace std;



int main() {
	
	int matrix[4][4];
	vector<int> v(4);
	vector<int> v2(4);
        int n;
        cin >> n;
	int aux;
	int x = 1;
   	while (x <= n){
		int fila;
		cin >> fila;
		//cout << fila << endl;
		//read matt
		for(int i =0; i<4;++i){
			for (int j = 0; j < 4; ++j){
				cin >> aux;
				//cout << " comp" << i << " " << fila-1 << endl;
				if(i == fila-1) v[j] = aux;
				//cout <<" vec " <<v[j] << endl;}
			}
		}
		cin >> fila;
		//cout << fila << endl;
		//read matt
		for(int i =0; i<4;++i){
			for (int j = 0; j < 4; ++j){
				cin >> aux;
				//cout << " comp" << i << " " << fila-1 << endl;
				if(i == fila-1) v2[j] = aux;
				//cout <<"vec 2 " << v2[j] << endl;}//cout << aux << endl;
			}
		}
		//comp
		bool trobat = false;
		bool repe = false;


		for(int i =0; i<4;++i){
			for (int j = 0; j < 4; ++j){
			if(v[i] == v2[j]) {
				if(not trobat){
					trobat = true;
					aux = v[i];
				}
				else {
					repe = true;
				}
			}
			}
		}
		if (repe) cout << "Case #" << x << ": Bad magician!" << endl;
		else if(trobat) cout << "Case #" << x << ": " << aux <<endl;
		else cout << "Case #" << x << ": Volunteer cheated!" << endl;
		++x;

		

		
	}

}

