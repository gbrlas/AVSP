#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;



double C,F,X,R ;
double Best_ans ;
int read_inp(){
	R=2.0 ;
	Best_ans = 0.0 ;
	scanf("%lf%lf%lf",&C,&F,&X) ;
	return 0 ;
}

int logic(){
	double local_ans=0.0 ;
	Best_ans= X/R ;
	double time_add =0.0;
	while(1){
		
		//printf("%.7f ",Best_ans) ;
		time_add += C/R ;
		R+=F ;
		local_ans= time_add+(X/R) ;
		//printf("%.7f ",local_ans) ;
		if(local_ans<=Best_ans)Best_ans=local_ans ;
		else
			break ;
	}
}


int main(){
	FILE *fp = freopen("1.in","r",stdin) ;
	FILE *fp1 = freopen("b1.out","w",stdout) ;
	int test ;
	scanf("%d",&test) ;
	for(int i=1;i<=test;i++){
	read_inp() ;
	logic() ;
	printf("Case #%d: %.7lf\n",i,Best_ans) ;
	}
}


