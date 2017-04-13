#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{

	ifstream in("C:\\Users\\Simy\\Downloads\\A-small-attempt0.in");
	if(in == NULL)
	{
		cout << "hello" << endl;
	}
	ofstream out("a.out");

	int T;
	in >> T;
	for(int i=0;i<T;i++)
	{
		char V[4][4];
		int a[4][4];
		bool w = false;
		bool finish = true;

		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				in >> V[j][k];
				if(V[j][k] == '.')
				{
					finish = false;
					a[j][k] = 0;
				}
				if(V[j][k] == 'O')
					a[j][k] = 1;
				if(V[j][k] == 'X')
					a[j][k] = 10;
				if(V[j][k] == 'T')
					a[j][k] = 100;
			}
		}

		for(int m=0;m<4;m++)
		{
			int z;
			int x;
			z=a[m][0]+a[m][1]+a[m][2]+a[m][3];
			x=a[0][m]+a[1][m]+a[2][m]+a[3][m];
			if(z==4 || z==103 || x==4 || x==103)
			{
				out << "Case #" << i+1 << ": " << "O won" << endl;
				w = true;
			}
			if(z==40 || z==130 || x==40 || x==130)
			{
				out << "Case #" << i+1 << ": " << "X won" << endl;
				w = true;
			}
		}
		int b = a[0][0]+a[1][1]+a[2][2]+a[3][3];
		int c = a[0][3]+a[1][2]+a[2][1]+a[3][0];
		if(b==4 || b==103 || c==4 || c==103)
		{
			out << "Case #" << i+1 << ": " << "O won" << endl;
				w = true;
		}
		if(b==40 || b==130 || c==40 || c==130)
		{
			out << "Case #" << i+1 << ": " << "X won" << endl;
				w = true;
		}

		if(w==false && finish ==false)
			out << "Case #" << i+1 << ": " << "Game has not completed" << endl;
		if(w==false && finish ==true)
			out << "Case #" << i+1 << ": " << "Draw" << endl;
	}

	return 0;
}