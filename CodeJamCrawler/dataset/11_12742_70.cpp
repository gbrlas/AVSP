#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int n[t];
	long int *cn[t];
	
	for(int i = 0; i < t; i++)
	{
		cin >> n[i];
		cn[i] = new long int[n[i]];
		for(int j = 0; j < n[i]; j++)
			cin >> cn[i][j];
	}
	
	
	for (int i = 0; i < t; i++)
	{
		long int ssum = 0;
		for (int j = 0; j < n[i]; j++)
			ssum = ssum ^ cn[i][j];
		
		if (ssum != 0)
			cout << "Case #" << i+1 << ": NO" << endl;
		else
		{
			long int bsum = 0;
			long int min = cn[i][0];
			for (int j = 0; j < n[i]; j++)
			{
				bsum += cn[i][j];
				if (min > cn[i][j])
					min = cn[i][j];
			}
			cout << "Case #" << i+1 << ": " << (bsum - min) << endl;
		}
	}
	
	return 0;
}

