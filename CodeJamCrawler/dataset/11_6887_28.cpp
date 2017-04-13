#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; 

int main()
{
	ifstream in; 
	ofstream out; 

	in.open("A-large.in");
	out.open("A.txt"); 
	
	int TC = 1, TestCase;

	in >> TestCase; 

	while(TestCase--)
	{
		int R, C, ret = 0;
		in >> R >> C;
		char mat[100][100];
		memset(mat, 0, sizeof(mat));

		for(int a = 0; a < R; a++ )
			for(int b = 0; b < C; b++ )
			{
				in >> mat[a][b]; 
			}

		for(int a = 0; a < R; a++ )
			for(int b = 0; b < C; b++ )
			{
				if( a+1 < R && b+1 < C ) {
					if( mat[a][b] == '#' && mat[a][b+1] == '#' &&  mat[a+1][b] == '#' &&  mat[a+1][b+1] == '#' ){
						mat[a][b] = '/', mat[a+1][b+1] = '/', mat[a+1][b] = 'a', mat[a][b+1] = 'a'; 
					}
				}
			}
			
		for(int a = 0; a < R; a++ )
			for(int b = 0; b < C; b++ )
			{
				if( mat[a][b] == '#' ) ret = -1;
			}

		for(int a = 0; a < R; a++ )
			for(int b = 0; b < C; b++ )
			{
				if( mat[a][b] == 'a' ) mat[a][b] = '\\'; 
			}

			cout << "Case #" << TC << ":" << endl;
		out << "Case #" << TC++ << ":" << endl;

		if( ret == -1 ) cout << "Impossible" << endl, out <<  "Impossible" << endl;
		else
		{
			for(int a = 0; a < R; a++ )
			{
				for(int b = 0; b < C; b++ )
				{
					cout << mat[a][b];
					out << mat[a][b];
				}
				cout << endl, out << endl;
			}
		}

	}
	out.close(); 
	in.close();

	return 0;
}