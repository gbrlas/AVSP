// CodeJam.cpp : Defines the entry point for the console application.
//

//////////////////////////////////////////////////////////////////////////
//	1

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;

#define L	1000
#define INT64	__int64


void qsort(int * a, int low, int high)
{
	int pivotloc;
	if (low < high) {                      
		int	temp = a[low],           
			pivotkey = a[low],      
			i = low,
			j = high;
		while (i<j) {            // 从表的两端交替地向中间扫描
			while (i<j && a[j]>=pivotkey) --j;
			a[i] = a[j];      // 将比枢轴记录小的记录移到低端
			while (i<j && a[i]<=pivotkey) ++i;
			a[j] = a[i];      // 将比枢轴记录大的记录移到高端
		}
		a[i] = temp;            // 枢轴记录到位
		pivotloc = i; 
		
		qsort(a, low, pivotloc-1); 
		qsort(a, pivotloc+1, high);          
	}
}

void sort(int * a, int la)
{
	qsort(a, 0, la - 1);
}

int main()
{
	int	n,
		p,
		k,
		l,
		i,
		j;
	INT64	num;
	int	f[L];

	// input file redirection
	freopen("input.txt", "r", stdin);
	
	// output file redirection
	freopen("output.txt", "w", stdout);

	cin >> n;
	for ( i = 0; i < n; i++ )
	{
		// input
		cin >> p >> k >> l;
		for ( j = 0; j < l; j++ )
			cin >> f[j];

		// calc

		// impossible case
		if ( p * l < l )
		{
			cout << "Case #" << i+1 << ": Impossible" << endl;
			continue;
		}

		num = 0;
		sort(f, l);
		INT64 w = 0;
		for ( j = 0; j < l; j++ )
		{
			if ( j % k == 0 )
				w++;
			num += f[l - 1 - j] * w;
		}


		// output
		cout << "Case #" << i+1 << ": ";
		unsigned long	x = num / ((unsigned long)INT_MAX + 1),
				y = num % ((unsigned long)INT_MAX + 1);
		if ( x )
			cout << x;
		cout << y << endl;

	}

	return 0;
}
