#include <iostream>
#include <string>

using namespace std;

unsigned long int C,n;
unsigned long int word[1001];

unsigned long int gcd(unsigned long int a,unsigned long int b){
	while (b != 0){
		unsigned long int c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int main(){
	cin >> C;
	for (int c=1; c<=C; c++){
		cin >> n;
		for (int i=1; i<=n; i++){
			cin >> word[i];
			int j = i;
			while (j > 1 && word[j] > word[j-1]){
				unsigned long int  tmp = word[j];
				word[j] = word[j-1];
				word[j-1] = tmp;
				j--;
			}
		}
		unsigned long int T;
		if (n == 2)
			T = word[1] - word[2];
		else
			T = gcd(word[1]-word[2], word[2]-word[3]);
		unsigned long int sol;
		sol = (T - (word[n] % T)) % T;
		cout << "Case #" << c << ": " << sol << endl;
	}

	return 0;
}

