#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

	int t;
	cin >> t;

	for(int k = 0; k < t; ++k) {

		int n;
		cin >> n;

		vector<double> Naomi(n), Ken(n);

		for(int i = 0; i < 2*n; ++i) {
			if(i < n)
				cin >> Naomi[i];
			else 
				cin >> Ken[i-n];
		}

		sort(Naomi.begin(), Naomi.end());
		sort(Ken.begin(), Ken.end());

		int i, j = 0, flag = 0;
		for(i = 0; i < n; ++i) {
			for(; j < n; ++j)
				if(Ken[i] < Naomi[j]) {
					++j;
					flag = 1;
					break;
				}

			if(!flag)
				break;

			flag = 0;
		}

		int vin = i;
		int vin2 = 0;

		for(i = n-1; i >= 0; --i) {

			int size = Ken.size();
			for(j = 0; j < size; ++j) {
				if(Naomi[i] < Ken[j]) {
					Ken.erase(Ken.begin() + j);
					break;
				}
			}

			if(j == size) {
				Ken.erase(Ken.begin());
				++vin2;
			}
		}

		cout << "Case #" << k+1 << ": " << vin << " " << vin2 << endl;
	}

	return 0;

}