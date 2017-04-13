#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define inputFile string("B-small-attempt5.in")
#define outputFile string("B-small-attempt5.out")

streambuf *cinbuf;
streambuf *coutbuf;
bool comp(pair<int, int> &a, pair<int,int> &b)
{
	return a.second < b.second;
}

void calc()
{
	int cases, rows, cols;
	bool f;
	cin >>cases;
	cin >> rows >> cols;
	int l;
	vector<pair<int,int> > ::iterator minIt, maxIt, minIt2, maxIt2;
	vector<vector<pair<int,int> > > rowsV;
	vector<vector<pair<int,int> > > colsV;
	vector<pair<int,int> >  temp;
	for (int i = 1; i <= cases; i++)
	{
		f = true;
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				cin >> l;
				temp.push_back(pair<int,int>(k,l));
			}
			rowsV.push_back(temp);
			temp.clear();
		}
		for (int k =0; k < cols; k++)
		{
			for (int j =0; j < rows; j++)
			{
				temp.push_back(pair<int,int>(j,rowsV[j][k].second));
			}

			colsV.push_back(temp);
			temp.clear();
		}

		for (int j = 0; j < rows && f; j++)
		{
			minIt = min_element(rowsV[j].begin(), rowsV[j].end(),comp);
			maxIt = max_element(rowsV[j].begin(), rowsV[j].end(),comp);
			if (minIt->second != maxIt->second && rows >= 2 && cols >= 2)
			{
				for (int k = 0; k < cols && f; k++)
				{
					if (rowsV[j][k].second == minIt->second)
					{
						minIt2 = min_element(colsV[k].begin(), colsV[k].end(),comp);
						maxIt2 = max_element(colsV[k].begin(), colsV[k].end(),comp);

						if (minIt2->second != maxIt2->second)
						{
							cout << "Case #" << i <<": NO" << endl;
							f = false;
							break;
						}
					}
				}

			}
		}

		for (int j = 0; j < cols && f; j++)
		{
			minIt = min_element(colsV[j].begin(), colsV[j].end(),comp);
			maxIt = max_element(colsV[j].begin(), colsV[j].end(),comp);
			if (minIt->second != maxIt->second && rows >= 2 && cols >= 2)
			{
				for (int k = 0; k < rows && f; k++)
				{
					if (colsV[j][k].second == minIt->second)
					{
						minIt2 = min_element(rowsV[k].begin(), rowsV[k].end(),comp);
						maxIt2 = max_element(rowsV[k].begin(), rowsV[k].end(),comp);
						if (minIt2->second != maxIt2->second)
						{
							cout << "Case #" << i <<": NO" << endl;
							f = false;
							break;
						}
					}
				}
			}
		}



		if (f)
		{
			cout << "Case #" << i <<": YES" << endl;
		}
		cin >> rows >> cols;
		rowsV.clear();
		colsV.clear();
}




}






int main()
{
	ifstream in(inputFile.c_str());
	if (!in.is_open())
	{
		cerr << "couldn't open input file, using default cin" << endl;
		cinbuf = NULL;
	}
	else
	{
		cinbuf = cin.rdbuf();
		cin.rdbuf(in.rdbuf());
	}

	ofstream out(outputFile.c_str());
	if (!out.is_open())
	{
		cerr << "couldn't open output file, using default cout" << endl;
		coutbuf = NULL;
	}
	else
	{
		coutbuf = cout.rdbuf();
		cout.rdbuf(out.rdbuf());
	}

	calc();

	if (cinbuf != NULL)
	{
		cin.rdbuf(cinbuf);
	}
	if (coutbuf != NULL)
	{
		cout.rdbuf(coutbuf);
	}
	exit(0);
}
