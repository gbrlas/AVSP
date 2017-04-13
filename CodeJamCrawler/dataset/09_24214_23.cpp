#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define TMAX 1005

int t;
char nr[100];
long long rez;
int uniq, n;
char numbers[256];

char alpha[40];

long long power(int a, int b) {
	long long ret = a;
	if (b==0) return 1;
	for (int i=1; i<b; i++) ret *= a;
	return ret;
}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	alpha[0] = '1';
	alpha[1] = '0';
	for (int i=2; i<10; i++) alpha[i] = '0'+i;
	for (int i=0; i<25; i++) alpha[10+i] = 'a'+i;
	scanf("%d", &t);
	for (int k=0; k<t; k++) {
		scanf("%s", nr);
		memset(numbers, 0, sizeof(numbers));
		uniq = 0;
		rez = 0;
		for (int i=0; i<strlen(nr); i++) {
			if (numbers[nr[i]]==0) {
				numbers[nr[i]] = alpha[uniq];
				uniq++;
			}
		}
		if (uniq==1) uniq++;
		n = strlen(nr)-1;
		for (int i=0; i<=n; i++) {
			rez = rez + ((numbers[nr[i]]-'0')*power(uniq, n-i));
		}
		printf("Case #%d: %lld\n", k+1, rez);
	}
	return 0;
}