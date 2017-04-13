#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int t, i, j, n;
	int min, sum, xorsum;
	int c[1000];
	cin >> t;
	for(i = 0; i < t; i++){
		cin >> n;
		sum = 0;
		min = 10000000;
		xorsum = 0;
		for(j = 0; j < n; j++){
			cin >> c[j];
			if(min > c[j])min = c[j];
			sum += c[j];
			xorsum ^= c[j];
		}
		cout << "Case #" << i + 1 << ": ";
		if(xorsum == 0)cout << sum - min << endl;
		else cout << "NO" << endl;
	}

    return 0;
}
