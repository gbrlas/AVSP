#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int sumSquare(int base, int cur) {
	int count = 0;
	while(cur > 0) {
		int mod = cur % base;
		count += mod * mod;
		cur = cur / base;
	}
	return count;
}

void buildHappy(int base, int cur, char** happy) {
	happy[base][cur] = 'x';
	int sum = sumSquare(base, cur);
	//cout << base << " " << cur << "-" << sum << " " << happy[base][sum] << endl;
	if(sum >= 100000) {
		happy[base][cur] = 'u';
		return;
	}
	if(happy[base][sum] == 'c') {
		buildHappy(base, sum, happy);
	} 
	if(happy[base][sum] == 'u') {
		happy[base][cur] = 'u';
	} else if(happy[base][sum] == 'a') {
		happy[base][cur] = 'a';
		return;
	} else {
		happy[base][cur] = 'b';
	}
}

int main (int argc, char * const argv[]) {
	FILE *fp=fopen("input.txt", "r"), *ofp=fopen("output.txt", "w");
	long long max = 100000;
	
	char** happy = (char**)malloc(sizeof(char*) * 11);
	for(int i = 2; i < 11; i++) {
		happy[i] = (char*)malloc(sizeof(char) * max);
		for(int j = 0; j < max; j++) happy[i][j] = 'c';
	}
	for(int i = 2; i < 11; i++) {
		happy[i][1] = 'a';
	}
	for(int i = 2; i < 11; i++) {
	   for(int j = 2; j < max; j++)
			buildHappy(i, j, happy);
	}
	
	int c;
	fscanf(fp, "%d\n", &c);
	for(int i = 1; i <= c; i++) {
		fprintf(ofp, "Case #%d: ", i);
		char* line = (char*)malloc(sizeof(char) * 20);
		fgets(line, 20, fp);
		int num = strlen(line)/2;
		int numbers[num];
		int count = 0;
		for(int j = 0; j < num; j++) {
			numbers[j] = line[count] - '0';
			count += 2;
			if(numbers[j] == 1) {
				count++;
				numbers[j] = 10;
			}
		}
		for(int j = 2; j < max; j++) {
			bool happiness = true;
			for(int k = 0; k < num; k++) {
				if(happy[numbers[k]][j] != 'a') happiness = false;
			}
			if(happiness) {
				cout << j << "!" << endl;
				fprintf(ofp, "%d", j);
				break;
			}
		}
		fprintf(ofp, "\n");
	}
	
	fclose(ofp);
	return 0;
}
