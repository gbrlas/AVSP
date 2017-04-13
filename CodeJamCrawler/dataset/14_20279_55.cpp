#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

void readTestCase(int &firstAns, int &secondAns, int (&card1)[4][4], int (&card2)[4][4]){
	scanf("%d", &firstAns);
	for(int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            scanf(" %d", &card1[i][j]);
        }
    }
	scanf("%d", &secondAns);
	for(int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            scanf(" %d", &card2[i][j]);
        }
    }
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T, firstAns, secondAns;
	int card1[4][4], card2[4][4];
	scanf("%d", &T);
	
	//print output
	for(int i = 1; i <= T; i++){
		readTestCase(firstAns, secondAns, card1, card2);
		int ans = 0;
		cout << "Case #" << i << ": ";
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				if(card1[firstAns-1][j] == card2[secondAns-1][k]){
					if(ans == 0) ans = card1[firstAns-1][j];
					else{ 
						ans = -1;
						break;
					}
				}
			}
		}
		if(ans == 0) cout << "Volunteer cheated!" << endl;
		else if(ans == -1) cout << "Bad magician!" << endl;
		else cout << ans << endl;
	}

	return 0;
}