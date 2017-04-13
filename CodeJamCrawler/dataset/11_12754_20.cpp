#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string *s[t];
	int n[t];
	
	for (int i = 0; i < t; i++)
	{
		cin >> n[i];
		s[i] = new string[n[i]];
		for (int j = 0; j < n[i]; j++)
			cin >> s[i][j];
	}
	
	for (int i = 0; i < t; i++)
	{
		float wp[n[i]], owp[n[i]], oowp[n[i]];
		int w[n[i]], p[n[i]];
		
		for (int j = 0; j < n[i]; j++)
		{
			int won=0, played=0;
			for (int k = 0; k < n[i]; k++)
			{
				if (s[i][j][k] != '.')
					played++;
				if (s[i][j][k] == '1')
					won++;
			}
			w[j] = won;
			p[j] = played;
		}
		
		// find wp
		for (int j = 0; j < n[i]; j++)
			wp[j] = ((float)w[j])/p[j];
		
		// owp
		for (int m = 0; m < n[i]; m++)
		{
			owp[m] = 0;
			for (int j = 0; j < n[i]; j++)
			{
				if (s[i][m][j] == '1')
					owp[m] += (((float)w[j])/(p[j]-1));
				else if (s[i][m][j] == '0')
					owp[m] += (((float)(w[j]-1))/(p[j]-1));
			}
			owp[m] = owp[m]/p[m];
		}
		
		// oowp
		for (int j = 0; j < n[i]; j++)
		{
			oowp[j] = 0;
			for (int k = 0; k < n[i]; k++)
			{
				if (s[i][j][k] != '.')
					oowp[j] += owp[k];
			}
			oowp[j] = oowp[j] / p[j];
		}
		
		cout << "Case #" << i+1 <<":\n";
		cout.precision(12);
		for (int j = 0; j<n[i]; j++)
		{
			// cout << wp[j] << "  " << owp[j] << "  " << oowp[j]<<endl;
			cout << (0.25*wp[j] + 0.50*owp[j] + 0.25*oowp[j]) << '\n';
		}		
	}
	
}

