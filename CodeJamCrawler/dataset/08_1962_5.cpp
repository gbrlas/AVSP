// CodeJam.cpp : Defines the entry point for the console application.
//

//////////////////////////////////////////////////////////////////////////
//	1.Minimum Scalar Product

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

#define N	1000
int	a[N];
int	b[N];

#define	INT64	__int64

//const INT64	MIN = 100000000000;

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
/*	for ( int i = 0; i < la -1; i++ )
		for ( int j = la - 1; j > i; j-- )
			if ( a[j-1] > a[j] )
			{
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
	*/
	qsort(a, 0, la - 1);
}

int main()
{
	int	t,
		n,
		i,
		j,
		h,
		l;

	INT64	tmp,
		min;

	// input file redirection
	freopen("input.txt", "r", stdin);
	
	// output file redirection
	freopen("output.txt", "w", stdout);

	cin >> t;
	for ( i = 0; i < t; i++ )
	{
		// input
		cin >> n;
		for ( j = 0; j < n; j++ )
			cin >> a[j];
		for ( j = 0; j < n; j++ )
			cin >> b[j];
	
		// calc
		min = 0;
		sort(a,n);
		sort(b,n);

		for ( j = 0; j < n; j++ )
		{
			tmp = a[j] * b[n-j-1];
			min += tmp;
		}


		h = min / INT_MAX;
		l = min % INT_MAX;
		// output
		if ( h )
			cout << "Case #" << i+1 << ": " << h << l << endl;
		else
			cout << "Case #" << i+1 << ": " << l << endl;

	}

	return 0;
}
