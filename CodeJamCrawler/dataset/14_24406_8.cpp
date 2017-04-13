#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <stdint.h>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

	int k;
	cin >> k;

	for(int i = 0; i < k; ++i) {
/*
		int n;
		cin >> n;

		string A[100];

		for(int l = 0; l < n; ++l) 
			cin >> A[l];


		int res = 0;
		string sample;
		sample += A[0][0];

		for(int l = 1; l < A[0].size(); ++l) {
			if(A[0][l] == A[0][l-1]) 
				++res;

			else
				sample += A[0][l];
		}

		for(int j = 1; j < n; ++j) {
			if(A[j][0] != sample[0]) {
				res = -1;
				break;
			}

			for(int l = 1, s = 1; l < A[j].size(); ++l) {
				if(A[j][l] == A[j][l-1]) {
					++res;
				}
				else if(A[j][l] == sample[s]) {
					++s;
				}

				else {
					res = -1;
					break;
				}
			}
		}

		cout << "Case #" << i+1 << ": ";

		if(res == -1)
			cout << res << endl;

		else 
			cout << "Fegla Won" << endl;*/


			int a, b, l;
		cin >> a >> b >> l;

		int res = 0;
		for(int it = 0; it < a; ++it) {
			for(int j = 0; j < b; ++j) {
				if((it & j) < l)
					++res;
			}
		}


		cout << "Case #" << i+1 << ": ";
		cout << res << endl;

	}

	return 0;
}