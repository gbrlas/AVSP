#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;
typedef long long int64;
int main(){
	int T;
	cin >> T;
	int g[10];
	for(int i = 0; i < T; ++i){
		int R, k ,N;
		cin >> R >> k >> N;
		for(int j = 0; j < N; ++j){
			cin >> g[j];
		}
		int res = 0, pos = 0;
		for(int step = 0; step < R; step++){
			int sum = 0;
			int oldpos = pos;
			do{
				sum += g[pos];
				if(sum > k){
					sum -= g[pos];
					break;
				}
				pos = (pos + 1) % N;
			}while(pos != oldpos);
			res += sum;
		}
		cout << "Case #" << i + 1 << ": " << res << endl; 
	}	
}
