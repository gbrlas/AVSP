/*
 * Q NO 3
 * Code Jam
 * Author Amit Jaspal
 */
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<sstream>
#include<string.h>
#define MAXN 7003
using namespace std;
char X[MAXN], Z[30];
long long int ans[2][MAXN];

int Is() {
	int i;
	for(i = 1; X[i]; i++){
		if(X[i] != Z[i]) return 1;
	}
	return 0;
}

void Initialize(int x) {
	int i, p = 0, j;
	for(i = 0; i<2; i++){
		for(j = 0; j<= x; j++){
			ans[i][j]=p;
		}
	}	
}

void Calculate(int x, int z) {
	int i, j, i1 = 0, i2 = 1 ,x11;
	Initialize(x);
	for(i = 1; i<= x; i++) {
		if(X[i] == Z[1]){
			ans[1][i]=ans[1][i]+ans[1][i-1];
			ans[1][i]=ans[1][i]%1000000;
			ans[1][i]=ans[1][i]+1;
			ans[1][i]=ans[1][i]%1000000;
		}
		else{
			ans[1][i] = ans[1][i-1];
			ans[1][i]=ans[1][i]%1000000;
		}	
	}
	for(i = 2; i<= z; i++) {
		for(j = 1; j <= x; j++) {
			if(Z[i] == X[j]) {
				ans[i1][j]=ans[i1][j-1]+ans[i2][j-1];
				ans[i1][j]=ans[i1][j]%1000000;
			}
			else {
				ans[i1][j]=ans[i1][j-1];
				ans[i1][j]=ans[i1][j-1]%1000000;
			}
		}
		i1 = !i1;
		i2 = !i2;
	}
	x11=ans[i2][x]%10000;
	stringstream ss;
	string s;
	ss<<x11;
	ss>>s;
	while(s.size()<4){
		s="0"+s;
	}
	cout<<s<<endl;
}
int main() {
	int ks,count=1;
	char ss[20];
	gets(ss);
	//cin>>ss;
	sscanf(ss,"%d",&ks);
	while(ks--) {
		gets(X+1);
		strcpy(Z,"!welcome to code jam");
		Z[21]='\0';
		int xlen, zlen;
		cout<<"Case #"<<count<<": ";
		count++;
		for(xlen = 1; X[xlen]; xlen++);
			for(zlen = 1; Z[zlen]; zlen++);
				xlen--;
			zlen--;
		if(xlen == zlen) {
			if(!Is())
				printf("0001\n");
			else printf("0000\n");
		}
		else if(xlen<zlen) {
			printf("0000\n");
		}else
			Calculate(xlen,zlen);
	}
	return 0;
}

