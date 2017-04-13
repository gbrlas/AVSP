#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(){
	int T,r1,r2,count,num;
	int a[4][4],b[4][4];
	scanf("%d",&T);
	for(int k=0;k<T;k++){
		scanf("%d",&r1);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++) scanf("%d",&a[i][j]);
		}
		scanf("%d",&r2);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++) scanf("%d",&b[i][j]);
		}
		count=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(a[r1-1][i]==b[r2-1][j]){
					count++;
					num=a[r1-1][i];
				}
			}
		}
		if(count>1) printf("Case #%d: Bad magician!\n",k+1);
		else{
			if(count) printf("Case #%d: %d\n",k+1,num);
			else printf("Case #%d: Volunteer cheated!\n",k+1);
		}
	}
	return 0;
}