#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

int old_arr[5][5] ;
int new_arr[5][5] ;
int r1,r2 ;
int cnt ,match ;

int read_inp(){
	cnt=0;match=0 ;
	scanf("%d",&r1) ;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			scanf("%d",&old_arr[i][j]) ;
		}
	}
	scanf("%d",&r2) ;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			scanf("%d",&new_arr[i][j]) ;
		}
	}
}

int logic(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(old_arr[r1][i]==new_arr[r2][j]){
				cnt++ ;
				match=old_arr[r1][i] ;
			}
		}
	}
}


int main(){
	FILE *fp = freopen("1.in","r",stdin) ;
	FILE *fp1 = freopen("a.out","w",stdout) ;
	int test ;
	scanf("%d",&test) ;
	for(int i=1;i<=test;i++){
		read_inp() ;
		logic() ;
		if(cnt>1){
			printf("Case #%d: Bad magician!\n",i) ;
		}
		else if(cnt==0)
			printf("Case #%d: Volunteer cheated!\n",i) ;
		else 
			printf("Case #%d: %d\n",i,match) ;
	}
}
