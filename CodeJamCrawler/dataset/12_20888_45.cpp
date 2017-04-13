#include <iostream>
#include <cmath>
using namespace std;

int nRecyclePairs(int n, int A, int B);
int digits(int n);

int main() {
 int T;
 cin >> T;
 for(int i=1; i<=T; i++) {
	int A,B,nPairs=0;
	cin >> A >> B;
	for(int j = A; j<=B; j++) {
	 nPairs+= nRecyclePairs(j,A,B);
	}

	cout << "Case #"<<i<<": "<<nPairs<<endl;
 }
 return 0;
}

int nRecyclePairs(int n,int A,int B) {
	int nPairs = 0;
	int d = digits(n);
	int rotated_n;
	for(int i = 1; i<=d; i++) {
	 int div_number = (int)pow(10.0,i);
	 int mul_number = (int) pow(10.0,d-i);
	 
	 rotated_n = (n%div_number)*mul_number + n/div_number;
	 
	 if(rotated_n > n && rotated_n >=A && rotated_n <=B  ) {nPairs++;}
	}
	return nPairs;
}
int digits(int n) {
	const unsigned int test[] = { 1, 10, 100, 1000, 10000, 100000, 1000000};
	unsigned int digits = 0;
	while(n >= test[digits]) ++digits;
	return digits;
}
