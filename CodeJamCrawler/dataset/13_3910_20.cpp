//============================================================================
// Name        : fsquare.cpp
// Author      : sanket sudake
// Version     :
// Copyright   : GNU GPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000
#define SQRT 31
void marksquare(bool square[MAX]) {
	for (int i = 1; i <= 1000; i++)
		square[i] = false;
	for (int i = 1; i <= SQRT; i++)
		square[i * i] = true;
}
bool palindrome(int number) {
	int rev = 0, digit, num = number;
	do {
		digit = (number % 10);
		rev = ((rev * 10) + digit);
		number = (number / 10);
	} while (number != 0);
	if (rev == num)
		return true;
	return false;
}
int main() {
	int testcase;
	bool square[MAX];
	marksquare(square);
	cin >> testcase;
	for (int k = 1; k <= testcase; k++) {
		int a, b;
		cin >> a >> b;
		int count = 0;
		for (int i = a; i <= b; i++)
			if (square[i] && palindrome(i) && palindrome(sqrt(i))) {
				count = count + 1;
			}
		cout << "Case #" << k << ": " << count << endl;
	}
	return 0;
}
