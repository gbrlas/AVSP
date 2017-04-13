#define _DEB

#ifndef _DEB
	#define inf cin
	#define ouf cout
	#include <iostream>
#else
	#include <fstream>
#endif



void sort(long *a, long n)
{
	long i, tmp;
	bool f = true;

	while (f)
	{
		f = false;
		for (i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				f = true;
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
}



long gcd(long a, long b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	long c;
	while (b) {
		c = a % b;
		a = b;
		b = c;        
	}
	return a;
}


int main()
{
	using namespace std;
#ifdef _DEB
	ifstream inf("input.txt");
	ofstream ouf("output.txt");
#endif

	int i, j, c;
	int N;
	long t[3], T;

	inf >> c;

	for (i = 0; i < c; i++)
	{
		inf >> N;
		for (j = 0; j < N; j++) inf >> t[j];

		sort(t, N);
		for (j = 0; j < N - 1; j++) t[j] = t[j + 1] - t[j];
		
		T = (N == 2) ? t[0] : gcd(t[0], t[1]);

		ouf << "Case #" << i + 1 << ": " << ( ((t[N - 1] % T) == 0) ? 0 : (T - (t[N - 1] % T))) << endl;
	}

#ifdef _DEB
	inf.close();
	ouf.close();
#endif
	return 0;
}
