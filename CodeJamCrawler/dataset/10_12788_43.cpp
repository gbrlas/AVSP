//
//  main.cpp
//  Round1B
//
//  Created by Trevor Gray on 5/7/10.
//  Copyright 2010 Trevor Gray. All rights reserved.
//

#include <iostream>
#include <queue>
#include "math.h"

using namespace std;

static int solve (int r, int k, int n);

int main (int argc, char * const argv[]) {
	int totalCases = 1;
	
	cin >> totalCases;
	
	for (int current = 1; current <= totalCases; ++current) {
		int r, k, n;
		cin >> r;
		cin >> k;
		cin >> n;
		
		cout << "Case #" << current << ": " << solve(r, k, n) << "\n";
	}
	
    return 0;
}

static int solve (int r, int k, int n) {
	queue<int> line;
	queue<int> onRide;
	int moneyMade = 0;
	
	for (int i = 0; i < n; ++i) {
		int size;
		cin >> size;
		line.push(size);
	}
	
	for (int currentRun = 0; currentRun < r; ++currentRun) {
		int maxSize = k;
		
		while (!line.empty()) {
			int nextGroup = line.front();
			if (maxSize < nextGroup)
				break;
			
			line.pop();
			onRide.push(nextGroup);
			
			maxSize -= nextGroup;
		}
		
		while (!onRide.empty()) {
			line.push(onRide.front());
			onRide.pop();
		}
		
		moneyMade += k-maxSize;
	}
	
	return moneyMade;
}

