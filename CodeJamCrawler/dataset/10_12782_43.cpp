//
//  main.cpp
//  Round1A
//
//  Created by Trevor Gray on 5/7/10.
//  Copyright 2010 Trevor Gray. All rights reserved.
//

#include <iostream>
#include "math.h"

using namespace std;

static bool solve(int n, int k);

int main (int argc, char * const argv[]) {
	int totalCases = 1;
	
	cin >> totalCases;
	
	for (int current = 1; current <= totalCases; ++current) {
		int n, k;
		cin >> n;
		cin >> k;
		
		cout << "Case #" << current << ": ";
		
		if (solve(n, k))
			cout << "ON";
		else
			cout << "OFF";
		
		cout << "\n";
		
	}
	
    return 0;
}

static bool solve(int n, int k) {
	int size = log2f(k)+1;
	if (size < n)
		size = n;
	char binary[size];
	
	for (int i = size; i >= 0; --i) {
		int power = powf(2, i);
		if (power <= k) {
			binary[i] = 1;
			k -= power;
		} else {
			binary[i] = 0;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (binary[i] == 0)
			return false;
		else
			continue;
	}
	
	return true;
}



