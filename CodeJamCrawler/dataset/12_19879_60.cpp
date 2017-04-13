#include<iostream>
#include<cmath>

using namespace std;

short tested[2000001];

int main(){
	int T, A, B, test, i, j, n, tail, length, result, elements;
	cin >> T;
	for(test = 1; test <= T; ++test){
		cin >> A >> B;
		result = 0;
		for(i = max(A,10); i <= B; ++i){
			if(tested[i] != test){
				length = (int) ceil( log10( (float) i));
				tail = (int) pow( (double) 10, length - 1);
				elements = 1;
				for(j = 0, n = (i % tail)*10 + i / tail; j < length - 1 && i != n; ++j, n = (n % tail)*10 + n / tail){
					if(n > i && A <= n && n <= B && n / tail != 0){
						tested[n] = test;
						++elements;
					}
				}	
				result += (elements * (elements - 1))/2;
			}
		}
		cout << "Case #" << test << ": " << result << endl;
	}
	return 0;
}
