#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int limits[11][2];
	for(int i=0; i<11; i++){
		limits[i][0] = i + 2*((i-1)>=0?(i-1):0);
		limits[i][1] = i + 2*((i-2)>=0?(i-2):0);
	}

	int T;
	cin >> T;

	for(int i=0; i<T; i++){
		int N,S,p,t[100];
		cin >> N >> S >> p;
		int Gn[100], Gs[100];
		for(int j=0; j<100; j++){
			Gn[j]=0; Gs[j]=0;
		}

		for(int j=0; j<N; j++){
			cin >> t[j];
			if(t[j] >= limits[p][0])
				Gn[j]=1;
			else if(t[j] >= limits[p][1])
				Gs[j]=1;
		}

		int GN=0, GS=0;
		for(int j=0; j<N;j++){
			GN += Gn[j]; GS += Gs[j];
		}
//		cout << "GN " << GN << " GS " << GS << endl;

		int G = GN+min(GS,S);
		cout << "Case #" << i+1 << ": " << G << endl;
	}

	return 0;
}
