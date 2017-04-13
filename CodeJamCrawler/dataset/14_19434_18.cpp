#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<fcntl.h>
#include<stack>
#include<queue>
#include<iostream>

using namespace std ;
//int logic(){
	
//}


int read_inp(){
	int a,b,k ;
	cin>>a>>b>>k ;
	int ans =0 ;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++)
			if((i&j)<k)
				ans++ ;
	}
	return ans ;
}

int main(){
	FILE *fp = freopen("1.in","r",stdin) ;
FILE *fp1 =freopen("1.out","w",stdout) ;
	int test ;
	scanf("%d",&test) ;
	for(int i=1;i<=test;i++){
	printf("Case #%d: ",i) ;
		int x = read_inp() ;
		cout<<x<<endl ;
	}
}
