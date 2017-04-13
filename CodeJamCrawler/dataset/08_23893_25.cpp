#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int op[100];
char str[100];
int len;
int cnt;

long long power(int n) {
	long long sum = 1;
	int i;
	for(i=0;i<n;i++) sum *= 10;
	return sum;
}

long long ATOI(char *str) {
	long long sum = 0;
	int i , lent;
	lent = strlen(str);
	for(i=0;i<lent;i++) 
		sum += (str[i]-'0') * power(lent-1-i);
	return sum;
}

long long numOfString(int start, int end , int saveop) {
	long long sign = (saveop)? -1 : 1;
	char temp[100];
	memset(temp , '\0' , 99);
	int index = 0 , i;
	for(i=start ; i < end ; i++) 
		temp[index++] = str[i];
	return (long long)sign * ATOI(temp);
}

void checkUgly(void) {

	int saveindex = 0 ,saveop = 0  ,i;
	long long sum = 0;

	for(i=1;i<len;i++) {
		if(op[i] != 2) {
			sum += numOfString(saveindex , i , saveop);
			saveop = op[i];
			saveindex = i;
		}
	}

	sum += numOfString(saveindex , i , saveop);

	if(!(sum%2) || !(sum%3) || !(sum%5) || !(sum%7)) 
		cnt++;
}

void gen(int index) {
	int i;
	if(index == len) {
		checkUgly();
	}
	else {
		for(i=0;i<3;i++) {
			op[index] = i;
			gen(index+1);
		}
	}
}

int main()
{
	int x, ncase;
	scanf("%d",&ncase);
	for(x=1;x<=ncase;x++) {

		cnt = 0;
		scanf("%s",str);
		len = strlen(str);

		if(len == 1) {
			int temp = str[0] - '0';
			if(!(temp%2) || !(temp%3) || !(temp%5) || !(temp%7)) 
				cnt = 1;
		}
		else gen(1);
		printf("Case #%d: %d\n",x ,cnt);
	}
	return 0;
}
