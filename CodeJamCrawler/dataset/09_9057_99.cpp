#include <iostream>
#include <fstream>
#define MAXL 16
#define MAXD 5001
#define MAXN 501
#define MAXC 30

using namespace std;

bool m[MAXN][MAXL][MAXC];
char z[MAXD][MAXL];
int main ()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	int l, d, n;
	char ch;
	fin >> l >> d >> n;
	for (int a=0; a<n; a++)
		for (int b=0; b<l; b++)
			for (int c=0; c<MAXC; c++)
				m[a][b][c] = false;
	for (int i=0; i<d; i++)
	{
		for (int r=0; r<l; r++)
		{
			fin >> ch;
			z[i][r] = ch;
		}
	}
	for (int i=0; i<n; i++)
 	{
		for (int r=0; r<l; r++)
		{
			fin >> ch;
			if (ch != '(')
			{
				cout << ch;
				m[i][r][ch] = true;
			} else {
				cout << "DAROM!" << endl;
				fin >> ch;
				while (ch != ')')
				{
					m[i][r][ch] = true;
     				cout << "-" << ch;
					fin >> ch;
				}
			}
		}
		cout << endl << endl;
	}
	
	bool tinka = true;
	int kiek[MAXN];
	for (int i=0; i<n; i++)
		kiek[i] = 0;
		
	for (int i=0; i<d; i++)
	{
		for (int j=0; j<n; j++)
		{
		tinka = true;
			for (int r=0; r<l; r++)
			{
				if (!m[j][r][z[i][r]])
				{
					tinka = false;
					break;
				}
			}
		if (tinka == true) { kiek[j]++; };
		}
	}
	for (int i=0; i<n; i++)
	{
		cout << "Case #" << i+1 << ": " << kiek[i] << endl;
		fout << "Case #" << i+1 << ": " << kiek[i] << endl;
	}
	fout.close();
	//cout << (int)'a' << " " << (int)'z' << endl;
	cin.get();
	return 0;
}
