// cj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream.h>

int	T,
	n;

const int	N = 1000;

int A[N];
int B[N];

void sort()
{
	int temp;
	for ( int i = 0; i < n; i++ )
		for ( int j = n-1; j > i; j-- )
		if ( A[j] < A[j-1] )
		{
			temp = A[j];
			A[j] = A[j-1];
			A[j-1] = temp;
			temp = B[j];
			B[j] = B[j-1];
			B[j-1] = temp;
		}
}


int main(int argc, char* argv[])
{
	int i, j, k;
	int total;

	freopen("p1is.txt", "r", stdin);
//	freopen("p1os.txt", "w", stdout);

	cin >> T;
	for ( i = 1; i <= T; i++ )
	{
		total = 0;
		cin >> n;
		for ( j = 0; j < n; j++ )
			cin >> A[j] >> B[j];

		sort();
		for ( j = 0; j < n; j++ )
			for ( k = 0; k < j; k++ )
				total = ( B[k] > B[j] ) ? total+1 : total;

		cout << "Case #" << i << ": " << total << endl;
	}
	return 0;
}

