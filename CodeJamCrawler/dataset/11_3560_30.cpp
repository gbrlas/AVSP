#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>

using namespace std;

int n;
int cards[1<<11];
int cardcnt[1<<14];

int main(){
	int tt; cin >> tt;
	for (int zz = 1; zz <= tt; zz++){
		cin >> n;
		memset(cardcnt,0,sizeof(cardcnt));
		for (int i = 0; i < n; i++){
			cin >> cards[i];
			cardcnt[cards[i]]++;
		}
		sort(cards,cards+n);
		int best = 0x3f3f3f3f;
		int cnt = 0;
		while(cnt < n){
			int i = 0;
			while(cardcnt[i] == 0) i++; 
			int len = 0;
			for(; cardcnt[i] > cardcnt[i-1]; i++){
				len++;
				cardcnt[i]--;
			}
			//cout << "i = " << i << endl;
			cnt += len;
			if (best > len) best = len;
			//cout << "len = " << len << endl;
		}
		if (best == 0x3f3f3f3f) best = 0;
		cout << "Case #" << zz <<": " << best << endl;
	}
	
	return 0;
}
