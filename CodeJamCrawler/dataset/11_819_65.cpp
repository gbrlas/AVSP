#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

char in_grid[51][51],out_grid[51][51];

int main(){
	int cases=1,r,c;
	scanf("%d",&cases);
	for(int t=1;t<=cases;t++){
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++){
			scanf("%s",in_grid[i]);
		}
		bool valid=true;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(in_grid[i][j]=='#'){
					if(i<r-1 && j<c-1 && \
					   in_grid[i][j+1]=='#' && \
					   in_grid[i+1][j]=='#' && \
					   in_grid[i+1][j+1]=='#'){
						in_grid[i][j]='/';
						in_grid[i+1][j]='\\';
						in_grid[i][j+1]='\\';
						in_grid[i+1][j+1]='/';
					} else {
						valid=false;
						break;
					}
				}
			}
			if(!valid)break;
		}
		printf("Case #%d:\n", t);
		if(!valid){
			printf("Impossible\n");
		} else {
			for(int i=0;i<r;i++){
				printf("%s\n",in_grid[i]);
			}
		}
	}
	return 0;
}
