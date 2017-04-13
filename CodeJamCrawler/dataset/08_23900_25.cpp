#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>

#define MAX 2147483647

using namespace std;

char *test;
string str ,mainstr;
int k;

int a[6] ,mem[6];
int mn ,lot;

void method(void) {
	char checkstr[1004];
	int idx=0;
	str = mainstr;
	int i ,j;
	string temp ;

	for(i=0;i<lot;i++) {
		temp = str.substr(0,k);
		if(i != lot-1) str = str.substr(k);
		for(j=0;j<k;j++) 
			checkstr[idx++] = temp[a[j]-1];
		
	}
	checkstr[idx] = '\0';

	char save = checkstr[0];
	int cnt = 1;
	for(i=1;i<idx;i++) {
		if(checkstr[i] != save) {
			save = checkstr[i];
			++cnt;
		}
	}
	if(mn > cnt) {
		mn = cnt;
		test = checkstr;
	}
	//mn = min(mn, cnt);

}

void permute(int index) {
	int i;
	if(index == k) {
		method();
		return;
	}
	for(i=1;i<=k;i++) {
		if(mem[i] == 0) {
			mem[i] = 1;
			a[index] = i;
			permute(index+1);
			mem[i] = 0;
		}
	}
}

void init(void) {
	int i;
	mn = MAX;
	for(i=0;i<6;i++) {
		mem[i] = 0;
		a[i] = 0;
	}

}
int main(int argc, char *argv[])
{
	int x,ncase;
	scanf("%d",&ncase);
	for(x=1;x<=ncase;x++) {
		init();
		scanf("%d",&k);
		cin >> mainstr;
		lot = mainstr.size() / k;
		permute(0);
		printf("Case #%d: %d\n",x,mn);
		//printf("%s\n",test);
	}
	return 0;
}
