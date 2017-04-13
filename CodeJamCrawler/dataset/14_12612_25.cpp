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
	int i,j,k;
    int number1,number2;
	int data1[6][6],data2[6][6];
	int sum, sumcnt, sumcount[4];

	ofstream outfile("output.txt");
	op = fopen("input.txt","r");


	fscanf(op,"%d",&t);

	for(i=0;i<t;i++) {

		fscanf(op,"%d",&number1);

		//infile >> number1;

		for(j=0;j<4;j++) {
			for(k=0;k<4;k++) {
				fscanf(op,"%d",&data1[j][k]);
			}
		}
		
		fscanf(op,"%d",&number2);
		
		for(j=0;j<4;j++) {
			for(k=0;k<4;k++)
				fscanf(op,"%d",&data2[j][k]);
		}

		sum = sumcnt = 0;

		for(j=0;j<4;j++) {
			for(k=0;k<4;k++) {
				if(data1[number1-1][j] == data2[number2-1][k]) {
					sumcnt+=1;
					sum = data1[number1-1][j];
					break;
				}
			}
		}

		
		/*
		Case #1: 7
		Case #2: Bad magician!
		Case #3: Volunteer cheated!*/

		outfile << "Case #" <<  i+1 << ": ";

			if(sumcnt == 1) {
						
				outfile << sum << endl;
			}

			if(sumcnt == 0) {
						
				outfile << "Volunteer cheated!" << endl;
			}

			if(sumcnt >= 2) {
						
				outfile << "Bad magician!" << endl;
			}


	}

	return 0;
}
