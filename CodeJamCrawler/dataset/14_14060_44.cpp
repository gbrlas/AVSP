#include <iostream>
#include <algorithm>

using namespace std;

int getWarScore(int index, double *a, double *b, int n)
{
	if(index >= n)
		return 0;
	double target = a[index];
	for(int i = 0; i < n; ++i)
	{
		if(b[i] > target)
		{
			b[i] = -1;
			return getWarScore(index + 1, a, b, n);
		}
	}

	return 1 + getWarScore(index + 1, a, b, n);
}

int getDWarScore(int index1, int index2, int startIndex1, double *a, double *b, int n)
{
	if(index1 < startIndex1)
		return 0;

	if(b[index2] >= a[index1])
	{
		return getDWarScore(index1, index2 - 1, startIndex1 + 1, a, b, n);
	}
	else
		return 1 + getDWarScore(index1 - 1, index2 - 1, startIndex1, a, b, n);
}

int main()
{
	int T;
	cin >> T;

	for(int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;

		double *a = new double[N];
		double *b = new double[N];
		double *c = new double[N];
		double *d = new double[N];

		for(int j = 0; j < N; ++j)
		{
			cin >> a[j];
		}
		for(int j = 0; j < N; ++j)
		{
			cin >> b[j];
		}

		sort(a, a+N);
		sort(b, b+N);
		for(int j = 0; j < N; ++j)
		{
			c[j] = a[j];
			d[j] = b[j];
		}

		int y = getWarScore(0, a, b, N);

		int z = getDWarScore(N - 1, N - 1, 0, c, d, N);

		cout << "Case #" << i + 1 << ": " << z << " " << y << endl; 
	}
	return 0;
}