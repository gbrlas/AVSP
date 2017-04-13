#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

bool stillWorks(int products[], int numProducts, int cards[]) {
	for(int pro = 0; pro < numProducts; pro++) {
		int product = products[pro];
		for(int x = 9; x >= 0; x--) {
			if(cards[x] && (product % x == 0)) {
				product /= x;
				if(product == 1) {
					return true;
				}
				
				for(int z = 2; z <= cards[x]; z++) {
					if(product % x == 0) {
						product /= x;
						if(product == 1) {
							return true;
						}
					}
					else {
						break;
					}
				}
			}
		}
	}
	
	return false;
}

int main(int argc, char ** argv) {
	int numCases;
	
	cin >> numCases;
	for(int caseNum = 1; caseNum <= numCases; caseNum++) {
		cout << "Case #" << caseNum << ":\n";
		
		int numLines;//R
		int numCards;//N
		int maxNum;//M
		int numProducts;//K
		
		cin >> numLines;
		cin >> numCards;
		cin >> maxNum;
		cin >> numProducts;
		
		int products[32];
		int cards[10];
		int maybes[10];
		int temp[10];
		
		for(int line = 0; line < numLines; line++) {
			bool allones = true;
			
			for(int x = 2; x < 10; x++) {
				cards[x] = 0;
				maybes[x] = 0;
			}
			
			for(int x = 0; x < numProducts; x++) {
				cin >> products[x];
				if(products[x] > 1) {
					allones = false;
				}
			}
			
			if(allones) {
				for(int x = 0; x < numCards; x++) {
					cout << '2';
				}
				cout << "\n";
				continue;
			}
			
			for(int x = 0; x < numProducts; x++) {
				int pro = products[x];
				if(pro == 2) {
					if(!cards[2]) cards[2] = 1;
				}
				else if(pro == 3) {
					if(!cards[3]) cards[3] = 1;
				}
				else if(pro == 5) {
					if(!cards[5]) cards[5] = 1;
				}
				else if(pro == 7) {
					if(!cards[7]) cards[7] = 1;
				}
			}
			for(int x = 0; x < numProducts; x++) {
				int pro = products[x];
				for(int x = 2; x <= maxNum; x++) {
					temp[x] = 0;
				}
				while(pro > 1) {
					if(pro % 2 == 0) {
						pro = pro/2;
						temp[2]++;
					}
					else if(pro % 3 == 0) {
						pro = pro/3;
						temp[3]++;
					}
					else if(pro % 5 == 0) {
						pro = pro/5;
						temp[5]++;
					}
					else if(pro % 7 == 0) {
						pro = pro/7;
						temp[7]++;
					}
				}
				
				for(int x = 2; x <= maxNum; x++) {
					if(x == 5 || x == 7) {
						if(temp[x] > cards[x]) {
							cards[x] = temp[x];
						}
					}
					if(temp[x] > maybes[x]) {
						maybes[x] = temp[x];
					}
				}
			}
			
			int numMaybe = 0;
			for(int x = 2; x < 10; x++) {
				numMaybe += maybes[x];
			}
			while(numMaybe > numCards) {
				if(maxNum >= 8 && numMaybe - numCards > 1 && maybes[2] - cards[2] > 2) {
					maybes[2] -= 3;
					maybes[8] += 1;
					if(stillWorks(products, numProducts, maybes)) {
						numMaybe -= 2;
						continue;
					}
					maybes[2] += 3;
					maybes[8] -= 1;
				}
				else if(maxNum >= 6 && maybes[3] - cards[3] > 0 && maybes[2] - cards[2] > 0) {
					maybes[2] -= 1;
					maybes[3] -= 1;
					maybes[6] += 1;
					if(stillWorks(products, numProducts, maybes)) {
						numMaybe--;
						continue;
					}
					maybes[2] += 1;
					maybes[3] += 1;
					maybes[6] -= 1;
				}
				else if(maxNum >= 4 && maybes[2] - cards[2] > 1) {
					maybes[2] -= 2;
					maybes[4] += 1;
					if(stillWorks(products, numProducts, maybes)) {
						numMaybe--;
						continue;
					}
					maybes[2] += 2;
					maybes[4] -= 1;
				}
				else {
					cerr << "SANITY CHECK FAILED.\n";
				}
			}
			
			while(numMaybe < numCards) {
				maybes[2]++;
				numMaybe++;
			}
			
			for(int x = 2; x < 10; x++) {
				while(maybes[x] > 0) {
					cout << x;
					maybes[x]--;
				}
			}
			cout << "\n";
		}
	}
}
