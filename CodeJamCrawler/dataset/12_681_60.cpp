#include <iostream>
#include <set>

using namespace std;

int count_digits(int n) {
	 int digits = 0;
	 while (n > 0) {
		  digits++;
		  n /= 10;
	 }
	 return digits;
}

int count(int A, int B, int n) {
//	 int sum = 0;
	 set<int> allms;

	 int ndigits = count_digits(n);

	 int factor = 1;
	 for (int i = 0; i < ndigits-1; i++) {
		  factor*=10;
	 }

	 int oldm = n;
	 for (int i = 0; i < ndigits-1; i++) {
		  
		  int m = oldm/10;
		  m += oldm%10*factor;

		  if (m > n && m <= B) {
				allms.insert(m);
		  }

		  oldm = m;
	 }

	 return allms.size();
}

void handle_case(int i) {
	 cout << "Case #" << i << ": ";

	 int A, B;

	 cin >> A >> B;

	 int sum = 0;
	 for (int i = A; i < B; i++) {
		  sum += count(A, B, i);
	 }
	 
	 cout << sum << endl;
}

int main(void) {
	 int T;
	 cin >> T;

	 for (int i = 0; i < T; i++) {
		  handle_case(i+1);
	 }
	 return 0;
}
