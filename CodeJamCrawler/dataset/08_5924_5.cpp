#include "stdio.h"
#include "string.h"


/* ////////////////////////////////////////

Small dataset

T = 1000
1 ¡Ü n ¡Ü 8
-1000 ¡Ü xi, yi ¡Ü 1000 

Large dataset

T = 10
100 ¡Ü n ¡Ü 800
-100000 ¡Ü xi, yi ¡Ü 100000 

*  ///////////////////////////////       */

static const int  line_len = 201;
static const int  N = 10;
static int  icase = 0;


void  A1_do_case(FILE * fp) {
	int  X[N];
	int  Y[N];
	char  line[line_len];
	int  n;

	//fgets(line, line_len, fp);
	//sscanf(line, "%d", &n);
	//printf("turnTime: %d\n", turnTime);

	fscanf(fp, "%d", &n);
	//printf("%d\n", n);

	//fgets(line, line_len, fp);
	for(int i = 0; i < n; i++) {
		//sscanf(line, "%d", &na, &nb);
		fscanf(fp, "%d", X+i);
	}
	for(int i = 0; i < n; i++) {
		//sscanf(line, "%d", &na, &nb);
		fscanf(fp, "%d", Y+i);
	}
	
	// X ÔöÐò   Y ½µÐò
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < n-i; j++) {
			int t;
			if(X[j] < X[j-1]) {
				t = X[j];
				X[j] = X[j-1];
				X[j-1] = t;
			}
			if(Y[j] > Y[j-1]) {
				t = Y[j];
				Y[j] = Y[j-1];
				Y[j-1] = t;
			}
		}
	}

	int resu = 0;
	/*int  idxx0 = -1, idxy0 = -1;
	for(int i = 1; i < n; i++) {
		if(X[i] >= 0 && X[i-1] < 0) {
			idxx0 = i; break;
		}
	}
	*/
	for(int i = 0; i < n; i++) {
		resu += X[i] * Y[i];
	}
	//Case #X: Y
	printf("Case #%d: %d\n", ++icase, resu);
}

int main(int argc, char * argv[]) {
	FILE * oldinfp = freopen("A-small-attempt0.in.txt", "r+t", stdin);
	//FILE * oldoutfp = stdout;
	FILE * oldoutfp = freopen("A-small-attempt0.out.txt", "w+t", stdout);
	//FILE * fp = fopen("B-small-attempt0.out", "r+t");
	char line[201] = {0};
	int T = 0;
	int i = 0;
	
	if(!oldinfp || !oldoutfp){
		fprintf(stderr, "open faile");
		return -1;
	}
	
	fgets(line, 101, stdin);
	sscanf(line, "%d", &T);
	for( ; i < T; i++) {
		A1_do_case(stdin);
		//printf("--------------------------\n");
	}
	return 0;
}



/**
Problem

You are given two vectors v1=(x1,x2,...,xn) and v2=(y1,y2,...,yn). The scalar product
of these vectors is a single number, calculated as x1y1+x2y2+...+xnyn. 

Suppose you are allowed to permute the coordinates of each vector as you wish. Choose
two permutations such that the scalar product of your two new vectors is the smallest 
possible, and output that minimum scalar product. 

Input

The first line of the input file contains integer number T - the number of test cases. 

For each test case, the first line contains integer number n. 
The next two lines contain n integers each, giving the coordinates of v1 and v2 respectively. 

Output

For each test case, output a line 

Case #X: Ywhere X is the test case number, starting from 1, and Y is the minimum scalar 
product of all permutations of the two given vectors. 

Limits


Small dataset

T = 1000
1 ¡Ü n ¡Ü 8
-1000 ¡Ü xi, yi ¡Ü 1000 

Large dataset

T = 10
100 ¡Ü n ¡Ü 800
-100000 ¡Ü xi, yi ¡Ü 100000 

Sample


Input 
   
  
2
3
1 3 -5
-2 4 1
5
1 2 3 4 5
1 0 1 0 1

Output 

Case #1: -25
Case #2: 6

 

*/