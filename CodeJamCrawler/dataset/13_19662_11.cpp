#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int find(long long pR, long long nR, int current, double paint)
{
	double blackArea = nR*nR - pR*pR;
	double paintNeeded = blackArea;
	paint -= paintNeeded;
	if(paint < 0)
		return current;
	else
		return find(pR + 2, nR + 2, current + 1, paint);
}


int main()
{
	ifstream cin("A-small-attempt1.in", ios::in);
	ofstream cout("out.out", ios::out);
	int testCases = 0;
	cin >> testCases;
	
	int (*grid)[2];
	grid = new int[testCases][2];

	for(int i = 0; i < testCases; i++)
	{
		for(int entry = 0; entry < 2; entry++)
		{
			cin >> grid[i][entry];
		}
	}

	for(int i = 0; i < testCases; i++)
	{
		//cout << "DATA: " << grid[i][0] << " " << grid[i][1] << endl;
		cout << "Case #" << i + 1 << ": " << find(grid[i][0], grid[i][0]+1, 0, grid[i][1]) << endl;
		//cout << grid[i][0] << " " << grid[i][1] << endl;
	}
	delete[] grid;
	cout.flush();
	cin.close();
	cout.close();
	return 0;
}