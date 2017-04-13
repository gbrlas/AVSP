#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>

#define INF 2147483647

using namespace std;

int mic[10002][2];
int op[10002] ,ch[10002];
int m, final;

void init(void) {
	int i,j;
	for(i=0;i<10002;i++) 
		for(j=0;j<2;j++) 
			mic[i][j] = INF;
}

void method(int index ,int op ,int plus) {
	int left = index*2;
	int right = index*2+1;
	if(op == 1) { // AND GATE
		if(mic[left][0] != INF && mic[right][0] != INF) 
			mic[index][0] = min(mic[index][0] ,mic[left][0] + mic[right][0] + plus);
		if(mic[left][0] != INF && mic[right][1] != INF) 
			mic[index][0] = min(mic[index][0] , mic[left][0] + mic[right][1] + plus);
		if(mic[left][1] != INF && mic[right][0] != INF) 
			mic[index][0] = min(mic[index][0] , mic[left][1] + mic[right][0] + plus);
		if(mic[left][1] != INF && mic[right][1] != INF) 
			mic[index][1] = min(mic[index][1] , mic[left][1] + mic[right][1] + plus);
	}
	else { // OR GATE
		if(mic[left][0] != INF && mic[right][0] != INF) 
			mic[index][0] = min(mic[index][0] , mic[left][0] + mic[right][0] + plus);
		if(mic[left][0] != INF && mic[right][1] != INF) 
			mic[index][1] = min(mic[index][1] , mic[left][0] + mic[right][1] + plus);
		if(mic[left][1] != INF && mic[right][0] != INF) 
			mic[index][1] = min(mic[index][1] , mic[left][1] + mic[right][0] + plus);
		if(mic[left][1] != INF && mic[right][1] != INF) 
			mic[index][1] = min(mic[index][1] , mic[left][1] + mic[right][1] + plus);
	}
}

int main() {
	int ncase ,x ,i ,j;
	scanf("%d",&ncase);
	for(x=1;x<=ncase;x++) {
		init();
		scanf("%d%d",&m ,&final);
		int temp = (m-1)/2;
		for(i=1;i<=temp;i++) 
			scanf("%d%d",&op[i] ,&ch[i]);
		for(;i<=m;i++) {
			scanf("%d",&temp);
			mic[i][temp] = 0;
		}
		for(i=(m-1)/2 ; i > 0 ; i--) {
			method(i ,op[i] ,0);
			if(ch[i]) method(i ,!op[i] ,1);
		}
		printf("Case #%d: ",x);
		if(mic[1][final] != INF) printf("%d\n",mic[1][final]);
		else printf("IMPOSSIBLE\n");
	}
	
	return 0;
}
