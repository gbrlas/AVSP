#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int t;
char buffer[256];
char tmp[256];
bool flag;
int numbers[256];

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &t);
	for (int k=0; k<t; k++) {
		scanf("%s", buffer);
		flag = next_permutation(buffer, buffer+strlen(buffer));
		if (!flag) {
			for (int i=0; i<strlen(buffer); i++) numbers[buffer[i]]++;
			memset(buffer, 0, sizeof(buffer));
			for (int i='1'; i<='9'; i++) {
				if (numbers[i]>0) {
					buffer[0] = i;
					numbers[i]--;
					break;
				}
			}
			buffer[1] = '0';
			for (int i='0'; i<='9'; i++) {
				while (numbers[i]>0) {
					buffer[strlen(buffer)] = i;
					numbers[i]--;
				}
			}			
		}
		printf("Case #%d: %s\n", k+1, buffer);
	}
	return 0;
}