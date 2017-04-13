// CodeJam.cpp : Defines the entry point for the console application.
//

//////////////////////////////////////////////////////////////////////////
//	2.Train TimeTable

#include <iostream>
#include <algorithm>
using namespace std;

#define N	100
#define NA	100
#define NB	100
#define T	60

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

int Trains( int * a, int la,  int * b, int lb )
{
	int num = 0;
	sort(a, la);
	sort(b, lb);

	int	i = 0,
		j = 0;
	while ( i < la && j < lb )
	{
		if ( a[i] < b[j] )
		{
			i++;
			num++;
		}
		else
		{
			i++;
			j++;
		}
	}

	num += la - i;

	return num;
}

int main()
{
	int	n,
		na,
		nb,
		i,
		j,
		t,
		depA[NA],
		depB[NB],
		arrA[NB],
		arrB[NA];
	char 	time[6];

	// input file redirection
	freopen("input.txt", "r", stdin);
	
	// output file redirection
	freopen("output.txt", "w", stdout);

	cin >> n;
	for ( i = 0; i < n; i++ )
	{
		// input a case
		cin >> t >> na >> nb;
		
		for ( j = 0; j < na; j++ )
		{
			cin >> time;
			depA[j] = ( ( time[0] - '0' ) * 10 + ( time[1] - '0' ) ) * 60
				+ ( ( time[3] - '0' ) * 10 + ( time[4] - '0' ) );
			cin >> time;
			arrB[j] = ( ( time[0] - '0' ) * 10 + ( time[1] - '0' ) ) * 60
				+ ( ( time[3] - '0' ) * 10 + ( time[4] - '0' ) ) + t;
		}

		for ( j = 0; j < nb; j++ )
		{
			cin >> time;
			depB[j] = ( ( time[0] - '0' ) * 10 + ( time[1] - '0' ) ) * 60
				+ ( ( time[3] - '0' ) * 10 + ( time[4] - '0' ) );
			cin >> time;
			arrA[j] = ( ( time[0] - '0' ) * 10 + ( time[1] - '0' ) ) * 60
				+ ( ( time[3] - '0' ) * 10 + ( time[4] - '0' ) ) + t;
		}

		// output a case
		cout << "Case #" << i + 1 << ": " << Trains(depA, na, arrA, nb) << " " << Trains(depB, nb, arrB, na) << endl;

	}

	return 0;
}
