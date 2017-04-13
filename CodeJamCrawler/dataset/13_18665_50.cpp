#include <iostream>
#include <math.h>

using namespace std;

bool palindrome(int x) {
	int t = x;
	int ret = 0;
	while(x > 0) {
		ret = ret*10 + x%10;
		x /= 10;
	}

	return t==ret;
}

int main () {
	int test;
	cin>>test;
	
	for (int t= 1; t <= test; t++) {
	cout<<"Case #"<<t<<": ";
	int a, b;
	cin>>a>>b;

	int lim1 = sqrt(a);
	int lim2 = sqrt(b);
	
	if (lim1*lim1 < a) lim1++;
	int ctr = 0;
	for (int i = lim1; i <= lim2; i++) {
		if (palindrome(i) && palindrome(i*i)) {
			ctr++;
		}
	}
	cout<<ctr<<endl;
	}
	return 0;
}
