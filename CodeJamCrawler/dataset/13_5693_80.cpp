/*
 * second.cpp
 *
 *  Created on: 13-Apr-2013
 *      Author: rspr
 */
#include<stdio.h>
int L[100][100];
using namespace std;
bool validRow(int r,int c,int RC,int CC){
	int val=L[r][c];
	for(int i=0;i<CC;++i)
		if(L[r][i] > val)
			return false;
	return true;
}
bool validCol(int r,int c,int RC,int CC){
	int val=L[r][c];
	for(int i=0;i<RC;++i)
		if(L[i][c] > val)
			return false;
	return true;
}
int main(){
	int T;scanf("%d",&T);
	int tc=0,flag=0;
	while(T-->0){
		int N,M;scanf("%d%d",&N,&M);
		++tc;flag=0;
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				scanf("%d",&L[i][j]);
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j)
				if(!validRow(i,j,N,M) && !validCol(i,j,N,M)){
					printf("Case #%d: NO\n",tc);
					flag=1; break;
				}
			if(flag)break;
		}
		if(flag==0)
			printf("Case #%d: YES\n",tc);
	}
	return 0;
}



