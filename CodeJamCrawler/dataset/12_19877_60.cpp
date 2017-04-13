#include<iostream>
#include<cmath>

using namespace std;

int tested[10000][10000];

bool recycled(int n, int m){
	int l = (int) ceil( log10( (float) n));
	if(l != (int) ceil( log10( (float) m))) {
		tested[n][m] = -1;
		return false;
	}
	else {
		int head;
		int tail = (int) pow( (double) 10, l - 1);
		for(int i = 0; i < l - 1; ++i){
			head = n / tail;
			n = (n % tail) * 10 + head;
			if(n == m){
				tested[n][m] = 1;
				return true;
			}
		}	
		tested[n][m] = -1;
		return false;
	}
}

int main(){
	int T, A, B, result;
	string n, m;
	cin >> T;
	for(int i = 1; i <= T; ++i){
		cin >> A >> B;
		result = 0;
		for(int j = A + 1; j <= B; ++j){
			for(int k = A; k < j; ++k){
				if(tested[j][k] == 1) ++result;
				else if(tested[j][k] == 0 && recycled(j,k)) ++result;
			}
		}
		cout << "Case #" << i << ": " << result << endl;
	}
	return 0;
}
