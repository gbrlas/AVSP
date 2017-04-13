#include <iostream>
#include <cmath>
#include <string>
#include<fstream>
using namespace std;

bool checkpalin(int A[], int a)
{
	for(int i=0;i<a;i++){
		if(A[i]!=A[a-i-1]) return false;}
	return true;
}

void convert(long long int A, int B[])
{
	for(int i=0 ; i<15; i++)
	{
		B[i]=A%10;
		A = A/10;
	}
	return;
}

int size(long long int A){
	long long int power = 10;
	for(int i=1; i<= 15 ; i++)
	{
		if((A/power)==0) return i;
		else power *= 10;
	}
}

int main()
{
	ifstream fi;
	ofstream fo;
	fi.open("input.in");
	fo.open("output.in");

	int N;
	fi>>N;
	
	for(int k=1 ; k<=N ;k++){
	double A1,B1;
	fi>>A1>>B1;
	
	long long int A = sqrt(A1);
	long long int B = sqrt(B1);
	long long int wins = 0;
	for (int i=A ; i<=B ;i++)
	{	
		int a =  size(i);
		int check[15];
		convert(i,check);
		if (checkpalin(check,a))
		{	long long int sqr = i*i;
			int a =  size(sqr);
			int	check[15];
			convert(sqr,check);

			if( (sqr>=A1)&&(sqr<=B1)&&checkpalin(check,a)) {wins++;
			
			//fo<<i<<endl<<i*i<<endl<<endl;
			
			}}}

	fo<<"Case  #"<<k<<": "<<wins<<endl;
	}

	return 0;
}