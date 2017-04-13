#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int num;

int main()
{
	ifstream in("F:\\Users\\Simy\\Downloads\\A-large (1).in");
	if(in == NULL)
	{
		cout << "hello" << endl;
	}
	ofstream out("a.out");


	in >> num;
	for(int i = 0;i<num;i++)
	{
		int r,c;
		in >> r >> c;
		vector< vector<char> > matrix(r,c);
		bool b = true;
		for(int j = 0;j<r;j++)
		{
			for(int k = 0;k<c;k++)
			{
				in >> matrix[j][k];
			}
		}

		out << "Case #" << i+1 << ": " << endl;

		for(int j = 0;j<r;j++)
		{
			for(int k = 0;k<c;k++)
			{
				if(matrix[j][k] == '#')
				{
					if(k != c-1 && j != r-1)
					{
						if(matrix[j+1][k] == '#' && matrix[j][k+1] == '#' && matrix[j+1][k+1] == '#')
						{
							matrix[j][k] = matrix[j+1][k+1] = '/';
							matrix[j+1][k] = matrix[j][k+1] = '\\';
						}
						else
						{
							b = false;
							break;
						}
					}
						else
						{
							b = false;
							break;
						}
				}
			}
		}
		
		if(b)
		{
			for(int j = 0;j<r;j++)
			{
				for(int k = 0;k<c;k++)
				{
					out << matrix[j][k];
				}
				out << endl;
			}
		}
		else
		{
			out << "Impossible" << endl;
		}
	}
	return 0;
}