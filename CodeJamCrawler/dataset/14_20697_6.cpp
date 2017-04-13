#include <cstdio>
using namespace std;

int counter = 0;

void make() {
    
    int try1, try2, ans;
    int match = 0;
    int pattern1[4][4], pattern2[4][4];
    scanf("%d", &try1);
    for(int i=0;i<4; ++i){
		for(int j=0; j<4; ++j){
			scanf("%d", &pattern1[i][j]);
		}
	}
	
    scanf("%d", &try2);
    for(int i=0;i<4; ++i){
		for(int j=0; j<4; ++j){
			scanf("%d", &pattern2[i][j]);
		}
	}
	
    for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			if(pattern1[try1-1][i] == pattern2[try2-1][j]){
				++match;
				ans = pattern1[try1-1][i];
			}
		}
	}
	
	printf("Case #%d: ", ++counter);
	switch(match){
		case 0: printf("Volunteer cheated! \n"); break;
		case 1: printf("%d \n",ans); break;
		default: printf("Bad magician! \n");
	}
	
    return;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
    freopen("a_outsmall0.txt", "w", stdout);
    int t; scanf("%d", &t);
    while(t--) {
        make();
    }
    return 0;
}
