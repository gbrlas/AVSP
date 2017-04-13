// Codejam Pratice rotate.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int t;
int sum[4][2]; 
int x,y;
int arrow[4][2]={{1,0},{0,1},{1,1},{-1,1}};
int rwin,bwin;
int rcheck, bcheck;
char data[60][60], temp[60][60];
int a,b;
int n,k;

FILE *op,*out;

int return_sum(int index, int j, int l) {
	
	a=j, b=l;
	rcheck = 0, bcheck = 0;

	while(a>=0 && a<n && b>=0 && b<n) {
		if(temp[a][b] == 'R' && rcheck==0) sum[index][0]+=1;
			else rcheck = 1;
					
		if(temp[a][b] == 'B' && bcheck==0) sum[index][1]+=1;
			else bcheck = 1;

		a+=arrow[index][0];
		b+=arrow[index][1];

		if(rcheck == 1 && bcheck ==1) break;

	}

	return 0;
}

int main()
{
	int i,j,k,aa;
    int number1,number2;
	int data1[6][6],data2[6][6];
	int ok=0,sum, sumcnt, sumcount[4];
	long double c,f,x,min,nvalue,now, total,p;

	//ofstream outfile("output.txt");
	op = fopen("input.txt","r");
	out = fopen("output.txt","w");

	fscanf(op,"%d",&t);

	for(i=0;i<t;i++) {

		fscanf(op,"%lf %lf %lf",&c, &f, &x);
		// cout << c << f<< x << endl;
		// infile >> number1;
		
		now = 0.2;
		total = 0;
		ok = 0;
		
		// 30.0 2.0 100.0
		
		while(1) {

			p = x / now ;
			if(ok == 0) { min = p; ok = 1; }
			else if(min > (total + p)) { min = total + p; }
			
			total += (c / now);
			now +=(f/10);

		//	cout << "P: " << p << "now: " << now << "min: " << min << endl;
	//		cin >> aa;; 

			if(total > min) break;			
		}
		fprintf(out,"Case #%d: ",i+1);
		fprintf(out,"%.7lf\n", min/10);
	}
	
	return 0;
}
