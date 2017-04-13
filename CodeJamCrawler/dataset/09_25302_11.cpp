//#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include<string>
#include <set>
#include <vector>
#pragma comment(linker, "/STACK:64000000")
using namespace std;

//ifstream cin("input.txt");
//ofstream cout("output.txt");


int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int k;
	//cin>>k;
	scanf("%d",&k);
	int n;
	double r,t,mini;
	int a[5][3];
	for(int l=0; l<k; l++){
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%d%d%d", &a[i][0],&a[i][1],&a[i][2]);
		}
		if(n==1){
			printf("Case #%d: %.6f\n",l+1,(double)a[0][2]); 
		}
		if(n==2){
			
			printf("Case #%d: %.6f\n",l+1,max((double)a[0][2],(double)a[1][2])); 
		}
		if(n==3){
			t=sqrt((double)(a[0][0]-a[1][0])*(a[0][0]-a[1][0])+(a[0][1]-a[1][1])*(a[0][1]-a[1][1]));
			t+=a[0][2]+a[1][2];
			t/=2;
			mini=max(t,(double)a[2][2]);
			t=sqrt((double)(a[0][0]-a[2][0])*(a[0][0]-a[2][0])+(a[0][1]-a[2][1])*(a[0][1]-a[2][1]));
			t+=a[0][2]+a[2][2];
			t/=2;
			mini=min(mini,max(t,(double)a[1][2]));
			t=sqrt((double)(a[1][0]-a[2][0])*(a[1][0]-a[2][0])+(a[1][1]-a[2][1])*(a[1][1]-a[2][1]));
			t+=a[1][2]+a[2][2];
			t/=2;
			mini=min(mini,max(t,(double)a[0][2]));
			printf("Case #%d: %.6f\n",l+1,mini); 

		}

	}
	return 0;
}	