#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cout << "Case #" << i << ": ";
		int A, B, K;
		cin >> A >> B >> K;
		int count = 0;
		for(int i = 0; i < A; i++){
			for(int j = 0; j < B; j++){
				if((i&j) < K) count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}