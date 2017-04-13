#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int T, N;
	cin >> T;
	for(int i = 1; i <= T; i++){
		//get data
		cin >> N;
		vector<float> Kent, Naomi;
		float tmp;
		for(int j = 0; j < N; j++){
			cin >> tmp;
			Naomi.push_back(tmp);
		}
		for(int j = 0; j < N; j++){
			cin >> tmp;
			Kent.push_back(tmp);
		}
		//sort the blocks according to weigh
		sort(Kent.begin(), Kent.end());
		sort(Naomi.begin(), Naomi.end());
		//compute y
		int y = 0;
		int k = 0;
		for(int j = 0; j < N; j++){
			if(Naomi[j] > Kent[k]){
				y++; k++;
			}
		}
		//compute z
		int z = 0;
		k = 0;
		for(int j = 0; j < N; j++){
			if(Kent[j] > Naomi[k]){
				z++; k++;
			}
		}
		z = N - z;
		cout << "Case #" << i << ": " << y << " " << z << endl;
	}
	
	return 0;
}