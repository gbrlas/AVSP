#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int pow10(int k){
	int val = 1;
	for(int i=0;i<k;i++){
		val *= 10;
	}
	return val;
}

int main(){
	int T;
	cin >> T;

	for(int i=0; i<T; i++){
		int A,B;
		cin >> A >> B;
		int N=0;
		int numDigits = (int)log10(A)+1;
//		cout << "Num Digits " << numDigits << endl;

		for(int n=A; n<=B; n++){
			set<int> mset;
			mset.clear();
			for(int k=1; k<numDigits; k++){
				int m = n/pow10(k)+(n%pow10(k))*(pow10(numDigits-k));
				if(m > n && n >= A && m <= B && mset.count(m)==0){
					N++;
					mset.insert(m);
//					cout << "(" << n << ", " << m << ")" << endl;
				}
			}
		}

		cout << "Case #" << (i+1) << ": " << N << endl;
	}
	return 0;
}
