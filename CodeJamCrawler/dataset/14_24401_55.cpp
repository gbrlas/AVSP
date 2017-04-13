#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

	int t, s;
	cin >> t;
	
	for(int k = 0; k < t; ++k) {

		cin >> s;
		int A[4], tmp;

		for(int j = 0; j < 16; ++j)
			if(j/4 + 1 == s)
				cin >> A[j - (s-1)*4];
			else 
				cin >> tmp;
		
		cin >> s;
		int B[4];

		for(int j = 0; j < 16; ++j)
			if(j/4 + 1 == s)
				cin >> B[j - (s-1)*4];
			else 
				cin >> tmp;

		int ans, flag = 0;

		for(int i = 0; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				if(A[i] == B[j]) {
					if(!flag) {
						ans = A[i];
						flag = 1;
					}

					else if(flag) {
						flag = 2;
					}
				}

		if(flag == 0)
			cout << "Case #" << k+1 << ": Volunteer cheated!" << endl;

		else if(flag == 1)
			cout << "Case #" << k+1 << ": " << ans << endl;

		else if(flag == 2)
			cout << "Case #" << k+1 << ": Bad magician!" << endl;


	}

	return 0;

}