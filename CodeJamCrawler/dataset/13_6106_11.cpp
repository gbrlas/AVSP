#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <sstream>

using namespace std;

long long n, a, b,c ,d,x,y,M;
long long N,k,l;
#define _CRT_SECURE_NO_WARNINGS
#define For(i,a,b) for (int i(a),_b(b); i < _b; ++i)

/*
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}*/

//qsort (arr, c, sizeof(int), compare);

//int sizeX,sizeY;
//myfile>>sizeX>>sizeY;
//int** ary = new int*[sizeX];
//for(int i = 0; i < sizeX; ++i)
//    ary[i] = new int[sizeY];

int main() {
	ifstream myfile;
	myfile.open("input.txt");
	ofstream myfile2;
	myfile2.open("output.txt");
	
	myfile >> N;
	

	for (int u = 0; u < N; u++) {
		long long r,t;
		myfile>>r>>t;
		int co=0;

		for(t-=(2*r+1);t>=0;t-=(2*r+1))
		{
			r+=2;
			co++;
		}

		/*while(t>=0){
			t-=(2*r+1);	
			r++;
			co++;
		}*/
		
		myfile2<<"Case #"<<u+1<<": "<<co<<endl;
		cout<<"Case #"<<u+1<<": "<<co<<endl;
		
	}
	system("pause");
}