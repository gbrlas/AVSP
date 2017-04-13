#include<iostream>

using namespace std;

int main(){
	int result;
	int T, N, S, p, score;
	cin >> T;
	for(int i = 1; i <= T; ++i){
		result = 0;
		cin >> N >> S >> p;
		for(int j = 0; j < N; ++j) {
			cin >> score;
			if(score >= 3*p - 2) ++result;
			else if(score >= 3*p - 4 && S > 0 && score > 0){ ++result; --S; }
		}
		cout << "Case #" << i << ": " << result << endl;
	}
	return 0;
}
