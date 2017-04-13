#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>


inline bool isPalindrom(long double number) {

	char word[20];
	itoa((long long int)number, word, 10);
	int len = strlen(word);
	for (int i=0; i<len/2; i++)
		if (word[i] != word[len-i-1])
			return false;

	return true;
}

inline void nextPalindrom(long double * number) {

	char word[20];
	while (true) {
		bool correct = true;
		(*number)++;
		itoa((long long int)*number, word, 10);
		int len = strlen(word);
		for (int i=0; i<len/2; i++) {
			if (word[i] != word[len-i-1]) {
				correct = false;
				break;
			}
		}
		if (correct)
			break;
	}
}

using namespace std;
int main() {

	fstream input;
	input.open("C-small-attempt0.in", fstream::in);

	int words;
	input >> words;

	for (int nr=1; nr<=words; nr++) {
		
		long double begin, end;
		input>>begin>>end;

		int cnt = 0;
		long double init = 1;

		while (pow(init, 2)<begin) {
			nextPalindrom(&init);
		}

		bool first = true;
		do {
			
			if (!first)
				nextPalindrom(&init);
			else
				first = false;

			long double result = pow(init, 2);
			if (result>end)
				break;
			//printf("(%ld->%ld)", (long int)begin, (long int)result);
			if (isPalindrom(result)) {
				//printf("%ld -> %ld, ", (long int)init, (long int)result);
				cnt++;
			}
		} while(true);
		printf("Case #%d: %d\n", nr, cnt);
	}

	getchar();
	return 0;
}