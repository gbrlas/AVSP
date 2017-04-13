// gcj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int compare (const void * a, const void * b)
{
	return ( *(int*)b - *(int*)a );
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	fflush(stdin);
	cin >> T;

	for (int i=0;i<T;i++)
	{
		int N,S,p;
		int t[101];

		cin >> N;
		cin >> S;
		cin >> p;

		int res=0;
		//cout << N << endl;
		//cout << S << endl;
		//cout << p << endl;

		for (int j=0; j<N;j++)
		{
			cin >> t[j];
			//cout << t[j];
		}
		qsort (t, N, sizeof(int), compare);


		cout <<"Case #" << i+1 << ": ";

		for (int j=0; j<N;j++)
		{
			//cout << "t" << t[j] << endl;
			int hasil1, hasil2;

			int  tt = t[j];
			hasil1= tt/3;
			hasil2= tt%3;

			if(hasil1>=p)
				res++;
			else if(hasil1==(p-1) && hasil2>0)
				res++;
			else if(hasil1>=1 && hasil1==(p-1) && hasil2==0 && S>0)
			{
				S--;
				res++;
			}
			else if(hasil1==(p-2) && hasil2>=2 && S>0)
			{
				S--;
				res++;
			}
		}

		cout << res << endl;
	}
	return 0;
}

